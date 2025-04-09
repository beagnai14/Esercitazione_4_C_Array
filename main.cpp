#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "Utils.hpp"

using namespace std;

int main()
{
	string inputFile = "data.txt";
	string outputFile = "result.txt";
	
	double S;
	size_t n;
	double *w = nullptr;
	double *r = nullptr;
	
	ImportVectors(inputFile, S, n, w, r);
	double prod = DotProduct(n, w, r);
	double V = ValuePortfolio(n, S, w, r);
	ExportResult(outputFile, n, S, w, r, prod, V);
	
	delete[] w;
	delete[] r;

    return 0;
}

