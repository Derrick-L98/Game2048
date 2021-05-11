#ifndef WIDGET2048_H
#define WIDGET2048_H

#include <QWidget>
#include <QKeyEvent>
#include "label.h"

namespace Ui {
class Widget2048;
}

class Widget2048 : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget2048(QWidget *parent = 0);
    ~Widget2048();

    // 加载数字
    void load_arr(void);

    // 保存数字
    void save_arr(void);

    // 加载最高分
    void load_best(void);

    // 保存最高分
    void save_best(void);

    // 计算空位置数量
    int count_null(void);

    // 随机生成一个整数
    void rand_num(void);

    // 把数字同步到标签数组
    void arr_sync_labs(void);

    // 键盘按下事件
    void keyReleaseEvent(QKeyEvent *event);

    // 窗口关闭事件
    void closeEvent(QCloseEvent *event);

    void up(void);
    void down(void);
    void left(void);
    void right(void);
    void check(void);
    
private slots:
    void on_new_game_btn_clicked();

private:
    Ui::Widget2048 *ui;
    Label* labs[4][4];
    int arr[4][4];
    int score;
    int best;
    bool is_move_merge;
};

#endif // WIDGET2048_H
