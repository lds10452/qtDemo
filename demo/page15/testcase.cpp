#include "testcase.h"
#include <QtTest>
#include "ch1501_AreaTest/testArea.h"
#include "ch1502_testQString/testqstring.h"
TestCase::TestCase()
{

}
void TestCase::addTest(QObject *test)
{
    testCaseList.push_back(test);
}
void TestCase::addTest()
{
    QObject* test=NULL;
    test=new TestArea;
    testCaseList.push_back(test);
    test=new TestQString;
    testCaseList.push_back(test);
}
void TestCase::runTest()
{
    foreach(QObject *test,testCaseList)
    {
        QTest::qExec(test);
    }
}
