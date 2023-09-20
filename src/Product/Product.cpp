#include "Product.h"

Product::Product(string id, string name, int price, int quantity) {
	this->id = id;
	this->name = name;
	this->price = price;
	this->quantity = quantity;
}

string Product::get_id() {
	return this->id;
}

void Product::set_id(string id) {
	this->id = id;
}

string Product::get_name() {
	return this->name;
}

void Product::set_name(string name) {
	this->name = name;
}


int Product::get_price() {
	return this->price;
}

void Product::set_price(int price) {
	this->price = price;
}


int Product::get_quantity() {
	return this->quantity;
}

void Product::decrease_quantity(int quantity) {
	this->quantity -= quantity;
}

void Product::increase_quantity(int quantity) {
	this->quantity += quantity;
}



Product::~Product() {}

