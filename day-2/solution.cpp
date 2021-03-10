#include<iostream>
#include<vector>
#include<string>
#include<fstream>

int main() {
	std::ifstream myFile("input.txt");
	std::vector<std::string> lines;
	std::string line;
	std::ofstream output("output.txt");
	int valid = 0;
	int minValue = 0;
	int maxValue = 0;

	if (myFile.is_open()) {
		while (getline(myFile, line)) {
			lines.push_back(line);
		}
		myFile.close();
	} 

	int count2 = 0;	
	for(int i = 0; i < lines.size(); i++) {
		int count = 0;
		minValue = std::stoi(lines[i].substr(0, lines[i].find("-", 0)));
		maxValue = std::stoi(lines[i].substr(lines[i].find("-", 0) + 1, lines[i].find(" ", 0) - 1));

		//Solo falta conseguir la palabra y la letra	
		std::string character = lines[i].substr(lines[i].find(" ", 0) + 1, lines[i].find(" ", 0) - 2);
		std::string word = lines[i].substr(lines[i].find(" ", lines[i].find(" ", 0) + 1) + 1, lines[i].size());
		
		// Contamos la cantidad de caracteres y verificamos que esté en rango
		for(int i = 0; i < word.size(); i++) {
			if(word[i] == character[0]) {
				count++;
			}
		}
	
		if( !(word[minValue - 1] != character[0]) != !(word[maxValue - 1] != character[0]) ) {
			count2++;
		}

		if(minValue <= count && maxValue >= count) {
			valid++;
		}
	}

	output << "Parte 1: " << valid << std::endl;
	output << "Parte 2: " << count2 << std::endl;

	std::cout << "Parte 1: " << valid << std::endl;
	std::cout << "Parte 2: " << count2 << std::endl;
	output.close();
	return 0;
}
