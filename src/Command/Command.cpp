#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include "./Command.h"
#include "../Product/Product.h"
#include "../Store/Store.h"

using namespace std;

Command::Command(Store* nikora) {
    this->store = nikora;
}

void Command::execute(string user_input) {
	vector<string> token = this->split(user_input);
    
    if (token.empty()) {
        cout << "No commands found!\n";
        return;
    }

    string command = token[0];
    
    if (command == "exit") {
        system("TASKKILL /F /IM eteam.exe");
    }

    if (command == "save_product") {
        // Check if the command has the correct number of arguments
        if (token.size() == 4) {
            string product_id = token[1];
            string name = token[2];
            int price = stoi(token[3]);
            this->store->save_product(product_id, name, price);
        }
        else {
            // Handle incorrect number of arguments for the command
            cout << "Invalid number of arguments for save_product command." << endl;
        }
    }
    else if (command == "purchase_product") {
        // Check if the command has the correct number of arguments
        if (token.size() == 4) {
            string product_id = token[1];
            int quantity = stoi(token[2]);
            int price = stoi(token[3]);
            this->store->purchase_product(product_id, quantity, price);
        }
        else {
            // Handle incorrect number of arguments for the command
            cout << "Invalid number of arguments for purchase_product command." << endl;
        }
    }
    else if (command == "order_product") {
        // Check if the command has the correct number of arguments
        if (token.size() == 3) {
            string product_id = token[1];
            int quantity = stoi(token[2]);
            this->store->order_product(product_id, quantity);
        }
        else {
            // Handle incorrect number of arguments for the command
            cout << "Invalid number of arguments for order_product command." << endl;
        }
    }
    else if (command == "get_quantity_of_product") {
        // Check if the command has the correct number of arguments
        if (token.size() == 2) {
            string product_id = token[1];
            int quantity = this->store->get_quantity_of_product(product_id);
            cout << "Quantity of product " << product_id << ": " << quantity << endl;
        }
        else {
            // Handle incorrect number of arguments for the command
            cout << "Invalid number of arguments for get_quantity_of_product command." << endl;
        }
    }
    else if (command == "get_average_price") {
        // Check if the command has the correct number of arguments
        if (token.size() == 2) {
            string product_id = token[1];
            float average_price = this->store->get_average_price(product_id);
            cout << "Average price of product " << product_id << ": " << average_price << endl;
        }
        else {
            // Handle incorrect number of arguments for the command
            cout << "Invalid number of arguments for get_average_price command." << endl;
        }
    }
    else if (command == "get_product_profit") {
        // Check if the command has the correct number of arguments
        if (token.size() == 2) {
            string product_id = token[1];
            int profit = this->store->get_product_profit(product_id);
            cout << "Profit of product " << product_id << ": " << profit << endl;
        }
        else {
            // Handle incorrect number of arguments for the command
            cout << "Invalid number of arguments for get_product_profit command." << endl;
        }
    }
    else if (command == "get_fewest_product") {
        // Check if the command has the correct number of arguments
        if (token.size() == 1) {
            Product fewest_product = this->store->get_fewest_product();
            cout << "Fewest product:" << endl;
            cout << "Product ID: " << fewest_product.get_id() << endl;
            cout << "Name: " << fewest_product.get_name() << endl;
            cout << "Price: " << fewest_product.get_price() << endl;
        }
        else {
            // Handle incorrect number of arguments for the command
            cout << "Invalid number of arguments for get_fewest_product command." << endl;
        }
    }
    else if (command == "get_most_popular_product") {
        // Check if the command has the correct number of arguments
        if (token.size() == 1) {
            Product most_popular_product = this->store->get_most_popular_product();
            cout << "Most popular product:" << endl;
            cout << "Product ID: " << most_popular_product.get_id() << endl;
            cout << "Name: " << most_popular_product.get_name() << endl;
            cout << "Price: " << most_popular_product.get_price() << endl;
        }
        else {
            // Handle incorrect number of arguments for the command
            cout << "Invalid number of arguments for get_most_popular_product command." << endl;
        }
    }

}

vector<string> Command::split(string& user_input) {
	vector<string> result;
	string current = "";
	for (char c : user_input) {
		if (c == ' ') {
            cout << current << endl;
			result.push_back(current);
			current = "";
		}
		else {
			current += c;
		}
	}

    if (current != "") {
        result.push_back(current);
    }

	return result;
}