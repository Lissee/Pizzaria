#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Pizzas {
protected:
    string name[4] = {"MARGARET", "CHEESE CHICKEN", "MEXICAN", "PEPPERONI"};
    string text[4] = {"increased portion of mozzarella,tomatoes, Italian herbs, tomato sauce",
                      "chicken, mozzarella,cheese sauce, tomatoes",
                      "spicy chicken, hot jalapeno pepper,salsa sauce, tomatoes,"
                      "\n sweet pepper, red onion, mozzarella, tomato sauce",
                      "Spicy pepperoni, an increased portion of mozzarella, tomato sauce"};
    double min_price[4] = {4.24, 3.99, 4.99, 4.56};
    unsigned short size[4] = {25, 30, 35, 40};

public:
   virtual void Price () = 0;

    Pizzas () = default;
    ~Pizzas() = default;

};


class Order :Pizzas {
private:
    const unsigned short max_cheese = 5;
    const unsigned short max_salt = 3;
    const string salt_name = "salt";
    const string cheese_name = "cheese";

    unsigned short salt, cheese;
    char check;

    vector <double> total_price;
    vector<unsigned short> cheque;

    //Проверка корректного ввода данных
    char Check() {
        while (check!='+' && check!='-') {
            cout << "Error! Please repeat the order:" << endl;
            cin >> check;
        }
        return check;
    }

    short Check(short value) {
        while (value!=0 && value!=1 && value!=2 && value!=3) {
            cout << "Error! Please repeat the order:" << endl;
            cin >> value;
        }
        return value;
    }

//Хотите сыр и/или соль?
    unsigned short More(unsigned short product, string name_product, unsigned short max_product){
        product = 0;
        check = '+';
        cout << "--------------------------------------------------------------------------------------------" <<endl;
        cout << "Do you want to add "<< name_product <<"?"<< endl;
        cout << "|(+) yes |(-) no|";
        while (check == '+') {
            cin >> check;
            check = Check();
            if (check == '+') {
                product += 1;
                if (product < max_product ) {
                    cout << "More " << name_product << "?" << endl;
                    cout << "|(+) yes |(-) no|";
                } else {check = '-';}
            }
        }
        return product;
    }

    // Цена одной пиццы:
    void Price ()
    {
        total_price.emplace_back(min_price[x] + ((double)size[y]/25 - 1) + cheese * (0.22 + ((double)size[y]/25 - 1)) + salt * (0.11 + ((double)size[y]/25 - 1)));
    }

    //Чек
    void Print_order () {
        x = 0, y = 0;

        cout << "Order:" <<endl;
        while (x<cheque.size()) {
            cout << "--------------------------------------------------------------------------------------------" <<endl;
            cout << "Pizza: "<< name[cheque[x]] <<" | Size: " << size[cheque[x+1]] <<endl;
            x = x+2;
            cout << "Amount of cheese: "<< cheque[x] <<" | Amount of salt: " << cheque[x+1] <<endl;
            x = x+2;
            cout << "Price: " << total_price[y] << "$" << endl;
            y = y +1;
            if (x<cheque.size()) {total_price[0] = total_price[0] + total_price[y];}
            cout << "--------------------------------------------------------------------------------------------" <<endl; }
        cout << "Final price: " << total_price[0] << "$" << endl <<endl;
        check = '*';
    }

public:
    Order() {
        cheese = 0;
        salt = 0;
        check = '+';
    }
    ~Order () = default;

    int x=0, y = 0;


    //Составляем заказ
    void New_pizza ()
    {
        //Меню
        cout << "Menu:" << endl;
        cout << "--------------------------------------------------------------------------------------------" <<endl;
        x = 0;
        while (x!=4) {
            cout  << "| (" << x << ") " << name[x] << " | " << min_price[x] << "$ - price for a small pizza ("<< size[0] <<")" << endl;
            cout << "| Description: " << text[x] << endl;
            cout << "--------------------------------------------------------------------------------------------" <<endl;
            x = x+1;}

        //Выбор пиццы
        cout << "(to select a pizza, enter its number in the table)"<< endl;
        cout << "Please choose a pizza_ ";
        cin >> x;
        x = Check(x);
        cheque.emplace_back(x);

        //Выбор размера пиццы
        cout << "Choose the size of the pizza:" << endl;
        cout << "--------------------------------------------------------------------------------------------" <<endl;
        cout  << "| (0) " << size[0] << " | (1) "<< size [1] << " | (2) " << size [2] << " | (3) " << size [3] << " |" <<endl;
        cout << "--------------------------------------------------------------------------------------------" <<endl;
        cout << "(to select a size of the pizza, enter its number in the table)"<< endl;
        cin >> y;
        y = Check(y);
        cheque.emplace_back(y);

        //Больше сыра?)
        cheese = More(cheese, cheese_name, max_cheese);
        cheque.emplace_back(cheese);

        //Больше соли?)
        salt = More(salt, salt_name, max_salt);
        cheque.emplace_back(salt);
        Price();
        cout << "--------------------------------------------------------------------------------------------" <<endl<<endl;

        //Еще одну пиццу?
        cout << "Would you like to order another pizza?"<<endl;
        cout << "|(+) yes |(-) no|";
        cin >> check;
        check = Check();
        cout << "--------------------------------------------------------------------------------------------" <<endl<< endl;
        if (check == '+') {New_pizza();}

        //Распечатать чек?
        if (check != '*') {
            cout << "Great! Your order is accepted!"<< endl;
            cout << "Show the cheque?" << endl;
            cout << "|(+) yes |(-) no|";
            cin >> check;
            check = Check();
            cout << "--------------------------------------------------------------------------------------------" <<endl<< endl;
            if (check == '+') {Print_order();
            }else {
                check = '*';
                x=1;
                while (x<total_price.size()) {
                    total_price[0] = total_price[0] + total_price[x];
                    x = x + 1;
                }
                cout << "Final price: " << total_price[0] << "$" << endl <<endl;
            }
        }
            return;
    };
};


#ifndef UNTITLED14_PIZZAS_H
#define UNTITLED14_PIZZAS_H

#endif //UNTITLED14_PIZZAS_H
