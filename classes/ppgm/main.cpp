#include <iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include "ppgm.h"

int main()
{
    std::string name;
    name = "casablanca.pgm";
    ppgm image1(name);
    ppgm image2{image1};
    image2.write("test.pgm");
}
