#ifndef SHIXIAN_H
#define SHIXIAN_H

#include <string>
#include <QVector>
#include <algorithm>
#include <QMap>
#include "show_widget.h"
#include "Character_single.h"
#include "Tools.h"

//增删查改

using std::string;

class Characters{
public:
    int findOne(string nameinpinyin);//利用姓名拼音查找
    int findOne(QString);//利用姓名查找
    void deleteone(int idx);//删除角色
    bool deleteone(string nameinpinyin);//删除角色-拼音
    bool deleteone(QString nameinhanzi);//删除角色-汉字
    void sortByStar();
    void sortBySex();
    void sortByCountry();
    void sortByProfession();
    void push_back(Character_single* a);
    void disply(QVector<show_widget*>);
    int  size();
    Character_single*& operator[](int idx);
private:
    QVector<Character_single*> characters;

    void base_sort(int idx);//排序
};


int Characters::findOne(string nameinpinyin) {
    for (int i=0;i<characters.size();i++) {
        string n = characters[i]->get_name_pinyin();
        if (nameinpinyin == n) {
            return i;
        }
    }
    return -1;//-1代表错误
}

int Characters::findOne(QString nameinhanzi){
    for (int i=0;i<characters.size();i++) {
        QString n = QString::fromStdString(characters[i]->get_name());
        if (nameinhanzi == n) {
            return i;
        }
    }
    return -1;//-1代表错误
}

void Characters::deleteone(int idx){
    Character_single* temp = characters[idx];
    characters.erase(characters.begin()+idx);
    temp->~Character_single();
}

bool Characters::deleteone(QString nameinhanzi) {//调用析构函数
    int t= findOne(nameinhanzi);
    if(t==-1) return false;
    else{
        deleteone(t);
    }
    return true;
}

bool Characters::deleteone(string nameinpinyin) {//调用析构函数
        int t = findOne(nameinpinyin);
        if(t==-1) return false;
        else deleteone(t);
        return true;
}

void Characters::base_sort(int idx) {
    //1.按星级排序  2.按性别排序  3.按国籍排序  4.按职业排序
    int size = characters.size();
    switch(idx){
        case 1:
            for(int i=0;i<size;i++){
                for(int j=1;j<size-i;j++){
                    if(characters[j]->get_star()>characters[j-1]->get_star())
                        swap(characters[j],characters[j-1]);
                    else if(characters[j]->get_star()==characters[j-1]->get_star())
                        if(characters[j]->get_name()>characters[j-1]->get_name())
                            swap(characters[j],characters[j-1]);
                }
            }
            for(int i=0;i<size;i++){
                qDebug()<<characters[i]->get_star()<<" ";
            }
        break;

        case 2:
            for(int i=0;i<size;i++){
                for(int j=1;j<size-i;j++){
                    if(characters[j]->get_sex()<characters[j-1]->get_sex())
                        swap(characters[j],characters[j-1]);
                    else if(characters[j]->get_sex()==characters[j-1]->get_sex())
                        if(characters[j]->get_name()>characters[j-1]->get_name())
                            swap(characters[j],characters[j-1]);
                }
            }
            for(int i=0;i<size;i++){
                qDebug()<<characters[i]->get_sex()<<" ";
            }
        break;

        case 3:
        for(int i=0;i<size;i++){
            for(int j=1;j<size-i;j++){
                    if(characters[j]->get_country()<characters[j-1]->get_country())
                        swap(characters[j],characters[j-1]);
                    else if(characters[j]->get_country()==characters[j-1]->get_country())
                        if(characters[j]->get_name()>characters[j-1]->get_name())
                            swap(characters[j],characters[j-1]);
                }
            }
            for(int i=0;i<size;i++){
                qDebug()<<characters[i]->get_country()<<" ";
            }
        break;

        case 4:
        for(int i=0;i<size;i++){
            for(int j=1;j<size-i;j++){
                    if(characters[j]->get_profession()<characters[j-1]->get_profession())
                        swap(characters[j],characters[j-1]);
                    else if(characters[j]->get_profession()==characters[j-1]->get_profession())
                        if(characters[j]->get_name()>characters[j-1]->get_name())
                            swap(characters[j],characters[j-1]);
                }
            }
            for(int i=0;i<size;i++){
                qDebug()<<characters[i]->get_profession()<<" ";
            }
        break;

    }
}

void Characters::sortByStar(){
     base_sort(1);
}

void Characters::sortBySex(){
     base_sort(2);
}

void Characters::sortByCountry(){
     base_sort(3);
}

void Characters::sortByProfession(){
     base_sort(4);
}

void Characters::push_back(Character_single* a){
    characters.push_back(a);
}

void Characters::disply(QVector<show_widget*> vec){
    for(int i=0;i<characters.size();i++){
        string s = ":/Resource/" + characters[i]->get_name_pinyin() + "2.jpg";
        vec[i]->setPixmap(s);
        vec[i]->show();
    }
}

int Characters::size(){
    return characters.size();
}

Character_single*& Characters::operator[](int idx){
    return characters[idx];
}


#endif //SHIXIAN_H_

