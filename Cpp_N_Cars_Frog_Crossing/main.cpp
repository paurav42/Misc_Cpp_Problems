
// There are N lanes, and the speed of each lane is given. 
// There are many cars in each lane. You are given the length of each car, its starting position, and its corresponding lane. There is a 
// frog that can perform two functions — wait() or jump (). 

// Find if there is a path for the frog to go from lane 1 to lane N without getting hit by any of the moving cars.


#include<iostream>
#include<unordered_map>
#include<list>

constexpr int N = 3;
constexpr int dT = 1;
constexpr int MAXCARS = 3;
constexpr int MAXTIME = 65536;
static long long T = 0;

class Lane{
    public: 
    int speed;
    int number;
};

class Car{
    public: 
    Lane* lane;
    int length;
    int starting_pos;
    int curr_pos;
    Car(){}
    Car(int startpos){
        curr_pos = startpos;
        starting_pos = startpos;
    }

    void updateCarPosn(){
        curr_pos += lane->speed * dT;
    }

};
// Assumption frog can jump only forward
// Frog takes 1 second to jump or wait
class Frog{
    public: 
    int currlane = 0;
    int frogPosn;
    //Car* cars = new Car[MAXCARS]; // instead of doing this, I can pass vector of car objects
    std::vector<Car> cars;
    Frog(int frogpos, std::vector<Car> cr):frogPosn{frogpos}, cars{cr}{}

    void wait(){
        // nothing, timer is independently ticking anyways.
    }
    void jump(){
        currlane++;
    }
    bool isCollision(int lanenum){
        for(int i = 0; i<MAXCARS; i++){
            if(cars[i].lane->number == lanenum){
                //check collision with front bumper center as car ref
                if(frogPosn <= cars[i].curr_pos && frogPosn > cars[i].curr_pos - cars[i].length)
                    return true;
            }
            //cars++;
        }
        return false;
    }
    // backtracking problem ??
    bool roadCrosser(){
        // keep running loop while(we dont reach end lane or while we dont reach time limit)

        while(currlane!=N && T<MAXTIME){

            T++;
            for(int i = 0; i<MAXCARS; i++){
                cars[i].updateCarPosn();
            }
            for(int i = 0; i<MAXCARS; i++){
                
                // if current car is one ahead of frog, check collision:
                if(cars[i].lane->number == currlane+1){
                    if(!isCollision(currlane+1)){ 
                    // no collision is happening
                        jump();
                        break;
                    // either wait or jump (simplify, let's just jump)
                    }else{
                        wait();
                    }
                }
                //cars = c2;
                //cars[i].lane++;
            }
        }
        // Timeout 
        if(T>= MAXTIME)
            return false;
        
        // while loop ended as frog's currlane is N
        return true;
    }
};


int main(){
    // wait for all cars to pass and then cross? lol : Not much of a coding problem
    // 
    

    std::cout<<" Enter car details"<<std::endl;
    std::vector<Car> cars;
    for(int i = 0; i< MAXCARS; i++){
       
       std::cout<<"For Car "<< i <<std::endl;
       std::cout<<"Enter initial Position of car "<< std::endl;
       int startingpos = 2+i;
       //std::cin >> startingpos;
       Car car(startingpos);
       Lane* ln = new Lane();
       std::cout<<"Enter size car "<< std::endl;
       //std::cin >> car.length;
       car.length = 2;
       std::cout<<"Enter Car lane number "<< std::endl;
       //std::cin >> ln.number;
        ln->number = i+1;
       std::cout<<"Enter lane number speed"<< std::endl;
       //std::cin >> ln.speed;
       ln->speed = 1;
       car.lane = ln;
       cars.push_back(car);
    }

    Frog fr(5, cars);
    
    std::cout<< "can frog cross road? " << fr.roadCrosser() <<std::endl;
    return 0;
}