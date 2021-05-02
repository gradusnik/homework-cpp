#include <iostream>

#define MON "monday"
#define TUE "tuesday"
#define WED "wednesday"
#define THU "thursday"
#define FRI "friday"
#define SAT "saturday"
#define SUN "sunday"
#define DISPLAY std::cout <<

int main() {
  int numOfDay(-1);
  DISPLAY "enter the number day of the week: ";
  std::cin >> numOfDay;
  if (numOfDay == 1) DISPLAY MON;
  else if (numOfDay == 2) DISPLAY TUE;
  else if (numOfDay == 3) DISPLAY WED;
  else if (numOfDay == 4) DISPLAY THU;
  else if (numOfDay == 5) DISPLAY FRI;
  else if (numOfDay == 6) DISPLAY SAT;
  else if (numOfDay == 7) DISPLAY SUN;
  else DISPLAY "no number day of the week";
  DISPLAY std::endl;
  return 0;
}
