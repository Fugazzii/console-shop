#include <iostream>
#include "./Store/Store.h"
#include "./Command/Command.h"

using namespace std;

int main() {
    Store* spar = new Store(1000);
    Command* command_handler = new Command(spar);
    string user_input;

    while (true) {
        cout << ">> ";
        getline(cin, user_input);
        command_handler->execute(user_input);
        cout << "Command executed!\n";
    }

    delete spar;

    return 0;
}
