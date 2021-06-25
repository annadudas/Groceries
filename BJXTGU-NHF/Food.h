#pragma once
#include "Product.h"

class Food : public Product
{
	int energy_;
	int expiration_;
public:
	Food(string productName, string label, int price, int rating, int isle, int energy, int expiration) : 
		Product(productName, label, price, rating, isle),  energy_(energy), expiration_(expiration) {};
	~Food();

	void print(std::ostream& os);
};

