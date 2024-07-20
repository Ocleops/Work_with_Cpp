#include<iostream>
#include<iterator>
#include<forward_list>

template<typename ForwardIt1, typename ForwardIt2>
ForwardIt1 search(ForwardIt1 first1, ForwardIt1 last1, ForwardIt2 first2, ForwardIt2 last2)
{
    auto beg2 = first2;
    auto beg1 = first1;
    auto check = beg1;
    int c=0;
    for(first1; first1 != last1; first1++){
        if(*first1 == * first2){
            beg1 = first1;
            beg2 = first2;
            c += 1;
            beg1++;
            beg2++;

            for(auto i=1; i<std::distance(first2, last2); i++){
                if(*beg1 == *beg2){
                    c += 1;
                    beg1++;
                    beg2++;
                }
                else{
                    break;
                }
            }
        }
        if(c == std::distance(first2,last2)){
            return first1;
        }
        else{
            beg1 = first1;
            beg2 = first2;
        }
    }
    return first1;
}


int main()
{
    std::forward_list<int> v1{15, 14, 13, -1, 0, 15, 14, 13, 12, 11};
    std::forward_list<int> v2{-1, -5};

    auto beg1 = v1.begin();
    auto end1 = v1.end();
    auto beg2 = v2.begin();
    auto end2 = v2.end();

    auto beg3 = search(beg1,end1,beg2,end2);

    if(beg3 == end1){
        std::cout<<"its a no";
    }
    else{
        std::cout<<*beg3;
    }


}
