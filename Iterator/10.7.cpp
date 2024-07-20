#include <iostream>
#include <forward_list>
#include <iterator>

template<typename Iterator>
void copied(Iterator beg1, Iterator end1, Iterator beg2)
{
    for(beg1; beg1 != end1; beg1++){
        *beg2 = *beg1;
        beg2++;
    }
}


int main()
{
    std::forward_list<double> v1{2,5,1,6,8,4.4};
    std::forward_list<double> v2{4,9,4,7,10,0,1,2.5,2.6,2,5,3};

    auto beg1 = v1.begin();
    auto end1 = v1.end();

    auto beg2 = v2.begin();
    auto end2 = v2.end();


    copied(beg1,end1,beg2);
    beg2 = v2.begin();

    for(beg2; beg2 != end2; beg2++){
        std::cout<<*beg2<<" ";
    }

}
