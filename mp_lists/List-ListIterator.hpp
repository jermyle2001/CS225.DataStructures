
class ListIterator : public std::iterator<std::bidirectional_iterator_tag, T> {
  private:
    // @TODO: graded in MP3.1
    ListNode* position_;

  public:
    ListIterator() : position_(NULL) { }
    ListIterator(ListNode* x) : position_(x) { }


    // Pre-Increment, ++iter
    ListIterator& operator++() {
        // @TODO: graded in MP3.1
/*
- Pre-Increment iterator (++iter)
- Iterator class has a single member var: pointer to position, "position_"
- It's a pre-increment operator: we want to increment our position, and 
-  THEN evaluate it.
*/

position_ = position_->next; //Increment position

        return *this; //Return new position
    }
    
    // Post-Increment, iter++
    ListIterator operator++(int) {
        // @TODO: graded in MP3.1
        ListNode* temp = position_;
        position_ = position_->next;
        return temp;
    }

    // Pre-Decrement, --iter
    ListIterator& operator--() {
        // @TODO: graded in MP3.1
//Return decremented iterator

position_ = position_ -> prev;


        return position_;
    }

    // Post-Decrement, iter--
    ListIterator operator--(int) {
        // @TODO: graded in MP3.1
ListNode* temp = position_;
position_ = position_->prev;
        return temp;
    }

    bool operator!=(const ListIterator& rhs) {
        // @TODO: graded in MP3.1
if(position_ == rhs.position_){
 return false;
}
        return true;
    }

    bool operator==(const ListIterator& rhs) {
        return !(*this != rhs);
    }

    const T& operator*() {
        return position_->data;
    }

    const T* operator->() {
        return &(position_->data);
    }
};
