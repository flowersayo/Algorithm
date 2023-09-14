#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

const string ALL = "-";
unordered_map<string, vector<int>> map;

void insert(string* key, int mask, int point) {
    string s = "";
    
    // key string 완성
    for (int i = 0; i < 4; i++) {
        s += (mask & (1 << i)) ? ALL : key[i];  
        
    }
    map[s].push_back(point);
}
/**
[순위검색]
https://school.programmers.co.kr/learn/courses/30/lessons/72412

특정 조건을 만족하는 지원자 수를 count 해야한다.


1. query 조건을 만족하는 후보자들의 점수 목록에 빠르게 접근하기 

    query로 주어질 수 있는 것은
    언어 x 직군 x 경력 x 소울푸트 경우의 수를 모두 곱해도 24가지 경우의 수밖에 나오지 않기 때문에

    이때, 점수까지 포함한 key 로 맵에 저장하려고 하면
    점수 범위는 1 이상 100,000 이하 로 굉장히 넓기 때문에  24 * 100,000 가지 경우의 수가 나온다.
   
    - key : 점수는 제외한 지원정보 
    - value(vector<int>) : 해당 지원정보를 만족한 점수들 넣어서

     따라서 다음과 같이 unordered_map 을 만든다. (해쉬 테이블 구조로 되어있으므로 탐색에 소요되는 시간은 O(1)이다.)


    예를 들어 java backend junior pizza 150 인 지원자는 

    java - - - 
    - backend - -
    java backend - - 
    - - pizza - 
    ...
    java backend junior pizza

    위 query에 모두 해당하는 지원자 이므로 16가지 key_string 에 대해 해당 지원자의 점수를 insert한다.
    이때 2^4 에 해당하는 경우의 수를 처리하기 위해 비트마스킹을 사용한다.
    
    이 과정을 각 후보자들에 대해 마치고 나면
    지원자 조건을 key_string으로 하고 해당 지원자 조건을 만족하는 사람의 점수가 value인 vector<int>형태로 담긴다.

2. vector<int> 점수 중 특정 점수 이상의 것 찾아내기
	이제  "1 이상 100,000 의 수로 구성된 vector<int> 배열에서 특정 점수 k점 이상인 사람들이 몇명인가"
    하는 문제로 간소화되었다.
    
	이때는 이진 탐색을 활용하여 특정 수 이상의 숫자 개수를 찾아낸다.
    이진 탐색을 위하여 벡터를 한번 정렬하고, lower_bound 함수를 활용한다.
    
	lower_bound(first iterator, last iterator, value) :  value 이상인 값을 가지는 이터레이터를 반환


	ex) [1,2,3,4,5,6] k=3  이라면
    
    3을 가리키는 iterator를 반환하는 식이다. 
    인덱스로 반환받고 싶으면 이터레이터를 다시 빼주면 되는데.
    이때, 3보다 큰 수의 개수를 구해야 하므로 가장 마지막 이터레이터에서 빼준다.

    따라서 아래 식은 v 에서 point 이상의 점수 값을 구해주는 식이 된다.
    
   ( v.end() - upper_bound(v.begin(), v.end(), point) )

*/
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    string key[4], tmp;
    int point;

    for (auto& inf : info) {
        istringstream iss(inf);
        iss >> key[0] >> key[1] >> key[2] >> key[3] >> point;
        for (int i = 0; i < 16; i++) insert(key, i, point);
    }

    
    // 벡터순으로 정렬
    for (auto& m : map) sort(m.second.begin(), m.second.end());

    for (auto& que : query) {
        istringstream iss(que);
        iss >> key[0] >> tmp >> key[1] >> tmp >> key[2] >> tmp >> key[3] >>
            point;
        string s = key[0] + key[1] + key[2] + key[3];
        vector<int>& v = map[s];
        
        // 특정 범위의 점수를 넘는 이진탐색 
        answer.push_back(v.end() - lower_bound(v.begin(), v.end(), point));
    }

    return answer;
}