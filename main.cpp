#include<iostream>
#include<cmath>

#define PI 3.14159265358979
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
		~Field(){delete[] value;}
		

		double getV_X(){return value[0];}
		double getV_Y(){return value[1];}
		double getV_Z(){return value[2];}

		void setV_X(double vx){value[0] = vx;}
		void setV_Y(double vy){value[1] = vy;}
		void setV_Z(double vz){value[2] = vz;}

		double magnitude(){

			double total = 0;

			for (int i = 0; i < 3; i++){

				total += pow(value[i], 2);
			}

			return sqrt(total);

		}

		void printMagnitude(){

			std::cout << "Magnitude: " << this->magnitude() << std::endl;
		}
		
};

class Electric_Field : public Field {

	
	private:
		double E;
	
		
	public:
	
		Electric_Field() : Field(){}
		Electric_Field(double ex, double ey, double ez) : Field(ex, ey, ez){}

		void Find_E_Field(double charge, double distance){

			E = charge/(4*PI*pow(distance, 2)*E0);

		}

		

		double E_Field(){
			return E;
		}
		
};

class Magnetic_Field : public Field{

	private:
		double B;
	
		public:

		Magnetic_Field() : Field(){}
		Magnetic_Field(double mx, double my, double mz) : Field(mx, my, mz){}
		void Find_B_Field(double current, double distance){
			B = (current*MU0)/(2*PI*distance);
		}


		double B_Field(){
			return B;
		}
		
};



int main(){

	double magnitude;
	
	Electric_Field E_default;
	Electric_Field E_components(1e5, 10.9, 1.7e2);
	E_components.Find_E_Field(10, 0.25);
	
	Magnetic_Field M_default;
	Magnetic_Field M_components(1e5, 10.9, 1.7e2);
	M_components.Find_B_Field(10, 0.25);

	std::cout << E_components << std::endl;
	E_components.printMagnitude();
	std::cout << "Electric Field " << E_components.E_Field() << std::endl;

	M_components.printComponents();
	M_components.printMagnitude();
	std::cout << "Magnetic Field " << M_components.B_Field() << std::endl;

	return 0;

}
