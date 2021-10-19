#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QPainter>
#include <QFile>
#include <QDialog>
#include <QInputDialog>
#include <QVector>
#include <vector>
#include <QMessageBox>
#include <sstream>
#include <QMovie>
#include "Characters.h"
#include "Tools.h"
#include "Life.h"

using std::string;

Characters all_characters;
Characters my_characters;
QVector<show_widget*> vec_show;
QVector<show_widget*> vec_myshow;
bool allIsImport = false, mineIsImport = false;
QVector<QString> stars = {"五星","四星"};
QVector<QString> sexes = {"男","女"};
QVector<QString> countries = {"蒙德","璃月","稻妻"};
QVector<QString> professions = {"单手剑","双手剑","长柄武器","弓箭","法器"};


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//--------------导入并存储角色--------------
    QString path = "C:/Users/Hasee/Desktop/Genshin_all.txt";  //指定地址
    QFile file(path);
    file.open(QIODevice::ReadOnly);

    QString head = file.readLine();

    while(!file.atEnd()){
        string arr = file.readLine().toStdString();
        QVector <string> oneCharacter = mysplit(arr);
        all_characters.push_back(new Character_single(oneCharacter[0],oneCharacter[1],oneCharacter[2],oneCharacter[3],oneCharacter[4],oneCharacter[5]));
    }
    file.close();
    qDebug()<<all_characters.size();

//----------------导入并展示素材--------------
    vec_show = {ui->show1,ui->show2,ui->show3,ui->show4,ui->show5,ui->show6,ui->show7,ui->show8,ui->show9,ui->show10};
    vec_myshow = {ui->my1,ui->my2,ui->my3,ui->my4,ui->my5,ui->my6,ui->my7,ui->my8,ui->my9,ui->my10};
    for(auto item:vec_show) item->hide();
    for(auto item:vec_myshow) item->hide();

//-------------------窗口设置-----------------
    setWindowIcon(QIcon(":/Resource/guoba.png"));
    setWindowTitle("应急食品");


    QMovie* movie =new QMovie(":/Resource/mianyi.gif");
    movie->start();
    ui->disply->setMovie(movie);

    connect(ui->import_mine,&QAction::triggered,this,&MainWindow::importMine);
    connect(ui->actionadd,&QAction::triggered,[=](){
        QInputDialog addCharacter(this,0);
        addCharacter.resize(500,600);
        addCharacter.setLabelText("请输入角色名：");
        addCharacter.setOkButtonText("确认");
        addCharacter.setCancelButtonText("取消");
        addCharacter.exec();
        QString name = addCharacter.textValue();
        if(name!=""){
            int t = all_characters.findOne(name);
            int isHave = my_characters.findOne(name);
            if(t==-1){
                QMessageBox::warning(this,"错误","无此角色");
                return;
            }
            if(isHave!=-1){
                QMessageBox::warning(this,"错误","已经拥有");
                return;
            }
            my_characters.push_back(new Character_single(all_characters[t]));
        }

    });
    connect(ui->actiondelete,&QAction::triggered,[=](){
        QInputDialog deleteCharacter(this,0);
        deleteCharacter.resize(500,600);
        deleteCharacter.setLabelText("请输入角色名：");
        deleteCharacter.setOkButtonText("确认");
        deleteCharacter.setCancelButtonText("取消");
        deleteCharacter.exec();
        QString name = deleteCharacter.textValue();
        qDebug()<<name;
        if(name!=""){
            int notHave = all_characters.findOne(name); //(name);
            int t = my_characters.findOne(name);
            if(t==-1){
                QMessageBox::warning(this,"错误","未拥有");
                return;
            }
            if(notHave==-1){
                QMessageBox::warning(this,"错误","无此角色");
                return;
            }
            my_characters.deleteone(name);
        }

    });

//    connect(ui->actionabout,&QMenuBar::triggered,[=](){

//    });

//-------------stack_widget 换页-------------------

    ui->Main_Widget->setCurrentIndex(0);
    for(int i=0;i<all_characters.size();i++){
        connect(vec_show[i], &show_widget::changeScene,this,&MainWindow::showInLabel);
    }


    connect(ui->search,&QPushButton::clicked,[=](){
        QString content = ui->searchtext->text();
        int t=-1;
        t=all_characters.findOne(content);
        if(t==-1){
            QMessageBox::warning(this,"错误","无此角色");
            return;
        }
        ui->preshow->show();
        QString s = QString::fromStdString(all_characters[t]->get_name_pinyin());
        ui->label->setPixmap(":/Resource/" + s + "2.jpg");
        qDebug()<<QString::fromStdString(all_characters[t]->get_name_pinyin());

        connect(ui->pushButton,&QPushButton::clicked,[=](){
            showInLabel(s,0);
            character_Scene = new Character_Show_Widget(this,all_characters[t]);
            //进入到选择人物展示场景中,自身隐藏
            this->hide();
            character_Scene->show();

            //监听人物界面的返回信号
            connect(character_Scene,&Character_Show_Widget::characterSceneBack,[&](){
                this->show();
                character_Scene->~Character_Show_Widget();
            });
    });
});

    connect(ui->home_page,&QPushButton::clicked,[=](){
        ui->Main_Widget->setCurrentIndex(0);
    });

    connect(ui->all_characters,&QPushButton::clicked,[=](){
        ui->Main_Widget->setCurrentIndex(1);
        if(ui->comboBox->currentIndex()==0) {
            all_characters.sortByStar();
            QString path = "排列顺序：";
            for(auto it:stars) path+=it+" ";
            ui->path_all->setText(path);
            QFont font("Microsoft YaHei", 20, 75);
            ui->path_all->setFont(font);
        }
        else if(ui->comboBox->currentIndex()==1) {
            all_characters.sortBySex();
            QString path = "排列顺序：";
            for(auto it:sexes) path+=it+" ";
            ui->path_all->setText(path);
            QFont font("Microsoft YaHei", 20, 75);
            ui->path_all->setFont(font);
        }
        else if(ui->comboBox->currentIndex()==2) {
            all_characters.sortByCountry();
            QString path = "排列顺序：";
            for(auto it:countries) path+=it+" ";
            ui->path_all->setText(path);
            QFont font("Microsoft YaHei", 20, 75);
            ui->path_all->setFont(font);
        }
        else if(ui->comboBox->currentIndex()==3) {
            all_characters.sortByProfession();
            QString path = "排列顺序：";
            for(auto it:professions) path+=it+" ";
            ui->path_all->setText(path);
            QFont font("Microsoft YaHei", 20, 75);
            ui->path_all->setFont(font);
        }

        all_characters.disply(vec_show);
    });

    connect(ui->character_query,&QPushButton::clicked,[=](){
        ui->Main_Widget->setCurrentIndex(2);
        ui->searchtext->setText("");
        ui->preshow->hide();
    });

    connect(ui->mine,&QPushButton::clicked,[=](){
        ui->Main_Widget->setCurrentIndex(3);
        for(auto item:vec_myshow) item->hide();
        if(!mineIsImport){
            QMessageBox::warning (this,"未导入","您未导入所拥有的角色\n请导入后再次进入此页面");
        }
        //-----------场景切换-------------
        qDebug()<<my_characters.size();

        if(ui->comboBox_my->currentIndex()==0) {
            my_characters.sortByStar();
            QString path = "排列顺序：";
            for(auto it:stars) path+=it+" ";
            ui->path_my->setText(path);
            QFont font("Microsoft YaHei", 20, 75);
            ui->path_my->setFont(font);
        }
        else if(ui->comboBox_my->currentIndex()==1) {
            my_characters.sortBySex();
            QString path = "排列顺序：";
            for(auto it:sexes) path+=it+" ";
            ui->path_my->setText(path);
            QFont font("Microsoft YaHei", 20, 75);
            ui->path_my->setFont(font);
        }
        else if(ui->comboBox_my->currentIndex()==2) {
            my_characters.sortByCountry();
            QString path = "排列顺序：";
            for(auto it:countries) path+=it+" ";
            ui->path_my->setText(path);
            QFont font("Microsoft YaHei", 20, 75);
            ui->path_my->setFont(font);
        }
        else if(ui->comboBox_my->currentIndex()==3) {
            my_characters.sortByProfession();
            QString path = "排列顺序：";
            for(auto it:professions) path+=it+" ";
            ui->path_my->setText(path);
            QFont font("Microsoft YaHei", 20, 75);
            ui->path_my->setFont(font);
        }

        my_characters.disply(vec_myshow);

        for(int i=0;i<my_characters.size();i++)
            connect(vec_myshow[i], &show_widget::changeScene,this,&MainWindow::showInLabel);

    });

}

void MainWindow::showInLabel(QString s,int idx){//0拼音 1汉字
    int t=-1;
    if(idx==0)
        t=all_characters.findOne(s.toStdString());
    else
        t=all_characters.findOne(s);
    if(t==-1){
        QMessageBox::warning(this,"错误","无此角色");
        return;
    }
    Character_single* one = all_characters[t];
    character_Scene = new Character_Show_Widget(this,one);
    //进入到选择人物展示场景中,自身隐藏
    this->hide();
    character_Scene->show();

    //监听人物界面的返回信号
    connect(character_Scene,&Character_Show_Widget::characterSceneBack,this,[=](){
       character_Scene->~Character_Show_Widget(); //hide();
       this->show();
    });
    one->~Character_single();
}

void MainWindow::paintEvent(QPaintEvent *){
     QPainter painter(this);
     QPixmap pix;
     pix.load(":/Resource/wanye.jpg");

     painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

void MainWindow::importMine(){
    if(mineIsImport){
        QMessageBox::critical(this,"错误","您已经导入成功");
        return;
    }

    QString path = QFileDialog::getOpenFileName(this,"选择文件","C:/Users/Hasee/Desktop","(*.txt)");
    if(path=="") return;
    QFile file(path);
    file.open(QIODevice::ReadOnly);

    QString head = file.readLine();
    if(head!="mycharacters:\r\n"){
        QMessageBox::critical(this,"错误","错误的文件");
        return;
    }

    if(head=="mycharacters:\r\n" && !mineIsImport){
        while(!file.atEnd()){
            string arr = file.readLine().toStdString();
            QVector <string> oneCharacter = mysplit(arr);
            my_characters.push_back(new Character_single(oneCharacter[0],oneCharacter[1],oneCharacter[2],oneCharacter[3],oneCharacter[4],oneCharacter[5]));
        }
        qDebug()<<my_characters.size();

        QMessageBox::information(this,"导入成功","您已导入成功");
        mineIsImport = true;

    }
    file.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

