
// #include<unordered_map>
// #include<vector>
// #include<string>
// #include<stringstream>



// enum class Airlines{
//     Delta, United, SouthWest, LuigiAir
// };

// enum class Level{
//     Economy, Business, Premium
// };

// const std::unordered_map<std::string, Level> level_map{
//     {"Economy",Level::Economy},
//     {"Business", Level::Business},
//     {"Premium", Level::Premium}};

// const std::unordered_map<std::string, Airlines> airlines_map{
//     {"Delta",Airlines::Delta},
//     {"United", Airlines::United},
//     {"SouthWest", Airlines::SouthWest},
//     {"LuigiAir", Airlines::LuigiAir}};



// class FlightTicket{
//     public:
//     float distance;
//     Level level;
//     Airlines airlines;

    
//     FlightTicket() = delete;
//     FlightTicket(const float dist, const std::string& lev, const std::string& air){
//         distance = dist;
//         level = level_map.at(lev);
//         airlines = airlines_map.at(air);
//     }
//     // friend class FlightTicketSystem;
//     // friend class Delta;
//     // friend class United;
//     // friend class LuigiAir;
//     // friend class SouthWest;
// };

// class FlightTicketSystem{
//     //needs input flight ticket, 
//     //computes and returns cost for a flight
//     public:
//     // create static instance from airlines
//     static FlightTicketSystem* Instance(const Airlines airl);

//     float getOperationsCost(const FlightTicket& ticket)const {
//         float operations_cost = 0;
//         if(ticket.level == Level::Economy){
//             operations_cost = 10 + ticket.distance * 0.2;
//         }else if(ticket.level == Level::Business){
//             operations_cost = 25 + ticket.distance * 0.25;
//         }else if(ticket.level == Level::Premium){
//             operations_cost = 50+ ticket.distance*0.5;
//         }

//         return operations_cost;
        
//     }

//     virtual float getTicketPrice(const FlightTicket& ticket) const = 0;

// };

// FlightTicketSystem*  FlightTicketSystem::Instance(const Airlines air){
    
//     switch(air){
//         case Airlines::Delta:{
//             return Delta::Instance();
//         }
//         case Airlines::LuigiAir:{
//             return LuigiAir::Instance();
//         }
//         case Airlines::SouthWest:{
//             return SouthWest::Instance();
//         }   
//         case Airlines::United:{
//             return United::Instance();
//         }
//     };

//     Type type = Type.GetType(DtoSelection.dto1.ToString());
//     var temp = Activator.CreateInstance(type);

//     return nullptr;
// }

// class Delta:public FlightTicketSystem{

//     public:
//     static Delta* instance_;

//     static Delta* Instance(){
//         if(!instance_){
//             instance_ = new Delta();
//         }
//         return instance_;
//     }

//     float getTicketPrice(const FlightTicket& ticket) const override{
//         return getOperationsCost(ticket) + 0.75*ticket.distance;
//     }

// };

// class United: public FlightTicketSystem{
//  public:
//     static United* instance_;
//     static United* Instance(){
//         if(!instance_){
//             instance_ = new United();
//         }
//         return instance_;
//     }
//     float getTicketPrice(const FlightTicket& ticket) const override{
//         return getOperationsCost(ticket) + 0.85*ticket.distance;
//     }
// };

// class SouthWest: public FlightTicketSystem{
//  public:
//     static SouthWest* instance_;
//     static SouthWest* Instance(){
//         if(!instance_){
//             instance_ = new SouthWest();
//         }
//         return instance_;
//     }
//     float getTicketPrice(const FlightTicket& ticket) const override{
//         return getOperationsCost(ticket) + 0.75*ticket.distance + 100;
//     }

// };

// class LuigiAir: public FlightTicketSystem{
//      public:
//     static LuigiAir* instance_;
//     static LuigiAir* Instance(){
//         if(!instance_){
//             instance_ = new LuigiAir();
//         }
//         return instance_;
//     }
//     float getTicketPrice(const FlightTicket& ticket) const override{
//         return getOperationsCost(ticket) + 0.75*ticket.distance + 100;
//     }

// };


// Delta* Delta::instance_ = nullptr;
// United* United::instance_ = nullptr;
// SouthWest* SouthWest::instance_ = nullptr;
// LuigiAir* LuigiAir::instance_ = nullptr;

// std::vector<std::string> parseString(std::string input_string){

//     std::stringstream sstr(input_string);
//     std::vector<std::string> vec{};

//     std::string temp;
//     while(temp>>sstr){
//         vec.push_back(temp);
//     }
//     return vec;
// }

// int main(){



//     std::vector<std::string> input_tickets {"United 150.0 Premium", "United 120.0 Economy",
//      "United 100.0 Business", "Delta 60.0 Economy",
//      "Delta 60.0 Premium", "Delta 60.0 Business", 
//      "SouthWest 1000.0 Economy", "SouthWest 4000.0 Economy",
//      "SouthWest 4000.0 Economy hhhhhhhh", "LuigiAir 50.0 Business"};  

//      for(auto& it:input_tickets){
//          // parse string
//          std::vector<std::string> vec = parseString(it);
//          //vec[0] = string airlines, 1- distance, 2-level
//         // Create instance of 
//         FlightTicket tkt(strtof(vec[1]), vec[2], vec[0]);
//         FlightTicketSystem* ticksys;
//         //ticksys->Instance(vec[0]);
//         ticksys->Instance(tkt.level);
//         std::cout<<  ticksys->getTicketPrice(tkt) << " for "<< tkt.airlines <<" " << tkt.level <<" " << tkt.distance<<std::endl;
       
//      }



//     return 0;
// }
