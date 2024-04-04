// main.cpp : Defines the entry point for the application.
//

#include "main.h"

int main(int argc, char* argv[]) {
    // ----- TESTING -----

    //Matrix lhs

    // ----- START -----

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
                std::string start = lineSegments[0];

                sRGB rgb(std::stod(lineSegments[1]), std::stod(lineSegments[2]), std::stod(lineSegments[3]));
                LinearRGB lrgb = LinearRGB::sRGBtoLinearRGB(rgb);

                newOBJ += start;
                newOBJ += ' ';
                newOBJ += lrgb.Output();
                newOBJ += '\n';
            }
            else if (lineSegments[0] == "o") {
                //std::cout << "o Linear RGB\n";
                newOBJ += "o CIE XYZ\n";
            }
            else {
                //std::cout << line << '\n';
                newOBJ += line;
                newOBJ += '\n';
            }
        }
    }

    std::cout << newOBJ;

    /*std::fstream newOBJFile;
    newOBJFile.open("data/cie_xyz.obj", std::ios_base::out);
    newOBJFile << newOBJ;
    newOBJFile.close();*/

    std::cout << "Press enter to exit...\n";
    std::cin.ignore();
    return 0;
}