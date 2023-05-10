vector<int> findAnagrams(string s, string p) {
  vector<int> result{};
  map<char, int> goal;
  map<char, int> temp;
  if (s.size()< p.size())
    return vector<int>{};
  for(char c:p){
    if(goal.count(c)>0)
      goal[c]++;
    else
      goal.insert({c,1});
  }
  for(int i{0}; i<p.size();i++){
    if(temp.count(s[i])>0)
      temp[s[i]]++;
    else
      temp.insert({s[i],1});
  }
  if(temp == goal)
    result.push_back(0);
  
  int k= p.size();
  
  for(int i{0}; i< s.size()- p.size(); i++){
    temp[s[i]]--;
    if(temp[s[i]]== 0)
      temp.erase(s[i]);
    if(temp.count(s[k])>0)
      temp[s[k]]++;
    else
      temp.insert({s[k],1});
    
    k++;
  
    if(temp == goal)
      result.push_back(i+1);  

  }
 
  return result;        
}