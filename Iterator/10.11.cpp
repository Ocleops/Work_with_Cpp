#include<iostream>
#include<iterator>
#include<forward_list>

template<typename Iterator1, typename Iterator2>
int common(Iterator1 beg1, Iterator1 end1, Iterator2 beg2, Iterator2 end2, int len)
{
    std::forward_list<double> v3(50);
    auto beg3 = v3.begin();

    auto start= beg2;
    int c1=0,c=0;
    for(beg1; beg1 != end1; beg1++){
        for(beg2; beg2 != end2; beg2++){
            if(*beg1 == *beg2){
                for(auto x :v3){
                    if(x==*beg1){
                        c1 += 1;
                    }
                }
                if(c1>0){
                    c1=0;
                    continue;
                }
                else{
                    *beg3=*beg1;
                    std::cout<<*beg3<<" ";
                    beg3++;
                    c++;
                }
            }
        }
        beg2 = start;
    }


    return c;
}


int main()
{
    std::forward_list<double> v1{2, 2, 3, 4, 4, 2, 5, 6, 7};
    std::forward_list<double> v2{9, 8, 7, 6, 4, 2, 5, 4, 3, 2, 1, 2, 4};

    auto beg1 = v1.begin();
    auto end1 = v1.end();
    auto beg2 = v2.begin();
    auto end2 = v2.end();

    int size1=0, size2=0, c=0;
    for(auto x: v1){
        size1 += 1;
    }

    for(auto x: v2){
        size2 += 1;
    }

    if(size1>size2){
        c = common(beg1, end1, beg2, end2, size1);
    }
    else{
        c = common(beg1, end1, beg2, end2, size2);
    }
    std::cout<<"\n"<<c;



}

