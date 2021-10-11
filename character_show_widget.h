#ifndef CHARACTER_SHOW_WIDGET_H
#define CHARACTER_SHOW_WIDGET_H

#include <QMainWindow>
#include <life.h>

class Character_Show_Widget : public QMainWindow
{
    Q_OBJECT
public:
    explicit Character_Show_Widget(QWidget *parent = nullptr);
    explicit Character_Show_Widget(QWidget *parent,Character_single* character);
    //~Character_Show_Widget();

signals:
    //返回主场景的信号
    void characterSceneBack();
};

#endif // CHARACTER_SHOW_WIDGET_H
