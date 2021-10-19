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

using namespace std;


//x''+x==0;
const double L = 1;
const double T = 10;
const double dt = 0.01;

int main() {

	ofstream Data; //here I'm defining output streams, i.e. files
	ios_base::openmode mode;
	mode = std::ofstream::out; //Erase previous file (if present)
	string filename = "Data.dat";
	Data.open("Data/"+filename, mode);
	Data.precision(15);


	vector<double> X(L,1);
	vector<double> P(L,0);

	const int N_steps = T/dt;
	for (int n = 0; n < N_steps; ++n){
		for (size_t i = 0; i < P.size(); ++i){
			P[i] = P[i] + dt * X[i];
			X[i] = X[i] - dt * P[i];
		}
		for (auto elem : X){
			Data << dt * n << "\t" << elem  << "\n";
		}
		//cout << endl;
	}


	return 0;
}
