#include<iostream>
#include<cmath>

class Electric_Field {

	private:
		double *E;

	public:

		// constructor
		Electric_Field(){E = new double[3];
			E[0]=0;
			E[1]=0;
			E[2]=0;}



		Electric_Field(double ex, double ey, double ez){E=new double[3];
			E[0]=ex;
			E[1]=ey;
			E[2]=ez;}

		~Electric_Field(){std::cout<< "Cleared Electric Field"  << std::endl, delete[] E;}


		// deconstructor

		// setter
		double getE_X(){return E[0];}
		double getE_Y(){return E[1];}
		double getE_Z(){return E[2];}
		// getter
		void setE_X(double ex){ex = E[0];}
		void setE_Y(double ey){ey = E[1];}
		void setE_Z(double ez){ez = E[2];}

		double magnitude(){

			double total = 0;

			for (int i = 0; i < 3; i++){

				total += pow(E[i], 2);
			}

			return sqrt(total);

		}

		double inner_product(){
			double total = 0;
			for (int i = 0; i < 3; i++){

				total += pow(E[i],2);

			}

			return total;

		}

};


class Magnetic_Field {

	private:
		double *M;

	public:
		Magnetic_Field(){M = new double[3];
			M[0]=0;
			M[1]=0;
			M[2]=0;}

		Magnetic_Field(double mx, double my, double mz){M=new double[3];
			M[0] = mx;
			M[1] = my;
			M[2] = mz;}

		~Magnetic_Field(){std::cout<< "Cleared Magnetic_Field" << std::endl, delete[] M;}

		double getM_X(){return M[0];}
		double getM_Y(){return M[1];}
		double getM_Z(){return M[2];}
		// getter
		void setM_X(double mx){mx = M[0];}
		void setM_Y(double my){my = M[1];}
		void setM_Z(double mz){mz = M[2];}

		double magnitude_M(){

			double total = 0;

			for (int i = 0; i < 3; i++){

				total += pow(M[i], 2);
			}

			return sqrt(total);

		}

		void unit_vector(){

			double magnitude = magnitude_M();
			double unit_x, unit_y, unit_z;
			for (int i = 0; i < 3; i++){

				unit_x = M[i]/magnitude;
				unit_y = M[i]/magnitude;
				unit_z = M[i]/magnitude;

				std::cout << "Unit Vector: " << unit_x << " " << unit_y << " " << unit_z << std::endl;

			}

		}

};



int main(){

	double magnitude;
	// type output
	Electric_Field E_default;
	Electric_Field E_components(1e5, 10.9, 1.7e2);
	Magnetic_Field M_default;
	Magnetic_Field M_components(1e5, 10.9, 1.7e2);

	magnitude = E_default.magnitude();
	std::cout << "Magnitude of Default Electric Field: " << magnitude << std::endl;
	E_default.inner_product();

	magnitude = E_components.magnitude();
	std::cout << "Magnitude of Electric Field: " << magnitude << std::endl;
	E_components.inner_product();

	magnitude = M_default.magnitude_M();
	std::cout << "Magnitude of Default Magnetic Field: " << magnitude << std::endl;
	M_default.unit_vector();

	magnitude = M_components.magnitude_M();
	std::cout << "Magnitude of Magnetic Field: " << magnitude << std::endl;
	M_components.unit_vector();

	return 0;

}
