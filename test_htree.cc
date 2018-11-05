#include "htree.hh"
#include <iostream>
#define DEBUG
#include <cassert>

int main()
{
    HTree::HTree tr(3, 4, 
        std::make_shared <const HTree> (7, 7, 
            std::make_shared <const HTree> (10, 7,
            std::make_shared <const HTree> (9, 7,
        std::make_shared <const HTree> (6, 7), 
            std::make_shared <const HTree> (11, 7)),
            std::make_shared <const HTree> (1, 7)))); //create tree
    bool is_key = tr.find(3); //test HTree::find
    bool is_key1 = tr.find(7); //test HTree::find
    bool is_key2 = tr.find(10); //test HTree::find
    bool is_key3 = tr.find(1); //test HTree::find

    HTree::path_t path = tr.path_to(3); //test path_to node 

    HTree::tree_ptr_t child = tr.HTree::get_child(HTree::Direction::LEFT);
    int child_val = child->get_key();
    std::cout << child_val << std::endl;

    assert(is_key = 1);
    assert(is_key1 = 1);
    assert(is_key2 = 1);
    assert(is_key3 = 1);
return 0;
}