#include<iostream>
#include<vector>
#include<fstream>
#include<iomanip>

int get_n_days(int y, int m)
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


int get_day(int d, int m, int y)
{
    if(m==1 || m==2){
        m=m+12;
        y--;
    }

    int a;
    a=13*(m+1)/5;

    int j,k;
    j=y/100;
    k=y%100;

    int b;
    b=j/4;

    int c;
    c=k/4;

    int h;
    h=a+b+c+d+k+5*j;

    int day = h%7;

    if(day>1){
        day--;
    }
    else{
        day=day+6;
    }

    return day;
}



int main()
{
    int d=1, m=11, y=2022,num_days,day;

    num_days = get_n_days(y,m);

    day = get_day(d,m,y);
    //std::cout<<d<<"\n"<<day;

    std::ofstream output("calendar.txt");

    if(m<10){
        output<<std::setw(10)<<"0"<<m<<"/"<<y<<"\n";
    }
    else{
        output<<std::setw(11)<<m<<"/"<<y<<"\n";
    }
    int space=0,c=0;
    output<<"ΔΕΥ "<<"ΤΡΙ "<<"ΤΕΤ "<<"ΠΕΜ "<<"ΠΑΡ "<<"ΣΑΒ "<<"ΚΥΡ "<<"\n";
    for(auto i=1; i<=num_days; i++){
        //std::cout<<day;
        if(day==1 && i!=0){
            //std::cout<<d<<"\n";
            output<<"\n";
            //d++;
        }

        if(i==1){
            output<<std::setw(4*(day-1)+3)<<i;
        }
        else if(day==1){
            output<<std::setw(3)<<i;
        }
        else{
            output<<std::setw(4)<<i;
        }
        day++;
        if(day%8==0){
            day = 1;
        }
    }




}
