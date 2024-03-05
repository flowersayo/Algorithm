class Solution
{
public:
    map<string, string> parents;     // parents[name] : name 의 representative node 저장
    map<string, string> owner;       // owner[account] : account 의 주인이름 저장
    map<string, set<string>> unions; // {이름, 계정} 그룹 목록

    string find(string email)
    { // 특정 email 의 representative email 찾기

        if (parents.find(email) == parents.end())
        {
            return email;
        }

        if (parents[email] == email)
        { // root 이메일이면
            return email;
        }

        return parents[email] = find(parents[email]); // 그래프 압축
    }
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {

        vector<vector<string>> ans;

        for (int i = 0; i < accounts.size(); i++)
        {

            string p = find(accounts[i][1]);
            owner[p] = accounts[i][0]; // representative email 저장

            for (int j = 1; j < accounts[i].size(); j++)
            {
                parents[find(accounts[i][j])] = p;
            }
        }

        for (auto elem : parents)
        {

            string currentEmail = elem.first;
            string rootParentEmail = find(currentEmail);

            unions[rootParentEmail].insert(currentEmail);
        }

        for (auto u : unions)
        {

            string rootParentEmail = u.first;
            set emailSet = u.second;

            vector<string> emailList;

            emailList.push_back(owner[rootParentEmail]);

            for (auto it = emailSet.begin(); it != emailSet.end(); it++)
            {
                emailList.push_back(*it);
            }

            sort(emailList.begin() + 1, emailList.end()); // 이름뻬고 정렬

            ans.push_back(emailList);
        }

        return ans;
    }
};