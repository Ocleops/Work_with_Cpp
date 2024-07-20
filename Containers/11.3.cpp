#include<iostream>
#include<iterator>
#include<vector>


template<typename Cont>
Cont In_Cont(int a, Cont v)
{

    int div=1, mod=10,c=0;
    for(auto i=0; i<v.size(); i++){
        if(i==v.size()-1){
            v[i] = a/div;
        }
        else{
            v[i] = a%mod/div;
            mod = mod*10;
            div = div*10;
        }
    }
    return v;
}

template<typename Iterator1, typename Iterator2, typename Iterator3>
void addition(Iterator1 beg1, Iterator1 end1, Iterator2 beg2, Iterator2 end2, Iterator3 beg3)
{
    auto stop = end1;
    auto start = beg1;
    int carry=0,sum=0,c=0;
    for(beg1; beg1 != end1; ++beg1){
        sum = *beg1 + *beg2;
        if(carry !=0 ){
            sum += carry;
            carry = 0;
        }
        if(sum>9){
            carry = sum/10;
            sum = sum%10;
        }
        *beg3 = sum;
        ++beg2;
        ++beg3;
        c += 1;

        if(c==10){
            *beg3 = *beg3+carry;
        }

    }
}


int main()
{
    int a=1958723584, b=60945983;
    std::vector<int> v1(10);
    std::vector<int> v2(10);

    v1 = In_Cont(a,v1);
    v2 = In_Cont(b,v2);

    std::vector<int> v3(v1.size()+1);

    auto beg1 = v1.begin();
    auto end1 = v1.end();

    auto beg2 = v2.begin();
    auto end2 = v2.end();

    auto beg3 = v3.begin();
    addition(beg1,end1,beg2,end2,beg3);

    for(auto i=0; i<v3.size(); i++){
        std::cout<<v3[v3.size()-i]<<" ";
    }

}
