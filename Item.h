#ifndef ITEM_INCLUDED
#define ITEM_INCLUDED

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Item class
class Items{
    private:
        //variables for the item object
        double price;
        int quantity;
        string name;

    public:
        // Item constructor
        Items(string n, double p, int q);

        //setter functions for item attributes
        void set_price(double p);
        void set_quantity(int q);
        void set_name(string n);

        //getter functions for item attributes
        double get_price();
        int get_quantity();
        string get_name();

        //function to reduce quantity of an item
        void reduceQuantity(int q);

        //function to increase quantity of an item
        void addQuantity(int q);
};

#endif
