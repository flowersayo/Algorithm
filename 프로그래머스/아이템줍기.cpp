#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

typedef pair<int, int> ci;

const int SIZE = 50;

using namespace std;

// 갈 수 있는 좌표 영역 표시
vector<vector<bool>> board(SIZE * 2 + 1, vector<bool>(SIZE * 2 + 1, false));

// 시작점으로부터의 거리 표시
vector<vector<int>> dist(SIZE * 2 + 1, vector<int>(SIZE * 2 + 1, -1));

// 동 북 남 서
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int bfs(int sx, int sy, int fx, int fy, vector<vector<int>> rectangle)
{ // (sx,sy) 로부터 (dx,dy) 까지의 거리 탐색

    queue<ci> q;

    q.push({sx, sy});

    dist[sx][sy] = 0; // 방문체크 거리초기화

    while (!q.empty())
    {

        ci current = q.front();
        int cx = current.first;
        int cy = current.second;
        q.pop();

        // 현재 정점에서 상하좌우로 갈 수 있는 정점 탐색
        for (int i = 0; i < 4; i++)
        {

            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx > SIZE * 2 || ny < 0 || ny > SIZE * 2 ||
                !board[nx][ny] || dist[nx][ny] != -1)
            { // 방문 할 수 없는 칸이거나 이미 방문한 칸이라면
                continue;
            }

            dist[nx][ny] = dist[cx][cy] + 1; // 최단거리
            q.push({nx, ny});

            if (nx == fx && ny == fy)
            { // 목적지에 도달하면
                return dist[nx][ny] / 2;
            }
        }
    }

    return -1;
}
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY)
{
    int answer = 0;

    // 모든 직사각형의 외곽 변을 갈 수 있는 영역으로 표시
    for (int i = 0; i < rectangle.size(); i++)
    {
        vector<int> coord = rectangle[i];
        // [좌측 하단 x, 좌측 하단 y, 우측 상단 x, 우측 상단 y]

        int bottom_left_x = coord[0] * 2;
        int bottom_left_y = coord[1] * 2;
        int top_right_x = coord[2] * 2;
        int top_right_y = coord[3] * 2;

        // 좌변
        for (int y = bottom_left_y; y <= top_right_y; y++)
        {
            board[bottom_left_x][y] = true;
        }

        // 우변
        for (int y = bottom_left_y; y <= top_right_y; y++)
        {
            board[top_right_x][y] = true;
        }

        // 윗변
        for (int x = bottom_left_x; x <= top_right_x; x++)
        {
            board[x][top_right_y] = true;
        }

        // 아랫변
        for (int x = bottom_left_x; x <= top_right_x; x++)
        {
            board[x][bottom_left_y] = true;
        }
    }

    // 사각형 내부는 못가도록 FALSE 표시
    for (int i = 0; i < rectangle.size(); i++)
    {
        vector<int> coord = rectangle[i];
        // [좌측 하단 x, 좌측 하단 y, 우측 상단 x, 우측 상단 y]

        int bottom_left_x = coord[0] * 2;
        int bottom_left_y = coord[1] * 2;
        int top_right_x = coord[2] * 2;
        int top_right_y = coord[3] * 2;

        for (int x = bottom_left_x + 1; x < top_right_x; x++)
        {
            for (int y = bottom_left_y + 1; y < top_right_y; y++)
            {
                board[x][y] = false;
            }
        }
    }

    return bfs(characterX * 2, characterY * 2, itemX * 2, itemY * 2, rectangle);
}