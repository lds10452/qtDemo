#ifndef AREA_H
#define AREA_H
#include <QObject>

class Area : public QObject
{
    Q_OBJECT
public:
    explicit Area(QObject *parent = nullptr)
    {

    }
    Area(const Area &area)
    {
        m_r = area.m_r;
    }
    Area(int r)
    {
        m_r=r;
    }
    double countArea()
    {
        return 3.14*m_r*m_r;
    }
private:
    double m_r;
signals:

};
Q_DECLARE_METATYPE(Area)

class TestArea:public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void toAreaTest();

    void toArea();
    void toArea_data();
};

#endif // AREA_H
