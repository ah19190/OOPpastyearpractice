#include <cstdlib>
#include <list> 
#include <vector> 

using namespace std; 

class DirectedRoadSegment;
class Vehicle;
class Intersection;

DirectedRoadSegment segments[1024];
int arr_start = 0; 


class DirectedRoadSegment {
  private:
  Intersection *intersectionOne;
  Intersection *intersectionTwo;
  int length; 
  int max_speed;
  vector<Vehicle*> vehicles_in_seg; //this will be used to add vehicles

  public:
  DirectedRoadSegment(int _length, int _max_speed, Intersection *_intersectionOne, Intersection *_intersectionTwo) {
    intersectionOne = _intersectionOne;
    intersectionTwo = _intersectionTwo;
    length = _length; 
    max_speed = _max_speed;

    //when constructing, insert it into segments array 
    segments[arr_start++] = *this; 
  }

  
}; 

class Vehicle {
  private:
  int travel_speed; 
  DirectedRoadSegment *current_road_seg;
  int dist_from_road_seg; 

  public:
  Vehicle(int _travel_speed, DirectedRoadSegment *_current_road_seg, int _dist_from_road_seg) {
    travel_speed = _travel_speed;
    current_road_seg = _current_road_seg; 
    dist_from_road_seg = _dist_from_road_seg; 
  }

  void set_current_road_seg(DirectedRoadSegment* new_seg) {
      current_road_seg = new_seg;
  }

};

class Intersection {
  private: 
  DirectedRoadSegment segmentsConnectedByIntersection[4]; 
  int no_of_intersections = 0; 

  public: 
  void add_road_seg(DirectedRoadSegment *d){
    segmentsConnectedByIntersection[no_of_intersections++] = *d; 
  // public:
//     Intersection() {}
//     Intersection(RoadSegment* r1, RoadSegment* r2, RoadSegment* r3, RoadSegment* r4) {
//         add_road(r1);
//         add_road(r2);
//         add_road(r3);
//         add_road(r4);
//     }

//     std::vector<RoadSegment*> roads; // connected road segments
//     std::vector<Vehicle*> vehicles; // vehicles waiting at this intersection

//     void add_road(RoadSegment* road) {
//         roads.push_back(road);
//     }
  }

}

// if have list template, could use this 
// class Intersection {
//   private: 
//   list<DirectedRoadSegment *> road_segments; //this does nto address the problem where can only have 4 in a list, although if have template could set max 

//   public:
//   void add_road_seg(DirectedRoadSegment *d){
//     road_segments.push_back(d); 
//   }

// };


int main(int argc, char* argv[]) {
  for(auto& segment : segments) {
    segment.moveTimeForward();
  }

  return 0;
}

//chatGPT implementation 
// #include <cstdlib>
// #include <list> 
// #include <vector> 
// #include <iostream>
// #include <ctime>

// using namespace std; 

// class DirectedRoadSegment;
// class Vehicle;
// class Intersection;

// DirectedRoadSegment segments[1024];
// int arr_start = 0; 


// class DirectedRoadSegment {
//   private:
//   Intersection *intersectionOne;
//   Intersection *intersectionTwo;
//   int length; 
//   int max_speed;
//   vector<Vehicle> vehicles_in_seg; //this will be used to add vehicles

//   public:
//   DirectedRoadSegment(int _length, int _max_speed, Intersection *_intersectionOne, Intersection *_intersectionTwo) {
//     intersectionOne = _intersectionOne;
//     intersectionTwo = _intersectionTwo;
//     length = _length; 
//     max_speed = _max_speed;

//     //when constructing, insert it into segments array 
//     segments[arr_start++] = *this; 
//   }

//   void moveTimeForward() {
//     //check if any vehicle at the end of the road segment
//     for (vector<Vehicle>::iterator it = vehicles_in_seg.begin(); it != vehicles_in_seg.end(); ) {
//       if (it->dist_from_road_seg == length) {
//         //vehicle at the end, make a turn
//         Intersection* current_intersection;
//         if (it->current_road_seg->intersectionOne == it->current_road_seg->intersectionTwo) {
//           current_intersection = it->current_road_seg->intersectionOne; //intersection is just a loop
//         } else if (it->current_road_seg->intersectionOne == intersectionOne) {
//           current_intersection = intersectionOne;
//         } else {
//           current_intersection = intersectionTwo;
//         }

//         int direction = rand() % 3;
//         DirectedRoadSegment* next_road_seg;
//         if (current_intersection->segmentsConnectedByIntersection[direction].length != 0) {
//           bool free_start = true;
//           for (vector<Vehicle>::iterator it2 = current_intersection->segmentsConnectedByIntersection[direction].vehicles_in_seg.begin(); it2 != current_intersection->segmentsConnectedByIntersection[direction].vehicles_in_seg.end(); it2++) {
//             if (it2->dist_from_road_seg == 0) {
//               free_start = false;
//               break;
//             }
//           }

//           if (free_start) {
//             next_road_seg = &current_intersection->segmentsConnectedByIntersection[direction];
//             it->current_road_seg = next_road_seg;
//             it->dist_from_road_seg = 0;
//             current_intersection->segmentsConnectedByIntersection[direction].vehicles_in_seg.push_back(*it);
//             it = vehicles_in_seg.erase(it);
//             continue;
//           }
//         }
//       }
//       it++;
//     }

//     //move all vehicles in the road segment
//     for (vector<Vehicle>::iterator it = vehicles_in_seg.begin(); it != vehicles_in_seg.end(); it++) {
//       int speed = min(it->travel_speed, max_speed);
//       int move_distance = speed;
//       for (vector<Vehicle>::iterator it2 = vehicles_in_seg.begin(); it2 != vehicles_in_seg.end(); it2++) {
//         if (it != it2 && it->dist_from_road_seg < it2->dist_from_road_seg && it->dist_from_road_seg + move_distance > it2->dist_from_road_seg) {
//           move_distance = it2->dist_from_road_seg - it->dist_from_road_seg - 1;
//           break;
//         }
//       }
//       it->dist_from_road_seg += move_distance;
//     }
//   }

// }; 

// class representing a vehicle
// class Vehicle {
//   private:
//     int travelSpeed;
//     DirectedRoadSegment* currentRoadSeg;
//     int distFromRoadSeg;

//   public:
//     Vehicle(int _travelSpeed, DirectedRoadSegment* _currentRoadSeg, int _distFromRoadSeg) {
//         travelSpeed = _travelSpeed;
//         currentRoadSeg = _currentRoadSeg;
//         distFromRoadSeg = _distFromRoadSeg;
//         currentRoadSeg->addVehicle(*this);
//     }

//     int getTravelSpeed() const {
//         return travelSpeed;
//     }
