#include<iostream>
#include<iterator>
#include<vector>
#include<list>

template<typename Iterator1, typename Iterator2>
void func(Iterator1 beg1, Iterator1 end1, Iterator2 beg2)
{
    *beg2=*beg1;
    auto a = *beg1;
    beg1++;
    beg2++;
    for(beg1; beg1 != end1; beg1++){
        if(a == *beg1){
            continue;
        }
        else{
            *beg2 = *beg1;
            beg2++;
            a = *beg1;

        }
    }
}

int main()
{
    std::vector<int> v1{1, 6, 6, 5, 2, 2, 2, 8, 9, 9, 8, 9, 7, 0, 1, 1};
    std::list<int> v2(v1.size());

    auto beg1 = v1.begin();
    auto end1 = v1.end();
    auto beg2 = v2.begin();

    func(beg1,end1,beg2);

    for(auto x:v2){
        std::cout<<x<<" ";
    }
}
