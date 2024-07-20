#include <iostream>
#include <string>
#include<cctype>
#include <algorithm>
#include <iterator>


int main()
{
    std::string phrase;
    std::cout<<"give phrase\n";
    std::getline(std::cin, phrase);
    auto beg = phrase.begin();
    auto end = phrase.end();
    auto it = std::remove_if(phrase.begin(), phrase.end(), [](char x) -> bool { return !std::isalnum(x);});
    phrase.erase(it, phrase.end());
    std::transform(phrase.begin(),phrase.end(),phrase.begin(), [](char x)-> char {return std::toupper(x);});
    std::string Phrase = phrase;
    std::reverse(phrase.begin(),phrase.end());

    if(std::includes(phrase.begin(),phrase.end(),Phrase.begin(),Phrase.end())){
        std::cout<<"yes";
    }
    else{
        std::cout<<"no";
    }


}
