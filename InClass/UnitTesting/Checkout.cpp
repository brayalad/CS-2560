//Checkout.cpp

#include "Checkout.h"

using namespace std;

Checkout::Checkout() :total(0) {


}

Checkout::~Checkout() {

}

void Checkout::addItemPrice(string item, int price) {
	prices[item] = price;
}

void Checkout::addItem(string item) {
	map<string, int>::iterator priceIter = prices.find(item);
	if (priceIter == prices.end()) {
		throw invalid_argument("Invalid item.  No price");
	}

	items[item]++;
}

void Checkout::addDiscount(string item, int nbrOfItems, int discountPrice) {
	Discount discount;
	discount.nbrOfItems = nbrOfItems;
	discount.discountPrice = discountPrice;
	discounts[item] = discount;
}

int Checkout::calculateTotal() {
	total = 0;

	for (map<string, int>::iterator itemIter = items.begin();
		itemIter != items.end(); itemIter++) {
		string item = itemIter->first;
		int itemCnt = itemIter->second;
		calculateItem(item, itemCnt);
	}

	return total;
}

void Checkout::calculateItem(string item, int itemCnt) {
	map<string, Discount>::iterator discountIter;
	discountIter = discounts.find(item);
	if (discountIter != discounts.end()) {
		Discount discount = discountIter->second;
		calculateDiscount(item, itemCnt, discount);
	}
	else {
		total += itemCnt * prices[item];
	}
}

void Checkout::calculateDiscount(string item, int itemCnt, Discount discount) {
	if (itemCnt >= discount.nbrOfItems) {
		int nbrOfDiscounts = itemCnt / discount.nbrOfItems;
		total += nbrOfDiscounts * discount.discountPrice;
		int remainingItems = itemCnt % discount.nbrOfItems;
		total += remainingItems * prices[item];
	}
	else {
		total += itemCnt * prices[item];
	}
}

