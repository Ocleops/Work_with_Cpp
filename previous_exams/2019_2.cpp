#include <iostream>
#include <forward_list>
#include <iterator>
#include <vector>

template<typename Iterator>
Iterator f(Iterator first, Iterator mid, Iterator last)
{
    auto itr = first;
    auto start1 = first;
    auto start2 = mid;
    std::vector<int> v1;
    std::vector<int> v2;

    for(start2; start2 != last; ++start2){
        v1.push_back(*start2);
    }

    for(start1; start1 != mid; ++start1){
        v2.push_back(*start1);
    }

    for(auto i=0; i<v1.size(); i++){
        *first = v1[i];
        first++;
    }

    itr = first;
    for(auto i=0; i<v2.size(); i++){
        *first = v2[i];
        first++;
    }

    return itr;


}

int main ()
{
    std::forward_list<int> l1{1,2,3,4,5,6,7,8};
    int move_first=1, move_last = 6, move_mid = move_last/2;
    auto first = l1.begin();
    std::advance(first,move_first);
    auto last = l1.begin();
    std::advance(last, move_last);
    auto mid = first;
    std::advance(mid,move_mid);

    auto itr = f(first, mid, last);
    auto beg = l1.begin();
    auto end = l1.end();
    for(beg; beg != end; ++beg){
        std::cout<<*beg;
    }


}
