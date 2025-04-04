#include "Utils.hpp"
#include "iomanip"
#include "iostream"
#include "fstream"
#include "sstream"

using namespace std;

bool ImportVectors(const string& inputFilePath,
                   double& S,
				   int& n,
                   double*& w,
                   double*& r) 
{			   
	
	ifstream file(inputFilePath);
	if (file.fail())
		return false;
	
	file.ignore(2,';');
	file >> S;
	file.get();   //ignoro il carattere '\n'
	
	file.ignore(2,';');
	file >> n;
	file.get(); 	//ignoro il carattere '\n'	

	string tmp; 	//per saltare le riga di intestazione
	getline(file, tmp); //leggo e non salvo la riga
	
	string line;
	w = new double[n]; 	
	r = new double[n]; 
	char separatore;
	
	for (int i = 0; i < n; i++) {
		getline(file, line);
		stringstream riga(line);
		
		riga >>  w[i]; 
		riga >> separatore;
		riga >> r[i];	
	}
	
	return true;
}

double DotProduct(const int& n,
                  const double* const& w,
                  const double* const& r)
{
	
	double prod = 0.0;
	for (int i = 0; i < n; i++){
		prod += w[i] * r[i];
	}
	
	return prod;
	
}


double VaulePortofolio (const int& n,
						const double& S,
						const double* const& w,
						const double* const& r)
{
	
	double V = 0.0;
	for (int i = 0; i < n; i++){
		V += w[i] * (1 + r[i]);
	}
	
	V = V * S;
	
	return V;
}


bool ExportResult (const int& n,
					const double& S,
					const double* const& w,
					const double* const& r,
					const double& DotProduct,
					const double& VaulePortofolio)
{
		
	ofstream outputFile("result.txt");
	if (outputFile.fail())
		return false;
	
	outputFile << fixed << setprecision(2);
		
	outputFile << "S = " << S << ", n = " << n << endl;
	
	//output w
	outputFile << "w = [ ";
	for (int i = 0; i < n; i++) {
		outputFile << w[i] << " ";
	}
	outputFile << "]" << endl;
	
	
	//output r
	outputFile << "r = [ ";
	for (int i = 0; i < n; i++) {
		outputFile << r[i] << " ";
	}
	outputFile << "]" << endl;
	
	double rate_R = DotProduct;
	outputFile << "Rate of return of the portfolio: " << rate_R << endl;
	
	double Value_P = VaulePortofolio;
	outputFile << "V: " << Value_P << endl;
	
	return true;
}
