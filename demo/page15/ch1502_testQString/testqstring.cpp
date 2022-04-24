#include "testqstring.h"
#include <QTest>
TestQString::TestQString(QObject *parent) : QObject(parent)
{

}
void TestQString::testToLower()
{
    QFETCH(QString,string);
    QFETCH(QString,result);

    QCOMPARE(string.toLower(),result);
    QVERIFY2(true,"exec failure!");
}
void TestQString::testToLower_data()
{
    QTest::addColumn<QString>("string");
    QTest::addColumn<QString>("result");

    QTest::newRow("lower")<<"hello"<<"hello";
    QTest::newRow("mixed")<<"heLLo"<<"hello";
    QTest::newRow("upper")<<"HELLO"<<"hello";
}

void TestQString::testBenchmark()
{
    QString str("heLLo");
    QBENCHMARK
    {
        str.toLower();
    }
    QVERIFY2(true,"exec failure");
}
