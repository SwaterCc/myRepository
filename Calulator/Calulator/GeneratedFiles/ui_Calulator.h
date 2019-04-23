/********************************************************************************
** Form generated from reading UI file 'Calulator.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALULATOR_H
#define UI_CALULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CalulatorClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CalulatorClass)
    {
        if (CalulatorClass->objectName().isEmpty())
            CalulatorClass->setObjectName(QStringLiteral("CalulatorClass"));
        CalulatorClass->resize(600, 400);
        menuBar = new QMenuBar(CalulatorClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        CalulatorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CalulatorClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CalulatorClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(CalulatorClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        CalulatorClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(CalulatorClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CalulatorClass->setStatusBar(statusBar);

        retranslateUi(CalulatorClass);

        QMetaObject::connectSlotsByName(CalulatorClass);
    } // setupUi

    void retranslateUi(QMainWindow *CalulatorClass)
    {
        CalulatorClass->setWindowTitle(QApplication::translate("CalulatorClass", "Calulator", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CalulatorClass: public Ui_CalulatorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALULATOR_H
