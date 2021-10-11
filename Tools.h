#ifndef TOOLS_H
#define TOOLS_H
#include <string>
#include <sstream>
#include <QVector>
#include "life.h"

using std::string;

//依据空格分割
QVector <string> mysplit(string arr){
    QVector<string> ret;
    std::stringstream ss;
    ss << arr;
    //依据空格分割

    string temp;
    while(ss>>temp)
        if(temp!="\0" && temp!="\r" && temp!="\n"){
            ret.push_back(temp);
        }
    return ret;
}


void swap(Character_single*& lhs,Character_single*& rhs){
    Character_single* temp = lhs;
    lhs = rhs;
    rhs = temp;
}

#endif // TOOLS_H
