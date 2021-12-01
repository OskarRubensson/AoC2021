#include <iostream>
#include <vector>
#include <stdexcept>

// Do not fear, StackOverflow is here
bool tryParse(std::string& input, int& output) {
    try{
        output = std::stoi(input);
    } catch (std::invalid_argument) {
        return false;
    }
    return true;
}

void part1(){
    std::vector<int> depths;
    std::string input_string;
    int input;

    while(std::getline(std::cin, input_string, '\n')){
        if ( tryParse(input_string, input))
            depths.push_back(input);
        else
            break;
    }


    // Calculate results (could have been done in loop-above but who cares)
    int lastDepth = -1;
    int incr_counter = 0;
    for (auto depth: depths) {

        if (lastDepth != -1 && lastDepth < depth)
            incr_counter++;
        lastDepth = depth;
    }
    std::cout << "Result: " << incr_counter << std::endl;
}

void part2(){
    std::vector<int> depths;
    std::string input_string;
    int input;

    while(std::getline(std::cin, input_string, '\n')){
        if ( tryParse(input_string, input))
            depths.push_back(input);
        else
            break;
    }

    int lastWindow = -1;
    int incr_counter = 0;
    for(std::vector<int>::iterator it = depths.begin(); it != depths.end(); it++) {
        int currWindow = *it + *(it + 1) + *(it + 2);
        if (lastWindow != -1 && lastWindow < currWindow)
            incr_counter++;
        lastWindow = currWindow;
    }
    std::cout << "Result: " << incr_counter << std::endl;
}

int main() {
    part1();
    part2();
    return 0;
}
