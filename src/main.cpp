﻿// main.cpp : Defines the entry point for the application.
//

#include "main.h"

int main(int argc, char* argv[]) {
    std::fstream objFile;

    std::string newOBJ = "";

    objFile.open("data/rgb_cube_subdivided.obj");
    if (objFile.is_open()) {
        std::string line;

        while (std::getline(objFile, line)) {
            std::stringstream lineStream(line.c_str());
            std::vector<std::string> lineSegments;
            std::string segment;
            // seperate by space
            while (std::getline(lineStream, segment, ' ')) {
                lineSegments.push_back(segment);
            }

            if (lineSegments[0] == "v") {
                for (size_t i = 0; i < lineSegments.size(); i++) {
                    //std::cout << lineSegments[i] << ' ';
                    //newOBJ += lineSegments[i];

                    if (i > 0) {
                        //newOBJ += lineSegments[i];

                        double value = std::stod(lineSegments[i]);
                        value = std::pow(value, 2.2);

                        std::string valueStr = std::to_string(value);
                        newOBJ += valueStr;

                        {
                            bool test = false;
                        }
                    }
                    else {
                        newOBJ += lineSegments[i];
                    }

                    newOBJ += ' ';
                }
                //std::cout << '\n';
                newOBJ += '\n';
            }
            else if (lineSegments[0] == "o") {
                //std::cout << "o Linear RGB\n";
                newOBJ += "o Linear RGB\n";
            }
            else {
                //std::cout << line << '\n';
                newOBJ += line;
                newOBJ += '\n';
            }
        }
    }

    std::cout << newOBJ;

    std::fstream newOBJFile;
    newOBJFile.open("data/linear_rgb.obj", std::ios_base::out);
    newOBJFile << newOBJ;
    newOBJFile.close();

    std::cout << "Press enter to exit...\n";
    std::cin.ignore();
    return 0;
}