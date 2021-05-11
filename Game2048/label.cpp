#include "label.h"

Label::Label(QWidget *parent) :
    QLabel(parent)
{
    // 设置大小
    resize(100,100);

    // 设置字体
    QFont font;
    font.setPointSize(28);
    font.setBold(true);
    setFont(font);

    // 设置水平居中对齐
    setAlignment(Qt::AlignCenter);
}

void Label::setNum(int num)
{
    // 设置要显示的数字
    QString str;
    str.setNum(num);
    this->setText(str);

    // 设置背景色
    switch(num)
    {
    case 0:
        this->setText("");
        this->setStyleSheet("background-color: rgb(205,193,179);");
        break;
    case 2:
        this->setStyleSheet("color: rgb(118, 111, 101);background-color: rgb(238,228,218);");
        break;
    case 4:
        this->setStyleSheet("color: rgb(118, 111, 101);background-color: rgb(237,224,220);");
        break;
    case 8:
        this->setStyleSheet("color: rgb(255, 255, 255);background-color: rgb(242,177,121);");
        break;
    case 16:
        this->setStyleSheet("color: rgb(255, 255, 255);background-color: rgb(245,149,99);");
        break;
    case 32:
        this->setStyleSheet("color: rgb(255, 255, 255);background-color: rgb(246,124,95);");
        break;
    case 64:
        this->setStyleSheet("color: rgb(255, 255, 255);background-color: rgb(246,94,59);");
        break;
    case 128:
        this->setStyleSheet("color: rgb(255, 255, 255);background-color: rgb(237,207,114);");
        break;
    case 256:
        this->setStyleSheet("color: rgb(255, 255, 255);background-color: rgb(237,204,97);");
        break;
    case 512:
        this->setStyleSheet("color: rgb(255, 255, 255);background-color: rgb(237,200,80);");
        break;
    case 1024:
    case 2048:
    case 4096:
    case 8192:
        this->setStyleSheet("color: rgb(255, 255, 255);background-color: rgb(237,197,63);");
        break;
    }
}
