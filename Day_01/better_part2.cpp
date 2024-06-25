#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    fstream file(argv[1]);

    if (!file.is_open()) {
        cout << "Failed to open file: " << argv[1] << endl;
        return 1;
    }

    string line;
    pair<string, char> numbers[] = {
        {"one", '1'},   {"two", '2'},   {"three", '3'},
        {"four", '4'},  {"five", '5'},  {"six", '6'},
        {"seven", '7'}, {"eight", '8'}, {"nine", '9'}
    };

    int sum = 0;

    while (getline(file, line)) {
        int first_num = 0, second_num = 0;
        size_t first_num_index = string::npos;
        size_t second_num_index = string::npos;
        second_num_index = 0;

        for (const auto& [spelling, digit] : numbers) {
            size_t first_num_digit = line.find(digit);
            size_t first_num_spelling = line.find(spelling);
            size_t second_num_digit = line.rfind(digit);
            size_t second_num_spelling = line.rfind(spelling);

            // Checking for first number
            if (first_num_digit != string::npos && first_num_digit < first_num_index) {
                first_num_index = first_num_digit;
                first_num = digit - '0';
            }
            if (first_num_spelling != string::npos && first_num_spelling < first_num_index) {
                first_num_index = first_num_spelling;
                first_num = digit - '0';
            }

            // Checking for second number
            if (second_num_digit != string::npos && second_num_digit >= second_num_index) {
                second_num_index = second_num_digit;
                second_num = digit - '0';
            }
            if (second_num_spelling != string::npos && second_num_spelling >= second_num_index) {
                second_num_index = second_num_spelling;
                second_num = digit - '0';
            }
        }

        sum += first_num * 10 + second_num;
    }

    // Print final sum after processing all lines
    cout << "Total sum: " << sum << endl;

    return 0;
}
