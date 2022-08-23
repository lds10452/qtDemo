#include "upgradebutton.h"
UpgradeButton::UpgradeButton(QWidget *p):QPushButton(p)
{
    QString style="QPushButton:hover{background-color:blue;}"
                  "QPushButton:pressed{background-color:red;}"
                  ;
    setStyleSheet(style);
}
