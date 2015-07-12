/*
 *有一个N*M的园子，雨后积起了水。八连通的积水是连接在一起的。请求出园子里总共有多少处积水（八连通是指）
   ***
   *W*
   ***
 */

/*
 *输入
 * N=10，M=12
  园子如下图（'w'表示有积水，'.'表示没有积水）

  w........ww.
  .www.....www
  ....ww...ww.
  .........ww.
  .........w..
  ..w......w..
  .w.w.....ww.
  w.w.w.....w.
  .w.w......w.
  ..w.......w.
 */

int N,M;
char field[N][M+1];
//现在位置(x,y)
void dfs(int x, int y)
{
	//将现在的位置替换为'.'
	field[x][y] = '.';

	//循环遍历此位置的8个方向
	for (int dx = -1; dx <= 1; dx++)
		for (int dy=-1; dy <= 1; dy++){
		//向x方向移动dx， 向y方向移动dy， 移动的结果为(nx, ny)
			int nx = x + dx, ny = y + dy;
			if(nx >= 0 && nx < N && ny >= 0 && ny < M && field[nx][ny] == 'w') 
				dfs(nx, ny);
		}
}

void sove()
{
	int res = 0;
	for (int i= 0; i < N; i++)
		for (int j = 0; j < M; j++){
			if(field[i][j] == 'w'){
				dfs(i , j);
				res++;
			}
		}
	printf("%d\n", res);
}
