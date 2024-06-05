#include "colorselectwidget.h"
#include "ui_colorselectwidget.h"
#include <QLabel>
#include <QPushButton>

#define BaseColorMaxRowSpace 5
#define BaseColorMaxCol 8
ColorNum ColorSelectWidget::colorNum[3][3]={
    {ColorNum{4,1,1},ColorNum{16,1,1},ColorNum{64,1,1}},
    {ColorNum{4,4,1},ColorNum{8,8,1},ColorNum{8,8,1}},
    {ColorNum{4,4,4},ColorNum{4,4,4},ColorNum{4,4,4}}
};
static QString textstyle="QPushButton {background-color: %1;"
                  "border: 1px solid #999999;border-radius: 2px;}"
                  "QPushButton:hover {border: 2px solid #000000;border-radius: 2px;}"
                  "QPushButton:checked{border: 2px solid #ff0000;border-radius: 2px;}";

ColorSelectWidget::ColorSelectWidget(SCREEN_COLOR color,SCREEN_GRAY gray,QColor defaultColor,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ColorSelectWidget)
{
    ui->setupUi(this);
    setWindowModality(Qt::ApplicationModal);
    setFixedSize(540,460);
    m_ScreenColor=color;
    m_ScreenGray=gray;
    InitWidget();
    m_CurSelectColor=defaultColor;
    UpdateColor(defaultColor);
}

ColorSelectWidget::~ColorSelectWidget()
{
    delete ui;
}

void ColorSelectWidget::UpdateColor(QColor color)
{
    m_TempSelectColor=color;
    ui->lineEditRed->setText(QString::number(color.red()));
    ui->lineEditGreen->setText(QString::asprintf("%d",color.green()));
    ui->lineEditBlue->setText(QString().setNum(color.blue()));

    ui->lineEditColorHex->setText(color.name().toUpper());
    ui->labelColor->setStyleSheet(QString("QLabel{background-color:%1;}").arg(color.name()));
}

void ColorSelectWidget::ColorClicked()
{
    if(m_pLastSelectButton!=NULL)
    {
        m_pLastSelectButton->setChecked(false);
    }
    QPushButton* pbtclr = dynamic_cast<QPushButton*>(sender());
    QString ptname=pbtclr->objectName();
    QColor color(ptname);
    UpdateColor(color);
    m_pLastSelectButton=pbtclr;
}

void ColorSelectWidget::InitWidget()
{
    translateUi();
    m_pLastSelectButton=NULL;
    m_nCustomColorCount=0;
    memset(m_arrCustomBtn,0x00,sizeof(m_arrCustomBtn));

    switch (m_ScreenGray) {
    case SCREEN_GRAY_LOW:
        m_nHighBitsNum=2;
        break;
    case SCREEN_GRAY_MIDDLE:
        m_nHighBitsNum=4;
        break;
    case SCREEN_GRAY_HIGH:
        m_nHighBitsNum=6;
        break;
    default:
        m_nHighBitsNum=1;
        break;
    }
//    m_nColorSpace=256/pow(2,m_nHighBitsNum);
    int value=0xff>>(8-m_nHighBitsNum);
    m_nMaxColorVaule=value<<(8-m_nHighBitsNum);

    DrawBaseColor();
    DrawCustomColor();

    ui->labelColor->setFixedWidth(60);
    ui->pushButtonOk->setProperty("isOk",true);
    connect(ui->pushButtonOk,&QPushButton::clicked,this,&ColorSelectWidget::PushButtonClickFinish);
    ui->pushButtonCancel->setProperty("isOk",false);
    connect(ui->pushButtonCancel,&QPushButton::clicked,this,&ColorSelectWidget::PushButtonClickFinish);
    ui->colorPanelWidget->InitColorPanel(m_ScreenColor,m_ScreenGray,m_nHighBitsNum,m_nMaxColorVaule);
    connect(ui->colorPanelWidget,&ColorPanelWidget::ColorChange,this,&ColorSelectWidget::UpdateColor);

//    ui->spinBoxRed->setSingleStep(64);
//    ui->spinBoxRed->setFocusPolicy(Qt::NoFocus);
}

void ColorSelectWidget::translateUi()
{
    ui->labelColor->setText("");
    ui->labelRed->setText(tr("red(R):"));
    ui->labelGreen->setText(tr("green(G):"));
    ui->labelBlue->setText(tr("blue(B):"));
    ui->groupBoxBaseColor->setTitle(tr("base colors"));
    ui->groupBoxCusColor->setTitle(tr("custom colors"));
    ui->ptnAddColor->setText(tr("add to custom colors"));
    ui->pushButtonOk->setText(tr("ok"));
    ui->pushButtonCancel->setText(tr("cancel"));
}

void ColorSelectWidget::DrawBaseColor()
{
    // 基本色
    QGridLayout *pGridLayout = new QGridLayout;
    pGridLayout->setContentsMargins(2, 2, 2, 2);
    pGridLayout->setSpacing(BaseColorMaxRowSpace);
    m_nRedNum=colorNum[m_ScreenColor-1][m_ScreenGray-1].RedNum;
    m_nGreenNum=colorNum[m_ScreenColor-1][m_ScreenGray-1].GreenNum;
    m_nBlueNum=colorNum[m_ScreenColor-1][m_ScreenGray-1].BlueNum;
    for (int i=0;i<m_nBlueNum;i++) {
        for (int j=0;j<m_nGreenNum;j++) {
            for (int k=0;k<m_nRedNum;k++) {
                QPushButton *pBtnColor = new QPushButton(ui->widgetBaseColor);
                pBtnColor->setCheckable(true);
                int index=k+j*m_nRedNum+i*m_nGreenNum*m_nRedNum;
                int row=index/BaseColorMaxCol;
                int col=index%BaseColorMaxCol;
                pBtnColor->setFixedSize(QSize(24, 24));
                int r=(m_nRedNum-1)>0?m_nMaxColorVaule/(m_nRedNum-1)*k:0;
                int g=(m_nGreenNum-1)>0?m_nMaxColorVaule/(m_nGreenNum-1)*j:0;
                int b=(m_nBlueNum-1)>0?m_nMaxColorVaule/(m_nBlueNum-1)*i:0;
                QColor c(r,g,b);
                pBtnColor->setObjectName(c.name());
                pBtnColor->setStyleSheet(textstyle.arg(c.name()));
                connect(pBtnColor,SIGNAL(clicked()),this,SLOT(ColorClicked()));
                pGridLayout->addWidget(pBtnColor, row, col);
            }
        }
    }

    ui->widgetBaseColor->setLayout(pGridLayout);
//    int row=rNum*gNum*bNum/BaseColorMaxCol;
//    int col=rNum*gNum*bNum%BaseColorMaxCol;
//    resize(BaseColorMaxRowSpace*row+4,BaseColorMaxRowSpace*col+4);
}

void ColorSelectWidget::DrawCustomColor()
{
    QGridLayout *pGridLayout = new QGridLayout;
    pGridLayout->setContentsMargins(2, 2, 2, 2);
    pGridLayout->setSpacing(BaseColorMaxRowSpace);
    for (int i=0;i<2;i++) {
        for (int j=0;j<8;j++) {
            QPushButton *pBtnColor = new QPushButton(ui->widgetCustomColor);
            pBtnColor->setCheckable(true);
            pBtnColor->setFixedSize(QSize(24, 24));

            pBtnColor->setStyleSheet(textstyle.arg("#ffffff"));
            pBtnColor->setObjectName("#ffffff");
            connect(pBtnColor,SIGNAL(clicked()),this,SLOT(ColorClicked()));
            pGridLayout->addWidget(pBtnColor, i, j);
            m_arrCustomBtn[i*8+j]=pBtnColor;
        }
    }
    ui->widgetCustomColor->setLayout(pGridLayout);
}

void ColorSelectWidget::on_ptnAddColor_clicked()
{
    QString color=ui->lineEditColorHex->text();
    QPushButton *btn=m_arrCustomBtn[m_nCustomColorCount];
    m_nCustomColorCount++;
    btn->setStyleSheet(textstyle.arg(color));
    btn->setObjectName(color);
}

void ColorSelectWidget::PushButtonClickFinish()
{
    QPushButton *button=qobject_cast<QPushButton*>(sender());
    bool isOk=button->property("isOk").toBool();
    if(isOk)
    {
//        emit ColorSelectFinish(m_CurSelectColor);
        m_CurSelectColor=m_TempSelectColor;
    }
//    else {
//        emit ColorSelectFinish(QColor());
//    }
    close();
}
