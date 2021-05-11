/********************************************************************************
** Form generated from reading UI file 'widget2048.ui'
**
** Created: Fri May 7 10:29:34 2021
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET2048_H
#define UI_WIDGET2048_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget2048
{
public:
    QWidget *view;
    QLabel *label_title;
    QLabel *label_score;
    QLabel *label_best;
    QLabel *lab_score;
    QLabel *lab_best;
    QPushButton *new_game_btn;

    void setupUi(QWidget *Widget2048)
    {
        if (Widget2048->objectName().isEmpty())
            Widget2048->setObjectName(QString::fromUtf8("Widget2048"));
        Widget2048->resize(480, 630);
        Widget2048->setMinimumSize(QSize(480, 630));
        Widget2048->setMaximumSize(QSize(480, 630));
        Widget2048->setStyleSheet(QString::fromUtf8("background-color: rgb(250, 248, 239);"));
        view = new QWidget(Widget2048);
        view->setObjectName(QString::fromUtf8("view"));
        view->setGeometry(QRect(15, 165, 450, 450));
        view->setStyleSheet(QString::fromUtf8("background-color: rgb(187, 173, 160);\n"
"border-radius:5px;\n"
"\n"
"\n"
""));
        label_title = new QLabel(Widget2048);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        label_title->setGeometry(QRect(15, 15, 150, 60));
        QFont font;
        font.setPointSize(48);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        label_title->setFont(font);
        label_title->setStyleSheet(QString::fromUtf8("color: rgb(118, 111, 101);"));
        label_title->setAlignment(Qt::AlignCenter);
        label_score = new QLabel(Widget2048);
        label_score->setObjectName(QString::fromUtf8("label_score"));
        label_score->setGeometry(QRect(300, 20, 80, 30));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label_score->setFont(font1);
        label_score->setStyleSheet(QString::fromUtf8("background-color: rgb(187, 173, 160);\n"
"color: rgb(235, 232, 209);\n"
"border-top-left-radius:5px;\n"
"border-top-right-radius:5px;"));
        label_score->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        label_best = new QLabel(Widget2048);
        label_best->setObjectName(QString::fromUtf8("label_best"));
        label_best->setGeometry(QRect(385, 20, 80, 30));
        label_best->setFont(font1);
        label_best->setStyleSheet(QString::fromUtf8("background-color: rgb(187, 173, 160);\n"
"color: rgb(235, 232, 209);\n"
"border-top-left-radius:5px;\n"
"border-top-right-radius:5px;"));
        label_best->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        lab_score = new QLabel(Widget2048);
        lab_score->setObjectName(QString::fromUtf8("lab_score"));
        lab_score->setGeometry(QRect(300, 50, 80, 30));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        lab_score->setFont(font2);
        lab_score->setStyleSheet(QString::fromUtf8("background-color: rgb(187, 173, 160);\n"
"color: rgb(255, 255, 255);\n"
"border-bottom-left-radius:5px;\n"
"border-bottom-right-radius:5px;"));
        lab_score->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        lab_best = new QLabel(Widget2048);
        lab_best->setObjectName(QString::fromUtf8("lab_best"));
        lab_best->setGeometry(QRect(385, 50, 80, 30));
        lab_best->setFont(font2);
        lab_best->setStyleSheet(QString::fromUtf8("background-color: rgb(187, 173, 160);\n"
"color: rgb(255, 255, 255);\n"
"border-bottom-left-radius:5px;\n"
"border-bottom-right-radius:5px;"));
        lab_best->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        new_game_btn = new QPushButton(Widget2048);
        new_game_btn->setObjectName(QString::fromUtf8("new_game_btn"));
        new_game_btn->setGeometry(QRect(345, 105, 120, 40));
        new_game_btn->setFont(font1);
        new_game_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(144, 122, 99);\n"
"color: rgb(255, 255, 255);\n"
"border-radius:5px;"));

        retranslateUi(Widget2048);

        QMetaObject::connectSlotsByName(Widget2048);
    } // setupUi

    void retranslateUi(QWidget *Widget2048)
    {
        Widget2048->setWindowTitle(QApplication::translate("Widget2048", "Widget2048", 0, QApplication::UnicodeUTF8));
        label_title->setText(QApplication::translate("Widget2048", "2048", 0, QApplication::UnicodeUTF8));
        label_score->setText(QApplication::translate("Widget2048", "SCORE", 0, QApplication::UnicodeUTF8));
        label_best->setText(QApplication::translate("Widget2048", "BEST", 0, QApplication::UnicodeUTF8));
        lab_score->setText(QApplication::translate("Widget2048", "0", 0, QApplication::UnicodeUTF8));
        lab_best->setText(QApplication::translate("Widget2048", "0", 0, QApplication::UnicodeUTF8));
        new_game_btn->setText(QApplication::translate("Widget2048", "New Game", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget2048: public Ui_Widget2048 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET2048_H
