#include<iostream>
#include<math.h>
#include<memory>

template<class T>
class Shared_ptr{
private:
  T *p = nullptr;
  uint* nResCount = nullptr;
public:
  
  uint getResCount(){
	 return nResCount==nullptr?0:*nResCount;
    //return *nResCount;
  }

  Shared_ptr():p(nullptr),nResCount(new uint(0)){
    std::cout<<"Default constructor"<<std::endl;
  }

  Shared_ptr(T* ptr):p(nullptr){
    this->nResCount = new uint(1);
    this->p = ptr;
    std::cout<<"Parameterized constructor"<<std::endl;
  }

  // copy constructor
  Shared_ptr(Shared_ptr &p1){
    
    this->p = p1.p;
    this->nResCount = p1.nResCount;
    if(p1.p!=nullptr)
      (*this->nResCount)++;
    std::cout<<"Copy constructor"<<std::endl;
  }

  //copy assignment operator
  Shared_ptr& operator=(Shared_ptr &p1){
    this->p = p1.p;
    this->nResCount = p1.nResCount;
    if(p1.p!=nullptr)
      (*this->nResCount)++;
    std::cout<<"Copy Assignment Operator"<<std::endl;
    return *this;
  }

  //Move constructor
  Shared_ptr(Shared_ptr&& p1){
    // dont increase count here
    this->p = p1.p;
    this->nResCount = p1.nResCount;
    p1.p = nullptr;
    p1.nResCount = nullptr;
    std::cout<<"Move constructor"<<std::endl;
  }

  //Move assignment operator
  Shared_ptr& operator=(Shared_ptr&& p1){
    // dont increase count here
    this->p = p1.p;
    this->nResCount = p1.nResCount;
    p1.p = nullptr;
    p1.nResCount = nullptr;
    std::cout<<"Move Assignment Operator"<<std::endl;
    return *this;
  }

  //overload the * operator
  T& operator*(){
	  std::cout<<"overloading * "<<std::endl;
    return *p;
  }

  //overload the -> operator
  T* operator->(){
	  std::cout<<"overloading ->"<<std::endl;
    return p;
  }
  
  ~Shared_ptr(){
    if(nResCount!=nullptr){
      (*this->nResCount)--;
      if(*this->nResCount==0){
        if(p!=nullptr)
          delete p;
        delete nResCount;
        std::cout<<" Destroyed all memory"<<std::endl;
      }
    }
      
  }

  // parameterized


};
// how to initialize static variable inside template class
// template<class T>
// int Shared_ptr<T>::nResCount = 0;

int main(){

// Test Default Constructur
{
	Shared_ptr<int> sp1;
	assert(sp1.getResCount() == 0);
}

//Test Parameterized Constructor
{
	int* ptr = new int(42);
	Shared_ptr<int> sp2(ptr);
	assert(sp2.getResCount() == 1);
}

//Test Copy Constructor
{
	int* ptr = new int(42);
	Shared_ptr<int> sp1(ptr);
	Shared_ptr<int> sp2(sp1);
	assert(sp1.getResCount() == 2);
	assert(sp2.getResCount() == 2);

}

//Test Copy Assignment Operator
{
	int* ptr = new int(42);
	Shared_ptr<int> sp1(ptr);
	Shared_ptr<int> sp2;
	sp2 = sp1;
	assert(sp1.getResCount() == 2);
	assert(sp2.getResCount() == 2);

}

//Test Move Constructur
{
	int* ptr = new int(42);
	Shared_ptr<int> sp1(ptr);
	Shared_ptr<int> sp2(std::move(sp1));
	assert(sp1.getResCount() == 0);
	assert(sp2.getResCount() == 1);
}

//Test Move Assignment Operator
{
	int* ptr = new int(42);
	Shared_ptr<int> sp1(ptr);
	Shared_ptr<int> sp2;
	sp2 = std::move(sp1);
	assert(sp1.getResCount() == 0);
	assert(sp2.getResCount() == 1);

}

//Test Overload
{
	int* ptr = new int(42);
	Shared_ptr<int> sp1(ptr);
	assert(*(sp1) == 42);
}

// Test Arrow
{
	struct Test {
  int val;
  Test(int val): val(val) {}
};
Shared_ptr<Test> sp1(new Test(42));
assert(sp1->val == 42);

}






//   int *p = new int;
//   *p = 100;

//   Shared_ptr<int> sp1(p);
//   //std::cout<<"count = "<< sp1.getResCount()<<std::endl;
//   *sp1 = 122;

// //Test Copy Constructor
//   Shared_ptr<int> sp2(sp1);
//   //std::cout<<"count = "<< sp1.getResCount()<<std::endl;
//   //std::cout<<" sp1 val = "<< *sp1<<" "<<*sp2<<std::endl;

// // Test Copy assignment
//   Shared_ptr<int> sp3;
//   sp3 = sp1;

// // Test Move Constructur
//   Shared_ptr<int> sp4 = std::move(sp1);

// // Test Move Assignment operator
//   Shared_ptr<int> sp5;
//   sp5 = std::move(sp2);

//   //std::cout<< 

  
  return 0;
}