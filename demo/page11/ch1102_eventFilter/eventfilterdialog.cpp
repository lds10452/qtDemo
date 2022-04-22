#include "eventfilterdialog.h"
#include <QPixmap>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QEvent>
#include <QMouseEvent>
eventFilterDialog::eventFilterDialog()
{
    pix1=new QPixmap(":/res/headPic/11.png");
    label1=new QLabel;
    label1->setAlignment(Qt::AlignCenter);
    label1->setPixmap(*pix1);

    pix2=new QPixmap(":/res/headPic/12.png");
    label2=new QLabel;
    label2->setAlignment(Qt::AlignCenter);
    label2->setPixmap(*pix2);

    pix3=new QPixmap(":/res/headPic/22.png");
    label3=new QLabel;
    label3->setAlignment(Qt::AlignCenter);
    label3->setPixmap(*pix3);

    showLabel=new QLabel("mouse press");
    showLabel->setAlignment(Qt::AlignHCenter);
    QHBoxLayout *layout=new QHBoxLayout;
    layout->addWidget(label1);
    layout->addWidget(label2);
    layout->addWidget(label3);
    QVBoxLayout *mainLayout=new QVBoxLayout(this);
    mainLayout->addLayout(layout);
    mainLayout->addWidget(showLabel);
    label1->installEventFilter(this);
    label2->installEventFilter(this);
    label3->installEventFilter(this);
    label1->removeEventFilter(this);
}

bool eventFilterDialog::eventFilter(QObject *watched, QEvent *event)
{
    if(watched==label1)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
            QMouseEvent *mouseEvent=(QMouseEvent *)event;
            if(mouseEvent->buttons()&Qt::LeftButton)
            {
                showLabel->setText(tr("左键按下左边图片"));
            }
            else if(mouseEvent->buttons()&Qt::MidButton)
            {
                showLabel->setText(tr("中键按下左边图片"));
            }
            else if(mouseEvent->buttons()&Qt::RightButton)
            {
                showLabel->setText(tr("右键按下左边图片"));
            }
            QMatrix matrix;
            matrix.scale(1.8,1.8);
            QPixmap curPix=pix1->transformed(matrix);
            label1->setPixmap(curPix);
        }
        if(event->type()==QEvent::MouseButtonRelease)
        {
            showLabel->setText(tr("鼠标释放左边图片"));
            label1->setPixmap(*pix1);
        }
    }
    else if(watched==label2)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
            //将事件event转化为鼠标事件
            QMouseEvent *mouseEvent=(QMouseEvent *)event;
            /* 以下根据鼠标的按键类型分别显示 */
            if(mouseEvent->buttons()&Qt::LeftButton)
            {
                showLabel->setText(tr("左键按下中间图片"));
            }
            else if(mouseEvent->buttons()&Qt::MidButton)
            {
                showLabel->setText(tr("中键按下中间图片"));
            }
            else if(mouseEvent->buttons()&Qt::RightButton)
            {
                showLabel->setText(tr("右键按下中间图片"));
            }
            /* 显示缩小的图片 */
            QMatrix matrix;
            matrix.scale(1.8,1.8);
            QPixmap curPix=pix2->transformed(matrix);
            label2->setPixmap(curPix);
        }
        /* 鼠标释放事件的处理，恢复图片的大小 */
        if(event->type()==QEvent::MouseButtonRelease)
        {
            showLabel->setText(tr("鼠标释放中间图片"));
            label2->setPixmap(*pix2);
        }
    }
    else if(watched==label3)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
            //将事件event转化为鼠标事件
            QMouseEvent *mouseEvent=(QMouseEvent *)event;
            /* 以下根据鼠标的按键类型分别显示 */
            if(mouseEvent->buttons()&Qt::LeftButton)
            {
                showLabel->setText(tr("左键按下右边图片"));
            }
            else if(mouseEvent->buttons()&Qt::MidButton)
            {
                showLabel->setText(tr("中键按下右边图片"));
            }
            else if(mouseEvent->buttons()&Qt::RightButton)
            {
                showLabel->setText(tr("右键按下右边图片"));
            }
            /* 显示缩小的图片 */
            QMatrix matrix;
            matrix.scale(1.8,1.8);
            QPixmap curPix=pix3->transformed(matrix);
            label3->setPixmap(curPix);
        }
        /* 鼠标释放事件的处理，恢复图片的大小 */
        if(event->type()==QEvent::MouseButtonRelease)
        {
            showLabel->setText(tr("鼠标释放右边图片"));
            label3->setPixmap(*pix3);
        }
    }
    //将事件交给上层对话框
    return QDialog::eventFilter(watched,event);
}
