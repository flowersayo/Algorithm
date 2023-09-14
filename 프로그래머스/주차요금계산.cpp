#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <math.h>
using namespace std;


int getDiff(string in_time, string out_time) {

    int in_time_total = stoi(in_time.substr(0,2)) * 60 + stoi(in_time.substr(3,2));
    int out_itme_total = stoi(out_time.substr(0,2)) * 60 +stoi(out_time.substr(3,2));
    
    return out_itme_total-in_time_total;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<pair<string,int>> tmp;
    unordered_map<string,vector<string>> map;
    unordered_map<string, int> res;
    
    for(int i = 0; i< records.size(); i++) {
        stringstream ss(records[i]);
        string tmp;
        vector<string> info;
        while (ss >> tmp) 
            info.push_back(tmp);
        
        if(info[2] == "IN") {
            map[info[1]].push_back(info[0]);
        }
        else {
            string out_time = info[0];
            string in_time = map[info[1]].back();
            map[info[1]].pop_back();
            int diff = abs(splitTime(out_time, in_time));
            res[info[1]] += diff;     
        }      
    }
    
    for(auto it : map) {
        if(!map[it.first].empty()) {
            res[it.first] += abs(splitTime("23:59",map[it.first].back()));
        }
    }
    
    for(auto it : res) {
        int price = 0;
        if(it.second <= fees[0]) price = fees[1];
        else {
            price = fees[1] + ceil((double)(it.second - fees[0]) / fees[2]) * fees[3];

        }
        tmp.push_back({it.first, price});
        
    }
    
    sort(tmp.begin(), tmp.end());
    
    for(int i = 0; i < tmp.size(); i++)
        answer.push_back(tmp[i].second);
    return answer;
}