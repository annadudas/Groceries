#include "Manager.h"



Manager::Manager()
{
}


Manager::~Manager()
{
	for (int i = 0; i < database.size(); i++) {
		delete database[i];
	}
}

void Manager::readFromFile(std::istream& is)
{
	int type;
	while (is >> type)
	{
		if (type == 1)
		{
			string productName;
			string label;
			int price;
			int rating;
			int isle;
			int energy;
			int expiration;

			is >> productName >> label >> price >> rating >> isle >> energy >> expiration;

			database.push_back(new Food(productName, label, price, rating, isle, energy, expiration));
		}
		else if (type == 2)
		{
			string productName;
			string label;
			int price;
			int rating;
			int isle;
			string color;

			is >> productName >> label >> price >> rating >> isle >> color;

			database.push_back(new Household(productName, label, price, rating, isle, color));
		}
		else
		{
			throw std::invalid_argument("Invalid file format");
		}
	}
}
void Manager::kiirDatabase(std::ostream& os) {
	for (int i = 0; i < database.size();i++) {
		os << "----------------" << std::endl;
		database[i]->print(os);
	}
}

void Manager::kiirWishlist(std::ostream& os) {
	for (int i = 0; i < wishlist.size();i++) {
		os << "----------------" << std::endl;
		database[i]->print(os);
	}
}
void Manager::readFromInput(std::istream & is)
{
	cout << "Please enter your wishlist (separating items with ENTER)\nEnter 'q' when done\n";
	string wishName;
	bool isRunning = true;
	//is >> wishName;
	while (isRunning && is >> wishName)
	{
		if (wishName == string("q")) isRunning = false;
		else {
			bool found = false;
			Product* legmegfelelobb = nullptr;//optimal
			for (int i = 0; i < database.size(); i++)
			{
				if (database[i]->getProductName() == wishName && found == false)
				{
					legmegfelelobb = database[i];
					found = true;
				}
				else if (database[i]->getProductName() == wishName && found == true)
				{
					legmegfelelobb = priority_ == 2 ?
						database[i]->getRating() > legmegfelelobb->getRating() ?
						database[i] :
						legmegfelelobb
						: database[i]->getPrice() < legmegfelelobb->getPrice() ?
						database[i]
						: legmegfelelobb;
				}
			}
			if (found) {
				if (wishlist.size() == 0) wishlist.push_back(legmegfelelobb);
				else {
					for (int i = 0; i < wishlist.size(); i++)
					{
						if (wishlist[i]->getIsle() > legmegfelelobb->getIsle())
						{
							if (i == 0) wishlist.insert(wishlist.begin(), legmegfelelobb);
							else wishlist.insert(wishlist.begin() + i - 1, legmegfelelobb);
							break;
						}
						if (i == wishlist.size() - 1) {
							wishlist.push_back(legmegfelelobb);
							break;
						}
					}
				}
			}
			else std::cout << "No such product. Please try again.\n" << std::endl;
			//wishlist.push_back(legmegfelelobb);

		}
	}
}

void Manager::setPriority()
{
	cout << "\n\nPlease choose a priority:\n1: price   |   2: quality rating\n";
	int jo = 0;
	cin >> priority_;
	do
	{
		if (priority_ == 1 || priority_ == 2)
		{
			jo = 1;
		}
		else {
			cout << "Error: priority #" << priority_ << " does not exit\nPlease try again:\n1: price   |   2: quality rating\n";
			cin >> priority_;
		}
	} while (jo = 0);

}

