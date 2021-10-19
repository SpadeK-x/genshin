#ifndef CHARACTER_SINGLE_H
#define CHARACTER_SINGLE_H

#include "Life.h"

class Character_single :public Life {
public:
    Character_single(string name, string name_pinyin, string star, string sex, string country, string profession);

    Character_single(Life& rhs);

    Character_single(Character_single*& rhs);

    Character_single* operator= (Character_single*& rhs);
    //~character();
};

Character_single::Character_single(string name, string name_pinyin, string star, string sex, string country, string profession)
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

Character_single::Character_single(Life& rhs){
    set_name(rhs.get_name());
    set_name_pinyin(rhs.get_name_pinyin());
    set_star(rhs.get_star());
    set_sex(rhs.get_sex());
    set_country(rhs.get_country());
    set_profession(rhs.get_profession());
}

Character_single::Character_single(Character_single*& rhs){
    set_name(rhs->get_name());
    set_name_pinyin(rhs->get_name_pinyin());
    set_star(rhs->get_star());
    set_sex(rhs->get_sex());
    set_country(rhs->get_country());
    set_profession(rhs->get_profession());
}

Character_single* Character_single::operator= (Character_single*& rhs){
    set_name(rhs->get_name());
    set_name_pinyin(rhs->get_name_pinyin());
    set_star(rhs->get_star());
    set_sex(rhs->get_sex());
    set_country(rhs->get_country());
    set_profession(rhs->get_profession());
}


#endif // CHARACTER_SINGLE_H
