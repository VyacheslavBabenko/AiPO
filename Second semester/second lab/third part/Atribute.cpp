#include "pch.h"
#include "Atribute.h"


Atribute::Atribute(int score){
	score_ = score;
	rate.insert({ 100,1 });
}

void Atribute::del_rate(int up_board) {
	rate.erase(rate.find(up_board));
}

int Atribute::get_score() {
	return score_;
}

void Atribute::set_score(int score) {
	auto it = rate.end(); 
	--it;
	if(it->first >= score)
		score_ = score;
	else std::cout << "данный уровень превышает максимально возможный: " << it->first <<"\n";
}

void Atribute::add_rate(int up_board, int rates) {
	rate.insert({ up_board,rates });
}

int Atribute::count_scores(int count) {
	int result = 0;
	for (std::map<int, int>::iterator it = rate.begin(); it != rate.end(); ++it) {
		if (score_ < it->first && count > 0) {
			if (score_ + count < it->first) {
				result += it->second * count;
				count = 0;
			}
			else {
				count = (score_ + count) - it->first + 1;
				result += it->second * (it->first - score_ - 1);
			}
		}
	}
	return result;
}

void Atribute::add_scores(int count) {
	if(score_ + count <= rate.rbegin()->first - 1)
		score_ += count;
	else score_ = rate.rbegin()->first - 1;
}

void Atribute::put_info_atr(){
	std::cout << "Количество очков: " << score_ << "\n";
	int start = 0;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "#Стоимость распределения очков :\n";
	for (std::map<int, int>::iterator it = rate.begin(); it != rate.end(); ++it) {
		std::cout << "# От " << start << " до " << it->first - 1 << " : " << it->second << " к 1\n";
		start = it->first;
	}
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

Atribute::~Atribute(){}
