#ifndef HEADER_24GAME
#define HEADER_24GAME

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include <chrono>

void swap(double& a, double& b);

void selectionSort(std::vector<double>& numVec);

void reverseSubVec(std::vector<double>& numVec, int idxFirst, int idxLast);

bool nextPermutation(std::vector<double>& numVec);

void computeSolution(std::vector<double> input, int& count, std::string& solution);

#endif