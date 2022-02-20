#include <iostream>
#include <algorithm>
#include <math.h>
#define INF 10e19

using namespace std;

int velocity[200000];//10^9

// A팀 : 가장 느린 사람이 속한 팀
// B팀 : 가장 느린 사람이 속하지 않은 팀
long long  getMinTime(int n, double k) {

	int avgVelocity_A, avgVelocity_B;// A,B팀에서 가장 느린 속도 (개인 평균 속도)
	double teamVelocity_A, teamVelocity_B; // A,B 팀의 팀별 분당 작업속도 
	long long finalTime; // 최종 작업속도

	long long minTime = INF; // 최소 시간 : 10^19/2
	for (int i = 1; i <= n-1; i++) { //i : 가장 느린 사람이 속한 팀의 사람 수
		
		avgVelocity_A = velocity[0]; 
		avgVelocity_B = velocity[i]; 
		
		teamVelocity_A = avgVelocity_A * i;
		teamVelocity_B = avgVelocity_B * (n - i);


		finalTime = ceil(k / (teamVelocity_A + teamVelocity_B)); 

		minTime = min(minTime, finalTime);
		

	}

	return minTime;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n; //사람수, 상자수
	double k; 
	cin >> n >> k;


	for (int i = 0; i < n; i++)
		cin >> velocity[i];
	
	sort(velocity, velocity + n); //오름차순 정렬

	cout << getMinTime(n, k);
}