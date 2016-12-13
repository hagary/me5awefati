#include "timer.hpp"
Timer::Timer(){
 /* durMins = durationMins;
  currMin = durMins;
  currSec = 0;
  pos.x = -30; pos.y = roomSize / 2 - 10; pos.z = - roomSize / 2 + 10;*/
}
void Timer::decTime(int value){
  //if(currSec == 0 && currMin == 0)
  //{
  //  //TODO DO SOMETHING -> UPDATE GAME MODE
  //  return;
  //}
  //if(currSec == 0){
  //  currSec = 59;
  //  currMin --;
  //}
  //else
  //  currSec--;
  //glutTimerFunc(1000, decTime, 0);
}

void Timer::drawTime(){
  //std::string secs = std:: to_string(currSec);
  //std::string mins = std:: to_string(currMin);
  //std::string time = mins +" : "+ secs;
  //glColor3f(1.0f,1.0f,1.0f);
  //glPushMatrix();
  //glRasterPos3f(pos.x, pos.y, pos.z);
  //for (unsigned int i = 0; i<time.length(); i++)
  //{
  //  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, time[i]);
  //}
  //glPopMatrix();
}
