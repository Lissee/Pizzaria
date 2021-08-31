#include <iostream>
#include <string>
#include "Pizzas.h"
using namespace std;

int main() {
    Order pizza;
    string check;

    cout << "Hello!" << endl;
    cout << "Welcome to the pizzeria!" << endl << endl;
    pizza.New_pizza();

    cout << "We are waiting for your return. "
            "\nBon appetit!^^"<< endl;

    return 0;
}
