#include <iostream>
//using namespace std;
#include <memory>


class Rectangle {
	int length;
	int breadth;

public:
	Rectangle(int l, int b){
		length = l;
		breadth = b;
	}

	int area(){
		return length * breadth;
	}
};

int main(){

	std::shared_ptr<Rectangle> P1 = std::make_shared<Rectangle>(10,5);
	std::cout << P1->area() << std::endl; // This'll print 50

	Rectangle* nP1 = new Rectangle(10,4);
	std::cout<< nP1->area() << std::endl;
	
	

	// unique_ptr<Rectangle> P2(P1);
	std::shared_ptr<Rectangle> P2;
	
    std::cout << P1.get() << std::endl;
    std::cout << P2.get() << std::endl;

	P2 = P1;

    std::cout<<"Count = "<<P2.use_count()<<std::endl;

	// This'll print 50
	std::cout << P2->area() << std::endl;
    std::cout<<"checking p1 again"<<std::endl;
    std::cout << P1.get() << std::endl;
	
	// cout<<P1->area()<<endl;
	return 0;
}
