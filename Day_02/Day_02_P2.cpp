#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;


int findNum(string &line,int& index){
    
    while(index < line.length() && !isdigit(line[index])){
        index++;
    }
    return index;
}

int StrtoNum(string &line, int& index){
    int ans = 0;
    while(isdigit(line[index])){
        ans = ans*10+(line[index]-'0');
        index++;
    }
    return ans;
}

int game_check(string &line){

    int strlen = line.length(); 
    int index = 0, numberlen = 0;
    int cubeNumber, maxRed = 0, maxGreen = 0, maxBlue = 0;

    
    //finding game ID
    findNum(line,index);
    StrtoNum(line,index);

    while(index < strlen){
        findNum(line,index);
        if(index >= strlen) break;
        cubeNumber = StrtoNum(line,index);
        index++;
        switch (line[index]){
            case 'r':
                if(cubeNumber > maxRed) maxRed = cubeNumber;
                break;
            case 'g':
                if(cubeNumber > maxGreen) maxGreen = cubeNumber;
                break;
            case 'b':
                if(cubeNumber > maxBlue) maxBlue = cubeNumber;
                break;
            default:
                cout << "Bug in Progarm\n";
                exit(EXIT_FAILURE);
                break;
        }
    }

    return maxRed*maxBlue*maxGreen;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    ifstream file(argv[1]); // Use ifstream for input file stream

    if (!file.is_open()) {
        cout << "Failed to open file: " << argv[1] << endl;
        return 1;
    }

    string line;
    int SumPowerSet = 0;
    while (getline(file,line)){
        SumPowerSet += game_check(line);
    } 
        

    cout << "Sum of the power set for the game is: " << SumPowerSet << endl;

    return 0;
}
