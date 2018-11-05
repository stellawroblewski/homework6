#include <iostream>
#define DEBUG
#include <cassert>
#include "HForest.hh"
int main(){
    HTree::HTree tr(3, 4, 
        std::make_shared <const HTree> (7, 7, 
            std::make_shared <const HTree> (10, 7,
            std::make_shared <const HTree> (9, 7,
        std::make_shared <const HTree> (6, 7), 
            std::make_shared <const HTree> (11, 7)),
            std::make_shared <const HTree> (1, 7)))); //create tree
    HTree::HTree tr1(3, 4, 
        std::make_shared <const HTree> (10, 7, 
            std::make_shared <const HTree> (12, 7,
            std::make_shared <const HTree> (6, 7,
        std::make_shared <const HTree> (11, 7), 
            std::make_shared <const HTree> (1, 7)),
            std::make_shared <const HTree> (9, 7)))); //create tree    

    HForest::HForest forest;
    forest.add_tree(tr); //add the two trees to the forest;
    forest.add_tree(tr1); 

    size_forest = forest.size()
}