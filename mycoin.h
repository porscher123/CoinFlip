#ifndef MYCOIN_H
#define MYCOIN_H

#include<QPushButton>
#include<QString>
#include<QTimer>
class MyCoin : public QPushButton
{
    Q_OBJECT
    enum Towards{Down,Up};
public:
        MyCoin(QString btn_img);//参数代表传入的是金币路径还是银币
        //
        int pos_x;
        int pos_y;
        int toward;

        QTimer* timer_for_down;
        QTimer* timer_for_up;
        int min=1;
        int max=8;
        bool fliping=false;
        bool is_win=false;
        //正在翻转和已经胜利时进行鼠标拦截
        void change_toward();
        void mousePressEvent(QMouseEvent*);
        void set_base(QString btn_img);
        void connect_timer();
signals:

};

#endif // MYCOIN_H
