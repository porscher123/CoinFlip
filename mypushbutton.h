#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H
#include <QWidget>
#include <QPushButton>
class MyPushButton : public QPushButton
{
    Q_OBJECT
    enum Direction{Down,Up};
    enum Back{Normal,Pressed};
public:
                //常规图片需要传进,默认无按压图片
    MyPushButton(QString normalImg,QString pressImg="");//重写构造函数
    void zoom_down();
    void zoom_up();
    void zoom(int );
    void transfer(Back);
    //保存用户传入的默认显示路径和按下后显示的图片路径
     //鼠标事件
     void mousePressEvent(QMouseEvent* ev);
     void mouseReleaseEvent(QMouseEvent*ev);
     //设置基础内容
     void set_base(QString btn_img);
     QString normalImgPath;
     QString pressImgPath;
     bool is_open=false;
signals:

};

#endif // MYPUSHBUTTON_H
