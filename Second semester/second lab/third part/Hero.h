#pragma once
#include "Atribute.h"
#include "Ability.h"
class Hero{
	
	public:
		Hero(std::string name);
		~Hero();


		void level_up(int lvl);// lvl+=5
		void level_set(int lvl);// lvl=5
		void add_atribute(std::string name, int start_score = 10); // добавляет САМ атрибут
		void change_score_atribute(std::string name, int score); // меняет кол-во очков для хар-ки
		void add_cost_atribute(std::string name, int up_board, int rate);// добавить коэффицент 
		void del_cost_atribute(std::string name, int up_board);// убрать коэффицент
		void set_score_atribute(std::string name, int score = 10);// установить коэффицент 
		void erase_atribute(std::string name);// удалить атрибут
		void add_ability(std::string name, int cost = 1);// добавить абилку
		void add_cost_ability(std::string name, std::string name_atr, int cost);// добавить характ-ку
		void del_cost_ability(std::string name, std::string name_atr);// удалить хар-ку
		void set_active_ability(std::string name);// сделать абилку активной
		void buy_ability(std::string name);// "купить" абилку
		void erase_ability(std::string name);// убрать абилку
		void del_active_ability(std::string name);// удалить у абилки активность
		void reset_settings();// сбросить все-все
		void change_name(std::string name);// меняет ник
		void put_info();// инфа

		

	private:
		std::map <std::string, Atribute> atributes;
		std::map <std::string, Ability> abilities;
		std::string name_;
		int level_, atribute_score, ability_score;

};

