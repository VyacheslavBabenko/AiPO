#include<iostream>
#include<fstream>
#include<set>

int main(){
	std::ifstream in("input.txt");
	std::set<int> answer;
	int n, m, student_ans;
	int date;
	in >> n;
	for(int i = 0; i < n; i++){
		in >> date;
		answer.insert(date);
	}
	in >> m;
	for(int i = 0; i < m; i++){
		in >> student_ans;
		int true_ans = 0;
		for(int j = 0; j < student_ans; j++){
			in >> date;
			auto it = answer.find(date);
			if(it != answer.end()){
				true_ans++;
				answer.erase(date);	
			}
		}
		std::cout << true_ans << std::endl;
	}
	return 0;
}
