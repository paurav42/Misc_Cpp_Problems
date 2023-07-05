
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<unordered_map>

class Ticket{
    public: 
    float distance;
    std::string level;
    std::string airline;

    Ticket(float distance, std::string level, std::string airlines):distance{distance}, level{level}, airline{airlines}{}
};

//Base Fare
class Level{
    public:
    float baseprice = 0;
    virtual float calculateBaseFare(Ticket* ticket) = 0;

};

class Economy:public Level{
    public:
    float calculateBaseFare(Ticket* ticket)  {
        baseprice = 50 + ticket->distance * 0.5;
        return baseprice;
    }
};
class Business:public Level{
    public:
    float calculateBaseFare(Ticket* ticket)  {
        baseprice = 80 + ticket->distance * 0.6;
        return baseprice;
    }
};
class Premium:public Level{
    public:
    float calculateBaseFare(Ticket* ticket)  {
        baseprice = 120 + ticket->distance * 0.65;
        return baseprice;
    }
};

// class Maps{

//     public:
//      std::unordered_map<std::string, float> ticket_airline_multiplier{{"Delta", 0.55},
//     {"LuigiAir", 0.85}, {"SouthWest", 0.95}, {"United", 0.88}};
   
//     Maps();
    
    
// };

class Airline{

    public:
    Ticket* ticket;
    Level* operatingLevel;
    //Maps* mps;
    static std::unordered_map<std::string, float> ticket_airline_multiplier;

    static void updateMapEntry(std::string str, float xplier){
        //override if existing, else write new.
        ticket_airline_multiplier[str] = xplier;
    }

    Airline(Ticket* tick):ticket{tick}{
        operatingLevel = nullptr;
        //ticket_airline_multiplier = mps->ticket_airline_multiplier;
    }

    Level* Instance(){
        if(ticket->level == "Economy"){
            return new Economy();
        }else if(ticket->level == "Business"){
            return new Business();
        }else if(ticket->level == "Premium"){
            return new Premium();
        }
        return nullptr;
    }
    
    float calculateAirlineFare(){
        operatingLevel = Instance();
        float operatingcost  = operatingLevel->calculateBaseFare(ticket);
        float travelcost = ticket->distance * ticket_airline_multiplier.at(ticket->airline);
        return  operatingcost + travelcost;
    }
};

std::unordered_map<std::string, float> Airline::ticket_airline_multiplier{
    {"Delta", 0.55},
    {"LuigiAir", 0.85},
    {"SouthWest", 0.95},
    {"United", 0.88}
};

//    static Airline::ticket_airline_multiplier{{"Delta", 0.55},
//     {"LuigiAir", 0.85}, {"SouthWest", 0.95}, {"United", 0.88}};

//Level* Airline::operatingLevel = nullptr;
 std::vector<std::string> Parser(std::string st){
     std::vector<std::string> strvec;
     std::string temp;
     std::stringstream sstr(st);
     while(sstr >> temp){
         strvec.push_back(temp);
     }
     return strvec;
 }

int main(){

    //
    // Ticket tick(100, "Premium", "Delta");
    // Airline air1(&tick); 

    std::vector<std::string> input_tickets {"United 150.0 Premium", "United 120.0 Economy",
     "United 100.0 Business", "Delta 60.0 Economy",
     "Delta 60.0 Premium", "Delta 60.0 Business", 
     "SouthWest 1000.0 Economy", "SouthWest 4000.0 Economy",
     "SouthWest 4000.0 Economy hhhhhhhh", "LuigiAir 50.0 Business"};

    
     for(auto it:input_tickets){

        std::vector<std::string> parsed_str = Parser(it);
        
        Ticket ticket(std::stof(parsed_str[1]), parsed_str[2], parsed_str[0]);
        Airline air1(&ticket);

        std::cout<< air1.calculateAirlineFare() << " for " << parsed_str[1] <<" "<< parsed_str[2]<<" " <<parsed_str[0]<<std::endl;
     }

    return 0;
}

