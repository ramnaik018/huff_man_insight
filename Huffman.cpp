#include<iostream>
#include<vector>
using namespace std;

struct nodeN {
	float p;
	nodeN* parentnode = NULL; //initially parent node is initialised with NULL pointer of nodeN type
	nodeN* rightchild = NULL; //initially rightchild node is initialised with NULL pointer of nodeN type
	nodeN* leftchild = NULL; //initially leftchild node is initialised with NULL pointer of nodeN type
};

void bianli(nodeN*& head, string str) {   
	//a void return type of binali function is created
	//in these first two if contions we call recursively binali funtion for string operations
	if (head->leftchild != NULL) {
		bianli(head->leftchild, str + "1"); 
	}
	if (head->rightchild != NULL) {
		bianli(head->rightchild, str + "0");
	}
	//if this condition becomes true we print str right away
	if (head->rightchild == NULL && head->leftchild == NULL) { 
		cout << str << endl;
	}
}

int main(int argc, char** argv) { 
	//we initialize main function to take in vector p
	cout << "Now you can enter the number of source symbols" << endl;
	int n;
	cin >> n;
	cout << "Now you can enter the probability distribution " << endl;
	vector<nodeN> p;
	float a = 0;
	for (int i = 0; i < n; i++) {
		nodeN p1;
		cin >> p1.p;
		p.push_back(p1);
		a += p1.p;
	}
	//when a!=1 we throw an error msg on console through cout statement
	if (a != 1) {
		cout << "Error! The sum of probabilities of distribution is not equal to 0" << endl;
		return 0;
	}
	//we initialised new nodeN of pointer root of nodeN type
	nodeN* root = new nodeN;
	for (int j = 0; j < n - 1; j++) {
		nodeN* pnode = new nodeN;
		nodeN* left = new nodeN;
		*left = p.back();
		p.pop_back();
		nodeN* right = new nodeN;
		*right = p.back();
		p.pop_back();
		pnode->p = right->p + left->p;
		pnode->rightchild = right;
		pnode->leftchild = left;
		right->parentnode = left->parentnode = pnode;
		for (vector<nodeN>::iterator k = p.begin(); k <= p.end(); k++) {
			nodeN p2 = *k;
			if (pnode->p >= p2.p) {
				p.insert(k, *pnode);
				break;
			}
			else {
				if (k == p.end()) {
					p.push_back(*pnode);
				}
			}
		}
		root = pnode;
	}
	//here we call binali function through some oops concepts
	cout << "The Huffman coding can be represented as follows:( 1)for high probability the lenght of code is short, 2)for low probability the length of code is long): " << endl;
	bianli(root, "");
	return 0;
}