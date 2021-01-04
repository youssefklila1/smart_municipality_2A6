/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLineEdit *utilisateur;
    QLineEdit *motdepasse;
    QPushButton *connection;
    QLabel *label;
    QWidget *page_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QLabel *label_3;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(732, 465);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 100, 731, 361));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        utilisateur = new QLineEdit(page);
        utilisateur->setObjectName(QStringLiteral("utilisateur"));
        utilisateur->setGeometry(QRect(522, 89, 141, 51));
        utilisateur->setStyleSheet(QLatin1String("  width: 200%;\n"
"\n"
"  margin: 10px 0;\n"
"\n"
"  border-radius: 10px;"));
        motdepasse = new QLineEdit(page);
        motdepasse->setObjectName(QStringLiteral("motdepasse"));
        motdepasse->setGeometry(QRect(522, 129, 141, 51));
        motdepasse->setStyleSheet(QLatin1String("  width: 200%;\n"
"\n"
"  margin: 10px 0;\n"
"\n"
"  border-radius: 10px;"));
        connection = new QPushButton(page);
        connection->setObjectName(QStringLiteral("connection"));
        connection->setGeometry(QRect(610, 200, 91, 31));
        connection->setStyleSheet(QLatin1String("  background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);"));
        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 731, 321));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/img/Untitled-2.jpg")));
        stackedWidget->addWidget(page);
        label->raise();
        utilisateur->raise();
        motdepasse->raise();
        connection->raise();
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        pushButton_3 = new QPushButton(page_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(490, 10, 191, 31));
        pushButton_3->setStyleSheet(QLatin1String("border: 1px solid black;\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"background: #318aff;\n"
"font: bold, \"Arial\";;\n"
"text-align:center;"));
        pushButton_4 = new QPushButton(page_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(490, 50, 191, 31));
        pushButton_4->setStyleSheet(QLatin1String("border: 1px solid black;\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"background: #318aff;\n"
"font: bold, \"Arial\";;\n"
"text-align:center;"));
        pushButton_5 = new QPushButton(page_2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(490, 90, 191, 31));
        pushButton_5->setStyleSheet(QLatin1String("border: 1px solid black;\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"background: #318aff;\n"
"font: bold, \"Arial\";;\n"
"text-align:center;"));
        pushButton_6 = new QPushButton(page_2);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(490, 130, 191, 31));
        pushButton_6->setStyleSheet(QLatin1String("border: 1px solid black;\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"background: #318aff;\n"
"font: bold, \"Arial\";;\n"
"text-align:center;"));
        pushButton_7 = new QPushButton(page_2);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(490, 170, 191, 31));
        pushButton_7->setStyleSheet(QLatin1String("border: 1px solid black;\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"background: #318aff;\n"
"font: bold, \"Arial\";;\n"
"text-align:center;"));
        pushButton_8 = new QPushButton(page_2);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(490, 210, 191, 31));
        pushButton_8->setStyleSheet(QLatin1String("border: 1px solid black;\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"background: #318aff;\n"
"font: bold, \"Arial\";;\n"
"text-align:center;"));
        label_3 = new QLabel(page_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 0, 731, 331));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/images/img/Untitled-2.jpg")));
        stackedWidget->addWidget(page_2);
        label_3->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        pushButton_5->raise();
        pushButton_6->raise();
        pushButton_7->raise();
        pushButton_8->raise();
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 0, 741, 101));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/images/img/Untitled-3.jpg")));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 732, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        connection->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        label->setText(QString());
        pushButton_3->setText(QApplication::translate("MainWindow", "Employ\303\251es", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "Dons", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "Chantiers", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "Fournisseurs", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("MainWindow", "Mat\303\251riaux", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("MainWindow", "Evenement", Q_NULLPTR));
        label_3->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
