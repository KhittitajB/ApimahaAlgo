#include <iostream>
#include <string>

int main() {
    std::string line;
    // Reads lines from standard input until EOF (e.g., Ctrl+Z on Windows, Ctrl+D on Unix)
    // or an input error occurs.
    while (std::getline(std::cin, line)) {
        std::cout << "Read: " << line << std::endl;
    }
    
    // After the loop, you can check if it ended due to EOF or an error.
    // if (std::cin.eof()) {
    //     std::cout << "End of file reached." << std::endl;
    // } else if (std::cin.fail()) {
    //     std::cout << "An input error occurred (not EOF)." << std::endl;
    // }

    std::cout << "\ngood job.  ";

    return 0;
}