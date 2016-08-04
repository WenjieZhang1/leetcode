#include <iostream>
#include <vector>
#include <queue>
// #include <pair>
using namespace std;
class Solution{
public:
	int minstep(vector<vector<int>>& chess){
		int ss=chess.size();
        vector<pair<int,int>> path={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{2,-1},{1,-2},{-1,-2}};
        int row=chess[0][0];
        int col=chess[0][1];
        int startrow=chess[1][0];
        int startcol=chess[1][1];
        int endrow=chess[2][0];
        int endcol=chess[2][1];
        vector<vector<int>> board(row, vector<int>(col, INT_MAX));
        board[startrow][startcol]=0;
        for(int i=4; i<ss; ++i){
        	board[chess[i][0]][chess[i][1]]=-1;// means there exists a blocked
        }
        queue<pair<int,int>> canreach;
        canreach.push(make_pair(startrow,startcol));
        while(!canreach.empty()){
        	int r=canreach.front().first;
        	int c=canreach.front().second;
        	canreach.pop();
        	for(auto it : path){
        		int x=r+it.first;
        		int y=c+it.second;
        		if(x<0 || y<0 || x>=row || y>=col || board[x][y]<=board[r][c]+1) continue;
        		board[x][y]=board[r][c]+1;
        		canreach.push(make_pair(x,y));
        	}
        }
        return board[endrow][endcol];
	}

};

int main(){
	Solution step;
	int res;
	// vector<vector<int>> chess(9, vector<int>(2,0));
	// chess[0][0]=7;
	// chess[0][1]=7;
	// chess[1][0]=0;
	// chess[1][1]=0;
	// chess[2][0]=0;
	// chess[2][1]=6;
	// chess[3][0]=5;
	// chess[3][1]=0;
	// chess[4][0]=2;
	// chess[4][1]=3;
	// chess[5][0]=3;
	// chess[5][1]=2;
	// chess[6][0]=3;
	// chess[6][1]=3;
	// chess[7][0]=3;
	// chess[7][1]=4;
	// chess[8][0]=4;
	// chess[8][1]=3;
    vector<vector<int>> chess(4, vector<int>(2,0));
	chess[0][0]=4;
	chess[0][1]=8;
	chess[1][0]=2;
	chess[1][1]=7;
	chess[2][0]=3;
	chess[2][1]=7;
	chess[3][0]=0;
	chess[3][1]=0;
	res=step.minstep(chess);
	cout<<res<<endl;
	return 0;
}



