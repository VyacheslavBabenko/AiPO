
#include<string>
#include<map>
#include"Dish.h"
using name_dish=std::string;

class Client{
private:
	std::string name_;
	std::map<name_dish, Dish> ready_for_order;
	std::map<name_dish, Dish> ready_for_rate;

public:
	Client(std::string name);
	~Client();

	void add_ready_for_order(Dish order);
	Dish give_order(Dish order);
	void get_dish(Dish order);
	Dish add_rate(Dish order, double rate);

	
};

