#include "Item.h"

Items::Items(string n, double p, int q){
    name = n;
    price = p;
    quantity = q;
}
void Items::set_price(double p){
    price = p;
}
void Items::set_quantity(int q){
    quantity = q;
}
void Items::set_name(string n){
    name = n;
}
double Items::get_price(){
    return price;
}
int Items::get_quantity(){
    return quantity;
}
string Items::get_name(){
    return name;
}
void Items::reduceQuantity(int q){
    quantity -= q;
}
void Items::addQuantity(int q){
    quantity += q;
}
