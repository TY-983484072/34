#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    
    //创建连接
    connect(ui->tBtnHu,&QToolButton::clicked,this,[=]()
    {
        QMessageBox::information(this,"提示","点什么点");
    });
    
    //设置性别默认选中
    ui->rBtnMan->setChecked(true);
     
    //判断性别选择
    connect(ui->rBtnMan,&QRadioButton::clicked,this,[=]()
    {
       //QMessageBox::information(this,"提示","选择了男");
        sex=true;
    });
    connect(ui->rBtnWoMan,&QRadioButton::clicked,this,[=]()
    {
       //QMessageBox::information(this,"提示","选择了女");
        sex=false;
    });
    
    //连接性别按钮
    connect(ui->btnSex,&QPushButton::clicked,this,[=]()
    {
       if(sex)
       {
           QMessageBox::information(this,"提示","选择了男");
       }
       else
       {
           QMessageBox::information(this,"提示","选择了女");
       }
    });
    
    //默认选中未婚
    ui->rBtnWei->setChecked(true);
    //选择婚否
    connect(ui->rBtnWei,&QRadioButton::clicked,this,[=]()
    {
        this->hun = true;
    });
    connect(ui->rBtnYi,&QRadioButton::clicked,this,[=]()
    {
        this->hun = false;
    });
    
    //连接婚否按钮
    connect(ui->btnHun,&QPushButton::clicked,this,[=]()
    {
        if(this->hun)
        {
            QMessageBox::information(this,"提示","选择了未婚");
        }
        else
        {
            QMessageBox::information(this,"提示","选择了已婚");
        }
    });
    
    //选择爱好
    
    //吃饭
    connect(ui->cBoxEat,&QCheckBox::stateChanged,this,[=](int state)
    {
        this->eat = state;
//        if(this->eat == 2)
//        {
//            QMessageBox::information(this,"提示","吃饭被选中了");
//        }
//        if(this->eat == 0)
//        {
//            QMessageBox::information(this,"提示","吃饭被取消选中了");
//        }
    });
    //睡觉
    connect(ui->cBoxSleep,&QCheckBox::stateChanged,this,[=](int state)
    {
        this->sleep = state;
    });
    //玩游戏
    connect(ui->cBoxPlay,&QCheckBox::stateChanged,this,[=](int state)
    {
        this->play = state;
    });
    
    //连接选择爱好按钮
    connect(ui->btnAi,&QPushButton::clicked,this,[=]()
    {
        this->AiHao.clear();
        if(this->eat == 2)
        {
            this->AiHao += "吃饭";
        }
        if(this->sleep == 2)
        {
            this->AiHao += "睡觉";
        }
        if(this->play == 2)
        {
            this->AiHao += "玩游戏";
        }
        QMessageBox::information(this,"提示","选择了："+this->AiHao);
    });
    
    //第一种添加方式
//    QListWidgetItem * item1 = new QListWidgetItem("锄禾日当午");
//    ui->listWidget->addItem(item1);
//    //设置文本居中对齐
//    item1->setTextAlignment(Qt::AlignHCenter);
    
    //第二种添加方式
    QStringList list;
    list<<"锄禾日当午"<<"汗滴禾下土"<<"谁知盘中餐"<<"粒粒皆辛苦";
    ui->listWidget->addItems(list);
    
    //连接
    //connect()
}

Widget::~Widget()
{
    delete ui;
}
