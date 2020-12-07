#include <iostream>
#include <fstream>
#include <string>
#include "Queue.h"
#include "MergeSort.h"
#include <chrono> 
using namespace std::chrono;
using namespace std;
void main() {
	ifstream read;
	string year;
	string level1;
	string level2;
	string population;
	PriorityQueue queue;
	read.open("singapore-residents-by-age-group-ethnic-group-and-sex-end-june-annual.csv");
	if (!read.is_open()) {
		cout << "Problem opening the file " << endl;
		return;
	}
	auto start = high_resolution_clock::now();
	while (!read.eof()) {
		getline(read, year, ',');
		getline(read, level1, ',');
		getline(read, level2, ',');
		getline(read, population);
		bool isNum = true;
		for (int i = 0; i < population.length(); i++) {
			if (!std::isdigit(population[i])) {
				isNum = false;
				break;
			}
		}
		if (isNum) {
			queue.insert(std::stoi(population));
		}
	}
	read.close();
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);	
	
	cout << "Queue: Time taken by function: "
		<< duration.count() << " milliseconds" << endl;	
		
	// To print Queue, uncomment the below line
	//queue.show();

	int* arr = new int[queue.getSize()];

	read.open("singapore-residents-by-age-group-ethnic-group-and-sex-end-june-annual.csv");
	if (!read.is_open()) {
		cout << "Problem opening the file " << endl;
		return;
	}
	int i = 0;
	while (!read.eof()) {
		getline(read, year, ',');
		getline(read, level1, ',');
		getline(read, level2, ',');
		getline(read, population);
		bool isNum = true;
		for (int i = 0; i < population.length(); i++) {
			if (!std::isdigit(population[i])) {
				isNum = false;
				break;
			}
		}
		if (isNum) {
			arr[i] = std::stoi(population);
			i++;
		}
	}	
	read.close();
	start = high_resolution_clock::now();
	mergeSort(arr, 0, i - 1);
	stop = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(stop - start);
	cout << "\nArray: Time taken by Merge Sort function: "
		<< duration.count() << " milliseconds" << endl;
	cout << "\nNo. of rows in the CSV file(singapore-residents-by-age-group-ethnic-group-and-sex-end-june-annual.csv) : " << i << endl;
	
	// Print the elements of the array
	cout << "\nPopulation Array in Sorted Order : ";
	show(arr, i);

	std::ofstream sortedFile;
	sortedFile.open("sortedData.csv");
	
	sortedFile << "year,level1,level2,population\n";
	
	for (int j = 0; j < i; j++)
	{
		read.open("singapore-residents-by-age-group-ethnic-group-and-sex-end-june-annual.csv");
		while (!read.eof()) {
			getline(read, year, ',');
			getline(read, level1, ',');
			getline(read, level2, ',');
			getline(read, population);
			bool isNum = true;
			for (int j = 0; j < population.length(); j++) {
				if (!std::isdigit(population[j])) {
					isNum = false;
					break;
				}
			}
			if (isNum) {

				if (arr[j] == stoi(population))
				{
					sortedFile << year << "," << level1 << "," << level2 << "," << population << "\n";

					read.close();
					break;
				}
			}
		}
	}
	sortedFile.close();
}