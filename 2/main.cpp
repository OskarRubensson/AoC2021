#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <map>

// Do not fear, StackOverflow is here
bool tryParse(std::string& input, int& output) {
    try{
        output = std::stoi(input);
    } catch (std::invalid_argument) {
        return false;
    }
    return true;
}

void part1() {
    std::vector<int> depths;
    std::string input_string;
    int input;
    std::map<std::string, int> position = {
            {"up", 0},
            {"down", 0},
            {"forward", 0},
    };

    while(std::getline(std::cin, input_string, '\n')){
        std::stringstream in_stream(input_string);
        std::string direction;
        std::string value;

        in_stream >> direction >> value;
        if ( tryParse(value, input))
            position[direction] += input;
        else
            break;
    }

    std::cout << "Result: " << (position["down"] - position["up"]) * position["forward"];
}

void part2(){
    std::vector<int> depths;
    std::string input_string;
    int input;
    std::map<std::string, int> position = {
            {"aim", 0},
            {"depth", 0},
            {"forward", 0},
    };

    while(std::getline(std::cin, input_string, '\n')){
        std::stringstream in_stream(input_string);
        std::string direction;
        std::string value;

        if (input_string == "q")
            break;

        in_stream >> direction >> value;

        if ( tryParse(value, input))
            if (direction == "forward") {
                position["forward"] += input;
                position["depth"] += input * position["aim"];
            } else if ( direction == "up" || direction == "down") {
                position["aim"] += input * (direction == "up" ? -1 : 1);
            }
        else
            break;
    }

    std::cout << "Result: " << position["depth"] * position["forward"];
}

int main() {
    // part1();
    part2();
    return 0;
}
