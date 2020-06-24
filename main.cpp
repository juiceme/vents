#include <string>
#include <iostream>

#include "vent.hpp"

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
  Vent *aa;
  Vent *bb;
  Vent *cc;
 
  try {
    aa = new Vent("AA0101201", "Vent_100", 50, 100.5);
    bb = new Vent("AA0101210", "Vent_125", 45, 90.3);
    cc = new Vent("AA0101202", "Vent_125", 10, 100);
  } catch (const char *error) {
    std::cout << "\n" << error << "\n";
    return 1;
  }

  print_result(aa->getVent());
  print_result(bb->getVent());
  print_result(cc->getVent());
  std::cout << "\n";
    
  return 0;
}
