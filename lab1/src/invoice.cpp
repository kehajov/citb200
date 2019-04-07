#include "invoice.h"

void Invoice::add(Product product, int quantity){
    Item item(product, quantity);
    this->items.push_back(item);
}

vector<Product> Invoice::getProducts(){
    vector<Product> products;
    for(auto item : items){
        products.push_back(item.getProduct());
    }

    return products;
}

vector<Item> Invoice::getItems(){
    return items;
}

double Invoice::computeItemTotal(Item item){
    return item.getQuantity()*item.getProduct().getPrice();
}

double Invoice::computeSubtotal(){
    double sum = 0;
    for(auto item: items){
        sum += computeItemTotal(item);
    }

    return sum;
}

double Invoice::computeTax(){
    return 0.1*computeSubtotal();
}