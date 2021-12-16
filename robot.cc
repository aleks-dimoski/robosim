#include "robot.hh"
#include "random.hh"

using namespace std;

/*
<<<<<<< HEAD
Author:Wang,YenHsiang and Aleksandar Dimoski
version : 1.1
date : Dec 16th, 2021
=======
Robot is the base class all of the vehicles will inherit from.
It takes the following:
- name = The name of the robot to tell the different robots apart
- loc = The real location as vector 3D object constisting of the x, y, and z positions
- horizontal_variance = Needed to determine error in estimated location
- vertical_variance = Needed to determine error in estimated location
- heading = horizontal direction of the robot
- speed = speed in the forward direction
- batteryLife = current battery life of the robot
For the estimated location, it is calculated by taking the real location and adding some Gaussian error,
which is a vector 3D consisting where each x, y, and z component is Gaussian with a mean of 0 and variance 
that is passed to the object (horizontal variance and vertical variance).
>>>>>>> 9c4d3d17b51fc6259b44aca1bd30c8ce871f29f0
*/

<<<<<<< HEAD
#include <vector>

#include "beacon.hh"

robot::robot(string name, double x, double y, double z, double posVarHoriz,
             double posVarVert, double heading, double speed,
             double headingVert, double BatteryLife = 100)
    : name(name),
      location(vec_3d(x, y, z)),
      posVarHoriz(posVarHoriz),
      posVarVert(posVarVert),
      heading(heading),
      speed(speed),
      headingVert(headingVert),
      BatteryLife(BatteryLife) {}

robot::robot(string name, const vec_3d& pos, double posVarHoriz,
             double posVarVert, double heading, double speed,
             double headingVert, double BatteryLife = 100)
    : name(name),
      location(pos),
      posVarHoriz(posVarHoriz),
      posVarVert(posVarVert),
      heading(heading),
      speed(speed),
      headingVert(headingVert),
      BatteryLife(BatteryLife) {}

void robot::move(double time) {
  double velX = time * speed * cos(heading);
  double velY = time * speed * sin(heading);
  double velZ = time * headingVert;
  location.x += velX;
  location.y += velY;
  location.z += velZ;
}

vec_3d robot::getEstLocation(vector<beacon> beacons) {
  vector<double> dists;
  for (beacon b : beacons) {
    dists.push_back(location.dist(b));
  }
  // TODO Calculate estimated position and return it; for now just returns
  // actual position
  return location;
}

std::ostream& robot::operator<<(std::ostream& s, robot& r) {
  s << "The object " << r.getName() << " is "
    << "Location= " << r.getLocation() << "\tBattery Life= " << r.getBatLife()
    << endl;
  return s;
}
=======
robot::robot(const string& name, const vec_3d& loc, double horizontal_variance, double vertical_variance, double heading, double speed, double batteryLife)
    : name(name), location(loc), heading(heading), speed(speed) {
        est_loc = location + vec_3d(N(0, horizontal_variance), N(0, horizontal_variance), N(0, vertical_variance));
    }

ostream& operator<< (std::ostream& a, robot & xyz) {
        a << xyz.location << "batterylife=" << xyz.batteryLife << endl;
        return a; 
    }
>>>>>>> 9c4d3d17b51fc6259b44aca1bd30c8ce871f29f0
