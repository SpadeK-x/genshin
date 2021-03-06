#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "character_show_widget.h"
#include "operations.h"
#include "show_widget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //重写paintEvent事件,画背景图
    void paintEvent(QPaintEvent *);
    void importAll();
    void importMine();
    void showInLabel(QString s,int idx);


    Character_Show_Widget* character_Scene = nullptr;
    operations* op_scene = nullptr;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
