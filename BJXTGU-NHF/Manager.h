#pragma once
#include <vector>
#include <exception>
#include <fstream>
#include "Product.h"
#include "Food.h"
#include "Household.h"


class Manager
{
	int priority_;
	std::vector<Product*> database;
	std::vector<Product*> wishlist;
public:
	Manager();
	~Manager();

	void kiirWishlist(std::ostream& os);
	void readFromFile(std::istream &is);
	void kiirDatabase(std::ostream &os);

	void readFromInput(std::istream &is);
	void setPriority();
};

