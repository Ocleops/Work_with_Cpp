#include <iostream>
#include "Date.h"


Date::Date()
{}

Date::Date(int a, int b, int c)
:day(a),
month(b),
year(c)
{
    number_of_days = get_n_days(year, month);
}

void Date::print()
{
    std::cout<<day<<" "<<month<<" "<<year<<"\n";//<<" "<<number_of_days<<"\n";
}

Date Date::operator+(Date other_ob)
{
    Date sumed_ob;
    sumed_ob.day = day + other_ob.day;
    sumed_ob.month = month + other_ob.month;
    sumed_ob.year = year + other_ob.year;

    return sumed_ob;
}

bool Date::operator>(Date other_ob)
{
    if(year < other_ob.year){
        return false;
    }
    else if(year > other_ob.year)
    {
        return true;
    }
    else if(year == other_ob.year && month < other_ob.month)
    {
        return false;
    }
    else if(year == other_ob.year && month > other_ob.month){
        return true;
    }
    else if(year == other_ob.year && month == other_ob.month && day < other_ob.day){
        return false;
    }
    else if(year == other_ob.year && month == other_ob.month && day > other_ob.day){
        return true;
    }

}

bool Date::operator==(Date other_ob)
{
    if(day == other_ob.day && month == other_ob.month && year == other_ob.year){
        return true;
    }
    else{
        return false;
    }
}


Date Date::operator-(Date other_ob)
{
    Date dif_ob;

    dif_ob.year = year - other_ob.year;
    //std::cout<<dif_ob.year<<"\n";

    if(month < other_ob.month){
        dif_ob.month = month + 12 - other_ob.month;
        dif_ob.year -= 1;
    }
    else{
        dif_ob.month = month - other_ob.month;
    }

    if(day < other_ob.day){
        dif_ob.day = day + other_ob.number_of_days - other_ob.day;
        dif_ob.month -= 1;
    }
    else{
        dif_ob.day = day - other_ob.day;
    }


    return dif_ob;

}



int Date::get_n_days(int y, int m)
{
    int n;
    switch(m){
    case(1):
        n=31;
        break;
    case(2):
        if(y>1923){
            if(y%4==0 && y%100 !=0){
                n=29;
            }
            else if(y%100==0 && y%400==0){
                n=29;
            }
            else{
                n=28;
            }
        }
        else if(y<1923){
            if(y%4==0){
                n=29;
            }
            else{
                n=28;
            }
        }
        else{
            n=15;
        }
        break;
    case(3):
        n=31;
        break;
    case(4):
        n=30;
        break;
    case(5):
        n=31;
        break;
    case(6):
        n=30;
        break;
    case(7):
        n=31;
        break;
    case(8):
        n=31;
        break;
    case(9):
        n=30;
        break;
    case(10):
        n=31;
        break;
    case(11):
        n=30;
        break;
    case(12):
        n=31;
        break;
        }

        return n;
}


Date::~Date()
{}
