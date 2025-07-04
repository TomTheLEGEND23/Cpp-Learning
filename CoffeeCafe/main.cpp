#include <iostream>
#include <string>
#include "Coffee.h"

int main() {
    std::string coffeePreference;
    
    std::cout << "What type of coffee do you like? ";
    std::getline(std::cin, coffeePreference);
    
    std::cout << "You like: " << coffeePreference << std::endl;
    
    return 0;
}