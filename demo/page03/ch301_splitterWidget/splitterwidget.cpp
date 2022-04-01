#include "splitterwidget.h"
#include <QSplitter>
#include <QTextEdit>
#include <QHBoxLayout>
SplitterWidget::SplitterWidget(QWidget *parent) : QWidget(parent)
{
    QSplitter *splitterMain=new QSplitter(Qt::Horizontal,0);
    QTextEdit *textLeft=new QTextEdit(tr("left textEdit"),splitterMain);
    textLeft->setAlignment(Qt::AlignCenter);

    QSplitter *splitterRight=new QSplitter(Qt::Vertical,splitterMain);
    splitterRight->setOpaqueResize(false);//拖拽分割条不实时显示
    QTextEdit *textUp=new QTextEdit(tr("top textEdit"),splitterRight);
    textUp->setAlignment(Qt::AlignCenter);
    QTextEdit *textBottom=new QTextEdit(tr("bottom textEdit"),splitterRight);
    textBottom->setAlignment(Qt::AlignCenter);
    splitterMain->setStretchFactor(1,1);
    //对话框大小改变时控件序号为1的splitterRight为可伸缩，
    //第二个参数大于0表示可伸缩,大小表示前后控件的伸缩比
    QHBoxLayout *lyout=new QHBoxLayout(this);
    lyout->addWidget(splitterMain);
}
