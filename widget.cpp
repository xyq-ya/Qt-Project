#include "widget.h"
#include "ui_widget.h"
#include "splashscreen.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    // 绘制背景
    QPixmap background;
    background.load(":/images/image/back2.png");
    painter.drawPixmap(0, 0, width(), height(), background);
}

void Widget::on_pushButton_clicked()
{
    QString name = ui->lineEdit->text();
    QString pass = ui->lineEdit_2->text();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();

    //启动窗口
    splashscreen *splash_screen = new splashscreen();
    splash_screen->show();
    this->close();

    //输入账号密码登录进入游戏
    // if(db.Login(name, pass)){
    //     game *game_widget = new game();
    //     game_widget->show();
    //     this->close();
    // }
    // else{
    //     QMessageBox msg;
    //     msg.setText("账号名或密码错误");
    //     msg.exec();
    // }
}

void Widget::on_pushButton_2_clicked()
{
    exit(0);
}

void Widget::on_pushButton_3_clicked()
{
    QString name = ui->lineEdit->text();
    QString pass = ui->lineEdit_2->text();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    QMessageBox msg;
    if(db.Add(name, pass)){
        msg.setText("创建账号成功");
    }
    else{
        msg.setText("创建账号失败，账号名重复");
    }
    msg.exec();
}

void Widget::on_pushButton_4_clicked()
{
    QString name = ui->lineEdit->text();
    QString pass = ui->lineEdit_2->text();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    QMessageBox msg;
    if(db.Change(name, pass)){
        msg.setText("更改密码成功");
    }
    else{
        msg.setText("更改密码失败，不存在该账户");
    }
    msg.exec();
}

void Widget::on_pushButton_5_clicked()
{
    QString name = ui->lineEdit->text();
    ui->lineEdit->clear();
    QMessageBox msg;
    if(db.Delete(name)){
        msg.setText("注销账号成功");
    }
    else{
        msg.setText("注销账号失败，不存在该账户");
    }
    msg.exec();
}

