#include<iostream>
#include<fstream>
#include<vector>
#include<queue>

bool board(std::pair<int,int> place,std::pair<int,int> size){
	return
		(place.first < size.first && 
		place.first >= 0 && 
		place.second < size.second && 
		place.second >= 0);
}

void bfs(std::vector<std::vector<char> >& field, std::pair<int,int> start){
	std::queue <std::pair<int,int> > que;
	que.push(start);
	while(que.size() != 0){
		std::pair<int,int> place = que.front();
		que.pop();
		if(board({place.first + 1, place.second},{field.size(), field[place.first + 1].size()}) && field[place.first + 1][place.second] =='#'){
			field[place.first + 1][place.second] = '.';
			que.push({place.first + 1, place.second});
		}
		
		if(board({place.first, place.second + 1},{field.size(), field[place.first].size()}) && field[place.first][place.second + 1] =='#'){
			field[place.first][place.second + 1] = '.';
			que.push({place.first, place.second + 1}); 
		}
		
		if(board({place.first - 1, place.second},{field.size(), field[place.first - 1].size()}) && field[place.first - 1][place.second] =='#'){
			field[place.first - 1][place.second] = '.';
			que.push({place.first - 1, place.second});
		}
		
		if(board({place.first, place.second - 1},{field.size(), field[place.first].size()}) && field[place.first][place.second - 1] =='#'){
			field[place.first][place.second - 1] = '.';
			que.push({place.first, place.second - 1});
		}	
	}
}

int main(){
	std::ifstream in("input.txt");
	int n, m;  
	int schet = 0;
	in >> n >> m;
	
	std::vector<std::vector<char> > field(n, std::vector<char>(m));
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			in >> field[i][j];
		
	for(int i = 0; i < field.size(); i++)
		for(int j = 0; j < field[i].size(); j++){
			if(field[i][j] == '#'){
				schet++;
				field[i][j] = '.';
				bfs(field,{i,j});
			}
		}
		
	std::cout << schet;
	return 0;
}
