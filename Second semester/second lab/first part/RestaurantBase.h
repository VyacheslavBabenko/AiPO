
#include<iostream>
#include<string>
#include<set>
#include<map>
#include"Dish.h"
typedef std::string type_dish;
typedef std::string name_dish;
class RestaurantBase
{
private:
	std::map<type_dish,std::set<name_dish>> menu;
	std::set<std::string> cooker;
public:
	RestaurantBase();
	~RestaurantBase();


	void add_type(std::string type);
	void add_dish(std::string foodname, std::string type);
	void add_cooker(std::string chefname);
	void erase_cooker(std::string chefname);
	void erase_type(std::string type);
	void erase_dish(std::string foodname, std::string type);
	bool find_dish(Dish food);
	bool find_cooker(Dish food);
	void put_menu();

	
};

