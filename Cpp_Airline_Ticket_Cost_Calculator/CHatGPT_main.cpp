
// #include<iostream>
// #include<math.h>
// #include<vector>

// //Questions: trivial Polymorphism dynamically typed vs statically 
// // typed (example) 
// //what is the difference between, instance, class and 
// // static methods 
// //(python) python question: given dict {"a": "a", "b": "b"} 
// // does function changes the dictionary. correct answer is yes. what should 
// // we do to not affect the dict? deep copy of the dictionary end.

// // Airline 
// // ticketing system calculate ticketing (cost of operations charges per airline, 
// // and cost ticketing changes per airline) 
// // airline_list = ['United 150.0 Economy', 'Southwest 150.0 Business', 'American 150.0 Premium',] 
// // What if you have 100 airlines with different cost calculations for operations and ticketing. how to tackle this?
// //


// // Flight class generic
// // Abstract class (contains a pure virtual function), cannot be instantiated
// // 

// class InterCityMap{
//     private:
//     std::unordered_map<std::string, std::pair<float, float>> city_lat_long;
//     public:
//     void updateMap(std::string city, float lat, float lon){}

//     float getDistance(std::string city1, std::string city2){
//         // compute distance between 2 cities

//         return 0.0;
//     }

// };

// class Flight{
//     protected:
//     float baseFare, distanceCost;
//     InterCityMap* icmp;

//     public:
//     virtual float calculateFare() = 0;
// };

// class EconomyFlight:public Flight{

//     public: 
//     EconomyFlight(float baseF){
//         this->baseFare = baseF;
//     }
//     float calculateFare() override{
//         return (baseFare + 0.1*baseFare);
//     }
// };

// class BusinessFlight:public Flight{

//     public: 
//     BusinessFlight(float baseF){
//         this->baseFare = baseF;
//     }
//     float calculateFare() override{
//         return (baseFare + 0.2*baseFare);
//     }
// };

// // Ticket class representing a passenger's ticket

// class Ticket{
//     private:
//     Flight* flight;

//     public:
//     // constructur 
//     Ticket(Flight* flight_):flight{flight_}{}
//     //getfare
//     float getFare(){
//         return flight->calculateFare();
//     }
// };

// // TicketCostCalculator class for calculating ticket costs
// class TicketCost{

//     private:
//     std::vector<Ticket> alltickets;
//     public:
//     void addTicket(Ticket tick){
//         alltickets.push_back(tick);
//     }

//     float calculateTotalCost(){
//         float totcost = 0;
//         for(auto it:alltickets){
//             std::cout<< it.getFare()<<std::endl;
//             totcost+= it.getFare();
//         }
//         return totcost;
//     }

// };

// int main()
// {
//     // Input Current City, Destination City, No. of Passengers, Class
//     // create and store a map of cities lat and long position
//     // enter cities map
//     // compute shortest distance between cities
//     // compute fare between cities

//     InterCityMap* icmp;
//     icmp->updateMap("mumbai", 3.0451, 7.0678);
//     icmp->updateMap("chennai", 5.8876, 9.0045);


//     float businessBase = 1000, economyBase = 100;

//     BusinessFlight f1(businessBase);
//     EconomyFlight e1(economyBase);

//     Ticket t1(&f1), t2(&e1);

//     TicketCost totcost;
//     totcost.addTicket(t1);
//     totcost.addTicket(t2);

//     std::cout<< totcost.calculateTotalCost() <<std::endl;

//     return 0;
    
// }