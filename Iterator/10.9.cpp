#include<iostream>
#include<iterator>
#include<vector>

template<typename Iterator>
bool check_double(Iterator beg, Iterator end)
{
    auto start = beg;
    auto start1 = beg;
    for(beg; beg != end; beg++){
        for(start; start != end; start++){
            if(start == beg){
                continue;
            }
            else if(*start == *beg){
                return false;
            }
        }
        start = start1;
    }
    return true;
}

int main()
{
    std::vector<double>v{1.11,1.12,1.1112,3,0,10.1,6.6,4.2};
    auto beg = v.begin();
    auto end = v.end();

    bool check = check_double(beg, end);

    std::cout<<std::boolalpha<<check;
}
