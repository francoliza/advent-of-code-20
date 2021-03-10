#include<iostream>
#include<vector>
#include<string>
#include<fstream>

int main(){
	std::ifstream myFile("input.txt");
	std::vector<int> numbers;
	std::string line;
	std::ofstream output("output.txt");


	for (int result; std::getline(myFile, line); result = std::stoi(line)) {
		numbers.push_back(result);
	}
	
	for (int i = 0; i < numbers.size(); i++) {
		for (int j = i; j < numbers.size(); j++) {
			if (numbers[i] + numbers[j] == 2020) {
				output << numbers[i] * numbers[j];	
				std::cout << "Parte 1: " << numbers[i] * numbers[j] << std::endl;
				continue;
			}
		}	
	}

	for (int i = 0; i < numbers.size(); i++) {
		for (int j = i; j < numbers.size(); j++) {
			for (int h = j; h < numbers.size(); h++) {
				if(numbers[i] + numbers[j] + numbers[h] == 2020) {	
					output << numbers[i] * (numbers[j] * numbers[h]) << std::endl;
					std::cout << "Parte 2: " << numbers[i] * (numbers[j] * numbers[h]) << std::endl;
					continue;
				}	
			}
		}
	}

	myFile.close();
	output.close();
	return 0;
}
