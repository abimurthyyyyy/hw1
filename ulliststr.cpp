#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

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

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val){
  if (size_==0){
    Item* temp = new Item();
    head_= temp;
    tail_=temp;
    temp->last=1;
    temp->val[0]=val;
  }
  else{
    if (tail_->last==ARRSIZE){
    Item* temp = new Item();
    tail_->next=temp;
    temp->prev=tail_;
    tail_=temp;
    tail_->last=1;
    tail_->val[0]=val;
    }
    else{
      tail_->val[tail_->last]=val;
      tail_->last++;
    }
  }
  size_++;
}

void ULListStr::push_front(const std::string& val){
  if (size_==0){
    Item* temp = new Item();
    head_= temp;
    tail_=temp;
    temp->first=ARRSIZE-1;
    temp->last=ARRSIZE;
    temp->val[temp->first]=val;
  }
  else{
    if (head_->first==0){
      Item* temp = new Item();
      head_->prev=temp;
      temp->next=head_;
      head_=temp;
      head_->first=ARRSIZE-1;
      head_->last=ARRSIZE;
      head_->val[head_->first]=val;
    }
    else{
      head_->first--;
      head_->val[head_->first]=val;
    }
    
  }
  size_++;

}

void ULListStr::pop_back(){
  if (size_==0){
    return;
  }
  else{
    size_--;
    tail_->last--;
    if (tail_->last-tail_->first==0){
      if (size_==0){
        delete head_;
        head_=NULL;
        tail_=NULL;
        return;
      }
      Item* temp=tail_->prev;
      delete tail_;
      tail_=temp;
      tail_->next=NULL;
    }
  }
}

std::string const & ULListStr::front() const{
  return head_->val[head_->first];
}

std::string const & ULListStr::back() const{
  return tail_->val[tail_->last-1];
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  if (loc<0 || loc>=size_){
    return NULL;
  }
  Item* temp = head_;
  while(loc+1>temp->last-temp->first){
    loc-=(temp->last-temp->first);
    temp=temp->next;
  }
  return &(temp->val[temp->first+loc]);
}

void ULListStr::pop_front(){
  if (size_==0){
    return;
  }
  else{
    size_--;
    head_->first++;
    if (head_->last-head_->first==0){
      if (size_==0){
        delete head_;
        head_=NULL;
        tail_=NULL;
        return;
      }
      Item* temp=head_->next;
      delete head_;
      head_=temp;
      head_->prev=NULL;
    }
  }
}

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
