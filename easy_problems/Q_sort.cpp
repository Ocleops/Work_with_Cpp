#include <algorithm>
#include <iostream>
#include <vector>

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

int main(int argc, const char* argv[])
{
    std::vector<int> vec = { 3, 2, 1, 5, 2, 12, 4356, 1, 5, 12 };
    auto beg = vec.begin();
    auto end = vec.end();

    bubble_sort( beg, end );

    for(auto i=0; i<vec.size(); i++){
        std::cout<<*beg<<" ";
        beg++;
    }

}
