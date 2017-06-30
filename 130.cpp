#include<vector>


using namespace std;
int i_offset[4] = { -1,1,0,0 };
int j_offset[4] = { 0,0,1,-1 };//�������ڸ�������
int max(int a, int b) {
	return a > b ? a : b;
}
int min(int a, int b) {
	return a < b ? a : b;
}
void corner_explore(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j) {//return true if is not surrounded
	int width = board.size();
	int length = board.at(0).size();
	//bool result = false;
	//if (i == 0 || i == width - 1 || j == 0 || j == length - 1) {//return true if cornered
	//	return true;
	//}
	
			
	if (visited.at(i).at(j))//©������ֹ����
		return;
	visited.at(i).at(j) = true;//visited����д��31�У��������룬ִ�е�22��ֱ����ֹ���ǲ��Ե�
	for (int ind = 0; ind < 4; ind++) {//ѭ��������������ͬ
		int new_i = max(min(width-1, i + i_offset[ind]), 0);//���ֵΪwidth-1
		int new_j = max(min(length-1, j + j_offset[ind]), 0);
		
		if (board.at(new_i).at(new_j) == 'O')
		{
			
			corner_explore(board, visited, new_i, new_j);
			
		}
	}
	//return result;


}
void solve(vector<vector<char>>& board) {
	int width = board.size();

	if (width < 1)//{}out of range
		return;
	int length = board.at(0).size();
	if (length < 1)
		return;//{{}}���� out of range����ʱboardΪsize1*0
	vector<vector<bool>> visited(width,vector<bool>(length,false));
	for (int i = 0; i < width; i++)
	{
		if (board.at(i).at(0) == 'O')
			corner_explore(board, visited, i, 0);
		if (board.at(i).at(length-1) == 'O')
			corner_explore(board, visited, i, length - 1);
	}
	for (int i = 0; i < length; i++)
	{
		if (board.at(0).at(i) == 'O')
			corner_explore(board, visited, 0, i);
		if (board.at(width-1).at(i) == 'O')
			corner_explore(board, visited, width-1, i);
	}
	
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < length; j++)
		{
			if (!visited.at(i).at(j)) {
				board.at(i).at(j) = 'X';
			}
		}
	}
	return;
}

int main() {
	//vector<vector<char>> board = { {} };
	vector<vector<char>> board = { {'O','O','O'},{'O','O','O'},{'O','O','O'} };
	//vector<vector<char>> board = { {'O','X','X','O'},{'X','O','O','X'},{'O','X','O','X'},{'X','O','X','O'} };

	solve(board);

	return 0;
}