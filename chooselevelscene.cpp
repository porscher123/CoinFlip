#include "chooselevelscene.h"
#include<QPixmap>
#include<QMenuBar>
#include<QMenu>
#include<QPainter>
#include"mypushbutton.h"
#include<QTimer>
#include<QLabel>
#include"playscene.h"
#include<QSoundEffect>
ChooseLevelScene::ChooseLevelScene(QWidget *parent)
    : QMainWindow{parent}
{
    //配置选择关卡场景
    this->set_base();
    this->set_menubar();//设置菜单栏
    this->add_start_menu();//给菜单栏添加菜单
    this->add_quit_action();//给菜单添加菜单项
    this->connect_quit_action();//点击退出菜单项,实现退出
    //音效准备
    this->set_level_sound();//准备点击关卡按钮的音效
    this->set_back_sound();//准备返回按钮音效
    //返回按钮
    this->set_back_btn();//设置返回按钮
    this->connect_back_btn_clicked();//连接返回按钮的点击信号
    //每个关卡
    this->create_play_scenes();//创建每个游戏场景
    this->create_level_btns();//创建每个关卡按钮
    this->connect_level_btns_clicked();//连接每个关卡按钮的点击事件
    this->monitor_back_signal();//监听每个游戏场景的返回信号
    this->monitor_win_signal();//监听每个游戏场景的胜利信号
}
//
void ChooseLevelScene::connect_quit_action()
{
    connect(action_quit,&QAction::triggered,this,[=](){
        this->close();
    });
}
//添加菜单项
void ChooseLevelScene::add_quit_action()
{
    this->action_quit=this->menu_start->addAction("退出");//创建菜单项
}
//添加菜单
void ChooseLevelScene::add_start_menu()
{
    this->menu_start=this->menu_bar->addMenu("开始");
}
//设置菜单栏
void ChooseLevelScene::set_menubar()
{
    this->menu_bar=this->menuBar();//创建菜单栏
    this->setMenuBar(this->menu_bar);//将菜单栏设置到选择关卡界面
}
//连接关卡按钮的点击事件
void ChooseLevelScene::connect_level_btns_clicked()
{
    for(int i=0;i<20;i++)
    {
        connect(this->btn_level[i],&MyPushButton::clicked,this,[=](){//连接每个按钮
            if(this->playscenes[i]->is_open)
            {
                qDebug()<<QString("点击的是第%1关").arg(i+1);
                //连接每个按钮的点击事件与音效
                level_sound->play();
                //进入游戏场景
                this->hide();//隐藏关卡场景
                this->playscenes[i]->setGeometry(this->geometry());//设置游戏场景的矩形框为选择关卡的矩形框
                this->playscenes[i]->show();//显示游戏场景
            }
        });
    }
}
//监听胜利信号
void ChooseLevelScene::monitor_win_signal()
{
    for(int i=0;i<20;i++)
    {
        //监听游戏场景的胜利信号
        connect(this->playscenes[i],&PlayScene::win_signal,this,[=](){
            this->playscenes[i+1]->is_open=1;//如果发出胜利信号,修改下一关的可进入性
            delete this->seals[i+1];
        });
    }
}
//监听返回信号
void ChooseLevelScene::monitor_back_signal()
{
    for(int i=0;i<20;i++)
    {
        //监听游戏场景的返回信
        connect(this->playscenes[i],&PlayScene::back_signal,this,[=](){
            this->setGeometry(playscenes[i]->geometry());//设置选择关卡的矩形框为游戏场景的矩形框位置
            this->playscenes[i]->hide();//隐藏该关卡
            this->show();//显示选择关卡场景
        });
    }
}
//创建每个关卡按钮
void ChooseLevelScene::create_level_btns()//创建每个关卡按钮
{
    for(int i=0;i<20;i++)
    {
        //初始化关卡按钮属性(坐标,图标,封锁,数字)

        this->btn_level[i]=new MyPushButton(":/resource/LevelIcon.png");
        this->btn_level[i]->setParent(this);
        //初始横轴坐标
        int x=60;
        int y=150;
        //每次增加的量
        x+=70*(i%4);//横向间距70
        y+=65*(i/4);//纵向间距65
        this->btn_level[i]->move(x,y);
        // 通过label给按钮上添加数字
        this->set_level_num(i);//给第i个关卡设置关卡号
        this->set_level_sealed(i);//设置第i个关卡为封锁
    }
}
//创建每个游戏场景
void ChooseLevelScene::create_play_scenes()
{
    for(int i=0;i<20;i++)
    {

        this->playscenes[i]=new PlayScene(i+1);//创建每个游戏场景
        this->playscenes[i]->is_open=0;
        this->playscenes[0]->is_open=1;
    }
}
//设置点击关卡的音效
void ChooseLevelScene::set_level_sound()
{
     this->level_sound =new QSoundEffect;
     this->level_sound->setSource(QUrl::fromLocalFile(":/resource/TapButtonSound.wav"));
}
//设置点击返回按钮的音效
void ChooseLevelScene::set_back_sound()
{
    this->back_sound=new QSoundEffect;
    this->back_sound->setSource(QUrl("qrc:/resource/BackButtonSound.wav"));
}
//设置选择关卡场景的基本设置
void ChooseLevelScene::set_base()
{
    this->setFixedSize(400,650);
    this->setWindowIcon(QPixmap(":/resource/Coin0001.png"));
    this->setWindowTitle("选择关卡场景");
}
//给主场景发送返回信号
void ChooseLevelScene::connect_back_btn_clicked()
{
    connect(btn_back,&QPushButton::clicked,this,[=](){
        back_sound->play();//播放返回按钮音效
        qDebug()<<"点击了返回按钮";
        QTimer::singleShot(400,this,[=](){
           emit this->back();//给主场景发送返回信号
        });
    });
}
//添加返回按钮
void ChooseLevelScene::set_back_btn()
{
    this->btn_back=new MyPushButton(":/resource/BackButton.png",":/resource/BackButtonSelected.png");//创建按钮,加载两种情况的图片
    this->btn_back->setParent(this);//添加到当前窗口
    this->btn_back->move(this->width()-this->btn_back->width(),this->height()-this->btn_back->height());//设置在右下角
}
//重写绘图事件,添加背景
void ChooseLevelScene::paintEvent(QPaintEvent*)
{
    //设置背景
    QPainter p(this);//指定画家的绘图设备为此窗口
    QPixmap pixmap(":/resource/OtherSceneBg.png");//创建pixmap对象,加载图片
    //从(0,0)宽为画窗宽,高为窗口高的pixmap
    p.drawPixmap(0,0,this->width(),this->height(),pixmap);

    //画一个背景上的图标
    pixmap.load(":/resource/Title.png");
    p.drawPixmap(0.5*(this->width()-pixmap.width()),0.05*(this->height()-pixmap.height()),pixmap.width(),pixmap.height(),pixmap);
}
//给每个关卡设置关卡号
void ChooseLevelScene::set_level_num(int i)
{
    int x=60;
    int y=150;
    //每次增加的量
    x+=70*(i%4);//横向间距70
    y+=65*(i/4);//纵向间距65
    QLabel* label=new QLabel;
    label->setParent(this);
    label->setFixedSize(this->btn_level[i]->width(),this->btn_level[i]->height());//大小设置为与按钮一样大
    label->setText(QString::number(i+1));//给便签加上序号
    label->move(x,y);//移动到按钮所在位置,左上对齐,按钮本质大小也是一个矩形框
    label->setAlignment(Qt::AlignCenter);//让标签上的数字居中,即在按钮中心
    label->setAttribute(Qt::WA_TransparentForMouseEvents);//设置让鼠标进行穿透
}
//设置此关卡为封锁
void ChooseLevelScene::set_level_sealed(int i)
{
    int x=60;
    int y=150;
    //每次增加的量
    x+=70*(i%4);//横向间距70
    y+=65*(i/4);//纵向间距65
    QPixmap pixmap(":/resource/elien.png");

    this->seals[i]=new QLabel;
    this->seals[i]->setFixedSize(this->btn_level[i]->width(),this->btn_level[i]->height());
    this->seals[i]->move(x,y);
    this->seals[i]->setParent(this);
    if(playscenes[i]->is_open)
    {
        this->seals[i]->setAttribute(Qt::WA_TransparentForMouseEvents);
    }
    else
    {
        this->seals[i]->setPixmap(pixmap);
    }
}
