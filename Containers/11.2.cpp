#include<iostream>
#include<iterator>
#include<list>

template<typename Iterator1, typename Iterator2>
void my_copy_odd(Iterator1 beg1, Iterator1 end1, Iterator2 beg2)
{
    int counter=1;
    for(beg1; beg1 != end1; ++beg1){
        if(counter%2==1){
            *beg2 = *beg1;
            ++beg2;
        }
        counter += 1;
    }
}

template<typename Iterator1, typename Iterator2>
void my_copy_even(Iterator1 beg1, Iterator1 end1, Iterator2 beg2)
{
    int counter=1;
    for(beg1; beg1 != end1; ++beg1){
        if(counter%2==0){
            *beg2 = *beg1;
            ++beg2;
        }
        counter += 1;
    }
}


template<typename container>
void split(container const & c, container & odd, container & even)
{
    int odd_size=0, even_size=0;
    odd_size = odd.size();
    even_size = even.size();

    odd.resize(c.size()+odd.size());
    even.resize(c.size()+even.size());

    auto end_odd = odd.end();
    auto beg_odd = odd.begin();

    auto end_even = even.end();
    auto beg_even = even.begin();

    auto beg_cont = c.begin();
    auto end_cont = c.end();

    std::advance(beg_odd, odd_size);
    std::advance(beg_even, even_size);

    my_copy_odd(beg_cont, end_cont, beg_odd);
    my_copy_even(beg_cont, end_cont, beg_even);
}




int main()
{

    std::list<int> l{3, 5, -1, 9, -7, 88, 3, -6, -4};
    std::list<int>even{1,2,3,4,5};
    std::list<int>odd{1,2,3,4,5};

    split(l, odd, even);

    auto beg1 = even.begin();
    auto end1 = even.end();

    for(beg1; beg1 != end1; beg1++){
        std::cout<<*beg1<<" ";
    }

}
