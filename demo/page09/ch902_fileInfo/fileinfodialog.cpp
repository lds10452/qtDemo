#include "fileinfodialog.h"
#include <QPushButton>
#include <QGridLayout>
#include <QApplication>
#include <QDebug>
#include <QLineEdit>
#include <QListWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QCheckBox>
#include <QFileDialog>
#include <QDateTime>
#include <QMessageBox>
#include <QFileSystemWatcher>
fileInfoDialog::fileInfoDialog()
{
    QPushButton *dirSize=new QPushButton(tr("get dir size"));
    connect(dirSize,SIGNAL(clicked()),this,SLOT(countDirSize()));
    QPushButton *show=new QPushButton(tr("show dir"));
    connect(show,SIGNAL(clicked()),this,SLOT(showDir()));
    QPushButton *fileInfo=new QPushButton(tr("get file info"));
    connect(fileInfo,SIGNAL(clicked()),this,SLOT(fileInfo()));
    QPushButton *watch=new QPushButton(tr("file watcher"));
    connect(watch,SIGNAL(clicked()),this,SLOT(fileWatcher()));
    QGridLayout *main=new QGridLayout(this);
    main->addWidget(dirSize,0,0);
    main->addWidget(show,0,1);
    main->addWidget(fileInfo,1,0);
    main->addWidget(watch,1,1);
}

void fileInfoDialog::countDirSize()
{
    QStringList args=qApp->arguments();
    QString path;
    if(args.count()>1)								//(a)
    {
        path=args[1];
    }
    else
    {
        path=QDir::currentPath();
    }
    qDebug()<<path;
    du(path);
}

void fileInfoDialog::showDir()
{
    QDialog *d=new QDialog;
    d->setModal(Qt::WindowModal);
    edit=new QLineEdit("/");
    widgt=new QListWidget;
    QVBoxLayout *layout=new QVBoxLayout(d);
    layout->addWidget(edit);
    layout->addWidget(widgt);
    connect(edit,SIGNAL(returnPressed()),this,SLOT(slotEnterShow()));
    connect(widgt,SIGNAL(itemDoubleClicked(QListWidgetItem *)),this,SLOT(slotClickShow(QListWidgetItem *)));
    QString root="/";
    QDir rootDir(root);
    slotEnterShow(rootDir);
    d->show();
}

void fileInfoDialog::fileInfo()
{
    QDialog *d=new QDialog;
    d->setModal(Qt::WindowModal);
    QLabel *fileNameLabel = new QLabel(tr("文件名："));
    fileEdit = new QLineEdit;
    QPushButton *fileBtn = new QPushButton(tr("文件"));
    QLabel *sizeLabel = new QLabel(tr("大小："));
    QLineEdit *sizeLineEdit = new QLineEdit;
    QLabel *createTimeLabel = new QLabel(tr("创建时间："));
    QLineEdit *createTimeLineEdit = new QLineEdit;
    QLabel *lastModifiedLabel = new QLabel(tr("最后修改时间："));
    QLineEdit *lastModifiedLineEdit = new QLineEdit;
    QLabel *lastReadLabel = new QLabel(tr("最后访问时间："));
    QLineEdit *lastReadLineEdit = new QLineEdit;
    QLabel *propertyLabel = new QLabel(tr("属性："));
    QCheckBox *isDirCheckBox = new QCheckBox(tr("目录"));
    QCheckBox *isFileCheckBox = new QCheckBox(tr("文件"));
    QCheckBox *isSymLinkCheckBox = new QCheckBox(tr("符号连接"));
    QCheckBox *isHiddenCheckBox = new QCheckBox(tr("隐藏"));
    QCheckBox *isReadableCheckBox = new QCheckBox(tr("读"));
    QCheckBox *isWritableCheckBox = new QCheckBox(tr("写"));
    QCheckBox *isExecutableCheckBox = new QCheckBox(tr("执行"));
    QPushButton *getBtn = new QPushButton(tr("获得文件信息"));
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(fileNameLabel,0,0);
    gridLayout->addWidget(fileEdit,0,1);
    gridLayout->addWidget(fileBtn,0,2);
    gridLayout->addWidget(sizeLabel,1,0);
    gridLayout->addWidget(sizeLineEdit,1,1,1,2);
    gridLayout->addWidget(createTimeLabel,2,0);
    gridLayout->addWidget(createTimeLineEdit,2,1,1,2);
    gridLayout->addWidget(lastModifiedLabel,3,0);
    gridLayout->addWidget(lastModifiedLineEdit,3,1,1,2);
    gridLayout->addWidget(lastReadLabel,4,0);
    gridLayout->addWidget(lastReadLineEdit,4,1,1,2);
    QHBoxLayout *layout2 = new QHBoxLayout;
    layout2->addWidget(propertyLabel);
    layout2->addStretch();
    QHBoxLayout *layout3 = new QHBoxLayout;
    layout3->addWidget(isDirCheckBox);
    layout3->addWidget(isFileCheckBox);
    layout3->addWidget(isSymLinkCheckBox);
    layout3->addWidget(isHiddenCheckBox);
    layout3->addWidget(isReadableCheckBox);
    layout3->addWidget(isWritableCheckBox);
    layout3->addWidget(isExecutableCheckBox);
    QHBoxLayout *layout4 = new QHBoxLayout;
    layout4->addWidget(getBtn);
    QVBoxLayout *mainLayout = new QVBoxLayout(d);
    mainLayout->addLayout(gridLayout);
    mainLayout->addLayout(layout2);
    mainLayout->addLayout(layout3);
    mainLayout->addLayout(layout4);
    connect(fileBtn,&QPushButton::clicked,this,[=]{
        QString fileName=QFileDialog::getOpenFileName(this,"open","/","files(*)");
        fileEdit->setText(fileName);
    });
    connect(getBtn, &QPushButton::clicked, this, [=](){
           QString file=fileEdit->text();
           QFileInfo info(file);
           qint64 size=info.size();
           QDateTime created=info.created();
           QDateTime lastModified=info.lastModified();
           QDateTime lastRead=info.lastRead();
           bool isDir = info.isDir();		//是否为目录
           bool isFile = info.isFile();	//是否为文件
           bool isSymLink = info.isSymLink();		//(a)
           bool isHidden = info.isHidden();		//判断QFileInfo对象的隐藏属性
           bool isReadable = info.isReadable();	//判断QFileInfo对象的读属性
           bool isWritable = info.isWritable();	//判断QFileInfo对象的写属性
           bool isExecutable = info.isExecutable();
           //判断QFileInfo对象的可执行属性
           /* 根据上面得到的结果更新界面显示 */
           sizeLineEdit->setText(QString::number(size));
           createTimeLineEdit->setText(created.toString());
           lastModifiedLineEdit->setText(lastModified.toString());
           lastReadLineEdit->setText(lastRead.toString());
           isDirCheckBox->setCheckState(isDir?Qt::Checked:Qt::Unchecked);
           isFileCheckBox->setCheckState(isFile?Qt::Checked:Qt::Unchecked);
           isSymLinkCheckBox->setCheckState(isSymLink?Qt::Checked:Qt:: Unchecked);
           isHiddenCheckBox->setCheckState(isHidden?Qt::Checked:Qt:: Unchecked);
           isReadableCheckBox->setCheckState(isReadable?Qt::Checked:Qt:: Unchecked);
           isWritableCheckBox->setCheckState(isWritable?Qt::Checked:Qt:: Unchecked);
           isExecutableCheckBox->setCheckState(isExecutable?Qt::Checked: Qt:: Unchecked);
    });
    d->show();
}

void fileInfoDialog::fileWatcher()
{
    QDialog *d=new QDialog;
    d->setModal(Qt::WindowModal);
    QStringList args=qApp->arguments();
    QString path;
    if(args.count()>1)
    {
        path=args[1];
    }
    else {
        path=QDir::currentPath();
    }
    QLabel *label=new QLabel;
    label->setText("监视的目录："+path);
    QVBoxLayout *main=new QVBoxLayout(d);
    main->addWidget(label);
    QFileSystemWatcher *watch=new QFileSystemWatcher(d);
    watch->addPath(path);
    connect(watch,&QFileSystemWatcher::directoryChanged,this,[=](QString str)
    {
        QMessageBox::information(d,"file watcher",str+" is changed!!!");
    });
    d->show();
}

void fileInfoDialog::slotEnterShow(QDir dir)
{
    QStringList string;
    string<<"*";
    QFileInfoList list=dir.entryInfoList(string,QDir::AllEntries,QDir::DirsFirst);
    widgt->clear();
    for (unsigned int i=0;i<list.count();i++) {
        QFileInfo curFileInfo=list.at(i);
        QString fileName=curFileInfo.fileName();
        if(curFileInfo.isDir())
        {
            QIcon icon(":res/file/dir.png");
            QListWidgetItem *item=new QListWidgetItem(icon,fileName);
            widgt->addItem(item);
        }
        else if (curFileInfo.isFile()) {
            QIcon icon(":/res/file/file.png");
            QListWidgetItem *item=new QListWidgetItem(icon,fileName);
            widgt->addItem(item);
        }
    }
}

void fileInfoDialog::slotClickShow(QListWidgetItem *item)
{
    QString str=item->text();
    QDir dir;
    dir.setPath(edit->text());
    dir.cd(str);
    edit->setText(dir.absolutePath());
    slotEnterShow(dir);
}

qint64 fileInfoDialog::du(const QString &path)
{
    QDir dir(path);
    qint64 size=0;
    foreach(QFileInfo fileInfo,dir.entryInfoList(QDir::Files))
    {
        size+=fileInfo.size();
    }
    foreach(QString subDir,dir.entryList(QDir::Dirs|QDir::NoDotAndDotDot))
    {
        size+=du(path+QDir::separator()+subDir);
    }
    char unit='B';
    qint64 curSize=size;
    if(curSize>1024)
    {
        curSize/=1024;
        unit='K';
        if(curSize>1024)
        {
            curSize/=1024;
            unit='M';
            if(curSize>1024)
            {
                curSize/=1024;
                unit='G';
            }
        }
    }
    qDebug()<<curSize<<unit<<"\t"<<qPrintable(path);
    return size;
}
