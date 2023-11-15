#pragma once

#include <fstream>
#include <string>
#include <iostream>

class FileInitializer {
private:
    std::ofstream outFile;

public:
    FileInitializer();
    ~FileInitializer();

    void initializeFile();
    void closeFile();

    template <typename T>
    FileInitializer& operator<<(const T& data);

    // Obs�uga specjalna dla endl
    FileInitializer& operator<<(std::ostream& (*manipulator)(std::ostream&));
};

template <typename T>
FileInitializer& FileInitializer::operator<<(const T& data) {
    if (outFile.is_open()) {
        outFile << data;
    }
    else {
        std::cout << "File is not open!" << std::endl;
    }
    return *this;
}

FileInitializer& FileInitializer::operator<<(std::ostream& (*manipulator)(std::ostream&)) {
    if (outFile.is_open()) {
        manipulator(outFile);
    }
    else {
        std::cout << "File is not open!" << std::endl;
    }
    return *this;
}
