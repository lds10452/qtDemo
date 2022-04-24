#ifndef TESTQSTRING_H
#define TESTQSTRING_H

#include <QObject>

class TestQString : public QObject
{
    Q_OBJECT
public:
    explicit TestQString(QObject *parent = nullptr);
private Q_SLOTS:
    void testToLower();
    void testToLower_data();

    void testBenchmark();
signals:

};

#endif // TESTQSTRING_H
