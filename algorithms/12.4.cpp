#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<iterator>

int main()
{
    std::ifstream inputA("fileA.txt");
    std::vector<int> v1;
    int i;
    while(inputA >> i){
        v1.push_back(i);
    }

    std::ifstream inputB("fileB.txt");
    std::vector<int>v2;
    while(inputB >> i){
        v2.push_back(i);
    }

    int v3_size=0;
    if(v1.size() > v2.size()){
        v3_size = v1.size();
    }
    else{
        v3_size = v2.size();
    }
    std::vector<int>v3(v3_size);

    auto beg1 = v1.begin();
    auto end1 = v1.end();
    auto beg2 = v2.begin();
    auto end2 = v2.end();
    auto beg3 = v3.begin();
    auto end3 = v3.end();

    std::sort(beg1,end1);
    std::sort(beg2,end2);

    beg3 = std::set_difference(beg1,end1,beg2,end2,beg3);
    beg3 = std::set_difference(beg2,end2,beg1,end1,beg3);
    v3.erase(beg3,end3);

    std::ofstream output("uncommon.txt");
    std::ostream_iterator<int> fbeg{output, "\n"};
    beg3 = v3.begin();
    std::copy(beg3, end3, fbeg);
}
