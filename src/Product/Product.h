#pragma once

#include <string>
#include <vector>

using namespace std;

class Product {
private:
	string id;
	string name;
	int price;
	int quantity;

public:
	Product(string id, string name, int price, int quantity);

	string get_id();
	void set_id(string id);

	string get_name();
	void set_name(string name);

	int get_price();
	void set_price(int price);
	
	int get_quantity();
	void decrease_quantity(int quantity);
	void increase_quantity(int quantity);

	~Product();
};

