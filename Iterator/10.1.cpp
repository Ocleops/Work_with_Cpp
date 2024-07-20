#include<iostream>
#include<vector>
#include<iterator>

template<typename Iterator>
Iterator minelement(Iterator beg, Iterator end)
{
    auto min = *beg;
    auto it = beg;

    for(beg; beg != end; beg++){
        if(*beg < min ){
            min = *beg;
            it = beg;
        }
    }
    return it;
}


int main()
{
    std::vector<double> v{-10.4, -5, 3, -1000, 44, 44.1, 23.99};
    const auto beg = v.cbegin();
    const auto end = v.cend();
    const auto it = minelement(beg, end);
    std::cout<<*it;

}
