#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_r1_clicked();

    void on_r2_clicked();

    void on_r3_clicked();

    void on_r4_clicked();

    void on_r5_clicked();

    void on_r6_clicked();

    // 添加槽函数, 处理复选框按钮状态变化
    void statusChanged(int );

private:
    Ui::MainWindow *ui;
    int count=0;//计数器
};
#endif // MAINWINDOW_H
