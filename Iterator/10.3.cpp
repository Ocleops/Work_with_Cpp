#include <iostream>
#include <iterator>
#include <list>

template<typename Iterator>
void inverse(Iterator beg, Iterator end, int len)
{
    auto shift = 0, c=0;
    end--;
    while(c<len/2){
        //std::cout<<*beg<<"  "<<*end<<"\n";
        shift = *beg;
        *beg = *end;
        *end = shift;
        beg++;
        end--;
        c += 1;
    }






}

int main()
{
    std::list<double> v{5,4,6,2,1};
    auto beg = v.begin();
    auto end = v.end();
    inverse(beg,end, v.size());

    beg = v.begin();
    end = v.end();

    for(beg; beg != end; beg++){
        std::cout<<*beg<<" ";
    }




}
