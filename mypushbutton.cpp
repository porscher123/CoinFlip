#include "mypushbutton.h"
#include<QDebug>
#include<QPropertyAnimation>
//声名中有默认参数,实现不写默认参数
MyPushButton::MyPushButton(QString normalImg,QString pressImg)
{
    this->normalImgPath=normalImg;
    this->pressImgPath=pressImg;
    this->set_base(normalImg);
}
void MyPushButton::set_base(QString normalImg)
{
    QPixmap pix;
    bool ret=pix.load(normalImg);
    if(!ret)//如果没加载成功
    {
        qDebug()<<"图片加载失败";
        return;
    }
    //设置图片固定大小
    this->setFixedSize(pix.width(),pix.height());
    //设置不规则图片样式
    this->setStyleSheet("QPushButton{border:0px;}");//呈现按钮本来形状
    //设置图标
    this->setIcon(pix);
    //设置图标大小
    this->setIconSize(QSize(pix.width(),pix.height()));
}
//传入参数判断是向上还是向下
void MyPushButton::zoom(int d)
{
    QPropertyAnimation* animation=new QPropertyAnimation(this,"geometry");//用按钮初始化对象c
    animation->setDuration(200);
    if(d==MyPushButton::Up)
    {
        //起始位置
        animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
        //结束位置
        animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    }
    else
    {
        //起始位置
        animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
        //结束位置
        animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    }
    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    animation->start();
}
//改变按钮图片状态
void MyPushButton::transfer(Back back)
{
    if(back==MyPushButton::Normal)
    {
        QPixmap pix;
        bool ret=pix.load(this->normalImgPath);
        if(!ret)//如果没加载成功
        {
            qDebug()<<"图片加载失败";
            return;
        }
        //设置图片固定大小
        this->setFixedSize(pix.width(),pix.height());
        //设置不规则图片样式
        this->setStyleSheet("QPushButton{border:0px;}");//呈现按钮本来形状
        //设置图标
        this->setIcon(pix);
        //设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    if(back==MyPushButton::Pressed)
    {
        QPixmap pix;
        bool ret=pix.load(this->pressImgPath);
        if(!ret)//如果没加载成功
        {
            qDebug()<<"图片加载失败";
            return;
        }
        //设置图片固定大小
        this->setFixedSize(pix.width(),pix.height());
        //设置不规则图片样式
        this->setStyleSheet("QPushButton{border:0px;}");//呈现按钮本来形状
        //设置图标
        this->setIcon(pix);
        //设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
}
//针对开始按钮与返回按钮
//不同特定
//过滤开始按钮
//重写鼠标按下事件
void MyPushButton::mousePressEvent(QMouseEvent*ev )
{
    //拦截
    if(this->pressImgPath!="")//传入的按下图片不为空
    {
         this->transfer(this->Pressed);
    }
    //让父类执行其它内容
    return QPushButton::mousePressEvent(ev);

}
//重写鼠标释放事件
void MyPushButton::mouseReleaseEvent(QMouseEvent*ev)
{
    if(this->pressImgPath!="")
    {
         this->transfer(this->Normal);
    }
    return QPushButton::mouseReleaseEvent(ev);

}
