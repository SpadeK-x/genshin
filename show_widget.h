#ifndef SHOW_WIDGET_H
#define SHOW_WIDGET_H

#include <QWidget>

namespace Ui {
class show_widget;
}

class show_widget : public QWidget
{
    Q_OBJECT

public:
    explicit show_widget(QWidget *parent = nullptr);
    explicit show_widget(QPixmap);
    void setPixmap(std::string path);
    static QString myextract(std::string source);
    //void hide();
    ~show_widget();

signals:
    void changeScene(QString path,int idx);

private:
    Ui::show_widget *ui;
};

#endif // SHOW_WIDGET_H
