#include "drawwindow.h"
#include "drawwidget.h"
#include <QToolBar>
#include <QColorDialog>
DrawWindow::DrawWindow(QWidget *parent) : QMainWindow(parent)
{
    m_pDrawWgt=new DrawWidget;
    setCentralWidget(m_pDrawWgt);
    creatToolBar();
    setMinimumSize(600,400);
    showStyle(0);
    m_pDrawWgt->setWidth(widthSpinBox->value());
    m_pDrawWgt->setColor(Qt::black);
}
void DrawWindow::creatToolBar()
{
    QToolBar *toolBar=addToolBar("tool");
    QLabel *styleLabel=new QLabel(tr("线型风格:"));
    styleComboBox=new QComboBox;
    styleComboBox->addItem(tr("SolidLine"),
                                static_cast<int>(Qt::SolidLine));
    styleComboBox->addItem(tr("DashLine"),
                                static_cast<int>(Qt::DashLine));
    styleComboBox->addItem(tr("DotLine"),
                                static_cast<int>(Qt::DotLine));
    styleComboBox->addItem(tr("DashDotLine"),
                                static_cast<int>(Qt::DashDotLine));
    styleComboBox->addItem(tr("DashDotDotLine"),
                                static_cast<int>(Qt::DashDotDotLine));
                                                //关联相应的槽函数
    connect(styleComboBox,SIGNAL(activated(int)),this,SLOT(showStyle(int)));
    QLabel widthLabel(tr("线宽:"));
    widthSpinBox=new QSpinBox;
    connect(widthSpinBox,SIGNAL(valueChanged(int)),m_pDrawWgt,SLOT(setWidth(int)));
    colorBtn=new QToolButton;
    QPixmap pixmap(20,20);
    pixmap.fill(Qt::black);
    colorBtn->setIcon(QIcon(pixmap));
    connect(colorBtn,SIGNAL(clicked()),this,SLOT(showColor()));
    clearBtn=new QToolButton;
    clearBtn->setText(tr("清除"));
    connect(clearBtn,SIGNAL(clicked()),m_pDrawWgt,SLOT(clear()));
    toolBar->addWidget(styleLabel);
    toolBar->addWidget(styleComboBox);
    toolBar->addWidget(&widthLabel);
    toolBar->addWidget(widthSpinBox);
    toolBar->addWidget(colorBtn);
    toolBar->addWidget(clearBtn);
}
void DrawWindow::showStyle(int index)
{
    m_pDrawWgt->setStyle(styleComboBox->itemData(
        index,Qt::UserRole).toInt());
    //m_pDrawWgt->setStyle(styleComboBox->itemData(styleComboBox->currentIndex()).toInt());
}
void DrawWindow::showColor()
{
    QColor color=QColorDialog::getColor(Qt::black,this);
    if(color.isValid())
    {
        m_pDrawWgt->setColor(color);
        QPixmap pix(20,20);
        pix.fill(color);
        colorBtn->setIcon(QIcon(pix));
    }
}
