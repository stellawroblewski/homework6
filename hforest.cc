//size: return how many trees are in the forest.
//add_tree: Take a pointer to an HTree and add it to the forest. You may use a smart pointer if you like.
//pop_tree: return a pointer to the HTree with the highest value in the root node, and remove it from the forest.

#include "HForest.hh"
#include <vector>
#include <iostream>

int HForest::size(){
    return (trees.size());
    }

bool compare_trees(HTree::tree_ptr_t t1, HTree::tree_ptr_t t2){
    return t1->get_key() < t2->get_key();
}

void HForest::add_tree(HTree::tree_ptr_t tree){
    trees.push_back(tree);
    std::make_heap(trees.begin(),trees.end(), compare_trees( ));
}

HTree::tree_ptr_t HForest::pop_tree(){
    HTree::tree_ptr_t maxval = trees[0];
    if (maxval != nullptr){
        return maxval;
        trees.erase(trees.begin());
    }
    else{
        return nullptr;
    }
}