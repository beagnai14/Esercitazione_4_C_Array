#pragma once
#include <iostream>

using namespace std;


bool ImportVectors(const string& inputFilePath,
                   double& S,
				   size_t& n,
                   double*& w,
                   double*& r);
				   
double DotProduct(const size_t& n,
                        const double* const& w,
                        const double* const& r);

double ValuePortfolio (const size_t& n,
						const double& S,
						const double* const& w,
						const double* const& r);
						
bool ExportResult (const string& outputFilePath,
					const size_t& n,
					const double& S,
					const double* const& w,
					const double* const& r,
					const double& prod,
					const double& V);