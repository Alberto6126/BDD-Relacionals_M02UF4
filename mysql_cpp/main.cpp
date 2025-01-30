#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
#include<vector>

struct stream {
	std::fstream script; 
	std::string line; 
};

struct typeDB {
	std::string name;
	short numTables; 
	std::vector<std::string> tableNames;
};




void createDatabase() {

}

void main() {
	bool isOff = false;
	std::string userInput;
	typeDB userInfo;  
 	while (!isOff) { 
		system("CLS");
		std::cout << "Bienvenido, inserte el nombre de la base de datos que quieres crear:  ";
		std::cin >> userInput;
		std::cout << "Introduce la cantidad de tablas que quieres crear:  ";
		std::cin >> userInput;
		userInfo.numTables = std::stoi(userInput); 
			for (int i = 0; i < userInfo.numTables; i++)
			{
				std::cout << "Introduce el nombre de la tabla " << i << ": ";
				std::cin >> userInput;
			}


	}
}