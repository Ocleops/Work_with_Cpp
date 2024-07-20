#include<iostream>
#include<iterator>
#include<algorithm>
#include<forward_list>

template<typename Iterator, typename T>
Iterator my_binary_search (Iterator beg, Iterator end, T v)
{
    auto start = beg;
    auto last = end;
    auto pos_counter = beg;

    auto mid = beg;
    int fix_mid = 0;
    fix_mid = std::distance(start,end)/2;
    start = beg;
    std::advance(mid, fix_mid);
    auto new_mid = mid;

    while(true){
        if(*mid == v){
            return mid;
        }
        else if(*mid > v){
            last = mid;
            mid = start;
            pos_counter = start;
            std::advance(mid, std::distance(pos_counter,last)/2);
        }
        else if(*mid < v){
            start = mid;
            pos_counter = start;
            std::advance(mid, std::distance(pos_counter,last)/2);
            pos_counter = start;
        }
        if(std::distance(pos_counter,last)<=1){
            return beg;
        }
        else{
            pos_counter = start;
        }
    }

}


int main ()
{
    std::forward_list <int> l{1,3,4,7,9,10};
    int v = 10;
    auto beg = l.begin();
    auto end = l.end();
    auto itr = my_binary_search(beg,end,v);

    if(itr == end){
        std::cout<<"value not found\n";
    }
    else{
        std::cout<<"value found\n";
    }
}
