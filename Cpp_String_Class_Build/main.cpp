
#include<iostream>

using namespace std;

class String{
    public:

    // 1) DEFAULT CONSTRUCTOR
    // 2 ways to initialize default constructor
    // in initializer list or in body of constructor
    // initializer list to initialize members of class
    // some cases inevitable : 
    // eg when we have const int a, or int& mem; we cannot change it in body, therefore need initializer list
    String() : res{nullptr}, len{0} {}
    // assigning to nullptr as no resource is given to string

    // 2) PARAMETERIZED CONSTRUCTIR
    String(const char* ch){
        len = strlen(ch);
        res = new char[len+1];
        strcpy(res,ch);
    }

    // 3) COPY CONSTRUCTOR
    String(const String& str){
        len= str.len;
        res = new char[len + 1];
        strcpy(res, str.res);
    }
    // why const is used here in above 2 constructors?
    // we pass a constant string tehrefore we need const.
    //  we dont want to change the value of the resource accidentally
     
    // why & is used?
    // to pass by reference, as we don't want to create a copy
    // copy constructor will be called when we call the COPY CONSTRUCTOR if no & is used
    // therefore we need to use & 

    // 4) COPY ASSIGNMENT OPERATOR
    // what's diff between copy constructor and copy ass operator
    // constructor called for first time during initialization
    // assignment operator called later as well

    String& operator=(const String& str){
        //check if user did str3 = str3
        // i.e checking for self assignment
        if(this!= &str){
            
            // for str3 = str2, str3 would already have resources
            // therefore to avoid memory leak, delete this resource
            delete[] res;
            //why delete[] and not delete?
            // when we assign memory in new char[] we use array of memory 
            // represented by the bracket, therefore we need to delete the whole array 
            // of memory
            len = str.len;
            res = new char[len+1];
            strcpy(res, str.res);

            return *this;

        }
        //"this" is a pointer refering to the...
        // present object that's called the function

        

    }

    /*
    // Better way for assignment operator CAS idiom : Copy And Swap
    String& operator=(String str){
            Swap( *this, str);

            return *this;
            
        }

    void Swap(String& str1, String& str2){
        std::swap(str1.res, str2.res);
        std::swap(str1.len, str2.len);

        return;
    }
    */

    unsigned int length(){
        return len;
    }

    friend ostream& operator<<(ostream&out, const String& str);
    friend istream& operator>>(istream& in, const String& str);


    // define a destructor
    ~String(){
    if (res){
        delete[] res;
        res = nullptr;
        len = 0;
    }
}
    private:
        char* res;
        uint len;

};
// we are making it global, outside of any class
// why ostream?
// Idea is make << as global and pass "Cout" and "Str" as parameters
// 
ostream& operator<<(ostream& out, const String& str){
    out<<str.res;
    // but res is a private member of the class, and this func is global outside class
    // we need to define this as a friend function;
    // what is a friend function?
    // if we declare this function inside that class then that function can access private members

    return out;
}

istream& operator>>(istream& in, const String& str){
    in>>str.res;

    return in;
}



int main(){

    // User defined string use cases

    String str1; // default constructor
    String str2 = "Hello"; // parameterized constructor
    String str3 = str1; // copy constructor
    str3 = str2; // copy assignment operator
    int len = str2.length();

    //tricky part for << and >> overloading
    // IMP: 
    /*
        when we are doing String str3 = str1;
        the way it works is an object of str3 is created and str1 is the parameter
        
        However cout<<str2 has cout object created defined by STL which we cannot use to override
        with , i.e cannot define << functionality inside cout. therefore we have to employ a different way to override: see above how:
    */
    cout<<str2; // overload << operator
    cin>>str1; // overload >>
    String str5(str1); // taken care by copy constructor
    String str6 = std::move(str2); // move constructor : came from c++ 11
    // concept : str2 resources like res, len is moved to str6 res and len and str2 is killed
    // this is an optimization in C++
    return 0;
}

/*
be thoroughly prepared with pointers and references concepts
inheritance vpointers vtable references
basic above needed for c++

questions like string class inplementation
go ahead, understand and remember this question
you will get it one way or another somehow
pointers concepts
Lot of concepts we had done: 
we have to not only undertsand but also remember 

*/

