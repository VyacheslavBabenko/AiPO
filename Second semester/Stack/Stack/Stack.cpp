// Stack.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include<thread>
#include<mutex>
#include<stack>
#include<string>
#include"Thread_guard.h"
#include"mutex_stack.h"

void func_for_thread(std::string name_in, std::string name_out, mutex_stack<int>& m) {
	std::ifstream fin(name_in , std::ios::in);
	std::ofstream fout(name_out , std::ios::out);
	std::string s;
	while (fin >> s) {
		if (s == "push"){
			int data;
			fin >> data;
			m.push(data);
		}
		if (s == "top") {
			std::shared_ptr<int> ans(m.top_and_pop());
			if(ans.get() != nullptr)
				fout << *ans << "\n";
			else fout << -1 << "\n";
		}
	}
}
int main(){
	Thread_guard sentinel;
	mutex_stack<int> m;
	std::string in1 = "input1.txt";
	std::string in2 = "input2.txt";
	std::string in3 = "input3.txt";
	std::string out1 = "output1.txt";
	std::string out2 = "output2.txt";
	std::string out3 = "output3.txt";
	sentinel.add_thread(std::thread(func_for_thread, std::ref(in1), std::ref(out1), std::ref(m)));
	sentinel.add_thread(std::thread(func_for_thread, std::ref(in2), std::ref(out2), std::ref(m)));
	sentinel.add_thread(std::thread(func_for_thread, std::ref(in3), std::ref(out3), std::ref(m)));
	
	sentinel.join();
	return 0;
}
