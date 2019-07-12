#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;


//Find in the vector, is vector has 2 elements v1, v2
//and v1 + v2 can equal to target value

template<typename T>
class TreeNode
{
public:
	TreeNode* parent;
	TreeNode* left;
	TreeNode* right;
	T val;
	void set(TreeNode* p, TreeNode* l, TreeNode* r, T v){
		parent = p;
		left = l;
		right = r;
		val = v;
	};
	TreeNode() :
		parent(NULL), left(NULL), right(NULL){};
};

void preOrderTravelsal(TreeNode<int>* root)
{
	if (!root)
		return;
	cout << "tree-val:" << root->val << endl;
	preOrderTravelsal(root->left);
	preOrderTravelsal(root->right);
}

void inOrderTravelsal(TreeNode<int>* root)
{
	if (!root)
		return;
	inOrderTravelsal(root->left);
	cout << "tree-val:" << root->val << endl;
	inOrderTravelsal(root->right);
}

void postOrderTravelsal(TreeNode<int>* root)
{
	if (!root)
		return;
	postOrderTravelsal(root->left);
	postOrderTravelsal(root->right);
	cout << "tree-val:" << root->val << endl;
}

int main()
{
	TreeNode<int> A;
	TreeNode<int> B;
	TreeNode<int> C;
	TreeNode<int> D;
	TreeNode<int> E;
	TreeNode<int> F;
	A.set(NULL, &B, &C, 1);
	B.set(&A, &D, &E, 2);
	C.set(&A, &F, NULL, 3);
	D.set(&B, NULL, NULL, 4);
	E.set(&B, NULL, NULL, 5);
	F.set(&C, NULL, NULL, 6);
	preOrderTravelsal(&A);
	cout << endl;
	inOrderTravelsal(&A);
	cout << endl;
	postOrderTravelsal(&A);
	return 0;
}
