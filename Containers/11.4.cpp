#include <iostream>
#include <iterator>
#include <vector>
#include <map>


template<typename Cont>
Cont In_Cont(int a, Cont v)
{

    int div=1, mod=10,c=0;
    for(auto i=0; i<10; i++){
        if(i==9){
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

template<typename Cont>
std::map<int,std::vector<int>> multiplication(Cont & mult)
{
    using Map = std::map<int, std::vector<int>>;
    Map new_mult;
    std::vector<int> v;
    int multiplier = 0, key=0;

    for(auto x:mult){
        int carry=0, result=0, c=0;
        v = x.second;
        multiplier = x.first;
        for(auto i=0; i<10; i++){
            result = v[i] * multiplier;
            if(carry != 0){
                result += carry;
                carry = 0;
            }
            if(result > 9){
                carry = result/10;
                result = result%10;
            }
            v[i] = result;
            c += 1;
            if(c==10){
                v[i] = result + carry;
            }
        }
        new_mult.insert(std::make_pair(key, v));
        key += 1;
    }
    return new_mult;
}

template<typename Cont>
std::vector<int> addition(Cont & mult)
{
    std::vector<int> v1;
    std::vector<int> v2;
    std::vector<int> v3(20);
    std::vector<int> v4(20);
    v1 = mult.at(9);
    v1.resize(20);
    int place = 1;
    int carry=0, sum=0, c=0;
    for(auto i=0; i<9; i++){
        v2 = mult.at(8-i);
        c=0;
        for(auto j=0; j<10; j++){
            v3[j+place] = v2[j];
        }
        place += 1;
        for(auto j=0; j<20; j++){
            sum = v3[j] + v1[j];
            if(carry != 0){
                sum += carry;
                carry = 0;
            }
            if(sum > 9){
                carry = sum/10;
                sum = sum%10;
            }
            v4[j] = sum;
            c += 1;
            if(c==20){
                v4[j] = v4[j] + carry;
                carry=0;
            }
        }
        v1 = v4;
    }
    return v1;

}

int main()
{
    int a=9000000, b=9000000;
    int transfer=0;
    std::vector<int> v1(10);
    std::vector<int> v2(10);
    std::vector<int> result(20);

    v1 = In_Cont(a,v1);
    v2 = In_Cont(b,v2);


     using Map = std::multimap<int,std::vector<int>>;
     Map mult;
     using map = std::map<int,std::vector<int>>;

     for(auto i=0; i<v2.size(); i++){
        transfer = v2[i];
        mult.insert(std::make_pair(transfer,v1));
     }

     map new_mult;
     new_mult = multiplication(mult);


     result = addition(new_mult);

     for(auto i=0; i<result.size(); i++){
        std::cout<<result[result.size()-1-i]<<" ";
     }



//     for(auto x:new_mult){
//        transfer = x.first;
//        v1 = x.second;
//        std::cout<<transfer<<" --> ";
//        for(auto i=0; i<v1.size(); i++){
//            std::cout<<v1[i]<<" ";
//        }
//        std::cout<<"\n";
//     }


}
