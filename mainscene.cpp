#include "mainscene.h"
#include "ui_mainscene.h"
#include<QPainter>
#include<QPixmap>
#include"mypushbutton.h"
#include<QDebug>
#include"chooselevelscene.h"
#include<QTimer>
#include<QtMultimedia>
#include<QSoundEffect>//音效头文件
MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);
    this->set_base();//设置窗口基础
    this->connect_quit_btn();//退出按钮实现
    this->set_start_sound();//设置开始按钮的点击音效
    this->set_start_btn();//创建开始按钮
    this->choose_scene=new ChooseLevelScene;//在主场景添加选择场景
    this->monitor_chooselevelscene_back_signal();//监听ChooseLevelScene的back信号,一次连接即可
    this->connect_start_btn_clicked();//连接开始按钮的点击信号
}
//设置点击开始按钮的音效
void MainScene::set_start_sound()
{
    //准备开始按钮的音效
    this->start_sound=new QSoundEffect;
    this->start_sound->setSource(QUrl::fromLocalFile(":/resource/TapButtonSound.wav"));
}
//设置开始按钮
void MainScene::set_start_btn()
{
    this->btn_start=new MyPushButton(":/resource/MenuSceneStartButton.png");
    this->btn_start->setParent(this);
    this->btn_start->move(this->width()*0.5-btn_start->width()*0.5,this->height()*0.7);//设置到水平中心
}
//设置窗口基本要素
void MainScene::set_base()
{
    //设置固定大小
    this->setFixedSize(400,650);
    //设置图标
    this->setWindowIcon(QIcon(":/resource/Coin0001.png"));
    //设置标题
    this->setWindowTitle("翻金币");
}
//重写绘图事件
void MainScene::paintEvent(QPaintEvent*)
{
    QPainter p(this);//为画家指定画图设备为当前窗口
    //指定从窗口(0,0)点开始,画窗口大小的图
    QPixmap pixmap(":/resource/PlayLevelSceneBg.png");//创建pixmap对象,并加载图片
    p.drawPixmap(0,0,this->width(),this->height(),pixmap);

    //画一个背景上的图标
    pixmap.load(":/resource/Title.png");
    pixmap=pixmap.scaled(pixmap.width()*0.5,pixmap.height()*0.5);
    p.drawPixmap(10,30,pixmap);

}
//连接开始按钮与进入下一个场景
void MainScene::connect_start_btn_clicked()
{
    //连接开始按钮
    connect(btn_start,&QPushButton::clicked,this,[=](){
        start_sound->play();//点击按钮有音效
        //弹起特效
        btn_start->zoom(0);
        btn_start->zoom(1);
        //延时进入选择关卡场景
        QTimer::singleShot(500,this,[=](){
            qDebug()<<"点击了开始";
            //隐藏主场景,显示选择关卡的场景
            this->hide();//隐藏主窗口
            choose_scene->show();
            choose_scene->setGeometry(this->geometry());//防止窗口移动
        });

    });
}
//监听选择关卡场景的返回信号
void MainScene::monitor_chooselevelscene_back_signal()
{
    connect(choose_scene,&ChooseLevelScene::back,this,[=](){
        choose_scene->hide();
        this->setGeometry(choose_scene->geometry());//监听到选择关卡场景的自定义返回信号时,设置主场景的矩形框为选择关卡场景的矩形框
        this->show();
    });
}
//连接退出按钮
void MainScene::connect_quit_btn()
{
    connect(ui->actionquit,&QAction::triggered,this,[=](){
        this->close();
    });
}
MainScene::~MainScene()
{
    delete ui;
}
