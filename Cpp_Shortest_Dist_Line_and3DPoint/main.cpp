// Shortest distance between a line and a point in 3d frame
#include<iostream>
#include<vector>
#include<string>
#include<vector>

class Vector{
	public:

	int x, y, z;
	Vector():x{0},y{0},z{0}{}
	Vector(int x_, int y_, int z_):x{x_}, y{y_}, z{z_}{}

	Vector ToVector(const Vector& b){
		Vector ans;
		ans.x = b.x - this->x;
		ans.y = b.y - this->y;
		ans.z = b.z - this->z;
		return ans;
	}

	Vector CrossProduct(const Vector &b ){
		// this cross b
		// i j k
		// x y z -2 0 0 
		// l m n - 1 1 0   0i +0 j -2k
		Vector ans;
		ans.x = this->y * b.z - this->z * b.y;
		ans.y = -(this->x * b.z - this->z * b.x);
		ans.z = this->x * b.y - this->y *b.x;
		return ans;
	}

	float modulo(){
		return sqrt(x*x  + y*y + z*z);
	}



};

// class Line{
// 	// line is of 2 points: 
// 	public:
// 	Point p1, p2;
// 	Line(Point p1_, Point p2_):p1{p1_}, p2{p2_}{

// 	}
// };


int main(){

	Vector a(1,0,0);
	Vector b(-1,0,0);
	Vector pt(0,1,0);

	// D = |AP x d| / |d|

	Vector d = a.ToVector(b);
	Vector ap = a.ToVector(pt);

	std::cout<< (ap.CrossProduct(d)).modulo() / d.modulo()<<std::endl;
	
	return 0;
}

