#include "htree.hh"
#define DEBUG
#include <cassert>

HTree::HTree(int key,
    uint64_t value,
    tree_ptr_t left,
    tree_ptr_t right) 
  : key_(key), value_(value), left_(left), right_(right)
{}

HTree::~HTree(){
    delete this;
}

int HTree::get_key() const{
    return key_;
}  // Return key in current node


uint64_t HTree::get_value() const{
    return value_;
} // Return value in current node
  // Return the child of this node indicated by dir.
  // If the child is nullptr (current node is a leaf), returns nullptr.

HTree::tree_ptr_t HTree::get_child(HTree::Direction dir) const{
    if (dir == Direction::LEFT){ 
        return (left_);
    }
    else{
        return (right_);
    }
}

bool HTree::find(int key) const{
    if (key_ == key) return true; //if curr node is the key, return
    if (left_ && left_->find(key_)) return true; //check left tree
    if (right_ && right_->find(key_)) return true; //check right tree
    return false;
}

// Return a list of directions from root to a node of a given key.
// Crashes (with an assert) if key not contained in this tree
HTree::path_t HTree::path_to(int key) const{
    bool is_key = find(key);
    assert(is_key == true); //make sure key is in tree
    path_t path;
    if (key_ == key) { //if curr key is correct, return path
        return path;
  } else if (left_ && find(left_->key_)) { //if it is in the left tree
        path.push_back(Direction::LEFT); // add Left to the path
        path_to(left_->key_); //rescursively call on left tree
  } else {  //if it is in the right tree
        path.push_back(Direction::RIGHT); // add Right to the path
        path_to(right_->key_);//rescursively call on right tree
  }
  return path;
}
    



