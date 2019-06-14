
#include "Client.h"


Client::Client(std::string name) {
	name_ = name;
}

void Client::add_ready_for_order(Dish order) {
	ready_for_order.insert({ order.foodname_,order });
}

Dish Client::give_order(Dish order) {
	if (ready_for_order.find(order.foodname_) != ready_for_order.end()) {
		order.username_ = name_;
		return order;
	}
}

void Client::get_dish(Dish order) {
	if (order.username_ == name_ && order.ready_ == true) {
		ready_for_order.erase(order.foodname_);
		ready_for_rate.insert({ order.foodname_, order });
	}
}

Dish Client::add_rate(Dish order, double rate) {
	if (ready_for_rate.find(order.foodname_) != ready_for_rate.end()) {
		order.rate_ = rate;
		return order;
	}
}


Client::~Client()
{
}
