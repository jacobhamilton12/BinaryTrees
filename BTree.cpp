/*
 * Binary Tree - source file (functions implementation)
 */

#include "BTree.h"


ostream& operator<<(ostream& out, BTree& tree)
{
  tree.inorder(out, tree.get_root());
  out << "\n\n";
  tree.print_level_by_level(out);

  return out;
}

ostream& operator<<(ostream& out, Node& node)
{
  out << "( "
      << node.value
      << ", "
      << node.search_cost
      << " )";
  return out;
}

istream& operator>>(istream& in, BTree& tree)
{
  /*
    take input from the in stream, and build your tree

    input will look like
    4 
    2 
    6 
    1 
    3 
    5 
    7
  */
  int n;
  in >> n;
  while(in.good()){
    tree.insert(n);
    in >> n;
  }
  

  return in;
}

BTree::BTree(const BTree& other)
{
  /*
    complete this copy constructor
    make sure when copying nodes to copy
    - value
    - left and right children
  */
  Node* node = other.get_root();
  root = new Node();
  root->value = node->value;
  root->search_cost = 1;

  help(other.get_root(),root);
}

BTree::BTree(BTree&& other)
{
  /*
    complete this move constructor
  */
  *this = other;
}

BTree& BTree::operator=(const BTree& other)
{
  if (this != &other) {
    /*
      complete this assignment operator
      make sure when copying nodes to copy
      - value
      - left and right children
    */
    Node* node = other.get_root();
    root = new Node();
    root->value = node->value;
    root->search_cost = 1;

    help(other.get_root(),root);
  }
  return *this;
}

void BTree::help(Node* node, Node* node2){
  Node* temp;
  
  if(node != nullptr){
    if(node->left != nullptr){
      temp = new Node();
      temp->value = node->left->value;
      temp->search_cost = node->left->search_cost;
      node2->left = temp;
      help(node->left, node2->left);
    }

    if(node->right != nullptr){
      temp = new Node();
      temp->value = node->right->value;
      temp->search_cost = node->right->search_cost;
      node2->right = temp;
      help(node->right, node2->right);
    }
  }


}

BTree& BTree::operator=(BTree&& other)
{
  if (this != &other) {
    *this = other;
  }
  return *this;
}

Node* BTree::insert(int obj)
{


  /*
    insert a node into the tree
    - first find where the node should go
    - then modify pointers to connect your new node 
  */
  return insertReal(obj, root);
}

Node* BTree::insertReal(int obj, Node* node){
  Node* temp = new Node();
  if(node == nullptr){
    node = new Node();
    node->value = obj;
    node->search_cost = 1;
    root = node;
  }
  else if(obj > node->value && node->right != nullptr)
    return insertReal(obj, node->right);
  else if(obj <= node->value && node->left != nullptr)
    return insertReal(obj, node->left);
  else if(obj > node->value && node->right == nullptr){
    temp->value = obj;
    temp->search_cost = node->search_cost + 1;
    node->right = temp;
  }
  else if(obj <= node->value && node->left == nullptr){
    temp->value = obj;
    temp->search_cost = node->search_cost + 1;
    node->left = temp;
  }
  if(temp->search_cost > size)
    size = temp->search_cost;
  return temp;
}

Node* BTree::search(int obj)
{
  /*
    recursivly search down the tree to find the node that contains obj
    - if you don't find anything return nullptr
  */
  return searchHelp(obj, root);
}

Node* BTree::searchHelp(int obj, Node* node){
  if(node != nullptr){
    if(obj > node->value){
      return searchHelp(obj, node->right);
    }
    if(obj < node->value){
      return searchHelp(obj, node->left);
    }
    if(obj = node->value){
      return node;
    }
  }
  return nullptr;
}

void BTree::update_search_cost()
{
  /*
    do a BFS of your tree and update the search cost of all nodes
  */
}

void BTree::inorder(ostream& out, Node* node)
{
  /*
    print your nodes in infix order

    if our tree looks like 

       4
     2   6
    1 3 5 7

    we should get

    1 2 3 4 5 6 7 
  */
  if(node != nullptr){
    inorder(out,node->left);
    out << node->value << " ";
    inord.push_back(node);
    inorder(out,node->right);
  }
}

void BTree::print_level_by_level(ostream& out)
{
  /*
    print the tree using a BFS 

    output should look like this if we dont have a full tree

    4
    2 6
    1 X 5 7
    X X X X X X X 9

    it will be helpfull to do this part iterativly, 
    so do the BFS with the std stack data structure.

    it may also be helpfull to put the entire tree into a vector 
    (probably google this if you dont know how to do it)
  */
  Node* node = get_root();
  if(node ==nullptr)
    return;

  out << root->value << endl;

  for(int i = 1; i < size; i++){
    for(Node* node : inord){
      if(node->search_cost == i){
        if(node->left != nullptr && node->right != nullptr)
          out << node->left->value << " " << node->right->value << " ";
        if(node->left == nullptr && node->right != nullptr)
          out << "X " << node->right->value << " ";
        if(node->left != nullptr && node->right == nullptr)
          out << node->left->value << " X ";
        if(node->left == nullptr && node->right == nullptr)
          out << "X X ";
      }
    }
    out << "\n";

     
  }
  return;
}



