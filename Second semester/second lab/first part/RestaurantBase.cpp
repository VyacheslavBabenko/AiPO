
#include "RestaurantBase.h"


RestaurantBase::RestaurantBase(){
}

void RestaurantBase::add_type(std::string type) {
	if (menu.find(type) == menu.end()) {
		std::set<std::string> nothing;
		menu.insert({ type,nothing });
	}
	else
		std::cout << "Такой вид блюд уже есть!\n";
}

void RestaurantBase::add_dish(std::string foodname, std::string type) {
	if (menu.find(type) != menu.end()) {
		if (menu.find(type)->second.find(foodname) == menu.find(type)->second.end()) {
			menu.find(type)->second.insert(foodname);
		}
		else
			std::cout << "Такое блюдо уже есть!\n";
	}
	else
		std::cout << "Такого вида блюд у нас нет=(\n";
}

void RestaurantBase::add_cooker(std::string chefname) {
	if (cooker.find(chefname) == cooker.end()) {
		cooker.insert(chefname);
	}
	else
		std::cout << "Такой повар уже работает у нас!\n";
}

void RestaurantBase::erase_cooker(std::string chefname) {
	cooker.erase(chefname);
}

void RestaurantBase::erase_type(std::string type) {
	menu.erase(type);
}

void RestaurantBase::erase_dish(std::string foodname, std::string type) {
	menu.find(type)->second.erase(foodname);
}

bool RestaurantBase::find_dish(Dish food) {
	if (menu.find(food.typename_) != menu.end()) {
		if (menu.find(food.typename_)->second.find(food.foodname_) != menu.find(food.typename_)->second.end())
			return true;
		else
			return false;
	}
	else
		return false;
}

bool RestaurantBase::find_cooker(Dish food) {
	if (cooker.find(food.chefname_) != cooker.end())
		return true;
	else
		return false;
}

void RestaurantBase::put_menu() {
	std::cout << "Menu: \n";
	for (auto it = menu.begin(); it != menu.end(); it++) {
		std::cout << "----------------------------------\n";
		std::cout << "| Dish type: " << it->first << "\n";
		for (auto it2 = menu.find(it->first)->second.begin(); it2 != menu.find(it->first)->second.end(); it2++) {
			std::cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
			std::cout << "|	Dish: " << it2->data() << "\n";
			std::cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
		}
		std::cout << "-----------Bon~Appetit------------\n";
	}
}

RestaurantBase::~RestaurantBase(){
}
