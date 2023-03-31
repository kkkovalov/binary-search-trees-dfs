// - [x]  insert // insert value into tree
// - [x]  get_node_count // get count of values stored
// - [x]  print_values // prints the values in the tree, from min to max
// - [x]  delete_tree
// - [x]  is_in_tree // returns true if given value exists in the tree
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

        int get_node_count(){
            int count = 1;
            if(root != NULL) counting_fnc(count, root->left, root->right);
            else return 0;
            return count;
        };

        bool is_in_tree(int value){
            bool result = false;
            if(root != NULL) find_node(result, value, root);
            else return false;
            return result;
        };

        int get_height(){
            return height(0,0, root);
        };

        void display_tree(){
            display("",root, false);
        };

        void delete_tree(){
            if(root != NULL) {
                delete_node(-1,root->left, root->right);
                free(root);
                root = NULL;
                std::cout<<"Tree deleted"<<std::endl;
            } else return;
        }

    private:
        void display(const std::string& prefix, tree_node *next, bool isLeft){
            if(next != NULL){
                std::cout<<prefix;
                std::cout << (isLeft ? "├──" : "└──" );
                std::cout<<next->key<<std::endl;
                display( prefix + (isLeft ? "│   " : "    "), next->left, true);
                display( prefix + (isLeft ? "│   " : "    "), next->right, false);
            };
        };
        void counting_fnc(int &count, tree_node *left, tree_node *right){
            if(left == NULL && right == NULL) return ;
            if(left != NULL) {
                count++;
                counting_fnc(count, left->left, left->right);
            }
            if(right != NULL) {
                count++;
                counting_fnc(count, right->left, right->right);
            }
        };

        void delete_node(int value, tree_node *left, tree_node *right){
            if(value == -1) {
                if(left != NULL){
                    delete_node(value, left->left, left->right);
                    free(left);
                } else return ;
                if(right != NULL){
                    delete_node(value, right->left, right->right);
                    free(right);
                } else return;
            } else return;
        };
        void find_node(bool &result, int value, tree_node *node){
            if(node->key == value) {
                result = true;
                return;
            }
            if(node->left != NULL) {
                find_node(result, value, node->left);
            };
            if(node->right != NULL){
                find_node(result, value, node->right);
            };
            return ;
        };

        int height(int left_count, int right_count, tree_node *node){
            if(node->left == NULL && node->right == NULL) return left_count >= right_count ? left_count : right_count;
            if(node->left != NULL){
                height(left_count + 1, right_count, node->left);
            };
            if(node->right != NULL) {
                height(left_count, right_count+1, node->right);
            };
            return ;
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
    std::cout<<"Tree count:  "<<newtree.get_node_count()<<std::endl;
    int search_value = 17;
    std::cout<<"Value: "<<search_value<<" Found: "<<newtree.is_in_tree(search_value)<<std::endl;
    std::cout<<"Tree height: "<<newtree.get_height()<<std::endl;

};

