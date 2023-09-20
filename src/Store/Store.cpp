#include "Store.h"
#include <iostream>

using namespace std;

Store::Store(int initial_balance) {
	this->balance = initial_balance;
	this->stock = {};
	this->history = {};
}

bool Store::is_in_stock(string product_id) {
	return this->stock.count(product_id) > 0;
}

void Store::save_product(string product_id, string name, int price) {
	Product* new_product = new Product(product_id, name, price, 1);
	this->stock[product_id] = new_product;
	cout << "New product has been added\n";
}

void Store::purchase_product(string product_id, int quantity, int price) {
	Product* requested_product = this->stock[product_id];
	
	if (requested_product->get_quantity() <= 0) {
		cout << "No products found!\n";
		return;
	}
	else if (requested_product->get_quantity() < quantity) {
		cout << "Not enough product!\n";
		return;
	}
	else {
		requested_product->decrease_quantity(quantity);		
		Trade* new_trade = new Trade(product_id, price, quantity);
		this->history.push_back(new_trade);
		this->balance += quantity * price;
	}
}

void Store::order_product(string product_id, int quantity) {
	/* Add product in stock, decrease balance */

	if (this->is_in_stock(product_id)) {
		Product* ordered = this->stock[product_id];
		ordered->increase_quantity(quantity);
		this->balance -= ordered->get_price() * quantity;
	}
	else {
		cout << "Failed to order product. Not in stock\n";
	}
	
}

int Store::get_quantity_of_product(string product_id) {
	if (this->is_in_stock(product_id)) {
		return this->stock[product_id]->get_quantity();
	}
	else {
		cout << "This product is not in stock\n";
		return 0;
	}
}

float Store::get_average_price(string id) {
	int quantity = 0, sum_price = 0;

	for (Trade* t : history) {
		if (t->get_id() == id) {
			quantity += t->get_quantity();
			sum_price += t->get_price() * t->get_quantity();
		}
	}

	return (float) sum_price / quantity;
}

int Store::get_product_profit(string id) {
	int profit = 0;
	if (this->is_in_stock(id)) {
		Product* product = this->stock[id];
		int total = product->get_quantity() * product->get_price();
		for (Trade* t : history) {
			if (t->get_id() == id) {
				total -= t->get_quantity() * t->get_price();
			}
		}
		profit = total;
	}
	return profit;
}

Product Store::get_fewest_product() {
	if (stock.empty()) {
		cout << "No products in stock.\n";
		return Product("", "", 0, 0);
	}

	auto min_prod = stock.begin()->second;
	for (const auto& pair : stock) {
		if (pair.second->get_quantity() < min_prod->get_quantity()) {
			min_prod = pair.second;
		}
	}

	return *min_prod;
}

Product Store::get_most_popular_product() {
	if (history.empty()) {
		cout << "No purchase history available.\n";
		return Product("", "", 0, 0);
	}

	unordered_map<string, int> quantity_map;
	for (Trade* trade : history) {
		quantity_map[trade->get_id()] += trade->get_quantity();
	}

	int max_quantity = 0;
	string max_prod_id;
	for (const auto& pair : quantity_map) {
		if (pair.second > max_quantity) {
			max_quantity = pair.second;
			max_prod_id = pair.first;
		}
	}

	if (is_in_stock(max_prod_id)) {
		return *stock[max_prod_id];
	}
	else {
		cout << "Most popular product is no longer in stock.\n";
		return Product("", "", 0, 0);
	}
}