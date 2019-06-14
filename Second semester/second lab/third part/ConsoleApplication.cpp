
#include "pch.h"
#include <iostream>
#include"Hero.h"
#include"Ability.h"
#include"Atribute.h"

void info() {

}

int main(){
	setlocale(LC_ALL, "Russian");
	std::string command;
	std::cout << "Велком в редактор\n";
	std::cout << "help --- расскажут, что к чему\n";
	std::cout << "exit --- можно догадаться \n";
	Hero hero("N0_N@m3");
	hero.add_atribute("strength");
	hero.add_atribute("agility");
	hero.add_atribute("stamina");
	hero.add_atribute("intelligence");
	hero.add_atribute("luck");


	hero.add_cost_atribute("strength", 30, 1);
	hero.add_cost_atribute("strength", 60, 2);
	hero.del_cost_atribute("strength", 100);
	hero.add_cost_atribute("strength", 100, 3);

	hero.add_cost_atribute("agility", 30, 1);
	hero.add_cost_atribute("agility", 60, 2);
	hero.del_cost_atribute("agility", 100);
	hero.add_cost_atribute("agility", 100, 3);

	hero.add_cost_atribute("stamina", 30, 1);
	hero.add_cost_atribute("stamina", 60, 2);
	hero.del_cost_atribute("stamina", 100);
	hero.add_cost_atribute("stamina", 100, 3);

	hero.add_cost_atribute("intelligence", 30, 1);
	hero.add_cost_atribute("intelligence", 60, 2);
	hero.del_cost_atribute("intelligence", 100);
	hero.add_cost_atribute("intelligence", 100, 3);

	hero.add_cost_atribute("luck", 30, 1);
	hero.add_cost_atribute("luck", 60, 2);
	hero.del_cost_atribute("luck", 100);
	hero.add_cost_atribute("luck", 100, 3);


	hero.add_ability("backflip");
	hero.add_cost_ability("backflip", "agility", 30);
	hero.add_cost_ability("backflip", "strength", 10);

	hero.add_ability("blink");
	hero.add_cost_ability("blink", "intelligence", 30);

	hero.add_ability("polymorphism");
	hero.add_cost_ability("polymorphism", "intelligence", 99);
	hero.add_cost_ability("polymorphism", "luck", 99);


	while (1) {
		std::cin >> command;
		if (command == "help") {
			std::cout << "Для редактирования персонажа: \n\n\n";
			std::cout << "Изменить имя: name или 1 \n\n";
			std::cout << "За каждый уровень дают 10 очков характеристик и 1 очко способности.\nЕсли хотите поднять уровень на N позиций и получить очки прокачки: lvl или 2\nЧтобы пондять уровень на 1: lvlup\n\n";
			std::cout << "Повысить характеристики: atrib или 3\n\n";
			std::cout << "Забыть способность sell или 5\n\n";
			std::cout << "Выучить способность: abil или 4\n\n";
			std::cout << "Сбросить настройки и начать редачить сначала: reset или 6\n\n";
			std::cout << "Узнать информацию о вашем персонаже: info или 7\n\n\n\n\n";
			
			std::cout << "Для редактирования редактора: \n\n\n";
			std::cout << "Добавить характеристику: addatrib или 8\n\n";
			std::cout << "Добавить способность: addabil или 9\n\n";
			std::cout << "Удалить характеристику: delatrib или 10\n\n";
			std::cout << "Удалить способность: delabil или 11\n\n";
			std::cout << "Добавить в характеристику курсы перевода очков: rateatrib или 12\n\n";
			std::cout << "Удалить  в характеристике курсы перевода очков: rateatribdel или 13\n\n";
			std::cout << "Добавить необходимую характеристику для способности: costabil или 14\n\n";
			std::cout << "Удалить необходимую характеристику для способности: costabildel или 15\n\n";
			std::cout << "Задать уровень герою и получить максимальное число очков прокачки на нем: setlvl или 16\n\n";
			std::cout << "Задать нужное число очков характеристики: setatrib или 17\n\n";
			std::cout << "Установить на перса способность: setactive или 18\n\n";

		}

		if (command == "name" || command == "1") {
			std::cout << "Введите новое имя: \n";
			std::string name;
			std::cin >> name;
			hero.change_name(name);
		}

		if (command == "lvl" || command == "2") {
			int a;
			std::cout << "Введите число на которое хотите повысить уровень: ";
			std::cin >> a;
			hero.level_up(a);
		}
		if (command == "lvlup") {
			hero.level_up(1);
		}

		if (command == "atrib" || command == "3") {
			std::cout << "Введите название характеристики и на сколько хотите ее повысить: \n";
			std::string name;
			int a;
			std::cin >> name >> a;
			hero.change_score_atribute(name, a);
		}

		if (command == "sell" || command == "5") {
			std::cout << "Введите название способности, которую хотите продать\n";
			std::string name;
			std::cin >> name;
			hero.del_active_ability(name);
		}

		if (command == "abil" || command == "4") {
			std::cout << "Введите название способности, которую хотите приобрести: \n";
			std::string name;
			std::cin >> name;
			hero.buy_ability(name);
		}

		if (command == "reset" || command == "6") {
			hero.reset_settings();
			std::cout << "Все настройки сброшены\n";
		}

		if (command == "info" || command == "7") {
			hero.put_info();
		}

		if (command == "addatrib" || command == "8"){
			std::cout << "Хотите задать начальные очки характеристики?(стандарт: 10) Введите: +";
			char answer;
			std::cin >> answer;
			std::cout << "Введите название характеристики: \n";
			std::string name;
			std::cin >> name;
			if (answer == '+') {
				std::cout << "Введите начальные очки: \n";
				int a;
				std::cin >> a;
				hero.add_atribute(name, a);
			}
			else
				hero.add_atribute(name);
		}

		if (command == "addabil" || command == "9") {
			std::cout << "Хотите задать начальную стоимость способности?(стандарт: 1) Введите: +";
			char answer;
			std::cin >> answer;
			std::cout << "Введите название способности: \n";
			std::string name;
			std::cin >> name;
			if (answer == '+') {
				std::cout << "Введите начальную стоимость: \n";
				int a;
				std::cin >> a;
				hero.add_ability(name, a);
			}
			else
				hero.add_ability(name);
		}

		if (command == "delatrib" || command == "10") {
			std::cout << "Введите название характеристики: \n";
			std::string name;
			std::cin >> name;
			hero.erase_atribute(name);
		}

		if (command == "delabil" || command == "11") {
			std::cout << "Введите название способности: \n";
			std::string name;
			std::cin >> name;
			hero.erase_ability(name);
		}

		if (command == "rateatrib" || command == "12") {
			std::cout << "Введите название характеристики: \n";
			std::string name;
			std::cin >> name;
			std::cout << "Введите уровень до которого будет работать курс и сам курс: \n";
			int up, rate;
			std::cin >> up >> rate;
			hero.add_cost_atribute(name, up, rate);
		}

		if (command == "rateatribdel" || command == "13") {
			std::cout << "Введите название характеристики: \n";
			std::string name;
			std::cin >> name;
			std::cout << "Введите уровень до которого  работает курс, который хотите убрать: \n";
			int up;
			std::cin >> up;
			hero.del_cost_atribute(name, up);
		}

		if (command == "costabil" || command == "14") {
			std::cout << "Введите название способности: \n";
			std::string name;
			std::cin >> name;
			std::cout << "Введите название характеристики и ее уровень: \n";
			std::string name_atr;
			int a;
			std::cin >> name_atr >> a;
			hero.add_cost_ability(name, name_atr, a);
		}

		if (command == "costabildel" || command == "15") {
			std::cout << "Введите название способности: \n";
			std::string name;
			std::cin >> name;
			std::cout << "Введите название характеристики, которую хотите убрать: \n";
			std::string name_atr;
			std::cin >> name_atr;
			hero.del_cost_ability(name, name_atr);
		}

		if (command == "setlvl" || command == "16") {
			std::cout << "Введите уровень, который хотите установить: \n";
			int lvl;
			std::cin >> lvl;
			hero.level_set(lvl);
		}

		if (command == "setatrib" || command == "17") {
			std::cout << "Введите название характеристики: \n";
			std::string name;
			std::cin >> name;
			std::cout << "Введите кол-во очков, которое хотите установить: \n";
			int score;
			std::cin >> score;
			hero.set_score_atribute(name,score);
		}

		if (command == "setactive" || command == "18") {
			std::cout << "Введите название способности: \n";
			std::string name;
			std::cin >> name;
			hero.set_active_ability(name);
		}

		if (command == "exit") {
			return 0;
		}
	}	
	return 0;
}

