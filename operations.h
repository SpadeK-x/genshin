#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <QWidget>

namespace Ui {
class operations;
}

class operations : public QWidget
{
    Q_OBJECT

public:
    explicit operations(QWidget *parent = nullptr);
    QString getname();
    ~operations();

signals:
    //返回主场景的信号
    void characterSceneBack();

private:
    Ui::operations *ui;
};

#endif // OPERATIONS_H
