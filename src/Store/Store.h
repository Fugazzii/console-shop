#pragma once

#include "../Product/Product.h"
#include "../Trade/Trade.h"

#include <unordered_map>
#include <string>

using namespace std;

class Store {
private:
	unordered_map<string, Product*> stock;
	vector<Trade*> history;

	int balance;
	
	bool is_in_stock(string product_id);

public:
	Store(int initial_balance);

	void save_product(string product_id, string name, int price);
	void purchase_product(string product_id, int quantity, int price);
	void order_product(string product_id, int quantity);
	
	int get_quantity_of_product(string product_id);
	float get_average_price(string product_id);
	int get_product_profit(string product_id);
	
	Product get_fewest_product();
	Product get_most_popular_product();

	~Store() {};
};

