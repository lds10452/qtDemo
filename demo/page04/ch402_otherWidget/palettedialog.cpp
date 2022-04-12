#include "palettedialog.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
PaletteDialog::PaletteDialog(QWidget *p):QDialog(p)
{
    createCtrlFrame();
    createContentFrame();
    QHBoxLayout *mainLayout=new QHBoxLayout(this);
    mainLayout->addWidget(m_pCtrlFrame);
    mainLayout->addWidget(m_pContentFrame);
}

void PaletteDialog::createCtrlFrame()
{
    m_pCtrlFrame=new QFrame;
    QLabel *windowLabel=new QLabel(tr("QPalette::window:"));
    windowCombox=new QComboBox;
    fillColorList(windowCombox);
    connect(windowCombox,SIGNAL(activated(int)),this,SLOT(showWindow()));

    QLabel *windowTextLabel=new QLabel(tr("QPalette::windowText:"));
    windowTextCombox=new QComboBox;
    fillColorList(windowTextCombox);
    connect(windowTextCombox,SIGNAL(activated(int)),this,SLOT(showWindowText()));

    QLabel *buttonLabel=new QLabel(tr("QPalette::button:"));
    buttonCombox=new QComboBox;
    fillColorList(buttonCombox);
    connect(buttonCombox,SIGNAL(activated(int)),this,SLOT(showButton()));

    QLabel *buttonTextLabel=new QLabel(tr("QPalette::buttonText:"));
    buttonTextCombox=new QComboBox;
    fillColorList(buttonTextCombox);
    connect(buttonTextCombox,SIGNAL(activated(int)),this,SLOT(showButtonText()));

    QLabel *baseLabel=new QLabel(tr("QPalette::base:"));
    baseCombox=new QComboBox;
    fillColorList(baseCombox);
    connect(baseCombox,SIGNAL(activated(int)),this,SLOT(showBase()));
    QGridLayout *mainLayout=new QGridLayout(m_pCtrlFrame);
    mainLayout->setSpacing(20);
    mainLayout->addWidget(windowLabel,0,0);
    mainLayout->addWidget(windowCombox,0,1);
    mainLayout->addWidget(windowTextLabel,1,0);
    mainLayout->addWidget(windowTextCombox,1,1);
    mainLayout->addWidget(buttonLabel,2,0);
    mainLayout->addWidget(buttonCombox,2,1);
    mainLayout->addWidget(buttonTextLabel,3,0);
    mainLayout->addWidget(buttonTextCombox,3,1);
    mainLayout->addWidget(baseLabel,4,0);
    mainLayout->addWidget(baseCombox,4,1);
}

void PaletteDialog::createContentFrame()
{
    m_pContentFrame=new QFrame;
    m_pContentFrame->setAutoFillBackground(true);
    QLabel *label1=new QLabel(tr("please enter value:"));
    QComboBox *combox1=new QComboBox;
    QLabel *label2=new QLabel(tr("please enter string:"));
    QLineEdit *lineEdit=new QLineEdit;
    QTextEdit *textEdit=new QTextEdit;
    QGridLayout *TopLayout =new QGridLayout;
    TopLayout->addWidget(label1,0,0);
    TopLayout->addWidget(combox1,0,1);
    TopLayout->addWidget(label2,1,0);
    TopLayout->addWidget(lineEdit,1,1);
    TopLayout->addWidget(textEdit,2,0,1,2);
    QPushButton *okBtn=new QPushButton(tr("ok"));
    okBtn->setAutoFillBackground(true);
    QPushButton *cancelBtn=new QPushButton(tr("cancel"));
    QHBoxLayout *bottom=new QHBoxLayout;
    bottom->addStretch(1);
    bottom->addWidget(okBtn);
    bottom->addWidget(cancelBtn);
    QVBoxLayout *mainLayout =new QVBoxLayout(m_pContentFrame);
    mainLayout->addLayout(TopLayout);
    mainLayout->addLayout(bottom);
}

void PaletteDialog::fillColorList(QComboBox *combox)
{
    QStringList colorList=QColor::colorNames();
    QString color;
    foreach(color,colorList)
    {
        QPixmap pix(QSize(70,20));
        pix.fill(QColor(color));
        combox->addItem(QIcon(pix),NULL);
        combox->setIconSize(QSize(70,20));
        combox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    }
}

void PaletteDialog::showWindow()
{
    QStringList colorList=QColor::colorNames();
    QColor color=QColor(colorList[windowCombox->currentIndex()]);
    QPalette p=m_pContentFrame->palette();
    p.setColor(QPalette::Window,color);
    m_pContentFrame->setPalette(p);
    m_pContentFrame->update();
}

void PaletteDialog::showWindowText()
{
    QStringList colorList=QColor::colorNames();
    QColor color=QColor(colorList[windowTextCombox->currentIndex()]);
    QPalette p=m_pContentFrame->palette();
    p.setColor(QPalette::WindowText,color);
    m_pContentFrame->setPalette(p);
}

void PaletteDialog::showButton()
{
    QStringList colorList=QColor::colorNames();
    QColor color=QColor(colorList[buttonCombox->currentIndex()]);
    QPalette p=m_pContentFrame->palette();
    p.setColor(QPalette::Button,color);
    m_pContentFrame->setPalette(p);
    m_pContentFrame->update();
}

void PaletteDialog::showButtonText()
{
    QStringList colorList=QColor::colorNames();
    QColor color=QColor(colorList[buttonTextCombox->currentIndex()]);
    QPalette p=m_pContentFrame->palette();
    p.setColor(QPalette::ButtonText,color);
    m_pContentFrame->setPalette(p);
}

void PaletteDialog::showBase()
{
    QStringList colorList=QColor::colorNames();
    QColor color=QColor(colorList[baseCombox->currentIndex()]);
    QPalette p=m_pContentFrame->palette();
    p.setColor(QPalette::Base,color);
    m_pContentFrame->setPalette(p);
}
