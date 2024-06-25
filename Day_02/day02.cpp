#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#define MAX_RED     12
#define MAX_GREEN   13
#define MAX_BLUE    14

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

int game_check(string &line,int& gameID){

    int strlen = line.length(); 
    int index = 0, numberlen = 0;
    int cubeNumber, maxCube;

    
    //finding game ID
    findNum(line,index);
    gameID = StrtoNum(line,index);

    while(index < strlen){
        findNum(line,index);
        if(index >= strlen) break;
        cubeNumber = StrtoNum(line,index);
        index++;
        switch (line[index]){
            case 'r':
                maxCube = MAX_RED;
                break;
            case 'g':
                maxCube = MAX_GREEN;
                break;
            case 'b':
                maxCube = MAX_BLUE;
                break;
            default:
                cout << "Bug in Progarm\n";
                exit(EXIT_FAILURE);
                break;
        }
        if(cubeNumber > maxCube) return false;
    }

    return true;
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
    int possible_game_total = 0;
    int gameID = 0;
    while (getline(file,line))
    {
        if(game_check(line,gameID)) possible_game_total += gameID;
    }
    


    cout << "Possible game total: " << possible_game_total << endl;

    return 0;
}
