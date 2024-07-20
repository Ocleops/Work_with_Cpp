#include <iostream>
#include <algorithm>
#include <random>
#include <fstream>
#include <vector>
#include <iterator>

void write()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(-1000000, 1000000);
    std::ofstream output("random.txt");

    for(auto i=0; i<1000000; i++){
        output << distr(gen)<<"\n";
    }
}

template<typename Cont>
Cont read(Cont & v1)
{
    v1.resize(1000000);
    auto first = v1.begin();
    std::ifstream input ("random.txt");
    std::istream_iterator<int> beg1{input}, end1{};
    std::copy(beg1,end1, first);


    return v1;
}

int main()
{
    std::vector<int>v1;
    v1 = read(v1);

    auto beg = v1.begin();
    auto end = v1.end();
    std::sort(beg, end);

    auto min_el = std::min_element(v1.cbegin(), v1.cend());
    auto max_el = std::max_element(v1.cbegin(), v1.cend());

    auto value = std::find(v1.begin(), v1.end(), -1234);
    beg = v1.begin();

    int position = 0;
    position = std::distance(beg, value);
    beg = v1.begin();

    int sum=0;
    double avg=0;
    sum = std::accumulate(beg,end,sum);
    avg = double(sum)/v1.size();
    beg = v1.begin();

    auto itr = std::equal_range(beg, end, 0);
    beg = v1.begin();

    int number_of_zeros = 0;
    number_of_zeros = std::distance(itr.first, itr.second);

    int number_of_positive = 0;
    number_of_positive = std::distance(itr.second,end);

    auto stop = v1.begin();
    std::advance(stop,1000);
    v1.erase(beg,stop);
    beg = v1.begin();

    int replace_val = 10000;
    std::replace_if(beg,end,[&replace_val](int x)->bool{return x>replace_val;}, replace_val);




    std::ofstream out ("new_random.txt");
    std::ostream_iterator<int> fbeg{out, "\n"};
    std::copy(beg,end,fbeg);


}
