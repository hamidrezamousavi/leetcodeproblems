class MyCalendar {
private:
  vector<vector<int>> meetings;
  bool has_intersect(const vector<int>& meeting,int start, int end){
    return start < meeting[1] && end > meeting[0];
  }
  
public:
  MyCalendar():meetings{} {
    
  }
    
bool book(int start, int end) {
  if (meetings.size()== 0){
    meetings.push_back(vector<int>{start, end});
    return true;
 
  }
  auto met = find_if(meetings.begin(), meetings.end(),
                  [start](auto m){return m[0] > start;});
    
     
  if(met == meetings.end()){
      if(!has_intersect(*(met -1) , start, end)){
        meetings.push_back(vector<int>{start, end});
        return true;
      }else {
        return false;
      }
    }
    
  if(met == meetings.begin()){
      if(!has_intersect(*(met) , start, end)){
        meetings.insert(meetings.begin(),vector<int>{start, end});
        return true;
      }else{
        return false;
      }
    }
    
    if(!has_intersect(*(met-1), start, end) &&
       !has_intersect(*met, start, end)){
      meetings.insert(met,vector<int>{start, end});
      return true;
       }
    return false;  
  }
};