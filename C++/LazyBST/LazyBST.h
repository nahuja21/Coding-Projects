//PA5 - Lazy Balanced Trees
//Caden Goodwin & Nikhil Ahuja

#ifndef LazyBST_H
#define LazyBST_H

#include <cmath>
#include "LBTNode.h"



template <typename T>
class LazyBST{



public:

  LazyBST();
  virtual ~LazyBST();

  void insert(T n);
  void remove(T n);
  bool contains(T n);

  T& find(T n);

  void printLBT();
  void printTreeBackwards();

  friend ostream &operator << (ostream &logFile, LazyBST& LazyBST) {
    return LazyBST.printTree(logFile);
  }

  ostream &printTree(ostream &logFile){
    displayTree(logFile, m_rootNode);
    return logFile;
  }


private:

  int max; //max number of nodes
  int nodes; //number of nodes

  LBTNode<T>* m_rootNode; //root node
  
  double numNodes(LBTNode<T>*);
  int addNode(LBTNode<T>*& selectedNode, LBTNode<T>* insertNode);
  bool containsNode(LBTNode<T>* selectedNode, LBTNode<T>* insertNode);

  LBTNode<T>* getparentNode(T n, LBTNode<T>* rootNode);
  LBTNode<T>* getSuccessor(LBTNode<T>* rightSubtree);

  void findQueryNode(T key, LBTNode<T>*& queryNode, LBTNode<T>*& parentNode);
  void rebalanceLBT(LBTNode<T>* selectedNode);
  int flattenTree(LBTNode<T>* selectedNode, LBTNode<T>** treeArray, int i);

  LBTNode<T>* restructureTree(LBTNode<T>** treeArray, int numNodes);
  LBTNode<T>** getSubTreeArray(LBTNode<T>** originalArray, int i, int f);

  void displayTree(LBTNode<T>* selectedNode);
  void displayTree(ostream &logFile, LBTNode<T>* selectedNode);
  void backwardsDFS(LBTNode<T>* selectedNode);




};

template <typename T>
LazyBST<T>::LazyBST() : m_rootNode(nullptr), nodes(0), max(0) {} //constructor

template <typename T>
LazyBST<T>::~LazyBST() { //destructor
  if (m_rootNode) {
    delete m_rootNode;
    m_rootNode = nullptr;
  }
}


static double const log32(int max){
  return log(max)/log(3.0 / 2.0); //log base 3/2 of max
}



template <typename T>
int LazyBST<T>::addNode(LBTNode<T> *&selectedNode, LBTNode<T> *insertNode) { //add node to tree
  if (!selectedNode) {
    selectedNode = insertNode;
    return 0;
  }
  insertNode->m_parentNode = selectedNode;
  if (insertNode->m_content < selectedNode->m_content) {
    return addNode(selectedNode->m_left, insertNode) + 1;
  } else {
    return addNode(selectedNode->m_right, insertNode) + 1;
  }
}



template <typename T>
bool LazyBST<T>::contains(T n) { //check if tree contains node
  LBTNode<T> *insertNode = new LBTNode<T>(n);
  bool result = containsNode(m_rootNode, insertNode);
  delete insertNode;
  return result;
}

template <typename T>
LBTNode<T> *LazyBST<T>::restructureTree(LBTNode<T> **subTreeArr, int numNodes) { //restructure tree
  if (numNodes == 0) return nullptr;
  else {
    int median = numNodes / 2;
    LBTNode<T> *selectedNode = new LBTNode<T>(subTreeArr[median]->m_content);
    selectedNode->m_left = restructureTree(getSubTreeArray(subTreeArr, 0, median), median);
    selectedNode->m_left = selectedNode->m_left ? selectedNode->m_left : nullptr;
    selectedNode->m_left->m_parentNode = selectedNode;
    selectedNode->m_right = restructureTree(getSubTreeArray(subTreeArr, median + 1, numNodes), numNodes - median - 1);
    selectedNode->m_right = selectedNode->m_right ? selectedNode->m_right : nullptr;
    selectedNode->m_right->m_parentNode = selectedNode;
    return selectedNode;
  }
}

template <typename T>
void LazyBST<T>::insert(T content) { //insert node into tree
  LBTNode<T> *insertNode = new LBTNode<T>(content);
  int n = addNode(m_rootNode, insertNode);
  ++nodes;
  ++max;
  double l = log32(max);
  if (n > l) {
    LBTNode<T> *child = insertNode;
    while (numNodes(child) / numNodes(child->m_parentNode) <= 2.0 / 3.0) {
      child = child->m_parentNode;
    }
    rebalanceLBT(child->m_parentNode);
  }
}

template <typename T>
T &LazyBST<T>::find(T n) { //find node in tree
  return getparentNode(n, m_rootNode)->m_content;
}

template <typename T>
LBTNode<T>** LazyBST<T>::getSubTreeArray(LBTNode<T>** originalArray, int f, int l) {
  int numNodes = l - f;
  LBTNode<T>** subTreeArray = new LBTNode<T>*[numNodes];
  int i = 0;
  while (f < l) {
    subTreeArray[i++] = originalArray[f++];
  }
  return subTreeArray;
}


//Implemented tenerary operators to make code more concise. Learned from: https://www.programiz.com/cpp-programming/ternary-operator

template <typename T>
bool LazyBST<T>::containsNode(LBTNode<T> *selectedNode, LBTNode<T> *insertNode) { //check if tree contains node
  if (!selectedNode) {
    return false;
  } else if (insertNode->m_content == selectedNode->m_content) {
    return true;
  } else {
    return insertNode->m_content < selectedNode->m_content
               ? containsNode(selectedNode->m_left, insertNode)
               : containsNode(selectedNode->m_right, insertNode);
  }
}


template <typename T>
void LazyBST<T>::remove(T n) { //remove node from tree
  LBTNode<T> *queryNode = nullptr, *parentNode = nullptr;
  queryNode = m_rootNode;
  findQueryNode(n, queryNode, parentNode);
  if (!queryNode) return; //if node not found

  if (!queryNode->m_left && !queryNode->m_right) { //no children
    if (queryNode == m_rootNode) m_rootNode = nullptr; //if root node
    else {
      if (queryNode == parentNode->m_left) parentNode->m_left = nullptr; //if left child
      else parentNode->m_right = nullptr; //if right child
    }
  } else if (queryNode->m_left && queryNode->m_right) { //two children
    LBTNode<T> *successor = getSuccessor(queryNode->m_right); //get successor
    T data = successor->m_content; //get successor data
    remove(data); //remove successor
    queryNode->m_content = data; //replace query node data with successor data
  } else { //one child
    LBTNode<T> *child = queryNode->m_left ? queryNode->m_left : queryNode->m_right; //get child
    if (queryNode == m_rootNode) m_rootNode = child; //if root node
    else { //if not root node
      if (queryNode == parentNode->m_left) parentNode->m_left = child; //if left child
      else parentNode->m_right = child; //if right child
    }
  }
  --nodes; //decrement nodes
  if (max > 2 * nodes) { //if max is greater than twice the number of nodes
    max = nodes;
    rebalanceLBT(m_rootNode); //rebalance tree
  }
}

template <typename T>
void LazyBST<T>::backwardsDFS(LBTNode<T>* selectedNode) { //backwards depth first search
  if (selectedNode) {
    backwardsDFS(selectedNode->m_left);
    backwardsDFS(selectedNode->m_right);
    cout << selectedNode->m_content << endl;
  }
}


template <typename T>
LBTNode<T> *LazyBST<T>::getparentNode(T n, LBTNode<T> *rootNode) { //get parent node of node
  if (!rootNode) {
    return nullptr;
  } else if (n == rootNode->m_content) {
    return rootNode;
  } else {
    return n < rootNode->m_content ? getparentNode(n, rootNode->m_left)
                                 : getparentNode(n, rootNode->m_right);
  }
}

template <typename T>
LBTNode<T> *LazyBST<T>::getSuccessor(LBTNode<T> *rightSubtree) { //get successor of node
  while (rightSubtree->m_left) {
    rightSubtree = rightSubtree->m_left;
  }
  return rightSubtree;
}



template <typename T>
void LazyBST<T>::rebalanceLBT(LBTNode<T> *selectedNode) { //rebalance tree
  int nodes = numNodes(selectedNode);
  LBTNode<T> **treeArray = new LBTNode<T> *[nodes];
  int i = 0;
  flattenTree(selectedNode, treeArray, i);
  LBTNode<T> *subTreeparentNode = selectedNode->m_parentNode;
  if (!subTreeparentNode) //if root node
    m_rootNode = restructureTree(treeArray, nodes); //restructure tree
  else {
    if (subTreeparentNode->m_content < selectedNode->m_content) { //if right child
      subTreeparentNode->m_right = restructureTree(treeArray, nodes); //restructure tree
      subTreeparentNode->m_right->m_parentNode = subTreeparentNode; //set parent node
    } else { //if left child
      subTreeparentNode->m_left = restructureTree(treeArray, nodes); //restructure tree
      subTreeparentNode->m_left->m_parentNode = subTreeparentNode; //set parent node
    }
  }
}

template <typename T>
void LazyBST<T>::findQueryNode(T key, LBTNode<T> *&queryNode, LBTNode<T> *&parentNode) { //find node in tree
  while (queryNode && queryNode->m_content != key) { //while node not found
    parentNode = queryNode;
    queryNode = key < queryNode->m_content ? queryNode->m_left : queryNode->m_right; //if key is less than node content, go left, else go right
  }
}


template <typename T>
int LazyBST<T>::flattenTree(LBTNode<T> *selectedNode, LBTNode<T> **treeArray, int i) { //flatten tree (make array)
  if (!selectedNode) return i;
  i = flattenTree(selectedNode->m_left, treeArray, i);
  treeArray[i++] = selectedNode;
  return flattenTree(selectedNode->m_right, treeArray, i);
}

template <typename T>
void LazyBST<T>::printTreeBackwards() { //print tree backwards (depth first search)
  backwardsDFS(m_rootNode);
}




template <typename T>
void LazyBST<T>::displayTree(LBTNode<T>* selectedNode) { //display tree (depth first search)
  if (selectedNode) {
    displayTree(selectedNode->m_left); //go left
    cout << selectedNode->m_content << endl; //print node
    displayTree(selectedNode->m_right); //go right
  }
}

template <typename T>
double LazyBST<T>::numNodes(LBTNode<T> *node) { //get number of nodes in tree
  return node ? numNodes(node->m_left) + numNodes(node->m_right) + 1.0 : 0.0; //if node exists, return number of nodes in left subtree + number of nodes in right subtree + 1, else return 0
}


template <typename T>
void LazyBST<T>::printLBT() { //print tree
  displayTree(m_rootNode);
}

template<typename T>
void LazyBST<T>::displayTree(ostream &logFile, LBTNode<T>* selectedNode) { //display tree (depth first search)
  if (selectedNode) {
    displayTree(logFile, selectedNode->m_left);
    logFile << selectedNode->m_content << endl;
    displayTree(logFile, selectedNode->m_right);
  }
}




#endif