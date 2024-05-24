#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    unordered_map<string, unordered_set<string>> reported_user;
    unordered_map<string, int> count;
    
    for(string &r : report)
    {
        stringstream ss(r);
        string user_id, reported_id;
        ss >> user_id >> reported_id;
        reported_user[reported_id].insert(user_id);
    }
    
    for(auto &[reported_id, user_id_lst] : reported_user)
    {
        if(user_id_lst.size() >= k)
        {
            for(const string &uid : user_id_lst)
                count[uid]++;
        }
    }
    
    vector<int> answer;
    for(string &id : id_list)
        answer.push_back(count[id]);
    return answer;
}