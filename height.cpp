//Daniel Aviles Gerena 
//801-24-5453
//CCOM3034-0U1


#include <iostream>
#include "bintree.h"

template<class Node>
int BinaryTree<Node>::height() {
  return height(root);
}

template<class Node>
int BinaryTree<Node>::height(Node *u) {
    
    // Si el nodo es nullptr, significa que no hay nodo.
    if (nullptr == u) {
        return 0;
    }
    //Estos variables guardan el height de ambos lados del arbol
    int heightL = 0;
    int heightR = 0;

    //Buscamos para height de cada lado del arbol
    heightR = height(u->left);
    heightL = height(u->right);
    

    if (heightR > heightL) 
    {
        //Sumamos uno al height para que devuelva el nodo actual
        return ++heightR;
    } 
    else 
    {
        return ++heightL;
    }
  // TODO - fix this function
  // You can follow the pattern we used in clear()
  // and size().
  return 0;
}

int main() {
  BinaryTree<BTNode> arbol;

  arbol.root = new BTNode();
  arbol.root->right = new BTNode();
  arbol.root->right->right = new BTNode();
  arbol.root->right->right->right = new BTNode();

  // should print 4
  std::cout << arbol.height() << std::endl;

  BinaryTree<BTNode> bt;
  bt.root = new BTNode();

  // should print 1
  std::cout << bt.height() << std::endl;

  bt.root->left = new BTNode();
  bt.root->right = new BTNode();
  
  // now should print 2
  std::cout << bt.height() << std::endl;
  
  return 0;
}
