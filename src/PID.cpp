#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  last_cte_initalized = false;
  cte_sum = 0;
}

void PID::UpdateError(double cte) {
  if (!last_cte_initalized) {
    last_cte_initalized = true;
    last_cte = cte;
  }
  else {
    last_cte = this->cte;
  }
  this->cte = cte;
  cte_sum += cte;

}

double PID::TotalError() {
  return -(Kp * cte)- (Kd * (cte - last_cte)) - (Ki * cte_sum);
}

