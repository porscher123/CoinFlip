#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include "mycoin.h"
#include<QPushButton>
#include<QLabel>
#include<QPixmap>
#include"mypushbutton.h"
#include<QSoundEffect>
#include<QFont>
class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    PlayScene(int level_num);
    void set_base();//设置窗口基础
    void paintEvent(QPaintEvent*);//绘图事件,设置背景
    //关于胜利
    bool is_win();//判断当前局面是否胜利
    void set_all_coins_win();//设置所有金币的属性为1
    void set_all_coins_unwin();//设置所有金币的属性为0
    void show_win_label(QLabel*);//展示胜利图片
    void reset_win_label();
    //关于菜单栏
    void set_menubar();
    void add_start_menu();
    void add_quit_action();
    void connect_quit_btn();
    //关于设置音效
    void set_back_sound();//返回按钮的音效
    void set_win_sound();//胜利音效
    void set_flip_sound();//金币翻转音效






    void set_back_btn();//设置返回按钮
    void connet_back_btn_clicked();//连接返回按钮点击

    void reset_time_label();
    void set_time_label();//设置计数器标签
    void set_level_label();//设置关卡标签
    void set_win_label();//设置胜利图片的基础

    void load_data();//载入布局数据



    void set_coins_background();//设置金币背景
    void add_coins();//在背景上添加金币
    void connet_coins_clicked();//连接每个金币的点击信号
    void reset();//重置金币布局



    //计时器
    QTimer* timer=nullptr;
    double time_limit=10;
    QLabel* time_label=nullptr;
    QLabel* clock_label=nullptr;
    QPixmap* clock_pixmap=new QPixmap(":/resource/clock.png");
    //关于菜单栏
    QMenuBar* menu_bar=nullptr;//菜单栏
    QMenu* menu_start=nullptr;//开始菜单
    QAction* action_quit=nullptr;//退出菜单项

    //关于图片
    QLabel* win_label=nullptr;//胜利时出现的图片
    QLabel* coin_background=nullptr;//进步的衬底
    QLabel* level_label=nullptr;//显示关卡号的标签,在游戏场景底部
    QFont *font=nullptr;
     //关于准备音效
    QSoundEffect* back_sound=nullptr;//返回按钮的音效
    QSoundEffect* coin_fliping_sound=nullptr;//金币翻转音效
    QSoundEffect* win_sound=nullptr;//胜利音效
     //关于金币布局
    MyCoin* coins[4][4];//保存每个关卡的金币
    int coin_layout [4][4];//记录01布局
    const int init_width=97;
    const int init_height=230;
    MyPushButton* btn_back=nullptr;//返回按钮
    int level_num;//记录所选关卡
    bool is_open=false;//该关卡是否开方
signals:
    void back_signal();//返回信号
    void win_signal();//胜利信号
};

#endif // PLAYSCENE_H
