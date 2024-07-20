#include<iostream>
#include<iterator>
#include<vector>

template<typename ForwardIterator, typename T>
ForwardIterator locate(ForwardIterator beg, ForwardIterator end, T size, T value)
{
    int counter = 0;
    auto start1 = beg;
    for(start1; start1 != end; start1++){
        if(*start1 == value){
            auto start2 = start1;
            for(auto i=0; i<size; i++){
                if(*start2 == value){
                    counter += 1;
                    start2++;
                }
                else{
                    counter = 0;
                    break;
                }
                if(counter == size){
                        counter = 0;
                    return start1;
                }
            }
        }
    }
    return start1;
}


int main()
{
    int position = 0;
    std::vector<int> v{1, 2, 2, 3, 3, 3, 4, 4, 5, 6, 6, 6};
    auto beg = v.begin();
    auto end = v.end();
    auto it = locate(beg,end,3,10);

    if(it == end){
        std::cout<<"Sequence not found";
    }
    else{
        it++;
        for(beg; beg != it; beg++){
            position += 1;
        }
        std::cout<<"Location is: "<<position;
    }

}
