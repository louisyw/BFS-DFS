/*
 *给定一个大小为N*M的迷宫。迷宫由通道和墙壁构成，每一步可以向邻接的上下左右四格的通道移动。请求出从起点到终点所需的最小步数。本题假设从起点一定可以移动到终点

 输入 N=10， M=10（迷宫如下图所示。'#', '.', 'S', 'G'分别表示墙壁，通道，起点和终点）
 */
#include <iostream>
#include <queue>

using namespace std;

const int N = 10;
const int M = 10;
const int INF = 100000000;

static char maze[N][M+1] = {
			  "#S######.#",
			  "......#..#",
			  ".#.##.##.#",
			  ".#........",
			  "##.##.####",
			  "....#....#",
			  ".#######.#",
			  "....#.....",
			  ".####.###.",
			  "....#...G#"
			 };

typedef pair<int, int> P;
int sx =0, sy = 1; //start point
int gx =9, gy = 8; //end point
int dis[N][M];  //the distance to start point

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int bfs()
{
	queue<P> que;

	for (int i= 0; i<N; i++)
		for (int j = 0; j <M; j++)
			dis[i][j] = INF;
	//起点入队列，并把起点的距离设为0
	que.push(P(sx,sy));
	dis[sx][sy] = 0;

	while(que.size()){
		P p = que.front();
			que.pop();
		//是否是终点
		if(p.first == gx && p.second == gy) break;
		//循环四个方向
		for (int i = 0 ; i < 4; i++){
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];
			if(0 <= nx && nx < N && 
			   0 <= ny && ny < M && 
			   maze[nx][ny] != '#' && 
			   dis[nx][ny] == INF){
				que.push(P(nx, ny));
				dis[nx][ny] = dis[p.first][p.second]+1;
			}
		}
	}
	return dis[gx][gy];
}

int main()
{
	int res = bfs();
	cout<<res<<endl;
}
