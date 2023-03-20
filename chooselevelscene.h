#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H
#include <QMainWindow>
#include"playscene.h"
#include"mypushbutton.h"
#include<QSoundEffect>
#include<QMenuBar>
#include<QMenu>
#include<QAction>
class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);
    //Methods
    void paintEvent(QPaintEvent*);//绘图事件,给选择关卡窗口绘制背景
    void set_base();//选择关卡窗口基础设置
    void connect_back_btn_clicked();//发送返回信号
    //关于按钮
    void set_back_btn();//设置返回按钮
    //关于音效
    void set_back_sound();//设置点击返回按钮的音效
    void set_level_sound();//设置点击关卡按钮的音效
    //关于菜单栏
    void set_menubar();//设置菜单栏
    void add_start_menu();//给菜单栏添加菜单
    void add_quit_action();//给菜单添加菜单项
    void connect_quit_action();//点击退出菜单项,实现退出
    //关于每个
    void set_level_num(int);//设置某关卡的关卡号标签
    void set_level_sealed(int);//设置某关卡为封锁
    void create_level_btns();//创建每个关卡按钮
    void create_play_scenes();//创建每个游戏场景
    void connect_level_btns_clicked();//连接每个关卡按钮的点击事件
    void monitor_back_signal();//监听游戏场景的返回信号
    void monitor_win_signal();//监听游戏场景的胜利信号
    //Datas
    //关于按钮
    MyPushButton* btn_back=nullptr;//返回按钮
    //关于音效
    QSoundEffect* back_sound=nullptr;//点击返回按钮音效
    QSoundEffect* level_sound=nullptr;//点击关卡按钮音效
    //关于菜单栏
    QMenuBar* menu_bar=nullptr;//菜单栏
    QMenu* menu_start=nullptr;//开始菜单
    QAction* action_quit=nullptr;//退出菜单项
    //关于每个
    MyPushButton* btn_level[21];//每个关卡的按钮
    PlayScene* playscenes[21];//每个关卡的场景
    QLabel* seals[21];//每个封锁标签
signals:
    void back();//选择关卡的返回信号
};

#endif // CHOOSELEVELSCENE_H
