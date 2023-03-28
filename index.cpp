// - [x]  insert // insert value into tree
// - [ ]  get_node_count // get count of values stored
// - [x]  print_values // prints the values in the tree, from min to max
// - [ ]  delete_tree
// - [ ]  is_in_tree // returns true if given value exists in the tree
// - [ ]  get_height // returns the height in nodes (single node’s height is 1)
// - [ ]  get_min // returns the minimum value stored in the tree
// - [ ]  get_max // returns the maximum value stored in the tree
// - [ ]  is_binary_search_tree
// - [ ]  delete_value
// - [ ]  get_successor // returns next-highest value in tree after given value, -1 if none
#include <iostream>
#include <string>

class Tree{
    private:
        struct tree_node{
            int key;
            tree_node *left;
            tree_node *right;
        };
        tree_node *root = NULL;


    public:
        void insert(int key){
            tree_node *newNode = (tree_node*) malloc(sizeof(tree_node));
            newNode->key = key;
            newNode->left = NULL;
            newNode->right = NULL;
            if(root == NULL) root = newNode;
            else findplace(newNode, root);
        };

        void findplace(tree_node *newNode, tree_node *next){
            //Look right
            if(newNode->key > next->key) {
                if(next->right != NULL) findplace(newNode, next->right);
                else {
                    //move RIGHT
                    next->right = newNode;
                };
            //Look left
            } if(newNode->key < next->key) {
                if(next->left != NULL) findplace(newNode, next->left);
                else{
                    //move LEFT
                    next->left = newNode;
                };
            };
        };
        void display_tree(){
            display("",root, false);
        };
        void display(const std::string& prefix, tree_node *next, bool isLeft){
            if(next != NULL){
                std::cout<<prefix;
                std::cout << (isLeft ? "├──" : "└──" );
                std::cout<<next->key<<std::endl;
                display( prefix + (isLeft ? "│   " : "    "), next->left, true);
                display( prefix + (isLeft ? "│   " : "    "), next->right, false);
            };
        };
} newtree;

int main(void){
    newtree.insert(12);
    newtree.insert(10);
    newtree.insert(15);
    newtree.insert(5);
    newtree.insert(11);
    newtree.insert(14);
    newtree.insert(17);
    newtree.insert(3);
    newtree.insert(8);
    newtree.insert(16);
    newtree.insert(19);
    newtree.insert(1);
    newtree.insert(4);
    newtree.insert(6);
    newtree.insert(9);
    newtree.insert(7);
    newtree.display_tree();
};

