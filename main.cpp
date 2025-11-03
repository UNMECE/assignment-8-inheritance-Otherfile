#include<iostream>
#include<cmath>

#define PI M_PI
#define E0 8.8541878188e-12
#define MU0 4*PI*(pow(10, -7))

class Field {

	protected:
		double *value;

	public:

		
		Field(){value = new double[3];
			value[0]=0;
			value[1]=0;
			value[2]=0;}

		Field(double vx, double vy, double vz) {value = new double[3];
        	value[0] = vx;
        	value[1] = vy;
        	value[2] = vz;
    }
		~Field(){delete[] value; std::cout << "Deconstructor Called" << std::endl;} 
		



		void printMagnitude(){

			std::cout << "Components: " << "X: " << this->value[0] << " Y: " << this->value[1] << " Z: " << this->value[2] << std::endl;
		}
		
};

class Electric_Field : public Field {

	
	private:
		double E;
	
		
	public:
	
		Electric_Field() : Field(){}
		Electric_Field(double ex, double ey, double ez) : Field(ex, ey, ez){}
		~Electric_Field(){}

		void Find_E_Field(double charge, double distance){

			E = charge/(4*PI*pow(distance, 2)*E0);

		}

		double E_Field(){
			return E;
		}
		
		Electric_Field operator+(const Electric_Field &other) const {

			Electric_Field e3;
			e3.value[0] = this->value[0] + other.value[0];
			e3.value[1] = this->value[1] + other.value[1];
			e3.value[2] = this->value[2] + other.value[2];
			return e3;
		}
		friend std::ostream &operator<<(std::ostream &os, const Electric_Field &ef){
			os << "Field: " << ef.E << " X: " << ef.value[0] << " Y: " << ef.value[1] << " Z: " << ef.value[2];
			return os;
		}
};

class Magnetic_Field : public Field{

	private:
		double B;
	
		public:

		Magnetic_Field() : Field(){}
		Magnetic_Field(double mx, double my, double mz) : Field(mx, my, mz){}
		~Magnetic_Field(){};


		void Find_B_Field(double current, double distance){
			B = (current*MU0)/(2*PI*distance);
		}


		double B_Field(){
			return B;
		}
		
		Magnetic_Field operator+(const Magnetic_Field &other) const {

			Magnetic_Field m3;
			m3.value[0] = this->value[0] + other.value[0];
			m3.value[1] = this->value[1] + other.value[1];
			m3.value[2] = this->value[2] + other.value[2];
			return m3;
		}
		friend std::ostream &operator<<(std::ostream &os, const Magnetic_Field &mf){
			os << "Field: " << mf.B << " X: " << mf.value[0] << " Y: " << mf.value[1] << " Z: " << mf.value[2];
			return os;
		}
};



int main(){

	double magnitude;
	
	Electric_Field e1(2.3523e5, 2, 3);
	Electric_Field e2(1e5, 10.9, 1.7e2);
	Electric_Field e3 = e1 + e2;
	e1.Find_E_Field(10, 0.25);
	e2.Find_E_Field(5, 0.75);
	e3.Find_E_Field(15, 1);
	
	Magnetic_Field m1(2.553323563e5, 2, 3);
	Magnetic_Field m2(1e5, 10.9, 1.7e2);
	Magnetic_Field m3 = m1 + m2;
	m1.Find_B_Field(10, 0.25);
	m2.Find_B_Field(5, 0.75);
	m3.Find_B_Field(15, 1);

	

	e1.printMagnitude();
	e2.printMagnitude();
	e3.printMagnitude();

	m1.printMagnitude();
	m2.printMagnitude();
	m3.printMagnitude();

	std::cout << e1 << std::endl;
	std::cout << e2 << std::endl;
	std::cout << e3 << std::endl;

	std::cout << m1 << std::endl;
	std::cout << m2 << std::endl;
	std::cout << m3 << std::endl;


	return 0;

}
