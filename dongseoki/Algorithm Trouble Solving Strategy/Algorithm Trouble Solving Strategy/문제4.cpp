#include <string>
#include <vector>
#include <queue>

#define F(p,q,r) for(int p =q; p<r;p++)
using namespace std;



void BFS(vector<vector<int>> board, vector<vector<vector<int>>> & memo) {
    queue<pair<pair<int, int>, int>> q;
    F(idx, 0, 4) {
        memo[0][0][idx] = 0;
        q.push(make_pair(make_pair(0, 0), idx));
    }

    while (!q.empty()) {
        pair<pair<int, int>, int> front = q.front();
        q.pop();
        
    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    vector<vector<vector<int>>> memo(board.size(), 
        vector<vector<int>>(board[0].size(), 
            vector<int>(4, -1)));


    BFS(board, memo);




    return answer;
}

int main(void) {
    vector<vector<int>> board = { {0, 0, 0}, { 0,0,0 }, { 0,0,0 } };
    solution(board);
}