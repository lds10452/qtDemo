#include "langswitchwidget.h"
#include <QLabel>
#include <QComboBox>
#include <QVBoxLayout>
#include <QTranslator>
#include <QApplication>
QTranslator *LangSwitchWidget::translator=NULL;
LangSwitchWidget::LangSwitchWidget(QWidget *parent) : QWidget(parent)
{
    combox=new QComboBox;
    combox->addItem("English", "en");			//(a)
    combox->addItem("Chinese", "zh");
    combox->addItem("Latin", "la");
    label = new QLabel;
    label->setText(tr("TXT_HELLO_WORLD", "Hello World"));							//设置标签的内容
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(combox, 1);
    layout->addWidget(label, 5);
    setLayout(layout);
    connect(combox, SIGNAL(currentIndexChanged(int)),
          this, SLOT(changeLang(int)));			//(b)
}

void LangSwitchWidget::changeLang(int index)
{
    QString langCode=combox->itemData(index).toString();
    changeTr(langCode);
    label->setText(tr("TXT_HELLO_WORLD", "Hello World"));
}

void LangSwitchWidget::changeTr(const QString &langCode)
{
    if(translator)
    {
       qApp->removeTranslator(translator);
       delete translator;
       translator=NULL;
    }
    translator=new QTranslator;
    QString fileName="lang_"+langCode;
    if(translator->load(QString(":/res/langFile/")+fileName))
    {
        qApp->installTranslator(translator);
    }
}
