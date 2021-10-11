#include "show_widget.h"
#include "ui_show_widget.h"
#include "mainwindow.h"
#include "life.h"
//#include "Tools.h"
//#include <QVector>

using std::string;

QString show_widget::myextract(string source){
    int cnt=0;
    string ret;
    for(int i=0;i<source.size();i++){
        if(cnt!=2){
            if(source[i]=='/') cnt++;
            continue;
        }
        if(source[i]!='2')
            ret+=source[i];
        else
            break;
    }
    return QString::fromStdString(ret);
}


show_widget::show_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::show_widget)
{
    ui->setupUi(this);
}

void show_widget::setPixmap(string path)
{
    QString s = QString::fromStdString(path);

    ui->label->setPixmap(QPixmap(s));

    connect(ui->pushButton,&QPushButton::clicked,[=](){
        QString s2 = myextract(path);
        emit this->changeScene(s2,0);
    });
}

show_widget::~show_widget()
{
    delete ui;
}
