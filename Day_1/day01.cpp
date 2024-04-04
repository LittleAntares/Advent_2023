#include <iostream>
#include <string>

int main(void){
    int counter{0}, sum{0}, initial[2];

    std::string input;

    while(std::getline(std::cin, input)){
        counter = 0;
        for(char ch : input){
            if(std::isdigit(ch)){
              if(counter == 0){
                initial[0] = (ch - '0')*10;
              }else{
                initial[1] = (ch - '0');
              };
              counter++;
            };
        }
        if(counter == 1) initial[1] = initial[0]/10;
        sum += initial[0]+initial[1];
        std::cout << "The cumulative sum is:" << sum << std::endl;
    }
};