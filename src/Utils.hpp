#pragma once
#include <iostream>

using namespace std;


bool ImportVectors(const string& inputFilePath,
                   double& S,
				   int& n,
                   double*& w,
                   double*& r);
				   
double DotProduct(const int& n,
                        const double* const& w,
                        const double* const& r);

double ValuePortfolio (const int& n,
						const double& S,
						const double* const& w,
						const double* const& r);
						
bool ExportResult (const string& outputFilePath,
					const int& n,
					const double& S,
					const double* const& w,
					const double* const& r,
					const double& prod,
					const double& V);