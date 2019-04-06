/*
 * Binary Tree - header file
 */

#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Node
{
  int value;
  Node* left;
  Node* right;
  int search_cost;

  // constructor
  Node(int val = 0, Node* l = nullptr, Node* r = nullptr)
    : value(val), left(l), right(r), search_cost(0) {}

  // query
  bool is_leaf() { return (left == nullptr && right == nullptr); }
};

class BTree
{
private:
  int size;
  Node* root;
  vector<Node*> inord;

public:
  // constructors
  BTree() : root(nullptr), size(0) {} // default constructor
  BTree(const BTree& other); // copy constructor
  BTree(BTree&& other); // move constructor
  void help(Node* node, Node* node2);
  // assignment and move assignment operator
  BTree& operator=(const BTree& other);
  BTree& operator=(BTree&& other);

  int get_size() { return size; }
  Node* get_root() const { return root; }

  // should not be used unless it is really necessary
  void set_root(Node* node) { root = node; }
  Node* insert(int obj);
  Node* insertReal(int obj, Node* node);
  Node* search(int obj);
  Node* searchHelp(int obj, Node* node);
  void update_search_cost();
  void inorder(ostream& out, Node* node);
  void print_level_by_level(ostream& out);

};

ostream& operator<<(ostream& out, BTree& tree);
ostream& operator<<(ostream& out, Node& node);

istream& operator>>(istream& in, BTree& tree);

#endif
