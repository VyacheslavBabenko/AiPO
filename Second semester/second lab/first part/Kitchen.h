
#include<map>
#include<string>
#include"Dish.h"
typedef std::string name_dish;
class Kitchen{
private:
	std::map<name_dish, Dish> ready_for_cook;
	std::map<name_dish, Dish> ready_for_eat;
public:
	Kitchen();
	~Kitchen();

	void get_order(Dish order);
	void cooking(Dish order);
	Dish give_dish(Dish order);
	
};

