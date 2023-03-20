#include "mycoin.h"
#include<QString>
#include<QPixmap>
#include<QDebug>
MyCoin::MyCoin(QString btn_img)
{

    this->set_base(btn_img);
    //初始化定时器
    this->timer_for_down=new QTimer(this);
    this->timer_for_up=new QTimer(this);


    this->connect_timer();

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
//改变金币朝向
void MyCoin::change_toward()
{
    if(this->toward==1)//当前为正面,则正面翻成反面
    {
        //开启定时器
        this->timer_for_down->start(30);
        this->fliping=true;
        this->toward=0;
    }
    else if(this->toward==0)
    {
        this->timer_for_up->start(30);
        this->fliping=true;
        this->toward=1;
    }
}
//正在翻转和已经胜利时进行鼠标拦截
void MyCoin::mousePressEvent(QMouseEvent*ev)
{
    if(this->fliping||this->is_win)
    {
        return;
    }
    else
    {
        QPushButton::mousePressEvent(ev);
    }
}
//设置金币基础内容
void MyCoin::set_base(QString btn_img)
{
    QPixmap pixmap;
    bool ret=pixmap.load(btn_img);
    if(!ret)
    {
        qDebug()<<"图片"+btn_img+"加载失败!";
        return;
    }
    this->setFixedSize(pixmap.width(),pixmap.height());//设置固定大小
    this->setStyleSheet("QPushButton{border:0px;}");//无边框
    this->setIcon(pixmap);//设置图标
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));//设置图标大小为图的大小
}
//
void MyCoin::connect_timer()
{
    //监听正面翻反面的信号,并且翻成反面////////////////////////////////////////////////////////////////////////////
    connect(this->timer_for_down,&QTimer::timeout,this,[=](){

        QString coin_path=QString(":/resource/Coin000%1.png").arg(this->min++);
        this->set_base(coin_path);
        if(this->min>this->max)//如果翻完
        {
            this->min=1;
            this->timer_for_down->stop();
            this->fliping=false;
        }
    });
    //监听反面翻唱正面的信号,并翻唱正面
    connect(this->timer_for_up,&QTimer::timeout,this,[=](){
        QString coin_path=QString(":/resource/Coin000%1.png").arg(this->max--);
        this->set_base(coin_path);
        if(this->min>this->max)//如果翻完
        {
            this->max=8;
            this->timer_for_up->stop();
            this->fliping=false;
        }
    });
}
