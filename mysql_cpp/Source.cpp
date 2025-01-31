#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
#include<vector>

const short LIMITENOMBRES = 30;


struct stream {
	std::fstream script; 
	std::string line; 
};

struct typeDB {
	std::string name;
	short numTables; 
	std::vector<std::string> tableNames;
};




void createDatabase(std::string name) { 
	std::string CreDB = "CREATE DATABASE";
	std::string UseDB = "USE";
	std::fstream scriptSQL;
	std::string line;
	scriptSQL.open("script.sql", { std::ios::out | std::ios::trunc });
	scriptSQL << CreDB << " " << name << ";\n";
	scriptSQL << UseDB << " " << name << ";\n";

}

void createTable(std::string tableName) {
	std::string CreTB = "CREATE TABLE";
	std::string cierres[2] = { "(\n",");\n" };
	std::fstream scriptSQL;
	std::string line;
	scriptSQL.open("script.sql", { std::ios::out | std::ios::app });
	scriptSQL << CreTB << " " << tableName << cierres[0];
	scriptSQL << cierres[1];
}

void main() {
	bool isOff = false;
	std::string userInput;
	typeDB userInfo;  
 	while (!isOff) { 
		system("CLS");
		std::cout << "Bienvenido, inserte el nombre de la base de datos que quieres crear:  ";
		std::cin >> userInput;
		while (userInput.length() > LIMITENOMBRES)
		{
			std::cout << "Porfavor introduce un nombre menor a 30 caracteres";
			std::cin >> userInput;
		}
		userInfo.name = userInput;
		std::cout << "Introduce la cantidad de tablas que quieres crear:  ";
		std::cin >> userInput;
		//AÑADIR VERIFICACIÓN
		userInfo.numTables = std::stoi(userInput); 
			for (int i = 0; i < userInfo.numTables; i++)
			{
				std::cout << "Introduce el nombre de la tabla " << i << ": ";
				std::cin >> userInput;
				//AÑADIR VERIFICACIÓN
				userInfo.tableNames.push_back(userInput);
			}

		createDatabase(userInfo.name);
		for (int i = 0; i < userInfo.numTables; i++)
		{
		createTable(userInfo.tableNames[i]); 
		}
		isOff = true;
		
	}
}