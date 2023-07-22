







#std::vector


###Iterator invalidation

Operations	Invalidated
All read only operations	Never
swap, std::swap	            end()
clear, operator=, assign	Always
reserve, shrink_to_fit	    If the vector changed capacity, all of them. If not, none.
erase	                    Erased elements and all elements after them (including end())
push_back, emplace_back	    If the vector changed capacity, all of them. If not, only end().
insert, emplace	            If the vector changed capacity, all of them. If not, only those at or after the insertion point (including end()).
resize	                    If the vector changed capacity, all of them. If not, only end() and any elements erased.
pop_back	                The element erased and end().

#Element access
at                          access specified element with bounds checking
operator[]                  access specified element
front                       access the first element
back                        access the last element
data                        direct access to the underlying array


###Iterators

begin                       returns an iterator to the beginning
cbegin
   
end                         returns an iterator to the end
cend
   
rbegin                      returns a reverse iterator to the beginning
crbegin
   
rend                        returns a reverse iterator to the end
crend

 
###Capacity
empty                       checks whether the container is empty
size                        returns the number of elements
max_size                    returns the maximum possible number of elements
reserve                     reserves storage
capacity                    returns the number of elements that can be held in currently allocated storage
shrink_to_fit               reduces memory usage by freeing unused memory



###Modifiers
clear                       clears the contents
insert                      inserts elements
insert_range                inserts a range of elements
emplace                     constructs element in-place
erase                       erases elements
push_back                   adds an element to the end
emplace_back                constructs an element in-place at the end
append_range                adds a range of elements to the end
pop_back                    removes the last element
resize                      changes the number of elements stored
swap                        swaps the contents
