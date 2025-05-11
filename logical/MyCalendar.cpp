#include<iostream>
#include<vector>
#include<utility>

class MyCalendar {
private: 
     std::vector<std::pair<int,int>> calendar;
public:
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        for(const auto [s,e]:this->calendar)
        {
            if(startTime<e && endTime>s)
            {
                return false;
            }
          
        }
        calendar.emplace_back(std::pair(startTime,endTime));
        return true;

        
    }
    
};

