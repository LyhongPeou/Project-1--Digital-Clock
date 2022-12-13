#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <unistd.h>
#include "main.h"

int main()
{

    tm* timePtr = createTime();

    struct clock* currClock = createClock(timePtr);

    clockDisplay(currClock);


    delete(currClock);

    return 0;

}


void clockDisplay (struct clock* Clock)
{
    int hour;

    while (1)
    {
        system("clear");

        
        if(Clock -> second >= 60)
        {
            Clock -> second = 0;
            Clock -> minute++;
        }

        if(Clock -> minute >=  60)
        {
            Clock -> minute = 0;
            Clock -> hour++;
        }

        if(Clock -> hour >= 24)
        {
            Clock -> hour = 0;
        }

        if(Clock -> hour >= 12)
        {
            Clock -> light = "PM";
            
        }
        else
        {
            Clock -> light = "AM";
        }

        if(Clock -> hour > 12)
        {
            hour  = Clock -> hour - 12;
        }
        else if (Clock -> hour == 0)
        {
            hour = 12;
        }
        

        std::cout << "Currrent Time: " << hour << ":" << Clock -> minute << ":" <<Clock -> second <<":" << Clock -> light <<std::endl;
        Clock -> second++;
        

        sleep(1);


    }
}


struct clock* createClock(tm* time)
{
    struct clock *newClock = new struct clock;

    newClock->hour = time -> tm_hour;
    newClock-> minute = time-> tm_min;
    newClock-> second = time-> tm_sec;

    return newClock;


}


struct tm* createTime()
{
    time_t t = time(NULL);

    struct tm* timePtr = localtime(&t);

    return timePtr;
}
