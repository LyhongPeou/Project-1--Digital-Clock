#include <string>

#ifndef MAIN_H
#define MAIN_H

struct clock{
    int hour;
    int minute;
    int second;
    std::string light ;
};


struct clock* createClock(struct tm*);
void clockDisplay (struct clock*);
struct tm* createTime();


#endif