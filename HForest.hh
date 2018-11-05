//size: return how many trees are in the forest.
//add_tree: Take a pointer to an HTree and add it to the forest. You may use a smart pointer if you like.
//pop_tree: return a pointer to the HTree with the highest value in the root node, and remove it from the forest.
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>
#include <list>
#pragma once

class HTree {
 public:
  using tree_ptr_t = std::shared_ptr<const HTree>;
  enum class Direction { LEFT, RIGHT };
  using path_t = std::list<Direction>;
    // Initialize with a key and a value:
  HTree(int key,
        uint64_t value,
        tree_ptr_t left = nullptr,
        tree_ptr_t right = nullptr);
  ~HTree();

  int get_key() const;  // Return key in current node
  uint64_t get_value() const;      // Return value in current node

  // Return the child of this node indicated by dir.
  // If the child is nullptr (current node is a leaf), returns nullptr.
  tree_ptr_t get_child(Direction dir) const;

  // Return a list of directions from root to a node of a given key.
  // Crashes (with an assert) if key not contained in this tree
  path_t path_to(int key) const;

  bool find(int key_) const;
  
  int key_;
  uint64_t value_;
  tree_ptr_t left_;
  tree_ptr_t right_;
};

class HForest{
  public:
    std::vector<HTree::tree_ptr_t> trees;

    int size();

    void add_tree(HTree::tree_ptr_t tree);

    HTree::tree_ptr_t pop_tree();







};