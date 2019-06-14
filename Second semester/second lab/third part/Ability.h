#pragma once
#include <map>
#include <iostream>
#include<string>
#include "Atribute.h"
class Ability{	
	
	public:
		Ability(int cost);
		~Ability();


		void add_cost(std::string name, int costs);// Устанавливает количество той или иной хар-ки
		void del_cost(std::string name);// Убирает    ^^^^^  из способности 
		int get_cost();// сколько стоит абилка
		void buy(std::map <std::string, Atribute> all_atrib);// Приобретает способность
		void set_active();// Активировать способность не взирая на очки
		void del_active();// Диактивировать способность
		void put_info_ab();// инфа об абилке
		
	
	private:
		bool active;
		int cost_score;
		std::map <std::string, int> cost;

};

