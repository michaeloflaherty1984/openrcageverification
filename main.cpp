#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main() {
    const std::string flagFile = "/var/run/age_verification_passed";

    // Check if age verification was already passed
    std::ifstream flagIn(flagFile);
    if (flagIn.good()) {
        std::cout << "Age verification already passed.\n";
        return 0;
    }

    int age = 0;
    std::cout << "Please enter your age: ";
    std::cin >> age;

    if (std::cin.fail() || age < 0) {
        std::cerr << "Invalid input.\n";
        return 1;
    }

    if (age >= 18) {
        std::ofstream flagOut(flagFile);
        if (!flagOut) {
            std::cerr << "Failed to write verification flag.\n";
            return 1;
        }
        flagOut << "verified\n";
        std::cout << "Age verification passed.\n";
        return 0;
    } else {
        std::cerr << "Age verification failed. Access denied.\n";
        return 1;
    }
}
