#include <iostream>
#include <vector>

using namespace std;

vector<int> parent; // 부모 정점 저장

int findParent(int x)
{
    if (parent[x] < 0)
    {
        return x;
    }

    return parent[x] = findParent(parent[x]); // 그래프 압축하며 루트 정점 찾기
}

void unionInput(int x, int y)
{

    int xp = findParent(x); // x의 루트 정점
    int yp = findParent(y); // y의 루트 정점

    if (xp == yp) // 이미 같은 집합에 속한 경우
    {
        return;
    }

    // 그룹 합치기

    if (parent[xp] < parent[yp]) // x 를 포함하는 집합의 크기가 더 크면 y가 포함된 그룹을 x 그룹으로 조인
    {
        parent[xp] += parent[yp];
        parent[yp] = xp;
    }
    else
    { // y 를 포함하는 집합의 크기가 더 크면 x가 포함된 그룹을 y 그룹으로 조인
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, cmd, a, b;

    // 입력
    cin >> n >> m;
    parent.assign(n + 1, -1);
    while (m--)
    {
        cin >> cmd >> a >> b;

        // 연산
        if (cmd == 0)
        { // 합집합 -> 유니온
            unionInput(a, b);
        }
        else if (cmd == 1)
        { // 파인드 -> 같은 집합인지 확인
            if (findParent(a) == findParent(b))
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
}