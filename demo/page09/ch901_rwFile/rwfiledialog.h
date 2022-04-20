#ifndef RWFILEDIALOG_H
#define RWFILEDIALOG_H
#include <QDialog>

class RwFileDialog : public QDialog
{
    Q_OBJECT
public:
    RwFileDialog();
private slots:
    void readText();
    void writeText();
    void readBinary();
    void writeBinary();
};

#endif // RWFILEDIALOG_H
