#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Node {
public: 
	int data;
	Node* leftChild = NULL;
	Node* rightChild = NULL;
	Node* parent = NULL;

	Node(int _data, Node* _leftChild, Node* _rightChild, Node* _parent){
		data = _data;
		leftChild = _leftChild;
		rightChild = _rightChild;
		parent = _parent;
	}
};

Node* root;


void InsertNode(Node* tree, Node* node) {
	if (node->data <= tree->data) {
		if (tree->leftChild == NULL) {
			tree->leftChild = node;
			node->parent = tree;
			return;
		}
		else {
			InsertNode(tree->leftChild, node);
		}
	}
	else if (node->data > tree->data) {
		if (tree->rightChild == NULL) {
			tree->rightChild = node;
			node->parent = tree;
			return;
		}
		else {
			InsertNode(tree->rightChild, node);
		}
	}
}


Node* removeMax(Node* tree) {
	if (tree == NULL) return NULL;
	if (tree->rightChild == NULL) {
		Node* result = tree;
		if (tree->parent == NULL) {
			tree->leftChild->parent = NULL;
			root = tree->leftChild;
		}
		else {
			if (tree->leftChild == NULL) {
				tree->parent->rightChild = NULL;
			}
			else {
				tree->parent->rightChild = tree->leftChild;
				tree->leftChild->parent = tree->parent;
			}

			
		}
		return result;
		
	}
	else {
		return removeMax(tree->rightChild);
	}
}

Node* removeMin(Node* tree) {
	if (tree == NULL) return NULL;
	if (tree->leftChild == NULL) {
		Node* result = tree;
		if (tree->parent == NULL) {
			tree->rightChild->parent = NULL;
			root = tree->rightChild;
		}
		else {
			if (tree->rightChild == NULL) {
				tree->parent->leftChild = NULL;
			}
			else {
				tree->parent->leftChild = tree->rightChild;
				tree->rightChild->parent = tree->parent;
			}

			
		}


		return result;
		
	}
	else {
		return removeMin(tree->leftChild);
	}
}

void printTree(Node* root) {
	if (root != NULL) {
		cout << root->data << " ";
		printTree(root->leftChild);
		printTree(root->rightChild);
	}
	
}




int main() {

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int M, N, c;
		string command;
		string s;
		int num;
		cin >> M >> N;

		cin >> c;
		root = new Node(c, NULL, NULL, NULL);

		
		for (int j = 1; j < M; j++) {
			cin >> c;
			Node* node = new Node(c, NULL, NULL, NULL);
			InsertNode(root, node);
		}


		for (int j = 0; j < N; j++) {
			cin >> command;

			if (command == "Delete") {
				cin >> s;

				if (s == "min") {
					removeMin(root);
				}
				else if (s == "max") {
					removeMax(root);
				}
			}
			else if (command == "Add") {
				cin >> num;
				Node* add = new Node(num, NULL, NULL, NULL);
				InsertNode(root, add);
			}
		}


		cout << removeMin(root)->data << " " << removeMax(root)->data << "\n";
		


	}


}