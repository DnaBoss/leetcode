class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row=grid.size();      //矩阵行数
        int col=grid[0].size();   //矩阵列数
        queue<pair<int,int>> que;
        vector<vector<int>> visited(row,vector<int>(col,0)); //初始化visited矩阵，没访问过为0，访问过为1
        int fresh=0;              //新鲜橘子数
        int rot=0;                //腐烂橘子数
        for(int i=0;i<row;i++)    //遍历矩阵grid，计算新鲜橘子与腐烂橘子数量，并将腐烂橘子的坐标加入队列
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==2)
                {
                    que.push(make_pair(i,j));
                    rot++;
                }
                if(grid[i][j]==1) fresh++;
            }
        }
        if(rot==0&&fresh==0) return 0; //若矩阵中无橘子，则直接返回0;
        int time=-1;
        while(!que.empty())  //广度优搜搜索算法，首先记录腐烂每一次扩散前腐烂的橘子的数量，再进行这一轮搜索
        {                    //每次扩散时向四个方向进行扩散，遇见新鲜橘子时就将fresh-1
            int size=que.size();
            for(int i=0;i<size;i++)
            {
                int x=que.front().first;
                int y=que.front().second;
                que.pop();
                if(x+1<row)
                {
                    if(grid[x+1][y]==1)
                    {
                        grid[x+1][y]=2;
                        fresh--;
                        que.push(make_pair(x+1,y));
                    }
                }
                if(x-1>=0)
                {
                    if(grid[x-1][y]==1)
                    {
                        grid[x-1][y]=2;
                        fresh--;
                        que.push(make_pair(x-1,y));
                    }
                }
                if(y+1<col)
                {
                    if(grid[x][y+1]==1)
                    {
                        grid[x][y+1]=2;
                        fresh--;
                        que.push(make_pair(x,y+1));
                    }
                }
                if(y-1>=0)
                {
                    if(grid[x][y-1]==1)
                    {
                        grid[x][y-1]=2;
                        fresh--;
                        que.push(make_pair(x,y-1));
                    }
                }
            }
            time++;
        }
        if(fresh==0) return time;  //如果最终fresh为0，说明所有新鲜橘子都腐烂了，返回经过的时间
        return -1;                 //否则返回-1
    }
};
