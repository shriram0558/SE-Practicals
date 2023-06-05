#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class OBST {
    public:
    int n;
    Node* root;
    vector<int> keys, p, q;
    vector<vector<int>> W, C, R;

    OBST(int n){
        this->n = n;
        keys.resize(n + 1);
        p.resize(n + 1);
        q.resize(n + 1);
        W.resize(n + 1, vector<int>(n + 1, -1));
        C.resize(n + 1, vector<int>(n + 1, -1));
        R.resize(n + 1, vector<int>(n + 1, -1));

        cout << "Enter Keys: ";
        for(int i=1; i<=n; i++){
            cin >> keys[i];
        }

        cout << "Enter Success Probabilities: ";
        for(int i=1; i<=n; i++){
            cin >> p[i];
        }

        cout << "Enter Failure Probabilities: ";
        for(int i=0; i<=n; i++){
            cin >> q[i];
        }
    }

    void construct() {

        // W[i][i] = q[i]
        for(int i=0; i<=n; i++){
            W[i][i] = q[i];
        }

        // C[i][i] = 0
        for(int i=0; i<=n; i++){
            C[i][i] = 0;
        }

        for(int diagonal=1; diagonal<=n; diagonal++){

            for(int i=0, j=diagonal; i<=n && j<=n; i++, j++){

                W[i][j] = W[i][j - 1] + p[j] + q[j];

                // minCost = min( all C[i][k] + C[k+1][j] ) where k = i to j-1
                int minCost = INT_MAX;
                int minK = -1;
                for(int k=i; k<j; k++){
                    if(C[i][k] + C[k+1][j] < minCost){
                        minCost = C[i][k] + C[k+1][j];
                        minK = k+1;
                    }
                }
                C[i][j] = minCost + W[i][j];
                R[i][j] = minK;
            }
        }
    }

    void buildObst() {
        root = build(0, n);
    }

    void print() {
        cout << "Inorder: ";
        inorder(root);
        cout << endl;
    }

    Node* build(int i, int j){

        if(R[i][j] == -1)
            return NULL;

        int index = R[i][j];
        int key = keys[index];
        Node* root = new Node(key);
        root->left = build(i, index-1);
        root->right = build(index, j);
        return root;
    }

    void inorder(Node* node){

        if(node == NULL)
            return;

        inorder(node->left);

        cout << node->data << " ";

        inorder(node->right);
    }
};

int main(){

    int n;
    cout << "Enter No of Nodes in OBST: ";
    cin >> n;

    OBST obst(n);
    obst.construct();
    obst.buildObst();
    obst.print();
    
    return 0;
}