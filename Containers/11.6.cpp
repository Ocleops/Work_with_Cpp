#include <iostream>
#include <string>
#include <map>
#include<fstream>

int main ()
{
    using Map = std::map<std::string, std::string>;
    std::ifstream input("Dictionary.txt");
    Map Dictionary;
    std::string word;
    std::string translation;
    std::string i;
    int counter=0;
    while(input >> i){
        if(counter%2==0){
            word = i;
            counter += 1;
            continue;
        }
        if(counter%2==1){
            translation = i;
            counter += 1;
        }
        if(counter == 2){
            Dictionary.insert(std::make_pair(word,translation));
            counter = 0;
        }
    }

    std::cout<<"Please type the word that you want to translate.\n";
    std::cin>>word;
    counter =0;
    for(auto x:Dictionary){
        if(x.first == word){
            std::cout<<word<<" --> "<<x.second;
            break;
        }
        else if(x.second == word){
            std::cout<<word<<" --> "<<x.first;
            break;
        }
        else{
            counter += 1;
        }
    }
    if(counter == Dictionary.size()){
        std::cout<<"There is no translation for this word. Please type translation.\n";
        std::cin>>translation;
        std::ofstream output("Dictionary.txt",std::ios_base::app);
        output<<"\n" <<word<<"\n"<<translation<<"\n";
    }
}
