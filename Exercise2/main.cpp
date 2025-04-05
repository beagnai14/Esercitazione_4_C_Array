#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "Utils.hpp"

using namespace std;

int main()
{
	cout << fixed << setprecision(2);
	
	string inputFile = "data.txt";
	
	double S;
	int n;
	double *w = nullptr;
	double *r = nullptr;
	
	ImportVectors(inputFile, S, n, w, r);
	double prod = DotProduct(n, w, r);
	double V = VaulePortofolio(n, S, w, r);
	ExportResult(n, S, w, r, prod, V);
	
	delete[] w;
	delete[] r;
	
    return 0;
}

