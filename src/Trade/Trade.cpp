#pragma once

#include <string>
#include "./Trade.h"

using namespace std;

Trade::Trade(string product_id, int price, int quantity) {
	this->product_id = product_id;
	this->price = price;
	this->quantity = quantity;
}

string Trade::get_id() {
	return this->product_id;
}

int Trade::get_price() {
	return this->price;
}

int Trade::get_quantity() {
	return this->quantity;
}