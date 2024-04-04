#include <iostream>
#include <string>
#include <cstddef>

int search_num(std::string const &input, int method) {
    int max_index = input.length() - 1;
    int ans = -1;
    // 0 is forward search
    if (method == 0) {
        for (int i = 0; i <= max_index; i++) {
            char ch = input[i];
            if (std::isdigit(ch)) {
                ans = i;
                break;
            }
        }
    }

    // 1 is backward search
    if (method == 1) {
        for (int i = max_index; i >= 0; i--) {
            char ch = input[i];
            if (std::isdigit(ch)) {
                ans = i;
                break;
            }
        }
    }

    return ans;
}

void search_text(std::string const &input, std::string *number, size_t *output, int mode) {

    for (int i = 0; i < 9; i++) {
        output[i] = (mode == 0) ? input.find(number[i]) : input.rfind(number[i]);
    }
}

int find_min(size_t *input, int index) {
    int ans{-1}, min = index;
    for (int i = 0; i < 9; i++) {
        if (input[i] != std::string::npos) {
            if (min == -1 || min > input[i]) {
                ans = i;
                min = input[i];
            };
        }
    }
    return (ans == -1) ? ans : ans + 1;
}

int find_max(size_t *input,int index) {
    int ans{-1}, max = index;
    for (int i = 0; i < 9; i++) {
        if (input[i] != std::string::npos) {
            if (max == -1 || max < input[i]) {
                ans = i;
                max = input[i];
            }
        }
    }
    return (ans == -1) ? ans : ans + 1;
}

int main(void) {

    std::string line;
    std::string::size_type n;
    std::string numbers[9] = {"one","two","three","four","five","six","seven","eight","nine"};
    size_t forward[9], backward[9];
    int sum{0}, max_index{0}, found{0}, index[2] = {0,0},pre_sum{0}, count{0};

    std::cout << std::string::npos << std::endl;

    while (std::getline(std::cin, line)) {

        max_index = line.length() - 1;
        pre_sum = 0;

        // Forward and Reverse Search for 1st numeric numbers
        index[0] = search_num(line, 0);
        index[1] = search_num(line, 1);

        search_text(line, numbers, forward, 0);
        found = find_min(forward,index[0]);
        
        if(found == -1){
            pre_sum += ((char) line[index[0]] - '0') * 10;
        } else{
            pre_sum += found*10;
        }

        search_text(line, numbers, backward, 1);
        found = find_max(backward,index[1]);
        if(found == -1){
            pre_sum += ((char) line[index[1]] - '0');
        } else{
            pre_sum += found;
        }

        sum += pre_sum;
        std::cout << "The line is: " << ++count << ", The pre sum is: " << pre_sum;
        std::cout << ", The cumulative sum is: " << sum << std::endl;
    };

    return 0;
};
