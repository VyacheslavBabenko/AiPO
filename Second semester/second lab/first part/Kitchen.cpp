
#include "Kitchen.h"


Kitchen::Kitchen(){
}

void Kitchen::get_order(Dish order) {
	if (ready_for_cook.find(order.foodname_) == ready_for_cook.end())
		ready_for_cook.insert({ order.foodname_,order });
}

void Kitchen::cooking(Dish order) {
	if (ready_for_cook.find(order.foodname_) != ready_for_cook.end()) {
		ready_for_eat.insert({ order.foodname_,order });
		ready_for_cook.erase(order.foodname_);
	}
}

Dish Kitchen::give_dish(Dish order) {
	if (ready_for_eat.find(order.foodname_) != ready_for_eat.end()) {
		order.ready_ = true;
		ready_for_eat.erase(order.foodname_);
		return order;
	}
}

Kitchen::~Kitchen(){
}
