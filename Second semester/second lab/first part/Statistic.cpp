
#include "Statistic.h"


Statistic::Statistic()
{
}

void Statistic::add_dish_to_statistic(Dish order) {
	if (clients_rates.find(order.username_) == clients_rates.end()) {
		std::vector<Dish> nothing;
		clients_rates.insert({ order.username_,nothing });
	}
	clients_rates.find(order.username_)->second.push_back(order);
	if (cooker_and_dish_rates.find({ order.chefname_,order.foodname_ }) == cooker_and_dish_rates.end()) {
		std::vector<Dish> nothing;
		cooker_and_dish_rates.insert({ {order.chefname_,order.foodname_}, nothing });
	}
	cooker_and_dish_rates.find({ order.chefname_,order.foodname_ })->second.push_back(order);
}

void Statistic::liar_check() {
	for (auto it = clients_rates.begin(); it != clients_rates.end(); it++) {
		int schet = 0;
		double rating;
		for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
			if (schet == 0) {
				rating = it2->rate_;
				schet++;
			}
			else {
				if (rating == it2->rate_)
					schet++;
				else
					schet = 0;
				if (schet > 2) {
					client_blacklist.insert(it->first);
					break;
				}
			}
		}
	}
}

void Statistic::show_rate_cooker_dish(Dish order) {
	if (cooker_and_dish_rates.find({ order.chefname_,order.foodname_ }) != cooker_and_dish_rates.end()) {
		std::cout << "Chef name: " << order.chefname_ << "\n";
		std::cout << "The dish: " << order.foodname_ << "\n";
		double count = 0;
		double sum = 0;
		for (auto it = cooker_and_dish_rates.find({ order.chefname_,order.foodname_ })->second.begin(); it != cooker_and_dish_rates.find({ order.chefname_,order.foodname_ })->second.end(); it++) {
			if (client_blacklist.find(it->username_) == client_blacklist.end()) {
				sum += it->rate_;
				count++;
			}
		}
		sum /= count;
		std::cout << "Rate: "<< sum << "\n";
	}
}

Statistic::~Statistic()
{
}
