#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    int arr1_row_size = arr1.size();
    int arr1_col_size = arr1[0].size();
    int arr2_row_size = arr2.size();
    int arr2_col_size = arr2[0].size();

    
    answer.assign(arr1_row_size,vector<int>(arr2_col_size,0));
    
    for(int i=0;i<arr1_row_size;i++){ // i : 행
        for(int j=0;j<arr2_col_size;j++){ // j : 열
            
            int sum=0;
            
            // i 행 원소와 j열 원소를 행렬 곱 
            for(int k=0;k<arr1_col_size;k++){
                sum += (arr1[i][k] * arr2[k][j]);
            }
            answer[i][j]= sum;
        }
    }
    return answer;
}