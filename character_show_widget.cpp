#include "character_show_widget.h"
#include <QPushButton>
#include <QLabel>
#include "life.h"

using std::string;

//星级？
QString sex[2] = {"男","女"};
QString country[4] = {"蒙德","璃月","稻妻","至冬"};
QString profession[5] = {"单手剑","双手剑","长柄武器","弓箭","法器"};

Character_Show_Widget::Character_Show_Widget(QWidget *parent) : QMainWindow(parent){
}

Character_Show_Widget::Character_Show_Widget(QWidget *parent,Character_single* character): QMainWindow(parent){
//---------配置窗口---------
    this->setFixedSize(570,900);

    this->setWindowIcon(QPixmap(":/Resource/guoba.png"));
    string path_background = ":/Resource/" + character->get_coutry_pinyin()+".png";

   //---------显示背景---------
    this->setWindowTitle(QString::fromStdString(character->get_name()));

    setAutoFillBackground(true);
    QPixmap pixmap(QString::fromStdString(path_background));
    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    setPalette(palette);
    resize(pixmap.size());

    QPushButton* Back_To_Main = new QPushButton("返回",this);
    Back_To_Main->move(this->width()-Back_To_Main->width(),this->height()-Back_To_Main->height());

    connect(Back_To_Main,&QPushButton::clicked,[=](){
        emit this->characterSceneBack();
    });

//----------------展示头像----------------
    QLabel* Face = new QLabel(this);
    Face->resize(256,256);
    string path = ":/Resource/" + character->get_name_pinyin() + ".png";
    Face->setPixmap(QPixmap(QString::fromStdString(path)));
    Face->setGeometry(0,0,256,256);

//----------------展示姓名----------------
    QLabel* Name = new QLabel("姓名："+QString::fromStdString(character->get_name()),this);
    Name->setGeometry(256,0,570-256,64);
    Name->setFont(QFont("Microsoft YaHei",20,50));
    Name->setAlignment(Qt::AlignCenter);

    QPalette pal ;
    pal.setColor(QPalette::Background, QColor(0x00,0xff,0x00,0x00));
    Name->setPalette(pal);

//----------------展示性别----------------
    QLabel* Sex = new QLabel("性别："+sex[character->get_sex()],this);
    Sex->setGeometry(256,64,570-256,64*2);
    Sex->setFont(QFont("Microsoft YaHei",20,50));
    Sex->setAlignment(Qt::AlignCenter);

    Sex->setPalette(pal);

//----------------展示国家----------------
    QLabel* Country = new QLabel("所属国家："+country[character->get_country()],this);
    Country->setGeometry(256,64*2,570-256,64*3);
    Country->setFont(QFont("Microsoft YaHei",20,50));
    Country->setAlignment(Qt::AlignCenter);
    Country->setPalette(pal);

//----------------展示武器----------------
    QLabel* Profession = new QLabel("使用武器："+profession[character->get_profession()],this);
    Profession->setGeometry(256,64*3,570-256,64*4);
    Profession->setFont(QFont("Microsoft YaHei",20,50));
    Profession->setAlignment(Qt::AlignCenter);
    Profession->setPalette(pal);

}

//Character_Show_Widget::~Character_Show_Widget(){
//    delete this;
//}
