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

class Character_single :public Life {
public:
    Character_single(string name, string name_pinyin, string star, string sex, string country, string profession)
    {
        int star_in, sex_in, country_in, profession_in;
        star_in = stoi(star); sex_in = stoi(sex); country_in = stoi(country); profession_in = stoi(profession);
        set_name(name);
        set_name_pinyin(name_pinyin);
        set_star(star_in);
        set_sex(sex_in);
        set_country(country_in);
        set_country_pinyin(country_in);
        set_profession(profession_in);
        //qDebug()<<QString::fromStdString(name)<<QString::fromStdString(name_pinyin)<<star_in<<sex_in<<country_in<<profession_in<<endl;
    };

    Character_single(QVector<string> vec){Character_single(vec[0],vec[1],vec[2],vec[3],vec[4],vec[5]);}

    Character_single(Life& rhs){
        set_name(rhs.get_name());
        set_name_pinyin(rhs.get_name_pinyin());
        set_star(rhs.get_star());
        set_sex(rhs.get_sex());
        set_country(rhs.get_country());
        set_profession(rhs.get_profession());
    }

    Character_single(Character_single*& rhs){
        set_name(rhs->get_name());
        set_name_pinyin(rhs->get_name_pinyin());
        set_star(rhs->get_star());
        set_sex(rhs->get_sex());
        set_country(rhs->get_country());
        set_profession(rhs->get_profession());
    }


    //~character();
};

#endif // LIFE_H
