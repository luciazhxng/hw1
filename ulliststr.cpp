#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream> // DELETE AFTER

using namespace std; // DELETE AFTER

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

void ULListStr::push_back(const std::string& val) {

  if(size_ == 0) {
    Item* curr_item = new Item();
    curr_item->val[0] = val;
    curr_item->first = 0; 
    curr_item->last = 1;
    size_++;
    head_ = curr_item;
    tail_ = curr_item;
  }
  else if(tail_->last == ARRSIZE) {
    Item* curr_item = new Item();
    curr_item->prev = tail_;
    tail_->next = curr_item;
    curr_item->val[0] = val;
    curr_item->first = 0; 
    curr_item->last = 1;
    tail_ = curr_item;
    size_++;
  }
  else {
    tail_->val[tail_->last] = val;
    tail_->last++;
    size_++;
  }
}

void ULListStr::pop_back() {
  if(size_ == 0) {
    return;
  }
  tail_->last--;
  size_--;
  if(size_ == 0) {
    delete tail_;
    tail_ = NULL;
    head_ = NULL;
  }
  else if(tail_->first == tail_->last) {

    Item* curr_item = tail_;
    tail_ = tail_->prev;
    tail_->next = NULL;
    delete curr_item;
  }
  
}

void ULListStr::push_front(const std::string& val) {
  if(size_ == 0) {
    Item* curr_item = new Item();
    curr_item->val[ARRSIZE-1] = val;
    curr_item->first = ARRSIZE - 1; 
    curr_item->last = ARRSIZE;
    size_++;
    head_ = curr_item;
    tail_ = curr_item;
  }
  else if(head_->first == 0) {
    Item* curr_item = new Item();
    curr_item->next = head_;
    head_->prev = curr_item;
    curr_item->val[ARRSIZE-1] = val;
    curr_item->first = ARRSIZE - 1; 
    curr_item->last = ARRSIZE;
    head_ = curr_item;
    size_++;
  }
  else {
    head_->val[head_->first-1] = val;
    head_->first--;
    size_++;
  }
}

void ULListStr::pop_front() {
  if(size_ == 0) {
    return;
  }
  // head_->val[head_->first] = "";
  head_->first++;
  size_--;
  if(size_ == 0) {
    delete head_;
    tail_ = NULL;
    head_ = NULL;
  }
  else if(head_->first == head_->last) {
    Item* curr_item = head_;
    head_ = head_->next;
    head_->prev = NULL;
    delete curr_item;
  }


}

std::string const & ULListStr::back() const {
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const {
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  if(loc < 0 || loc >= size_) {
    return NULL;
  }
  Item* curr_item = head_;
  int temp = 0; 
  while((temp + (curr_item->last - curr_item->first)) <= loc) {
    temp += curr_item->last - curr_item->first;
    curr_item = curr_item->next;
  }
  int sub_index = loc - temp;
  std::string* ret_val = &curr_item->val[curr_item->first + sub_index];
  return ret_val;
}
// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
