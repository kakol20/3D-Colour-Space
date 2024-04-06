// main.cpp : Defines the entry point for the application.
//

#include "main.h"

int main(int argc, char* argv[]) {
    // ----- OTHER -----

    CIE_XYZ::ToRGBMat = CIE_XYZ::ToXYZMat;
    CIE_XYZ::ToRGBMat.Invert3x3();

    LinearLMS::ToXYZMat = LinearLMS::ToLLMSMat;
    LinearLMS::ToXYZMat.Invert3x3();

    OkLab::ToLMSMat = OkLab::ToOkLabMat;
    OkLab::ToLMSMat.Invert3x3();

    // ----- START -----

    std::fstream objFile;

    std::string obj_string = "";

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

                sRGB rgb(std::stod(lineSegments[1]), std::stod(lineSegments[3]), std::stod(lineSegments[2]));
                LinearRGB lrgb = LinearRGB::sRGBtoLinearRGB(rgb);
                CIE_XYZ xyz = CIE_XYZ::LinearRGBtoXYZ(lrgb);
                LinearLMS l_lms = LinearLMS::XYZtoLinearLMS(xyz);
                LMS lms = LMS::LinearLMStoLMS(l_lms);
                OkLab lab = OkLab::LMStoOkLab(lms);

                obj_string += start;
                obj_string += ' ';
                obj_string += lab.Output();
                obj_string += '\n';
            }
            else if (lineSegments[0] == "o") {
                //std::cout << "o Linear RGB\n";
                obj_string += "o OkLab\n";
            }
            else {
                //std::cout << line << '\n';
                obj_string += line;
                obj_string += '\n';
            }
        }
    }

    std::cout << obj_string;

    std::fstream obj_fstream;
    obj_fstream.open("data/oklab.obj", std::ios_base::out);
    obj_fstream << obj_string;
    obj_fstream.close();

    //std::cout << "Press enter to exit...\n";
    //std::cin.ignore();
    return 0;
}