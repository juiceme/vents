#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

#include "vent.hpp"

typedef std::vector< Vent::VentOutput > Vents;

void print_result(Vent::VentOutput output)
{
  std::cout << "\n";
  std::cout << std::get<0>(output) << "\t";
  std::cout << std::get<1>(output) << "\t";
  std::cout << std::get<2>(output) << "\t";
  std::cout << std::get<3>(output) << "\t";
  std::cout << std::get<4>(output) << "\t";
}

int main(int argc, char *argv[])
{
  Vents all_vents;
  std::ifstream inFile;
  inFile.open("vents.txt");
  std::string line;
  Vent *vent;

  while (std::getline(inFile, line)) {
    std::istringstream line_stream(line);
    std::vector<std::string> v1;
    std::string temp;
    while (line_stream >> temp) {
      v1.push_back(temp);
    }

    vent = new Vent((std::string)v1.at(0), (std::string)v1.at(1), std::stoi(v1.at(2)), std::stod(v1.at(3))); 
    all_vents.push_back(vent->getVent());
  }

  std::sort(begin(all_vents), end(all_vents), 
	    [](Vent::VentOutput const &t1, Vent::VentOutput const &t2) {
	      return std::get<2>(t1) > std::get<2>(t2); // or use a custom compare function
	    }
	    );
  
  for (auto i: all_vents)
    print_result(i);
  std::cout << "\n";

  return 0;
}
