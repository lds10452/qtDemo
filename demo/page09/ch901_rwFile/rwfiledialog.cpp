#include "rwfiledialog.h"
#include <QPushButton>
#include <QGridLayout>
#include <QFile>
#include <QDebug>
#include <QDate>
RwFileDialog::RwFileDialog()
{
    QPushButton *readTextBtn=new QPushButton(tr("read text file"));
    connect(readTextBtn,SIGNAL(clicked()),this,SLOT(readText()));
    QPushButton *writeTextBtn=new QPushButton(tr("write text file"));
    connect(writeTextBtn,SIGNAL(clicked()),this,SLOT(writeText()));
    QPushButton *readBinBtn=new QPushButton(tr("read bin file"));
    connect(readBinBtn,SIGNAL(clicked()),this,SLOT(readBinary()));
    QPushButton *writeBinBtn=new QPushButton(tr("write bin file"));
    connect(writeBinBtn,SIGNAL(clicked()),this,SLOT(writeBinary()));
    QGridLayout *main=new QGridLayout(this);
    main->addWidget(readTextBtn,0,0);
    main->addWidget(writeTextBtn,0,1);
    main->addWidget(readBinBtn,1,0);
    main->addWidget(writeBinBtn,1,1);
}

void RwFileDialog::readText()
{
    QFile file("../demo/res/text/data.txt");
    if(file.open(QIODevice::ReadOnly))
    {
        char buffer[2048];
        qint64 lineLen=file.readLine(buffer,sizeof (buffer));
        if(lineLen!=-1)
        {
            qDebug()<<buffer;
        }
        file.close();
    }
}

void RwFileDialog::writeText()
{
    QFile file("../demo/res/text/data.txt");
    if(file.open(QFile::WriteOnly|QFile::Truncate))
    {
        QTextStream out(&file);
        out<<QObject::tr("score:")<<qSetFieldWidth(10)<<left<<100<<endl;
    }
    file.close();
    qDebug()<<"write text finish";
}

void RwFileDialog::readBinary()
{
    QFile file;
    file.setFileName("../demo/res/text/binary.bat");
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"error!";
        return;
    }
    QDataStream in(&file);
    QString name;
    QDate birthday;
    qint32 age;
    in>>name>>birthday>>age;
    qDebug()<<name<<birthday<<age;
    file.close();
}

void RwFileDialog::writeBinary()
{
    QFile file("../demo/res/text/binary.bat");
    if(file.open(QIODevice::WriteOnly|QIODevice::Truncate))
    {
        QDataStream out(&file);
        out<<QString("zhang san:");
        out<<QDate::fromString("1996/01/23","yyyy/MM/dd");
        out<<(qint32)21;
        qDebug()<<"write binary finish!";
    }
    file.close();
}
