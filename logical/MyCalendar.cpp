class MyCalendar {
private: 
     std::vector<pair<int,int>> calendar;
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
        calendar.emplace_back(pair(startTime,endTime));
        return true;

        
    }
    
};

