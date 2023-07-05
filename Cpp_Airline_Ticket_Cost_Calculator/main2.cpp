// Design a flight ticket cost calculator: 
// consider flight distance, class and airlines

#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<unordered_map>

enum class Level{
    Economy, Business, Premium
};

enum class Airline{
    Delta, SouthWest, United, LuigiAir
};

class Ticket{
    public:
    float distance;
    Airline airline;
    Level level;

    Ticket(const float& distance_, const Airline& airline_, const Level& level_){
        distance = distance_;
        airline = airline_;
        level = level_;
    }

};

class TicketingSystem{

    public:

    static TicketingSystem* Instance(const Airline air){
        switch(air){
            case Airline::Delta:
                return Delta::Instance();
            case Airline::United:
                return United::Instance();
            case Airline::LuigiAir:
                return LuigiAir::Instance();
            case Airline::SouthWest:
                return SouthWest::Instance();
        };

        return nullptr;

    }

    float getLevelCost(Ticket ticket){
        float level_cost = 0;
        if(ticket.level == Level::Economy)
            level_cost = 20 + 0.1*ticket.distance;
        else if(ticket.level == Level::Business)
            level_cost = 25 + 0.25*ticket.distance;
        else if(ticket.level == Level::Premium)
            level_cost = 50 + 0.5*ticket.distance;
        
        return level_cost;
    }

    virtual float getOperatingCost(const Ticket& ticket) = 0;

};

class Delta: public TicketingSystem{
    public:
    static Delta* instance_;

    static Delta* Instance(){
        if(!instance_){
            instance_ = new Delta();
        }
        return instance_;
    }
    float getOperatingCost(const Ticket& ticket) const override{
        return getLevelCost(ticket) + ticket.distance * 0.75;
    }
    

};
class United: public TicketingSystem{
    public:
    static United* instance_;

};
class LuigiAir: public TicketingSystem{
    public:
    static LuigiAir* instance_;

};
class SouthWest: public TicketingSystem{
    public:
    static SouthWest* instance_;

};

SouthWest* SouthWest::instance_ = nullptr;
LuigiAir* LuigiAir::instance_ = nullptr;
United* United::instance_ = nullptr;
Delta* Delta::instance_ = nullptr;



int main(){

    // input format: 
    std::vector<std::string> input_tickets {"United 150.0 Premium", "United 120.0 Economy",
     "United 100.0 Business", "Delta 60.0 Economy",
     "Delta 60.0 Premium", "Delta 60.0 Business", 
     "SouthWest 1000.0 Economy", "SouthWest 4000.0 Economy",
     "SouthWest 4000.0 Economy hhhhhhhh", "LuigiAir 50.0 Business"};

     // 1. Parse string
     // 2. Store ticket details in class Ticket
        //
     // 3. Compute effective cost in class TicketingSystem  
        // compute level cost
        // compute Airlines cost
        // Return total cost

    


    

    return 0.0;
}