#include<iostream>
using namespace std;

class node{
   public:
   int data;
   node*left;
   node*right;
   node(int value){
     data=value;
     left=NULL;
     right=NULL;
   }
};
class BST{
  public:
  node*root;
  BST(){
  root=NULL;}

void insert(int value){
   inserthelper(root,value);
}
void inserthelper(node*curr,int value){
   //base case if curr is null
   if(curr==NULL){
   curr=new node(value);
       if(root==NULL)
       root=curr;
       return;
   }

   //else compare the data with value and move to left or right
   else if(value<curr->data){
   //move left and insert
   if(curr->left==NULL)curr->left=new node(value);
   else inserthelper(curr->left,value);}
      else{
      //move right and insert
       if(curr->right==NULL)curr->right=new node(value);
       else inserthelper(curr->right,value);
      }
}

   
void display(){
   display2(root);
   cout<<endl;}
void display2(node*curr){
    //base condition
   if(curr==NULL) return;
   //display left
   
  else{
   display2(curr->left);
   //display curr
   cout<<curr->data<<",";
   //display right
   display2(curr->right);}
}

node*search1(node*curr,int value){
	//if value found or reach the end of the tree
	if(curr==NULL||curr->data==value)return curr;
	else if(value<curr->data) search1(curr->left,value);
	else search1(curr->right,value);}
bool search(int value){
	if(search1(root,value)!=NULL){
	cout<<"found"<<endl;}
	else{
		cout<<"not found"<<endl;}
	}
int count(){
	return count2(root);}
int count2(node*curr){
	if(curr==NULL){return 0;}
	else{
		return count2(curr->left)+1+count2(curr->right);
	}
}
int rangesearch(int k1,int k2){
	return rangesearch1(root,k1,k2);
		}
int rangesearch1(node*curr,int k1,int k2){
	//if current is NULL
	if (curr==NULL) return 0; 
	//current data is the highest value
	if (curr->data == k2 && curr->data == k1){ 
		cout<<curr->data<<","<<endl;
		return 1;
	}
	//current data within the range
	if (curr->data <= k2 && curr->data >= k1){ 
	//print the data
	cout<<curr->data<<",";
	//count the nodes
	return 1 + rangesearch1(curr->left, k1, k2) + rangesearch1(curr->right, k1, k2); 
	} 
	//is current data is less than k2 and k1
	else if (curr->data < k2){ 
	return rangesearch1(curr->right, k1, k2); 
			} 
	//if current data is greater than k2
	else {
	cout<<"\n"<<"The range of the given interval is ";
	return rangesearch1(curr->left, k1, k2); 
			}
			
}
int height(){
	return height1(root);
}
int height1(node* curr){  
    if (curr == NULL)  
    return 0;  
    else{  
      // compute the depth of each subtree 
      int leftheight = height1(curr->left);  
      int rightheight = height1(curr->right);  
              
      // use the larger one 
      if (leftheight > rightheight)  
          return(leftheight + 1);  
          else return(rightheight + 1);  
        } 
 } 
void print2DUtil(node *root, int space){
	// Base case  
	if (root == NULL)  
    return;  
	// Increase distance between levels  
	space += 5;  
	// Process right child first  
	print2DUtil(root->right, space);  

	// Print current node after space  
	// count  
	cout<<endl;  
	for (int i = 5; i < space; i++)  
	   cout<<" ";  
	   cout<<root->data<<"\n";  

	// Process left child  
	print2DUtil(root->left, space);  
			}  

// Wrapper over print2DUtil()  
void print2D(){  
	 cout << "******************************" << endl;
     // Pass initial space count as 0  
     print2DUtil(root, 0);  
     cout << "******************************" << endl;
                } 
};
int main(){
    BST b1;
    b1.insert(10);
    b1.insert(4);
    b1.insert(15);
    b1.insert(1);
    b1.insert(5);
    b1.insert(12);
    b1.insert(14);
    b1.insert(6);
    b1.insert(3);
    b1.display();
    b1.print2D();
    b1.search(8);
    cout<<"no of nodesis:"<<b1.count()<<endl;
    cout<<b1.rangesearch(4,12)<<endl;
    cout<<"the height is:"<<b1.height()<<endl;
}
