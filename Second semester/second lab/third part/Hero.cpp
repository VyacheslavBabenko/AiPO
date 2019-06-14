#include "pch.h"
#include "Hero.h"


Hero::Hero(std::string name) {
	level_ = 1;
	name_ = name;
	atribute_score = 0;
	ability_score = 0;
}
void Hero::level_up(int lvl) {
	level_ += lvl;
	atribute_score += 10 * lvl;
	ability_score += lvl;
}

void Hero::level_set(int lvl) {
	level_ = lvl;
	atribute_score = 10 * lvl;
	ability_score = lvl;
}

void Hero::add_atribute(std::string name, int start_score) {
	Atribute atr(start_score);
	atributes.insert({ name,atr });
}

void Hero::change_score_atribute(std::string name, int score) {
	if (atributes.find(name) != atributes.end()) {
		int scores = atributes.find(name)->second.count_scores(score);
		if (atribute_score > scores) {
			atribute_score -= scores;
			atributes.find(name)->second.add_scores(score);
		}
		else
			std::cout << "Не хватает " << scores - atribute_score << " Очков для прокачки =(";
	}
	else
		std::cout << "Нет такого атрибута =(\n";
}

void Hero::add_cost_atribute(std::string name, int up_board, int rate) {
	if (atributes.find(name) != atributes.end())
		atributes.find(name)->second.add_rate(up_board, rate);
	else
		std::cout << "Нет такого атрибута =(\n";
}

void Hero::del_cost_atribute(std::string name, int up_board) {
		atributes.find(name)->second.del_rate(up_board);
}

void Hero::set_score_atribute(std::string name, int score) {
	if (atributes.find(name) != atributes.end())
		atributes.find(name)->second.set_score(score);
	else
		std::cout << "Нет такого атрибута =(\n";
}

void Hero::erase_atribute(std::string name) {
	atributes.erase(atributes.find(name));
}

void Hero::add_ability(std::string name, int cost) {
	Ability abil(cost);
	abilities.insert({ name,abil });
}

void Hero::add_cost_ability(std::string name, std::string name_atr, int cost) {
	if (abilities.find(name) != abilities.end())
		abilities.find(name)->second.add_cost(name_atr, cost);
	else
		std::cout << "Нет такой способности =(\n";
}

void Hero::del_cost_ability(std::string name, std::string name_atr) {
		abilities.find(name)->second.del_cost(name_atr);
}

void Hero::set_active_ability(std::string name) {
	abilities.find(name)->second.set_active();
}

void Hero::buy_ability(std::string name) {
	if (abilities.find(name) != abilities.end()) {
		if (ability_score < abilities.find(name)->second.get_cost()) {
			std::cout << "не хватает очков прокачки =(\n";
			return;
		}
		abilities.find(name)->second.buy(atributes);
		ability_score -= abilities.find(name)->second.get_cost();
	}
	else
		std::cout << "Нет такой способности =(\n";
}

void Hero::erase_ability(std::string name) {
	abilities.erase(abilities.find(name));
}

void Hero::del_active_ability(std::string name) {
	if (abilities.find(name) != abilities.end()) {
		abilities.find(name)->second.del_active();
		ability_score += abilities.find(name)->second.get_cost();
	}
	else
		std::cout << "Нет такой способности =(\n";
}

void Hero::reset_settings() {
	level_ = 1;
	
	for (std::map<std::string, Atribute>::iterator it = atributes.begin(); it != atributes.end(); ++it) {
		set_score_atribute(it->first);
	}
	for (std::map<std::string, Ability>::iterator it = abilities.begin(); it != abilities.end(); ++it) {
		del_active_ability(it->first);
	}
	atribute_score = 0;
	ability_score = 0;
}

void Hero::change_name(std::string name) {
	name_ = name;
}

void Hero::put_info() {
	std::cout << "Имя: " << name_ << "\n";
	std::cout << "Уровень: " << level_ << "\n";
	std::cout << "Свободные очки прокачки характеристик: " << atribute_score << "\n";
	std::cout << "Свободные очки прокачки способностей: " << ability_score << "\n";
	std::cout << "---------------------------------------\n";
	std::cout << "-------------ХАРАКТЕРИСТИКИ------------\n";
	std::cout << "---------------------------------------\n";
	for (std::map<std::string, Atribute>::iterator it = atributes.begin(); it != atributes.end(); ++it) {
		std::cout << it->first << " : \n";
		it->second.put_info_atr();
		std::cout << "\n";
	}
	std::cout << "---------------------------------------\n";
	std::cout << "--------------СПОСОБНОСТИ--------------\n";
	std::cout << "---------------------------------------\n";
	for (std::map<std::string, Ability>::iterator it = abilities.begin(); it != abilities.end(); ++it) {
		std::cout << it->first << " : \n";
		it->second.put_info_ab();
		std::cout << "\n";
	}

}
	Hero::~Hero(){}
