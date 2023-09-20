#pragma once

#include <string>

using namespace std;

class Trade {
private:
	string product_id;
	int price;
	int quantity;

public:
	Trade(string product_id, int price, int quantity);
	
	string get_id();

	int get_price();

	int get_quantity();

	~Trade() {}
};