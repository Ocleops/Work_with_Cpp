#include <iostream>
#include "Date.h"


int main()
{
    Date ob1(23,12,2023);
    Date ob2(1,1,2023);
    Date ob3;

    if(ob1 > ob2){
        ob3 = ob1 - ob2;
        //std::cout<<"1\n";
    }
    else{
        //std::cout<<"2\n";
        ob3 = ob2 - ob1;
    }

    ob3.print();



}
