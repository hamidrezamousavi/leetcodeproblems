 vector<vector<string>> groupAnagrams(vector<string>& strs) {
  map<string, vector<string>> strMap{};
  string temp{};
  for(string str:strs){
    temp = str ;
    sort(str.begin(), str.end());
    strMap[str].push_back(temp);
  }
  int i{0};
  vector<vector<string>> result;
  for (const auto& [key, value] : strMap){   
    result.push_back(vector<string>{});
    for(auto item:value)        
        result[i].push_back(item);
    i++; 
  }
 return result;      
}