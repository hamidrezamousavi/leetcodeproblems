

struct NodeTree{
  int id;
  vector<NodeTree*> subOrd;
  int informTime;
};

vector<vector<int>> subVec(int n, vector<int>& manager){
  vector<vector<int>> result(n);
  for(int i{0}; i< n; i++){
    
    if(manager[i] == -1)
      continue;
    result[manager[i]].push_back(i);
  }
  return result;
}
NodeTree* setTree(int n, int headID, vector<int>& manager, vector<int>& informTime){
  NodeTree* headNode = new NodeTree{.id=headID,.subOrd={}, .informTime=informTime[headID]};
  vector<vector<int>> subOrd = subVec(n, manager);
  vector<NodeTree*> tempNodes{};
  for(auto sub:subOrd[headID]){
    NodeTree* temp = new NodeTree{.id = sub, .subOrd{},.informTime = informTime[sub]};
    headNode->subOrd.push_back(temp);
    tempNodes.push_back(temp);
  }
  
  while(!tempNodes.empty()){
    NodeTree* node = tempNodes.back();
    
    tempNodes.pop_back();
    
    for(auto sub:subOrd[node->id]){
      
      NodeTree* temp = new NodeTree{.id = sub, .subOrd{},.informTime = informTime[sub]};
      node->subOrd.push_back(temp);
      tempNodes.push_back(temp);
    }
  }

  return headNode;
}
vector<NodeTree*> getEndNodes(NodeTree* head){
  vector<NodeTree*> nodeStack{};
  vector<NodeTree*> tempNodeStack{};
  vector<NodeTree*> endNodeStack{};
  nodeStack = head->subOrd;
  while(!nodeStack.empty()){  
    for(auto node:nodeStack){
      if(node->subOrd.empty()){
        endNodeStack.push_back(node);
      }else{
        tempNodeStack.insert(tempNodeStack.end(),
                            node->subOrd.begin(),
                            node->subOrd.end());;
      }
    }
    nodeStack = tempNodeStack;
    tempNodeStack = {};
  }
  

  return endNodeStack;
}
int getIdRecvTime(int id,
                    vector<int>& manager,
                    vector<int>& informTime,
                    int headID){
  int time{0};
  while(id != headID){
    time += informTime[manager[id]];
    id = manager[id];
  }
  return time;  
}

int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
  auto tree = new NodeTree;
  tree = setTree(n, headID, manager, informTime);
  auto endNodes = getEndNodes(tree);
  int time{0};
  for(auto node:endNodes){
    int idTime = getIdRecvTime(node->id, manager, informTime, headID);
    time = idTime > time ?idTime:time;
  }
  return time;
}
