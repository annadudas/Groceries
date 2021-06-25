#pragma once
#include "Product.h"

class Household : public Product
{
	string color_;
public:

	Household(string productName, string label, int price, int rating, int isle, string color) : 
		Product(productName, label, price, rating, isle), color_(color) {};
	~Household();

	void print(std::ostream& os);
};

