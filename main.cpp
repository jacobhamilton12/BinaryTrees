/* 
 *  main function
 */

#include "BTree.h"





int main()
{
  /*
    write main function
  */
	BTree tree;
	tree.insert(4);
	tree.insert(3);
	tree.insert(7);
	tree.insert(6);
	tree.insert(2);
	tree.insert(1);

	cout << tree << endl;
	cout << "\nSearch 6: " << tree.search(6)->value << endl;

	BTree tree2;
	ifstream file;
	file.open("../data-files/7p");
	file >> tree2;
	file.close();
	cout << tree2 << endl;

}

