
#include "Waiter.h"


Waiter::Waiter(){
}

Dish Waiter::get_order_and_process(Dish order) {
	order.ready_ = false;
	if (orders.find(order.foodname_) == orders.end()) {
		orders.insert({ order.foodname_,order });
		return order;
	}
}
void Waiter::get_dish(Dish order) {
	if (order.ready_ == true) {
		orders.erase(order.foodname_);
		dishes.insert({ order.foodname_,order });
	}
}
Dish Waiter::give_dish(Dish order) {
	if (dishes.find(order.foodname_) != dishes.end()) {
		dishes.erase(order.foodname_);
		return order;
	}
}

Waiter::~Waiter()
{
}
