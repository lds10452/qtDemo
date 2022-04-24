#include "testArea.h"
#include <QtTest>
void TestArea::toAreaTest()
{
    Area area(1);
    QVERIFY(qAbs(area.countArea()-3.14)<0.0000001);
    QVERIFY2(true,"exec failure!");
}

void TestArea::toArea()
{
    QFETCH(Area,area);
    QFETCH(double,result);
    QVERIFY(qAbs(area.countArea()-result)<0.0000001);
    QVERIFY2(true,"exec failure!");
}

void TestArea::toArea_data()
{
    QTest::addColumn<Area>("area");
    QTest::addColumn<double>("result");

    QTest::newRow("1")<<Area(1)<<3.14;
    QTest::newRow("2")<<Area(2)<<12.56;
    QTest::newRow("3")<<Area(3)<<28.26;
}
