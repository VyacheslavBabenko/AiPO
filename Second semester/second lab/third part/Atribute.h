#pragma once
#include <map>
#include <iostream>
class Atribute {

public:
	Atribute(int score = 10);
	~Atribute();

	void add_rate(int up_board, int rates);// Устанавливает коэффицент 
	void del_rate(int up_board);// Удаляет коэффицент скалирования 
	int get_score();//  Уровень характеристики 
	int count_scores(int count);// Сколько нужно очков атрибута, чтоб повысить характ-ку
	void add_scores(int count);// Добавляет очков атрибута
	void set_score(int score);// Устанавливает очки атрибута 
	void put_info_atr();// Информация об атрибуте 
	


private:
	int score_;
	std::map <int, int> rate;
};
