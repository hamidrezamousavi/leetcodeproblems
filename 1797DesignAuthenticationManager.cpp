#include <string>
#include <map>
#include <algorithm>
using namespace std;

struct Token{
  string tokenId;
  int startTime;
  int endTime;
};

class AuthenticationManager {
  int timeToLive;
  map<string,pair<int, int>> tokTable;
public:
    AuthenticationManager(int timeLive) {
      timeToLive = timeLive;
      tokTable = {};
    }
    
    void generate(string tokenId, int currentTime) {
      Token newToken{.tokenId{tokenId},
                     .startTime{currentTime},
                     .endTime{currentTime+timeToLive}};
      tokTable[newToken.tokenId] = pair<int,int>{
                    newToken.startTime, newToken.endTime};
      
      return;
    }
    
    void renew(string tokenId, int currentTime) {
      if (currentTime <= tokTable[tokenId].first ||
          currentTime >= tokTable[tokenId].second)
        return;
      tokTable[tokenId].second = currentTime + timeToLive;
      return;  
    }
    
    int countUnexpiredTokens(int currentTime) {
      int result = count_if(tokTable.begin(), tokTable.end(),
                           [currentTime](auto token){
                            return 
                            currentTime>token.second.first && 
                            currentTime<token.second.second;
                           });
      return result;    
    }
};
