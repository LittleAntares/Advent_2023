#include <iostream>
#include <string>

int main(void){
    int sum{0};

    std::string input;

    while(std::getline(std::cin, input)){

        //Forward Search
        for(char ch : input){
            if(std::isdigit(ch)){
              sum += (ch - '0')*10;
              break;
            }
        }

        //Reverse Search
        for(int i = input.length()-1; i >=0; i--){
          char ch = input[i];
          if(std::isdigit(ch)){
            sum += (ch - '0');
            break;
          }
        }

        std::cout << "The cumulative sum is:" << sum << std::endl;
    }
};