#include "Product.h"
#include "Product.h"
#include "Food.h"
#include "Manager.h"
#include <iostream>
#include <fstream>
#include <string.h>



int main()
{
	
	Manager mg;
	//
	std::ifstream file("C:\\Users\\dudan\\source\\repos\\BJXTGU-NHF\\BJXTGU-NHF\\Debug\\supply.txt");
	if (!file.is_open()) {
		throw std::logic_error("Nem nyilt meg a file");
	}
	mg.readFromFile(file);
	mg.kiirDatabase(std::cout);
	mg.setPriority();
	mg.readFromInput(std::cin);
	mg.kiirWishlist(std::cout);

	std::cin.get();
	std::cin.get();
	


}