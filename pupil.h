#ifndef PUPIL_H
#define PUPIL_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class Elective {M, E, PH, CH, ART, PHIL};
const vector<string> elective_names{"Mathematics", "English", "Physics", "Chemistry", "Arts", "Philosophy"};

class Pupil{
  string name;
  Elective elective1;
  Elective elective2;
  int points;
  public:
   Pupil(string, Elective);
   Pupil(string, Elective, Elective);
   Pupil(string, Elective, Elective, int);
  int chose(Elective choice) const;
  int change_points(int amount);
  void elect(Elective choice, bool first);
  int get_points() const;
  ostream& ins(ostream&) const;
};
ostream& operator<<(ostream&, const Pupil&);
//Definition der Klasse Pupil

#endif
