#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <string>
#include <vector>
#include "pupil.h"

using namespace std;

class Form{
  string id;
  vector<Pupil> pupils;
  public:
  Form(string, vector<Pupil>);
  double perc(Elective choice, int minpoints) const;
  ostream& ins(ostream&) const;
  vector<Elective> popular() const;
  int distribute(Elective choice, int amount);
};
ostream& operator<<(ostream&, const Form&);
//Definition der Klasse Form

#endif
