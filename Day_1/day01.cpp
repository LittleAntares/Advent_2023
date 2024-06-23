#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main(int argc, char* argv[]){
    int n, i, sum = 0;
    string input;
    ifstream file("input.txt");

    while(getline(file,input)){
        n = input.length();
        i = 0;
        int first = -1, second = -1;
        while((first == -1) || (second == -1) || i < n){
            if(isdigit(input[i]) && (first == -1)) first = input[i] - '0';
            if(isdigit(input[n-i-1]) && (second == -1)) second = input[n-i-1] - '0';
            i++;
        }
        sum += first*10+second;
    }
    cout << sum << endl;
}  