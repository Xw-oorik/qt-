#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->n1->setText("我的世界");
    ui->n1->setIcon(QIcon(":/111"));
    ui->n1->setIconSize(QSize(30, 30));  //QToolButton默认只显示图标，这块设置下
    ui->n1->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);//都显示
    connect(ui->n1,&QToolButton::clicked,this,[=](){
        qDebug()<<"你好世界.";
    });

    //有checked属性的按钮
    ui->n2->setCheckable(true);
    connect(ui->n2,&QToolButton::toggled,this,[=](bool bl){
        qDebug()<<"等待..."<<bl;
    });
    //关联菜单
    ui->n3->setText("选择你喜欢的城市");
    QMenu *menu=new QMenu;
    QAction*act=menu->addAction("福建");
    menu->addAction("杭州");
    menu->addAction("成都");
    menu->addAction("上海");
    ui->n3->setMenu(menu);    //QToolButton默认需要点击按住不放一会 菜单栏才会显示
    connect(act,&QAction::triggered,this,[=]{
        qDebug()<<"喜欢..."<<act;
    });

    // 设置图标和文本的显示模式 3种
    //用qaction方式去设置图标和文本信息
    QAction* ac=new QAction(QIcon(":/222"),"冲冲冲");
    ui->n4->setDefaultAction(ac);
    connect(ui->n4,&QToolButton::triggered,this,[=](){
        ac->setText("我是修改后的");
        ac->setIcon(QIcon(":/111"));
    });
    //基于自带的样式，给按钮设置箭头图标
    ui->n5->setArrowType(Qt::UpArrow);
    ui->n5->setText("向上");
    ui->n5->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);//都显示

    //关联菜单  设置成不延时的  ,有三种 ，默认是延时的
    ui->n6->setMenu(menu);
    ui->n6->setPopupMode(QToolButton::MenuButtonPopup);
    connect(ui->n6,&QToolButton::clicked, this, [=]()
    {
        qDebug() << "我是新菜单按钮...";
    });

    //设置根节点 ，分类 ，的三态属性
    ui->fenlei->setTristate(true);
    //处理根节点点击鼠标的事件
    connect(ui->fenlei, &QCheckBox::clicked, this, [=](bool bl){
       if(bl){//被选中的状态
           ui->kehuan->setChecked(true);
           ui->aiqing->setChecked(true);
           ui->xiju->setChecked(true);
       }
       else{
           ui->kehuan->setChecked(false);
           ui->aiqing->setChecked(false);
           ui->xiju->setChecked(false);
       }
    });
    //处理子节点的一个状态变化，实现槽函数
    connect(ui->kehuan,&QCheckBox::stateChanged,this,&MainWindow::statusChanged);
    connect(ui->aiqing,&QCheckBox::stateChanged,this,&MainWindow::statusChanged);
    connect(ui->xiju,&QCheckBox::stateChanged,this,&MainWindow::statusChanged);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::statusChanged(int st)
{
    if(st==Qt::Checked){
        count++;//选中了 ++
    }
    else{
        count--;
    }
    // 根据计数器值判断根节点是否需要做状态的更新
     if(count == 3)
     {
         ui->fenlei->setCheckState(Qt::Checked);
     }
     else if(count == 0)
     {
         ui->fenlei->setCheckState(Qt::Unchecked);
     }
     else
     {
         ui->fenlei->setCheckState(Qt::PartiallyChecked);
     }
}

void MainWindow::on_r1_clicked()
{
     qDebug() << "要吃饭...";
}

void MainWindow::on_r2_clicked()
{
     qDebug() << "要睡觉...";
}

void MainWindow::on_r3_clicked()
{
     qDebug() << "要打豆豆...";
}

void MainWindow::on_r4_clicked()
{
     qDebug() << "不要上班...";
}

void MainWindow::on_r5_clicked()
{
     qDebug() << "要下班...";
}

void MainWindow::on_r6_clicked()
{
     qDebug() << "卷死你...";
}
