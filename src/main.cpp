// main.cpp : Defines the entry point for the application.
//

#include "main.h"

int main(int argc, char* argv[]) {
  // ----- OTHER -----

  CIE_XYZ::ToRGBMat = CIE_XYZ::ToXYZMat;
  //CIE_XYZ::ToRGBMat.Invert3x3();
  CIE_XYZ::ToRGBMat.Invert();

  LinearLMS::ToXYZMat = LinearLMS::ToLLMSMat;
  LinearLMS::ToXYZMat.Invert();

  OkLab::ToLMSMat = OkLab::ToOkLabMat;
  OkLab::ToLMSMat.Invert();

  // ----- START -----

  //GenerateOBJs();
  //GenerateCSV();
  //FindMaxValue();

  std::cout << "Press enter to exit...\n";
  std::cin.ignore();
  return 0;
}

void GenerateOBJs() {
  std::fstream objFile;

  std::string obj_string = "";

  objFile.open("data/rgb_cube_subdivided.obj");
  if (objFile.is_open()) {
    std::string line;

    struct Values {
      double a;
      double b;
      double c;
    };

    struct MinMax {
      Values min;
      Values max;
      std::string aName;
      std::string bName;
      std::string cName;

      std::string spaceName;
    };

    std::map<std::string, MinMax> minMaxes;
    bool firstLine = true;

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
        CIE_XYZ xyz = CIE_XYZ::LinearRGBtoXYZ(lrgb);
        LinearLMS l_lms = LinearLMS::XYZtoLinearLMS(xyz);
        LMS lms = LMS::LinearLMStoLMS(l_lms);
        OkLab lab = OkLab::LMStoOkLab(lms);

        if (firstLine) {
          firstLine = false;

          minMaxes["1_xyz"].min.a = xyz.GetX();
          minMaxes["1_xyz"].min.b = xyz.GetY();
          minMaxes["1_xyz"].min.c = xyz.GetZ();
          minMaxes["1_xyz"].max.a = xyz.GetX();
          minMaxes["1_xyz"].max.b = xyz.GetY();
          minMaxes["1_xyz"].max.c = xyz.GetZ();
          minMaxes["1_xyz"].aName = "X";
          minMaxes["1_xyz"].bName = "Y";
          minMaxes["1_xyz"].cName = "Z";
          minMaxes["1_xyz"].spaceName = "CIE XYZ";

          minMaxes["2_l_lms"].min.a = l_lms.GetL();
          minMaxes["2_l_lms"].min.b = l_lms.GetM();
          minMaxes["2_l_lms"].min.c = l_lms.GetS();
          minMaxes["2_l_lms"].max.a = l_lms.GetL();
          minMaxes["2_l_lms"].max.b = l_lms.GetM();
          minMaxes["2_l_lms"].max.c = l_lms.GetS();
          minMaxes["2_l_lms"].aName = "L";
          minMaxes["2_l_lms"].bName = "M";
          minMaxes["2_l_lms"].cName = "S";
          minMaxes["2_l_lms"].spaceName = "Linear LMS";

          minMaxes["3_lms"].min.a = lms.GetL();
          minMaxes["3_lms"].min.b = lms.GetM();
          minMaxes["3_lms"].min.c = lms.GetS();
          minMaxes["3_lms"].max.a = lms.GetL();
          minMaxes["3_lms"].max.b = lms.GetM();
          minMaxes["3_lms"].max.c = lms.GetS();
          minMaxes["3_lms"].aName = "L";
          minMaxes["3_lms"].bName = "M";
          minMaxes["3_lms"].cName = "S";
          minMaxes["3_lms"].spaceName = "LMS";

          minMaxes["4_lab"].min.a = lab.GetL();
          minMaxes["4_lab"].min.b = lab.GetA();
          minMaxes["4_lab"].min.c = lab.GetB();
          minMaxes["4_lab"].max.a = lab.GetL();
          minMaxes["4_lab"].max.b = lab.GetA();
          minMaxes["4_lab"].max.c = lab.GetB();
          minMaxes["4_lab"].aName = "L";
          minMaxes["4_lab"].bName = "a";
          minMaxes["4_lab"].cName = "b";
          minMaxes["4_lab"].spaceName = "OkLab";
        } else {
          minMaxes["1_xyz"].min.a = std::min(xyz.GetX(), minMaxes["1_xyz"].min.a);
          minMaxes["1_xyz"].min.b = std::min(xyz.GetY(), minMaxes["1_xyz"].min.b);
          minMaxes["1_xyz"].min.c = std::min(xyz.GetZ(), minMaxes["1_xyz"].min.c);
          minMaxes["1_xyz"].max.a = std::max(xyz.GetX(), minMaxes["1_xyz"].max.a);
          minMaxes["1_xyz"].max.b = std::max(xyz.GetY(), minMaxes["1_xyz"].max.b);
          minMaxes["1_xyz"].max.c = std::max(xyz.GetZ(), minMaxes["1_xyz"].max.c);

          minMaxes["2_l_lms"].min.a = std::min(l_lms.GetL(), minMaxes["2_l_lms"].min.a);
          minMaxes["2_l_lms"].min.b = std::min(l_lms.GetM(), minMaxes["2_l_lms"].min.b);
          minMaxes["2_l_lms"].min.c = std::min(l_lms.GetS(), minMaxes["2_l_lms"].min.c);
          minMaxes["2_l_lms"].max.a = std::max(l_lms.GetL(), minMaxes["2_l_lms"].max.a);
          minMaxes["2_l_lms"].max.b = std::max(l_lms.GetM(), minMaxes["2_l_lms"].max.b);
          minMaxes["2_l_lms"].max.c = std::max(l_lms.GetS(), minMaxes["2_l_lms"].max.c);

          minMaxes["3_lms"].min.a = std::min(lms.GetL(), minMaxes["3_lms"].min.a);
          minMaxes["3_lms"].min.b = std::min(lms.GetM(), minMaxes["3_lms"].min.b);
          minMaxes["3_lms"].min.c = std::min(lms.GetS(), minMaxes["3_lms"].min.c);
          minMaxes["3_lms"].max.a = std::max(lms.GetL(), minMaxes["3_lms"].max.a);
          minMaxes["3_lms"].max.b = std::max(lms.GetM(), minMaxes["3_lms"].max.b);
          minMaxes["3_lms"].max.c = std::max(lms.GetS(), minMaxes["3_lms"].max.c);

          minMaxes["4_lab"].min.a = std::min(lab.GetL(), minMaxes["4_lab"].min.a);
          minMaxes["4_lab"].min.b = std::min(lab.GetA(), minMaxes["4_lab"].min.b);
          minMaxes["4_lab"].min.c = std::min(lab.GetB(), minMaxes["4_lab"].min.c);
          minMaxes["4_lab"].max.a = std::max(lab.GetL(), minMaxes["4_lab"].max.a);
          minMaxes["4_lab"].max.b = std::max(lab.GetA(), minMaxes["4_lab"].max.b);
          minMaxes["4_lab"].max.c = std::max(lab.GetB(), minMaxes["4_lab"].max.c);
        }

        obj_string += start;
        obj_string += ' ';
        obj_string += lab.Output();
        obj_string += '\n';
      } else if (lineSegments[0] == "o") {
        obj_string += "o OkLab\n";
      } else {
        //std::cout << line << '\n';
        obj_string += line;
        obj_string += '\n';
      }
    }

    std::string minMaxStr = "";
    for (auto it = minMaxes.begin(); it != minMaxes.end(); it++) {
      minMaxStr += it->second.spaceName + ":\n";

      minMaxStr += "  Min:\n";
      minMaxStr += "    " + it->second.aName + " = " + std::to_string(it->second.min.a) + '\n';
      minMaxStr += "    " + it->second.bName + " = " + std::to_string(it->second.min.b) + '\n';
      minMaxStr += "    " + it->second.cName + " = " + std::to_string(it->second.min.c) + '\n';

      minMaxStr += "  Max:\n";
      minMaxStr += "    " + it->second.aName + " = " + std::to_string(it->second.max.a) + '\n';
      minMaxStr += "    " + it->second.bName + " = " + std::to_string(it->second.max.b) + '\n';
      minMaxStr += "    " + it->second.cName + " = " + std::to_string(it->second.max.c) + '\n';

      minMaxStr += '\n';
    }

    std::cout << minMaxStr;

    std::fstream minMaxfs;
    minMaxfs.open("data/minMax.txt", std::ios_base::out);
    minMaxfs << minMaxStr;
    minMaxfs.close();
  }

  std::cout << obj_string;

  std::fstream obj_fstream;
  obj_fstream.open("data/oklab.obj", std::ios_base::out);
  obj_fstream << obj_string;
  obj_fstream.close();
}

void GenerateCSV() {
  std::string output = "R,G,B,R',G',B',X,Y,Z,L',M',S',L,M,S,L,a,b\n";

  for (double b = 0; b <= 1; b += 1. / 16.) {
    for (double g = 0; g <= 1; g += 1. / 16.) {
      for (double r = 0; r <= 1; r += 1. / 16.) {
        sRGB srgb(r, g, b);
        output += std::to_string(r) + ',' + std::to_string(g) + ',' + std::to_string(b) + ',';

        LinearRGB lrgb = LinearRGB::sRGBtoLinearRGB(srgb);
        output += std::to_string(lrgb.GetR()) + ',' + std::to_string(lrgb.GetG()) + ',' + std::to_string(lrgb.GetB()) + ',';

        CIE_XYZ xyz = CIE_XYZ::LinearRGBtoXYZ(lrgb);
        output += std::to_string(xyz.GetX()) + ',' + std::to_string(xyz.GetY()) + ',' + std::to_string(xyz.GetZ()) + ',';

        LinearLMS llms = LinearLMS::XYZtoLinearLMS(xyz);
        output += std::to_string(llms.GetL()) + ',' + std::to_string(llms.GetM()) + ',' + std::to_string(llms.GetS()) + ',';

        LMS lms = LMS::LinearLMStoLMS(llms);
        output += std::to_string(lms.GetL()) + ',' + std::to_string(lms.GetM()) + ',' + std::to_string(lms.GetS()) + ',';

        OkLab lab = OkLab::LMStoOkLab(lms);
        output += std::to_string(lab.GetL()) + ',' + std::to_string(lab.GetA()) + ',' + std::to_string(lab.GetB());

        output += '\n';
      }
    }
  }

  std::fstream csvfs;
  csvfs.open("data/spaces.csv", std::ios_base::out);
  csvfs << output;
  csvfs.close();

  std::cout << output;
}

void FindMaxValue() {
  const int r = 255;

  int maxG = 0, maxB = 0;

  double oklab_l = 0;
  double oklab_a = 0.;
  double oklab_b = 0;
  for (int g = 0; g < 256; g++) {
    for (int b = 0; b < 256; b++) {
      //std::cout << "Current(" << r << ',' << g << ',' << b << "): ";

      sRGB srgb(double(r) / 255., double(g) / 255., double(b) / 255.);
      OkLab lab = ColorSpaces::sRGBtoOkLab(srgb);

      maxG = lab.GetA() >= oklab_a ? g : maxG;
      maxB = lab.GetA() >= oklab_a ? b : maxB;

      //std::cout <<

      oklab_l = lab.GetA() >= oklab_a ? lab.GetL() : oklab_l;
      oklab_b = lab.GetA() >= oklab_a ? lab.GetB() : oklab_b;
      oklab_a = lab.GetA() >= oklab_a ? lab.GetA() : oklab_a;

      //std::cout << l << ", " << maxA << ", " << b << '\n';
    }
  }

  std::cout << "RGB(" << r << ", " << maxG << ", " << maxB << "): ";
  std::cout << oklab_l << ", " << oklab_a << ", " << oklab_b << '\n';
}