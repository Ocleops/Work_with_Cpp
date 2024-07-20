#include<iostream>
#include<iterator>
#include <vector>

//This function is from https://stackoverflow.com/questions/42273197/bubble-sort-implementation-in-c
template <typename ForwardIterator>
void bubble_sort( ForwardIterator first, ForwardIterator last )
{
    for ( ForwardIterator sorted = first; first != last; last = sorted )
    {
        sorted = first;
        for ( ForwardIterator current = first, prev = first; ++current != last; ++prev )
        {
            if ( *current < *prev )
            {
                std::iter_swap( current, prev );
                sorted = current;
            }
        }
    }
}



template<typename InputIterator1, typename InputIterator2, typename OutputIterator>
OutputIterator f(InputIterator1 beg1, InputIterator1 end1,
                InputIterator2 beg2, InputIterator2 end2, OutputIterator beg3)
{
    auto restart = beg2;
    int common_value = 0, c1=0, c2=0;
    for(beg1; beg1 != end1; beg1++){
        for(beg2; beg2 != end2; beg2++){
            if(!(*beg1< *beg2) && !(*beg2 < *beg1)){
                common_value = *beg1;
                auto check1 = beg1;
                auto check2 = beg2;
                for(check1; check1 != end1; check1++){
                    if(!(*check1 < common_value) && !(common_value < *check1)){
                        c1 += 1;
                    }
                }
                std::advance(beg1,c1);
                for(check2; check2 != end2; check2++){
                    if(!(*check2 < common_value) && !(common_value < *check2)){
                        c2 += 1;
                    }
                }
                std::advance(beg2,c2);
                if(c2>c1){
                    for(auto i=0; i<c1; i++){
                        *beg3 = common_value;
                        beg3++;
                    }
                }
                else{
                    for(auto i=0; i<c2; i++){
                        *beg3 = common_value;
                        beg3++;
                    }
                }
                c1=0;
                c2=0;
            }
        }
        beg2 = restart;
    }

    return beg3;
}


int main()
{
    int v3_size=0;
    std::vector<int> v1{11, 5, 9, 7, 5, 3, 3, 3};
    std::vector<int> v2 {5, 5, 5, 6, 7, 8, 1, 2, 3, 4} ;
    std::vector<int> copy_vec;
    std::vector<int> v3(v1.size() + v2.size());

    if(v2.size() > v1.size()){
        copy_vec = v1;
        v1 = v2;
        v2 = copy_vec;
    }

    auto beg1 = v1.begin();
    auto end1 = v1.end();
    auto beg2 = v2.begin();
    auto end2 = v2.end();
    auto beg3 = v3.begin();

    bubble_sort(beg1, end1);
    bubble_sort(beg2, end2);

    for(auto i=0; i<v1.size(); i++){
        std::cout<<v1[i]<<" ";
    }
    std::cout<<"\n";

    for(auto i=0; i<v2.size(); i++){
        std::cout<<v2[i]<<" ";
    }
    std::cout<<"\n";

    beg3 = f(beg1, end1, beg2, end2, beg3);

    for(auto i=0; i<v3.size(); i++){
        std::cout<<v3[i]<<" ";

    }





}



