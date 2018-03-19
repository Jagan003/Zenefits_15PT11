#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct node{

    int value;
    node *left, *right;
};

node* root = NULL, *prev, *prev1;

int count1 = -1;

void inorder(node* root){
    if(root == NULL)
        return;
    inorder(root->left);
    cout << root->value << " ";
    inorder(root->right);
}

void tree(int value, int count){

    node* temp = new node();
    if(count == 0){
        temp -> value = value;
        temp -> left = NULL;
        temp -> right = NULL;
        root = temp;
    }
    else if(count == 1){
        node* temp1 = root;
        if(count1 == 1 || count1 == 2){
            while(temp1->left != NULL){
                prev = temp1;
                temp1 = temp1->left;
            }
        }
        if(count1 >= 0){
            count1++;
            if(value){
                if(count1 == 3){
                    temp -> value;
                    temp -> left = NULL;
                    temp -> right = NULL;
                    prev -> right = temp;
                }
                else{
                    temp -> value;
                    temp -> left = NULL;
                    temp -> right = NULL;
                    temp1 -> left = temp;
                }
            }

        }
    }
    else if(count == 2){
        node* temp1 = root;
        if(count1 == 1 || count1 == 3){
            while(temp1->right != NULL){
                prev1 = temp1;
                temp1 = temp1->left;
            }
        }
        if(count1 >= 0){
            count1++;
            if(value){
                if(count1 == 2){
                    temp -> value;
                    temp -> left = NULL;
                    temp -> right = NULL;
                    prev -> left = temp;
                }
                else{
                    temp -> value;
                    temp -> left = NULL;
                    temp -> right = NULL;
                    temp1 -> right = temp;
                }
            }

        }
    }
}

void constructTree(string input){

    int count = 0, value;
    for(int _char=1;_char < input.length();_char++){

        if(input[_char] >= 49 && input[_char] <= 57){
            value = (int)input[_char] - 48;
            tree(value, count);
        }
        else if(input[_char] == 48 && count1 == -1){
            if(count == 0 || count == 2){
                count = 1;
            }
            else if(count == 1){
                count = 2;
            }
            tree(0, count);
        }
        else if(input[_char] == 123){
            if(count == 0 || count == 2)
                count = 1;
            else if(count == 1)
                count = 2;
            count1 = 0;
        }
        else if(input[_char] == 125)
            count1 = -1;
    }
}

int main(){

    int noOfCase;
    string input;
    cin >> noOfCase;
    for(int _case = 0;_case < noOfCase;_case++){
        cin >> input;
        constructTree(input);
        inorder(root);
    }
}
