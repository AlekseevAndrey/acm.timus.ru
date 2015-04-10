//#1078 from acm.timus.ru
#include <map>
#include <list>
#include <stack>
#include <iostream>

using namespace std;

struct TreeNode{
  TreeNode(int _ID, int _left, int _right):ID(_ID),left(_left),right(_right) {}
  int ID;
  int left, right;
  list<TreeNode*> sons;
};

TreeNode Head(0,0,0);
multimap<int, TreeNode> nodes;//pos, id 

void read();
void buildTree();
list<TreeNode*>::iterator getIteratorFor(TreeNode* node, list<TreeNode*>& stack);
void traversingTree();

int main(){
  read();
  buildTree();
  //traversingTree();
}


void read(){
  int N;
  cin >> N;
  
  int left, right;
  for(int i = 1; i <= N; i++){
    cin >> left >> right;
    TreeNode node(i,left,right);
    nodes.insert( {left,  node} );
    nodes.insert( {right, node} );
    cout<<endl << "====" << left << " " <<right;
  }
}

void buildTree(){
  list<TreeNode*> stack;// Or use tradition "stack"?
  for(auto& i:nodes){
    if(i.first == i.second.left){
      stack.push_back(&(i.second));
    } else {
      list<TreeNode*>::iterator list_it = getIteratorFor(&(i.second), stack);
  
      for(list<TreeNode*>::iterator i = stack.begin(); i != list_it; i++){
	//(*i)->sons.push_back(*list_it);// нужна проверка на то, что вершины не совпадают
	cout<<"ttt";
      }
      stack.erase(list_it);
    }
  }
}

list<TreeNode*>::iterator  getIteratorFor(TreeNode* node, list<TreeNode*>& stack){
  for(list<TreeNode*>::iterator i = stack.begin(); i != stack.end(); i++)
    if(*i == node)
      return i;
  return stack.end();
}

void traversingTree(){
}