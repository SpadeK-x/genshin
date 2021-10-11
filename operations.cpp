#include "operations.h"
#include "ui_operations.h"

QString name;

operations::operations(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::operations)
{
    ui->setupUi(this);

    connect(ui->pushButton,&QPushButton::clicked,[=](){
        name = ui->label->text();
        emit characterSceneBack();
    });
}

QString operations::getname(){
    return name;
}

operations::~operations()
{
    delete ui;
}
