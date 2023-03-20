#include "playscene.h"
#include<QDebug>
#include<QMenuBar>
#include<QPainter>
#include<QPixmap>
#include<QTimer>
#include<QLabel>
#include"mypushbutton.h"
#include"mycoin.h"
#include"dataconfig.h"
#include<QString>
#include<QPropertyAnimation>
#include<QSoundEffect>
int xx[]={0,1,0,-1};
int yy[]={1,0,-1,0};
PlayScene::PlayScene(int level_num)
{
    //初始化游戏场景
    this->set_base();
    this->level_num=level_num;
    qDebug()<<QString("进入了第%1关").arg(level_num);
    //关于标签
    this->set_level_label();//设置该关卡的关卡号标签
    this->set_win_label();//初始化游戏场景的胜利标签



    //关于开始菜单
    this->set_menubar();//创建菜单栏
    this->add_start_menu();//添加开始菜单
    this->add_quit_action();//创建退出菜单项
    this->connect_quit_btn();//点击退出菜单项,实现退出

    //准备音效
    this->set_flip_sound(); //准备金币翻转音效
    this->set_win_sound();//准备胜利音效
    this->set_back_sound();//准备返回按钮音效

    this->set_back_btn();//添加返回按钮
    this->connet_back_btn_clicked();//实现点击返回按钮,延时后返回关卡界面


    //创建金币背景和金币,并连接点击金币信号
    this->load_data();//加载关卡的布局数据
    this->set_coins_background();//给第i行,第j列的金币设置背景
    this->add_coins();//在第i行,第j列添加金币
    this->connet_coins_clicked();//对每个按钮进行连接
    this->set_time_label();//设置显示时间的标签
}
//重写绘图事件,给游戏场景绘制背景
void PlayScene::paintEvent(QPaintEvent*)
{
    //设置背景
    QPainter p(this);//指定画家的绘图设备为此窗口
    QPixmap pixmap(":/resource/PlayLevelSceneBg.png");//创建pixmap对象,加载图片
    //从(0,0)宽为画窗宽,高为窗口高的pixmap
    p.drawPixmap(0,0,this->width(),this->height(),pixmap);

    //画一个背景上的图标
    pixmap.load(":/resource/Title.png");
    pixmap=pixmap.scaled(0.5*pixmap.width(),0.5*pixmap.height());//赋值缩放
    p.drawPixmap(10,30,pixmap);
}
//判断是否胜利
bool PlayScene::is_win()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(this->coin_layout[i][j]!=-1)//当此处有金币才看正反面
            {
                if(this->coins[i][j]->toward==0)//遍历改关卡的所有金币,有反面则不赢
                {
                    return false;
                }
            }
        }
    }
    return true;

}
//设置所有金币的is_win为true
void PlayScene::set_all_coins_win()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(this->coin_layout[i][j]!=-1)
            {
                this->coins[i][j]->is_win=1;
            }
        }
    }
}
//设置所有金币的is_win为false
void PlayScene::set_all_coins_unwin()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(this->coin_layout[i][j]!=-1)
            {
                this->coins[i][j]->is_win=0;
            }
        }
    }
}
//胜利图片显示
void PlayScene::show_win_label(QLabel*winLabel)
{
    QPropertyAnimation* animation = new QPropertyAnimation(winLabel,"geometry");
   //设置时间间隔
   animation->setDuration(1000);
   //设置开始位置
   animation->setStartValue(QRect(winLabel->x(),winLabel->y()-winLabel->height(),winLabel->width(),winLabel->height()));
   //设置结束位置
   animation->setEndValue(QRect(winLabel->x(),winLabel->y()+winLabel->height()+80,winLabel->width(),winLabel->height()));
   //设置缓和曲线
   animation->setEasingCurve(QEasingCurve::OutBounce);
   //执行动画
   animation->start();
}
//菜单
void PlayScene::set_menubar()
{
    this->menu_bar=this->menuBar();//创建菜单栏
    this->setMenuBar(this->menu_bar);//将菜单栏设置到选择关卡界面
}
void PlayScene::add_start_menu()
{
     this->menu_start=this->menu_bar->addMenu("开始");
}
void PlayScene::add_quit_action()
{
    connect(action_quit,&QAction::triggered,this,[=](){
        this->close();
    });
}
void PlayScene::connect_quit_btn()
{
    this->action_quit=this->menu_start->addAction("退出");//创建菜单项
}
//游戏场景窗口基础设置
void PlayScene::set_base()
{
    this->setFixedSize(400,650);
    this->setWindowTitle(QString("Game Scene"));//窗口标题
    this->setWindowIcon(QPixmap(":/resource/Coin0001.png"));//图标
}
//设置返回按钮的音效
void PlayScene::set_back_sound()
{
    this->back_sound=new QSoundEffect;
    this->back_sound->setSource(QUrl("qrc:/resource/BackButtonSound.wav"));
}
//设置胜利音乐
void PlayScene::set_win_sound()
{
    this->coin_fliping_sound=new QSoundEffect;
    this->coin_fliping_sound->setSource(QUrl("qrc:/resource/ConFlipSound.wav"));
}
//设置翻动金币的音效
void PlayScene::set_flip_sound()
{
    this->win_sound=new QSoundEffect;
    this->win_sound->setSource(QUrl("qrc:/resource/LevelWinSound.wav"));
}
//添加返回按钮
void PlayScene::set_back_btn()
{
    this->btn_back=new MyPushButton(":/resource/BackButton.png",":/resource/BackButtonSelected.png");
    this->btn_back->setParent(this);//添加到游戏窗口
    this->btn_back->move(this->width()-this->btn_back->width(),this->height()-this->btn_back->height());//设置位置
}
//连接点击返回按钮的信号与......
void PlayScene::connet_back_btn_clicked()
{
    //点击返回按钮后
    connect(this->btn_back,&QPushButton::clicked,this,[=](){
        this->back_sound->play();//播放点击返回按钮的特效
        //延时做
        QTimer::singleShot(400,this,[=](){
            emit this->back_signal();//给选择关卡发送返回信号
            this->win_sound->stop();//关闭胜利的音乐
            this->reset();//重置该关卡
            this->reset_time_label();//重置计数器
            this->reset_win_label();//收回胜利标签
        });
    });
}
//设置关卡标签
void PlayScene::set_level_label()
{
    this->level_label=new QLabel;
    this->level_label->setParent(this);
    this->level_label->setText(QString("Level %1").arg(this->level_num));
    this->level_label->setAlignment(Qt::AlignCenter);//垂直水平居中
    this->level_label->setFixedSize(175,80);

    //设置字体
    this->font=new QFont;
    this->font->setFamily("华文新魏");
    this->font->setPointSize(20);
    this->level_label->setFont(*this->font);//为标签设置字体
    this->level_label->move(0,this->height()-this->level_label->height());
}
//加载该关卡的布局数据
void PlayScene::load_data()
{
    dataConfig data;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            this->coin_layout[i][j]=data.mData[this->level_num][i][j];
        }
    }
}
//设置胜利标签
void PlayScene::set_win_label()
{
    this->win_label = new QLabel;
    QPixmap tmpPix;
    tmpPix.load(":/resource/LevelCompletedDialogBg.png");
    this->win_label ->setGeometry(0,0,tmpPix.width(),tmpPix.height());
    this->win_label ->setPixmap(tmpPix);
    this->win_label ->setParent(this);
    this->win_label ->move((this->width()-tmpPix.width())*0.5,-tmpPix.height());
}
//设置计数器标签
void PlayScene::set_time_label()
{
    //设置闹钟图案
    this->clock_label=new QLabel;
    this->clock_label->setPixmap(*this->clock_pixmap);
    this->clock_label->setFixedSize(this->clock_pixmap->width(),this->clock_pixmap->height());
    this->clock_label->setParent(this);
    this->clock_label->move(200,20);
    //设置时间标签
    this->time_label=new QLabel;
    this->time_label->setParent(this);
    this->time_label->setFixedSize(this->clock_pixmap->width(),this->clock_pixmap->height());
    this->time_label->move(200,0);
    this->time_label->setAlignment(Qt::AlignCenter);
    this->time_label->setText(QString("%1s left").arg(this->time_limit));
    this->time_label->setFont(*this->font);

    this->timer=new QTimer;

    connect(this->timer,&QTimer::timeout,this,[=](){
        this->time_label->setText(QString("%1s left").arg(this->time_limit-=0.1));
        if(this->time_limit-0.1<=0)//时间到了
        {
            this->set_all_coins_win();//封锁金币

            this->time_limit=10;//重置时间
            this->timer->stop();//暂停计时
            this->clock_label->hide();//隐藏闹钟
            //居中显示时间到了
            this->font->setPointSize(50);
            this->time_label->setText(QString("time over!"));
            this->time_label->setFixedSize(400,100);
            this->time_label->setFont(*this->font);
            int cx=0.5*(this->width()-this->time_label->width());
            int cy=0.5*(this->height()-this->time_label->height());
            this->time_label->move(cx,cy);
        }
    });
}
//重置计数器
void PlayScene::reset_time_label()
{
    //恢复字号,位置,时间
    this->timer->stop();
    this->time_limit=10;
    this->clock_label->show();
    this->time_label->move(200,0);
    this->font->setPointSize(20);
    this->time_label->setFont(*this->font);
    this->time_label->setText(QString("%1s left").arg(this->time_limit));
    this->time_label->setFixedSize(this->clock_pixmap->width(),this->clock_pixmap->height());
}

//设置金币的背景衬底
void PlayScene::set_coins_background()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            this->coin_background=new QLabel;
            QPixmap pixmap(":/resource/BoardNode.png");
            //label->setGeometry(0,0,50,50);
            this->coin_background->setFixedSize(pixmap.width(),pixmap.height());
            this->coin_background->setPixmap(pixmap);
            this->coin_background->setParent(this);
            this->coin_background->move(i*50+this->init_width,j*50+this->init_height);
        }
    }

}
//在背景上加金币
void PlayScene::add_coins()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            QString coin_path;
            if(this->coin_layout[i][j]==1)//1表示创建金币
            {
                coin_path=":/resource/Coin0001.png";

            }
            else if(this->coin_layout[i][j]==0)//0表示创建银币
            {
                coin_path=":/resource/Coin0008.png";
            }
            else
            {
                continue;
            }
            this->coins[i][j]=new MyCoin(coin_path);
            this->coins[i][j]->setParent(this);
            this->coins[i][j]->move(i*50+this->init_width+2,j*50+this->init_height+2);
            //给金币属性赋值
            this->coins[i][j]->pos_x=i;
            this->coins[i][j]->pos_y=j;

            //将金币放到当前关卡的数组里,便于后期维护,内存都相同
            if(this->coin_layout[i][j]==1)//  正面
            {
                this->coins[i][j]->toward=1;

            }
            if(this->coin_layout[i][j]==0)// 反面
            {
                this->coins[i][j]->toward=0;
            }
        }
    }

}
//连接点击金币的信号
void PlayScene::connet_coins_clicked()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(this->coin_layout[i][j]!=-1)//如果此处有金币
            {
                connect(this->coins[i][j],&QPushButton::clicked,this,[=](){

                        this->timer->start(100);//点击金币开始计时
                        this->coin_fliping_sound->play();//播放翻转金币音效
                        this->set_all_coins_win();//点击瞬间禁用所有按钮

                        this->coins[i][j]->change_toward();//所点击的金币翻转
                        this->coin_layout[i][j]=this->coin_layout[i][j]^1;//相应地,取反,修改二维矩阵中地值

                        //延时翻转四周的金币
                        QTimer::singleShot(300,this,[=](){
                            for(int k=0;k<4;k++)
                            {
                                int dx=this->coins[i][j]->pos_x+xx[k];
                                int dy=this->coins[i][j]->pos_y+yy[k];
                                if(dx>=0&&dx<4&&dy>=0&&dy<4&&this->coin_layout[dx][dy]!=-1)//在范围内且存在金币
                                {
                                    this->coins[dx][dy]->change_toward();//翻转
                                    this->coin_layout[dx][dy]=this->coin_layout[dx][dy]^1;//修改金币布局数组
                                }
                            }

                            this->set_all_coins_unwin();//周围所有金币翻完,还原(解禁)

                            if(this->is_win())//如果游戏胜利
                            {
                                qDebug()<<"wins";
                                this->set_all_coins_win();//锁死按钮
                                this->show_win_label(this->win_label);//胜利图片显示
                                win_sound->play();//播放胜利音乐
                                emit win_signal();//向选择关卡按钮发送返回信号
                            }
                        });
                });
            }
        }
    }
}
//重置金币布局
void PlayScene::reset()
{
    this->load_data();
    //删除先前金币
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(this->coin_layout[i][j]!=-1)
            {
                delete this->coins[i][j];
                this->coins[i][j]=nullptr;
            }
        }
    }
    this->add_coins();//重新添加金币
    this->connet_coins_clicked();//连接每个金币
    this->set_all_coins_unwin();//解禁每个
}
//收回胜利标签
void PlayScene::reset_win_label()
{
    QPixmap tmpPix;
    tmpPix.load(":/resource/LevelCompletedDialogBg.png");
    this->win_label ->move((this->width()-tmpPix.width())*0.5,-tmpPix.height());//将胜利标志返回原处
}
