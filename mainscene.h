#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include"chooselevelscene.h"
#include<QSoundEffect>//音效头文件
#include"mypushbutton.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainScene; }
QT_END_NAMESPACE

class MainScene : public QMainWindow
{
    Q_OBJECT

public:

    //methed
    MainScene(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);//绘图事件,设置背景
    void connect_start_btn_clicked();//连接开始按钮的点击信号
    void monitor_chooselevelscene_back_signal();//监听选择关卡场景的返回信号
    void connect_quit_btn();
    //基础设置
    void set_base();//设置主窗口基础
    void set_start_sound();//设置开始按钮音效
    void set_start_btn();//设置开始按钮
    ~MainScene();


    //data
    ChooseLevelScene* choose_scene=nullptr;//主场景的一个数据成员时选择关卡场景,添加选择场景
    MyPushButton* btn_start=nullptr;//开始按钮
    QSoundEffect* start_sound=nullptr;//点击开始按钮的音效

private:
    Ui::MainScene *ui;
};
#endif // MAINSCENE_H
