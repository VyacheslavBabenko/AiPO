#include <iostream>
#include"Client.h"
#include"Kitchen.h"
#include"Dish.h"
#include"RestaurantBase.h"
#include"Statistic.h"
#include"Waiter.h"
int main(){

	RestaurantBase RestaurantBase;
	RestaurantBase.add_cooker("Pontiff Sulyvahn");
	RestaurantBase.add_type("Lothric");
	RestaurantBase.add_dish("AbsolutButtHurt", "Lothric");
	RestaurantBase.put_menu();
	std::cout << "\n\n\n";
	Client Ashen_One("Ashen One");
	Waiter Fire_Keeper;
	Kitchen Irithyll_of_the_Boreal_Valley;
	Dish order;
	Statistic table;
	order.chefname_ = "Pontiff Sulyvahn";
	order.foodname_ = "AbsolutButtHurt";
	order.typename_ = "Lothric";
	Ashen_One.add_ready_for_order(order);
	order = Ashen_One.give_order(order);
	if (RestaurantBase.find_cooker(order) && RestaurantBase.find_dish(order)) {
		order = Fire_Keeper.get_order_and_process(order);
		Irithyll_of_the_Boreal_Valley.get_order(order);
		Irithyll_of_the_Boreal_Valley.cooking(order);
		order = Irithyll_of_the_Boreal_Valley.give_dish(order);
		Fire_Keeper.get_dish(order);
		order = Fire_Keeper.give_dish(order);
		Ashen_One.get_dish(order);
		double rate = 1337;
		order = Ashen_One.add_rate(order, rate);
		table.add_dish_to_statistic(order);
		table.liar_check();
		table.show_rate_cooker_dish(order);
	}
	return 0;
}

