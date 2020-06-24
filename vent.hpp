/*
 * Vent class handling
 */

#ifndef INCLUDE_VENT_HPP_
#define INCLUDE_VENT_HPP_

#include <string>
#include <cmath>
#include <tuple>

#define KV100 1.152
#define KV125 1.454
  
class Vent {
public:
  typedef std::tuple<std::string, std::string, double, int, double> VentOutput;
  
  Vent(std::string vent_name, std::string vent_type,
       int initial_position, double target_airflow) {
    id = vent_name;
    type = vent_type;
    position = initial_position;
    if (vent_type.compare("Vent_100") == 0) {
      kValue = KV100;
    } else if (vent_type.compare("Vent_125") == 0) {
      kValue = KV125;
    } else {
      throw "Invalid vent type";
    }

    // The start airflow is what goes through the vent with the default
    // settings when first given.

    start_airflow = kValue * position * 2;

    // Calculate the needed opening for the given target airflow,
    // since Airflow = kValue * opening  -->  opening = Airflow / kValue
    // As there are 50 positions for opening from 0% to 100%, position is
    // half of the opening.

    opening = (double) target_airflow / kValue;
    position = round(opening/2);

    // the end airflow is what should be achieved as close as possible
    // to the target airflow.

    end_airflow = kValue * opening;
  }
  
  ~Vent() {
  }

  VentOutput getVent() {
    VentOutput final_position;
    std::get<0>(final_position) = id;
    std::get<1>(final_position) = type;
    std::get<2>(final_position) = start_airflow;
    std::get<3>(final_position) = position;
    std::get<4>(final_position) = end_airflow;
    
    return final_position;
  }
  
private:
  std::string id;
  std::string type;
  int position;
  double opening;
  double kValue;
  double start_airflow;
  double end_airflow;
};

#endif  // INCLUDE_VENT_HPP
