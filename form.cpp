#include <iostream>
#include <string>
#include <vector>
#include "pupil.h"
#include "form.h"

using namespace std;


Form::Form(string id, vector<Pupil> pupils): id(id), pupils(pupils) {
  if(id.length()<=0) throw runtime_error("Iligal id");
  if(pupils.size()<=0) throw runtime_error("Iligal list of students");
}
  double Form::perc(Elective choice, int minpoints) const{
    double n = 0;
    for(size_t i =0; i<pupils.size(); i++){
     if((pupils.at(i).chose(choice) == 1 || pupils.at(i).chose(choice) == 2) && pupils.at(i).get_points()>=minpoints) n++;
    }
    return n/pupils.size()*100;
  }
  ostream& Form::ins(ostream& out) const{
    int n=0;
    out<<"["<<id<<": {";
    for(size_t i =0; i<pupils.size(); i++){
      n+=pupils.at(i).get_points();
      if(i==pupils.size()-1) out<<pupils.at(i);
      else out<<pupils.at(i)<<", ";
    }
    out<<"}, "<<n<<"]";
    return out;
  }
vector<Elective> Form::popular() const{
  vector<Elective> subjects {Elective::M, Elective::E, Elective::PH, Elective::CH, Elective::ART, Elective::PHIL};
  vector<Elective> often;
  int pop = pupils.size()/2;
  for(size_t i =0; i<subjects.size(); i++){
    Elective tmp = subjects.at(i);
    int n =0; 
    for(size_t i =0; i<pupils.size(); i++){
      if(pupils.at(i).chose(tmp) == 1 || pupils.at(i).chose(tmp) == 2) n++;
    }
    if(n>pop) often.push_back(tmp);
}
  return often;
}
int Form::distribute(Elective choice, int amount){
  
    int second =0;
    int first =0;
    int x, rest;
    int sum =0;
  if(amount<0) throw runtime_error("Iligal amount");
  else {
  for(size_t i =0; i<pupils.size(); i++){
       if(pupils.at(i).chose(choice) == 2) {
         second++;
       }
       if(pupils.at(i).chose(choice) == 1){
         first++;
       }
     }
    x = amount/(second + first*2);
    rest = amount%(second + first*2);
    for(size_t i =0; i<pupils.size(); i++){
      if(pupils.at(i).chose(choice) == 2) sum += pupils.at(i).change_points(x);
      if(pupils.at(i).chose(choice) == 1) sum += pupils.at(i).change_points(2*x);
    }

  }
  return rest + sum;
}

ostream& operator<<(ostream& o, const Form& klas){
  return klas.ins(o);
}
