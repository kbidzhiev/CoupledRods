//============================================================================
// Name        : Coupled_Rods.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include <vector>
#include <fstream>
#include <cmath>
using namespace std;


//x''+x==0;
const double L = 11;
const double T = 10;
const double dt = 0.1;

int main() {

	ofstream Data; //here I'm defining output streams, i.e. files
	ios_base::openmode mode;
	mode = std::ofstream::out; //Erase previous file (if present)
	string filename = "Data.dat";
	Data.open("Data/"+filename, mode);
	Data.precision(15);


	vector<double> X(L,1.0);
	for (size_t i = 0; i < X.size(); ++i){
		double R = X.size();
		double pos = i - R/2 + 0.5;

		X[i] = sqrt(R*R/4 - pos*pos);
	}
	//X[X.size()/2] = 0.5;
	vector<double> P(L,0.0);

	const int N_steps = T/dt;
	for (int n = 0; n < N_steps; ++n){
		for (size_t i = 1; i < P.size() - 1; ++i){
			X[i] = X[i] - dt * P[i];
			P[i] = P[i] + dt * ( X[i+1] + 2*X[i] + X[i-1]);
		}

		if (true){
			Data << "\"t = " << n*dt << "\"\n";
			int position = 1;
			for (auto elem : X){
				Data << position++ << "\t" << elem  <<"\t"<< dt * n <<"\n";
			}
			Data <<"\n\n";

		}
		//cout << endl;
	}


	return 0;
}
