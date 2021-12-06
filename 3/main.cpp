/*
 * This code is so ugly I want to vomit.
 * I'm so sorry if I made your eyes bleed :(
 */

#include <iostream>
#include <vector>
#include <math.h>       /* pow */

// Do not fear, StackOverflow is here
bool tryParse(std::string& input) {
    int output;
    try{
        output = std::stoi(input);
    } catch (std::invalid_argument) {
        return false;
    }
    return true;
}

void toBinary(std::vector<int> &arr){
    for(int& i: arr){
        i = i >= 0 ? 1 : 0;
    }
}

void invert(std::vector<int> &arr){
    for(int& i: arr){
        i = 1 - i;
    }
}

int parseBits(const std::vector<int> arr){
    int result = 0;
    int base = 1;
    for(auto it = arr.rbegin(); it != arr.rend(); it++) {
        result += (*it) * base;
        base *= 2;
    }
    return result;
}

void part1(){
    std::vector<int> gamma = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    std::string input_string;

    while(std::getline(std::cin, input_string, '\n')){
        if (input_string.empty())
            break;

        for(int i = 0; i < input_string.length(); i++) {
            gamma.at(i) += input_string.at(i) == '0' ? -1 : 1;
        }
    }

    toBinary(gamma);
    std::vector<int> epsilon = gamma;
    invert(epsilon);

    int gammaDec = parseBits(gamma);
    int epsilonDec = parseBits(epsilon);

    std::cout << "Result: " << gammaDec * epsilonDec << std::endl;
}

std::vector<int> getBitArrayValue(std::vector<std::vector<int> > values, bool less = false){
    size_t index = 0;
    while(values.size() > 1) {

        std::vector<std::vector<int>> bit_0;
        std::vector<std::vector<int>> bit_1;

        for(auto it = values.begin(); it != values.end(); it++){
            (*it).at(index) == 0 ? bit_0.push_back(*it) : bit_1.push_back(*it);
        }


        if (less)
            values = bit_1.size() < bit_0.size() ? bit_1 : bit_0;
        else
            values = bit_1.size() >= bit_0.size() ? bit_1 : bit_0;

        index++;
        if (index > values.at(0).size())
            index = 0;
    }
    return values.at(0);
}

void part2(){
    std::vector<std::vector<int> > input;
    std::string input_string;

    while(std::getline(std::cin, input_string, '\n')){
        if (input_string.empty())
            break;
        std::vector<int> bit_arr;
        for(int i = 0; i < input_string.length(); i++) {
            bit_arr.push_back( input_string.at(i) == '0' ? 0 : 1 );
        }
        input.push_back(bit_arr);
    }

    int scrubber = parseBits(getBitArrayValue(input, true));
    int generator = parseBits(getBitArrayValue(input, false));

    std::cout << "Result: " << scrubber * generator << std::endl;
}

int main() {
    // part1();
    part2();
    return 0;
}
