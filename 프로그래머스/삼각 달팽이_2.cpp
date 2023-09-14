
#include <string>
#include <vector>
#include <iostream>

using namespace std;
int arr[1000][1000];
/**
[삼각달팽이]
https://school.programmers.co.kr/learn/courses/30/lessons/68645

관찰! 길이가 n인 삼각형을 그려나갈 때 
안쪽으로 말려 들어가면서 길이가 n -> n-1 -> n-2 씩 줄어드는 규칙이 있다.
따라서 매번 크기가 1씩 줄어드는 
일정한 개수의 타일로 구성된 한 변을 모두 그리고 나서 적절하게 방향을 바꾸어주면 된다.
이때 아래 -> 오른쪽 -> 왼쪽 위 세개의 방향 규칙이 반복되므로 
반복문을 사용하여 i%3==0 일경우 아래, i%3==1 일경우 오른쪽, i%3==2 일경우 왼쪽 위 로 처리해주면 
쉽게 방향 규칙을 적용할 수 있다.
*/
vector<int> solution(int n) {
    vector<int> answer;
    int p = n;
    int k = 1;
    int x = -1, y = 0;
    for (int i = 0; i < n; i++) { // 방향 
        for (int j = p;j >= 1; j--) { // 한변의 길이

            if(i%3==0) {
                arr[++x][y] = k;
            } else if (i % 3 == 1) {
                arr[x][++y] = k;
            } else if (i % 3 == 2) {
                arr[--x][--y] = k;
            }
            k++;
        }
        p--;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i;  j++) {
            answer.emplace_back(arr[i][j]);
        }
    }

    return answer;
}
