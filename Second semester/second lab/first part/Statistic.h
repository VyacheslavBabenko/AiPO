
#include<set>
#include<map>
#include<iostream>
#include<string>
#include<vector>
#include"Dish.h"
typedef std::pair<std::string, std::string> cooker_and_dish_name;
class Statistic{
private:
	std::set<std::string> client_blacklist;
	std::map<std::string, std::vector<Dish>> clients_rates;
	std::map<cooker_and_dish_name, std::vector<Dish>> cooker_and_dish_rates;

public:
	Statistic();
	~Statistic();

	void add_dish_to_statistic(Dish order);
	void liar_check();
	void show_rate_cooker_dish(Dish order);

};

