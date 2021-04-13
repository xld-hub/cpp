#include <iostream>

using namespace std;

typedef struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

}*Bitree;


TreeNode * buildTree(int arr[],int i,int n)//建立二叉树  
{  
    // if(begin>end)//递归的出口  
    //     return;
    // int mid = (begin+end)/2;//中间元素的下标  
    // if(T==NULL)//为当前树的根节点申请空间  
    // {            
    //     T = (TreeNode *)malloc(sizeof(TreeNode));  
    //     T->val = a[mid];//赋值  
    //     T->left = NULL;//左右子树也要置为NULL  
    //     T->right = NULL;  
    // }  
    // cout<<a[mid]<<" ";//下面2行为了方便看建立的过程  
    // buildTree(T->left,a,begin,mid-1);//递归简历左子树  
    // buildTree(T->right,a,mid+1,end);//递归建立右子树  
  
    
	TreeNode *ptr = NULL;
	if(i > n || NULL == arr)
	{
		return ptr;
	}
	if(i < n)
	{
		ptr = (TreeNode *)malloc(sizeof(TreeNode));  
		ptr->left = buildTree(arr,2*i+1,n);
        ptr->val = arr[i];
		ptr->right = buildTree(arr,2*i+2,n);
		
	}
	return ptr;

}

// void travel(Bitree T)  
// {  
//      if(T != NULL)  
//      {  
                          
//         travel(T->left);  
//         cout<<endl<<T->val<<" ";//中序遍历  
//         travel(T->right);  
//      }  
// }


class Solution {
public:
    int min = 65535;
    int prev = -10000;//0 <= Node.val <= 10^5
    int minDiffInBST(TreeNode* root) {
        if (root != nullptr) {

            minDiffInBST(root->left);
            
            min = (root->val - prev)<min?(root->val - prev):min;
            prev = root->val;
            minDiffInBST(root->right);
        }
        return min;
    }
};

int main(int argc, char const *argv[])
{
    
    Bitree tree = nullptr;
    int val[] = {4,2,6,1,3};
    int begin = 0, end = (sizeof(val)/sizeof(int));
    tree = buildTree(val, 0, end);
    Solution solution;
    cout<<solution.minDiffInBST(tree);

    return 0;
}
