#ifndef LIFE_H
#define LIFE_H
#include <iostream>
#include <QMainWindow>
#include <QVector>
#include <QDebug>

using std::string;

class Life {
public:
    //life();
    string countrys[3]={"mengde","liyue","daoqi"};
    void set_name(string n) { name = n; }
    string get_name() { return name; }

    void set_name_pinyin(string n) { name_pinyin = n; }
    string get_name_pinyin() { return name_pinyin; }

    void set_star(int l) { star = l; }
    int get_star() { return star; }

    void set_sex(int s) { sex = s; }
    int get_sex() { return sex; }

    void set_country(int h) { country = h; }
    int get_country() { return country; }

    void set_profession(int a) { profession = a; }
    int get_profession() { return profession; }

    void set_country_pinyin(int c) { country_pinyin=countrys[c];}
    string get_coutry_pinyin() { return country_pinyin;}

    void display() {qDebug()<<QString::fromStdString(name)<<QString::fromStdString(name_pinyin)<<star<<sex<<country<<profession<<endl;}

private:
    string name;
    string name_pinyin;
    int star;
    int sex;
    int country;
    string country_pinyin;
    int profession;
};


#endif // LIFE_H
