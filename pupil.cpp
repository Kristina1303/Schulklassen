#include <iostream>
#include <string>
#include <vector>
#include "pupil.h"

using namespace std;

  Pupil::Pupil(string name, Elective elective1): name(name), elective1(elective1){
    if(name.length()<=0) throw runtime_error("Iligal name");
    if(elective1 == Elective::PHIL || elective1 == Elective::ART) throw runtime_error("Iligal elective");
    if(elective1 == elective2) throw runtime_error("Illegal elective duplicate");
    elective2 = Elective::PHIL;
    points = 20;
  }
Pupil::Pupil(string name, Elective elective1, Elective elective2): name(name), elective1(elective1), elective2(elective2){
    if(name.length()<=0) throw runtime_error("Iligal name");
    if(elective1 == Elective::PHIL || elective1 == Elective::ART) throw runtime_error("Iligal elective");
    if(elective1 == elective2) throw runtime_error("Illegal elective duplicate");
   points = 20;
  }
Pupil::Pupil(string name, Elective elective1, Elective elective2, int points): name(name), elective1(elective1), elective2(elective2), points(points){
    if(name.length()<=0) throw runtime_error("Iligal name");
    if(elective1 == Elective::PHIL || elective1 == Elective::ART) throw runtime_error("Iligal elective");
    if(elective1 == elective2) throw runtime_error("Illegal elective duplicate");
    if(points<0 || points>100) throw runtime_error("Illegal points");
  }
  int Pupil::chose(Elective choice) const{
    
    if(choice == elective1) return 1;
    if(choice == elective2) return 2;
    else return 0;   
  }
  int Pupil::change_points(int amount){
    points += amount;
    if(points > 100){
      int dif1 = points - 100;
      points = 100;
      return dif1;
    }
    else if(points < 0){
      int dif2 = points;
      points = 0;
      return dif2;
    } 
    else return 0;
  }
  void Pupil::elect(Elective choice, bool first){
    if(first){
      if((choice != Elective::PHIL && choice != Elective::ART) && (choice != elective2) && (choice != elective1))
      elective1 = choice;
      else throw runtime_error("Iligal choice");
    }
    else {
      if((choice != elective2) && (choice != elective1))
      elective2 = choice;
      else throw runtime_error("Iligal choice 2");
    }
  }
  int Pupil::get_points() const{
    return points;
  }
  ostream& Pupil::ins(ostream& out) const{
    int n = static_cast<int>(elective1);
    int m = static_cast<int>(elective2);
    out<<"["<<name<<": "<<elective_names.at(n)<<", "<<elective_names.at(m)<<", "<<points<<"]";
    return out;
  }
ostream& operator<<(ostream& o, const Pupil& student){
  return student.ins(o);
}
