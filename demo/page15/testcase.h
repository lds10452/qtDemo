#ifndef TESTCASE_H
#define TESTCASE_H
#include <QObject>

class TestCase
{
public:
    TestCase();
    void addTest(QObject *);
    void addTest();
    void runTest();
private:
    QList<QObject*> testCaseList;
};

#endif // TESTCASE_H
