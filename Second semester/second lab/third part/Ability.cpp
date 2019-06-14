#include "pch.h"
#include "Ability.h"



Ability::Ability(int cost = 1)
{
	active = false;
	cost_score = cost;
}


void Ability::add_cost(std::string name, int costs) {
	cost.insert({ name,costs});
}

void Ability::del_cost(std::string name) {
	cost.erase(cost.find(name));
}

void Ability::buy(std::map <std::string, Atribute> all_atrib) {
	if (active == false) {
		for (std::map<std::string, int>::iterator it = cost.begin(); it != cost.end(); ++it) {
			if (all_atrib.find(it->first) == all_atrib.end()) {
				std::cout << "Ага, не все так просто\nнет нужной характеристики\n";
				return;
			}
			Atribute tmp = all_atrib.find(it->first)->second;
			if (tmp.get_score() < it->second) {
				std::cout << "Ага, не все так просто\nне хватает уровня характеристики для приобретения способности \n";
				return;
			}
		}
		active = true;
	}
	else
		std::cout << "У твоего пеерсонажа уже это есть\n";

}


void Ability::set_active() {
	active = true;
}

void Ability::del_active() {
	active = false;
}

int Ability::get_cost() {
	return cost_score;
}

void Ability::put_info_ab() {
	if (active)
		std::cout << "Статус: Приобретена\n";
	else
		std::cout << "Статус: Не приобретена\n";

	std::cout << "Стоимость: " << cost_score << "\n";

	std::cout << "Необходимые характеристики: \n";
	std::cout << "-----====================-----\n";
	for (std::map<std::string, int>::iterator it = cost.begin(); it != cost.end(); ++it)
		std::cout << "@ " << it->first << " " << it->second << "\n";
	std::cout << "-----====================-----\n";
}
Ability::~Ability(){}
