
// std::vector
// http://www.cplusplus.com/reference/vector/vector/

// Resizes the container so that it contains n elements.
// If n is smaller than the current container size, the content is reduced to its first n elements, removing those beyond (and destroying them).
void resize (size_type n);
void resize (size_type n, const value_type& val);

// Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
template <class InputIterator>
  void assign (InputIterator first, InputIterator last);
void assign (size_type n, const value_type& val);	
void assign (initializer_list<value_type> il);

// The vector is extended by inserting new elements before the element at the specified position, effectively increasing the container size by the number of elements inserted.
// Return an iterator that points to the first of the newly inserted elements.
iterator insert (const_iterator position, const value_type& val);
iterator insert (const_iterator position, size_type n, const value_type& val);
template <class InputIterator>
iterator insert (const_iterator position, InputIterator first, InputIterator last);
iterator insert (const_iterator position, value_type&& val);
iterator insert (const_iterator position, initializer_list<value_type> il);

// Removes from the vector either a single element (position) or a range of elements ([first,last)).
// Returns an iterator pointing to the new location of the element that followed the last element erased by the function call.
iterator erase (const_iterator position);
iterator erase (const_iterator first, const_iterator last);


// std::list
// http://www.cplusplus.com/reference/list/list/
// resize assign erase insert 同上
// splice remove remove_if unique merge


// std::deque
// http://www.cplusplus.com/reference/deque/deque/
// But in any case, they allow for the individual elements to be accessed directly through random access iterators
// But, unlike vectors, deques are not guaranteed to store all its elements in contiguous storage locations: accessing elements in a deque by offsetting a pointer to another element causes undefined behavior.
// The elements of a deque can be scattered in different chunks of storage, with the container keeping the necessary information internally to provide direct access to any of its elements in constant time and with a uniform sequential interface (through iterators).















