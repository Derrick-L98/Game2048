#include "widget2048.h"
#include "ui_widget2048.h"
#include <QMessageBox>
#include <fstream>
using namespace std;

Widget2048::Widget2048(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget2048)
{
    ui->setupUi(this);
    for(int row=0; row<4; row++)
    {
        for(int col=0; col<4; col++)
        {
            labs[row][col] = new Label(ui->view);
            labs[row][col]->move(col*110+10,row*110+10);
        }
    }

    // 加载最高分
    load_best();

    // 从文件加载数据
    load_arr();

    // 随机产生一个整数
    rand_num();

    arr_sync_labs();
}

Widget2048::~Widget2048()
{
    save_best();
    delete ui;
}

void Widget2048::on_new_game_btn_clicked()
{
    score = 0;
    memset(arr,0,sizeof(arr));
    is_move_merge = true;
    rand_num();
    arr_sync_labs();
}

// 计算空位置数量
int Widget2048::count_null(void)
{
    int null = 0;
    for(int x=0; x<4; x++)
    {
        for(int y=0; y<4; y++)
        {
            if(0 == arr[x][y])
            {
                null++;
            }
        }
    }
    return null;
}

// 随机生成一个整数
void Widget2048::rand_num(void)
{
    if(!is_move_merge || 0 == count_null())
    {
        return;
    }

    while(true)
    {
        int x = rand() % 4;
        int y = rand() % 4;
        if(0 == arr[x][y])
        {
            arr[x][y] = 2;
            return;
        }
    }
}

// 把数字同步到标签数组
void Widget2048::arr_sync_labs(void)
{
    for(int row=0; row<4; row++)
    {
        for(int col=0; col<4; col++)
        {
            labs[row][col]->setNum(arr[row][col]);
        }
    }

    QString str;
    str.setNum(score);
    ui->lab_score->setText(str);

    if(score > best)
    {
        best = score;
        str.setNum(best);
        ui->lab_best->setText(str);
    }
}

// 加载数字
void Widget2048::load_arr(void)
{
    ifstream ifs(".arr.dat");
    if(ifs.is_open())
    {
        ifs.read((char*)arr,sizeof(arr));
        ifs.read((char*)&score,sizeof(score));
        is_move_merge = false;
        remove(".arr.dat");
    }
    else
    {
        // 加载文件失败
        memset(arr,0,sizeof(arr));
        is_move_merge = true;
        score = 0;
    }
    ifs.close();
}

// 保存数字
void Widget2048::save_arr(void)
{
    ofstream ofs(".arr.dat");
    ofs.write((char*)arr,sizeof(arr));
    ofs.write((char*)&score,sizeof(score));
    ofs.close();
}

// 加载最高分
void Widget2048::load_best(void)
{
    ifstream ifs(".best.dat");
    if(ifs.is_open())
        ifs.read((char*)&best,sizeof(best));
    else
        best = 0;
    ifs.close();

    QString str;
    str.setNum(best);
    ui->lab_best->setText(str);
}

// 保存最高分
void Widget2048::save_best(void)
{
    ofstream ofs(".best.dat");
    ofs.write((char*)&best,sizeof(best));
    ofs.close();
}

// 键盘弹起事件
void Widget2048::keyReleaseEvent(QKeyEvent *event)
{
    is_move_merge = false;

    switch(event->key())
    {
    case Qt::Key_Up: up(); break;
    case Qt::Key_Down: down(); break;
    case Qt::Key_Left: left(); break;
    case Qt::Key_Right: right(); break;
    }

    rand_num();
    arr_sync_labs();
    check();
}

void Widget2048::closeEvent(QCloseEvent *event)
{
    QMessageBox msgBox(this);
    msgBox.setText("游戏还未结束，是否存档？");
    msgBox.setStandardButtons(QMessageBox::No|QMessageBox::Yes);
    msgBox.setDefaultButton(QMessageBox::Yes);
    if(QMessageBox::Yes == msgBox.exec())
    {
        save_arr();
    }
}

void Widget2048::up(void)
{
    for(int y=0; y<4; y++)
    {
        int end = 0;
        for(int x=1; x<4; x++)
        {
            for(int i=x; i>0 && end<i; i--)
            {
                if(arr[i][y] == arr[i-1][y] && arr[i][y])
                {
                    end = i;
                    arr[i-1][y] *= 2;
                    arr[i][y] = 0;
                    is_move_merge = true;
                    score += arr[i-1][y];
                }
                else if(arr[i][y] && !arr[i-1][y])
                {
                    arr[i-1][y] = arr[i][y];
                    arr[i][y] = 0;
                    is_move_merge = true;
                }
            }
        }
    }
}

void Widget2048::down(void)
{
    for(int y=0; y<4; y++)
    {
        int end = 3;
        for(int x=2; x>=0; x--)
        {
            for(int i=x; i<4 && end>i; i++)
            {
                if(arr[i][y] == arr[i+1][y] && arr[i][y])
                {
                    end = i;
                    arr[i+1][y] *= 2;
                    arr[i][y] = 0;
                    is_move_merge = true;
                    score += arr[i+1][y];
                }
                else if(arr[i][y] && !arr[i+1][y])
                {
                    arr[i+1][y] = arr[i][y];
                    arr[i][y] = 0;
                    is_move_merge = true;
                }
            }
        }
    }
}

void Widget2048::left(void)
{
    for(int x=0; x<4; x++)
    {
        int end = 0;
        for(int y=1; y<4; y++)
        {
            for(int i=y; i>=0 && end<i; i--)
            {
                if(arr[x][i] == arr[x][i-1] && arr[x][i])
                {
                    end = i;
                    arr[x][i-1] *= 2;
                    arr[x][i] = 0;
                    is_move_merge = true;
                    score += arr[x][i-1];
                }
                else if(arr[x][i] && !arr[x][i-1])
                {
                    arr[x][i-1] = arr[x][i];
                    arr[x][i] = 0;
                    is_move_merge = true;
                }
            }
        }
    }
}

void Widget2048::right(void)
{
    for(int x=0; x<4; x++)
    {
        int end = 3;
        for(int y=2; y>=0; y--)
        {
            for(int i=y; i<4 && end>i; i++)
            {
                if(arr[x][i] == arr[x][i+1] && arr[x][i])
                {
                    arr[x][i+1] *= 2;
                    arr[x][i] = 0;
                    end = i;
                    is_move_merge = true;
                    score += arr[x][i+1];
                }
                else if(arr[x][i] && !arr[x][i+1])
                {
                    arr[x][i+1] = arr[x][i];
                    arr[x][i] = 0;
                    is_move_merge = true;
                }
            }
        }
    }
}

void Widget2048::check(void)
{
    if(0 < count_null())
        return;

    for(int x=0; x<4; x++)
    {
        for(int y=0; y<3; y++)
        {
            if(arr[x][y] == arr[x][y+1])
                return;
        }
    }

    for(int y=0; y<4; y++)
    {
        for(int x=0; x<3; x++)
        {
            if(arr[x][y] == arr[x+1][y])
                return;
        }
    }

    QMessageBox msgBox(this);
    msgBox.setText("游戏已经结束，是否再来一把？");
    msgBox.setStandardButtons(QMessageBox::No|QMessageBox::Yes);
    msgBox.setDefaultButton(QMessageBox::Yes);
    if(QMessageBox::Yes == msgBox.exec())
    {
        on_new_game_btn_clicked();
    }
    else
    {
        save_best();
        exit(0);
    }
}
