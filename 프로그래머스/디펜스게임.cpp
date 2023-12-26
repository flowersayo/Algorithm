#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> ci;
const int INF = 1000001;
/**
 * 디펜스 게임
 * https://school.programmers.co.kr/learn/courses/30/lessons/142085
 *
 *
 * 기본적으로 무적권은 병사를 소모하지 않고 패스하는 것이다.
 * 따라서 가장 숫자가 큰 적에 쓰는 것이 유리하다.
 *
 * 그러면 내림차순 정렬 후, k번째까지 큰 수 들에 무적권을 사용한다?
 * => 뒤쪽 더 큰 수에 무적권을 사용하느라, 정작 앞에서 병사 부족으로 뒤에까지 가보지도 못하고 멈출 수 있음
 * ex) 10 10 1 2 3 11  ( n =16, k =1 인 상황 )
 * => 즉, 무적권을 모두 사용하지 못하는 경우 존재하므로 불가능
 *
 *
 * 현재 마주친 적이 4명이라면 무적권을 사용해야할까? 말아야할까? 에 대한 질문은
 * 4명이라는 하나의 상황만 보고는 판단이 불가능하다.
 * 근처 뒤에 더 크기가 큰 적이 있다면 거기에 무적권을 쓰는게 이득이고,
 * 현재 적이 가장 큰 수라면 지금 무적권을 쓰는게 이득이다.
 *
 * 그렇다고 매 선택마다 모든 enemy를 고려할 필요는 없다.
 * "남아 있는 무적권의 크기" 만큼만 남아있는 enemy 들을 고려해주면 된다.
 *
 * 무적권 개수만큼 이후에 훨씬 더 큰 적이 있어서 더 효율적으로 사용할 수 있다고 해도,
 * 현재 병사 수가 모자란데 지금 안쓰면 거기에 도달하지도 못할거 그곳에 무적권을 쓰는 선택은 낭비이기 때문이다.
 *
 * 따라서 무적권 개수 이후에 적들에 무적권을 사용하는 것은 고려하지 않아도 괜찮다.
 *
 * "매 라운드를 지나면서 여태까지 지나온 적들 중 가장 큰 상위 k개의 적을 유지시키는 것" 이 핵심!
 *
 * [구현]
 * 우선순위 큐를 활용해 현재 탐색한 지점까지 무적권을 사용할 k개의 enemy를 유지한다.
 * 이 때, 매 탐색에서 최솟값을 효율적으로 구하기 위해서 우선순위 큐를 활용한다.
 *
 * 우선순위큐에 enemy 를 하나씩 넣으면서 k(무적권 사용 개수)를 초과하면,
 * 그 중 가장 크기가 작은 enemy를 pop하여 무적권 사용에서 제외시킨다.
 * 이 때, pop된 원소가 n보다 크다면 즉시 종료한다.
 * 그러면 자연스럽게 현재 지나온 값들 중에서 상위 크기 k개의 값들이 그대로 힙에 남아있게 된다.
 *
 *

 */

int solve(int n, int k, vector<int> enemy)
{

    priority_queue<int, vector<int>, greater<int>> minHeap; // k개의 무적권 사용 대상

    for (int i = 0; i < enemy.size(); i++)
    {

        minHeap.push(enemy[i]);

        if (minHeap.size() > k)
        {

            int min_value = minHeap.top();
            minHeap.pop();

            if (min_value > n)
            {
                return i;
            }

            n -= min_value;
        }
    }

    return enemy.size();
}
int solution(int n, int k, vector<int> enemy)
{
    int answer = solve(n, k, enemy);

    return answer;
}