#include <iostream>
#include <iterator>
#include <vector>
#include <forward_list>

template<typename Iterator>
bool is_sorted(Iterator beg, Iterator end)
{
    auto it = beg;
    beg++;
    for(beg; beg != end; beg++){
        if(*beg < *it){
            return false;
        }
        else{
            it++;
        }
    }
    return true;
}

int main ()
{
    std::forward_list<double> v{0,1,2,3,4,5};

    auto beg = v.begin();
    auto end = v.end();

    auto b = is_sorted(beg, end);

    std::cout<<"\n";
    std::cout<<std::boolalpha<<b;
}
