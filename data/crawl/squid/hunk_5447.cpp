 SQUIDCEXTERN void arrayAppend(Array * s, void *obj);
 SQUIDCEXTERN void arrayPreAppend(Array * s, int app_count);
 
+#ifdef __cplusplus
+
+template<class E>
+void *
+Vector<E>::operator new(size_t size)
+{
+    return xmalloc (size);
+}
+
+template<class E>
+void
+Vector<E>::operator delete (void *address)
+{
+    xfree (address);
+}
+
+template<class E>
+Vector<E>::Vector() : capacity (0), count(0), items (NULL)
+{
+}
+
+template<class E>
+Vector<E>::~Vector() 
+{
+    clean();
+}
+
+template<class E>
+void
+Vector<E>::clean()
+{
+    /* could also warn if some objects are left */
+    delete[] items;
+    items = NULL;
+    capacity = 0;
+    count = 0;
+}
+
+/* grows internal buffer to satisfy required minimal capacity */
+template<class E>
+void
+Vector<E>::reserve(size_t min_capacity)
+{
+    const int min_delta = 16;
+    int delta;
+    if (capacity >= min_capacity)
+	return;
+    delta = min_capacity;
+    /* make delta a multiple of min_delta */
+    delta += min_delta - 1;
+    delta /= min_delta;
+    delta *= min_delta;
+    /* actual grow */
+    if (delta < 0)
+	delta = min_capacity - capacity;
+    E*newitems = new E[capacity + delta];
+    for (size_t counter = 0; counter < size(); ++counter) {
+	newitems[counter] = items[counter];
+    }
+    capacity += delta;
+    delete[]items;
+    items = newitems;
+}
+
+template<class E>
+void
+Vector<E>::push_back(E obj)
+{
+    if (size() >= capacity)
+	reserve (size() + 1);
+    items[count++] = obj;
+}
+
+template<class E>
+E
+Vector<E>::pop_back()
+{
+    assert (size());
+    value_type result = items[--count];
+    items[count] = value_type();
+    return result;
+}
+
+template<class E>
+E &
+Vector<E>::back()
+{
+    assert (size());
+    return items[size() - 1];
+}
+
+/* if you are going to append a known and large number of items, call this first */
+template<class E>
+void
+Vector<E>::preAppend(int app_count)
+{
+    if (size() + app_count > capacity)
+	reserve(size() + app_count);
+}
+
+template<class E>
+Vector<E> &
+Vector<E>::operator = (Vector const &old)
+{
+    clean();
+    reserve (old.size());
+    for (size_t counter = 0; counter < old.size(); ++counter)
+	push_back (old.items[counter]);
+    return *this;
+}
+
+template<class E>
+bool
+Vector<E>::empty() const
+{
+    return size() == 0;
+}
+
+template<class E>
+size_t
+Vector<E>::size() const
+{
+    return count;
+}
+
+template<class E>
+Vector<E>::iterator
+Vector<E>::begin()
+{
+    return iterator (0, *this);
+}
+
+template<class E>
+Vector<E>::iterator
+Vector<E>::end()
+{
+    return iterator(size(), *this);
+}
+
+template<class E>
+Vector<E>::const_iterator
+Vector<E>::begin() const
+{
+    return const_iterator (0, *this);
+}
+
+template<class E>
+Vector<E>::const_iterator
+Vector<E>::end() const
+{
+    return const_iterator(size(), *this);
+}
+
+
+template<class C>
+VectorIteratorBase<C>::VectorIteratorBase() : pos(0), theVector(NULL)
+{
+}
+
+template<class C>
+VectorIteratorBase<C>::VectorIteratorBase(C &container) : pos(container.begin()), theVector(&container)
+{
+}
+
+template<class C>
+VectorIteratorBase<C>::VectorIteratorBase(size_t aPos, C &container) : pos(aPos), theVector(&container) {}
+
+template<class C>
+bool VectorIteratorBase<C>:: operator != (VectorIteratorBase const &rhs)
+{
+    assert (theVector);
+    return pos != rhs.pos;
+}
+
+template<class C>
+bool VectorIteratorBase<C>:: operator == (VectorIteratorBase const &rhs)
+{
+    assert (theVector);
+    return pos == rhs.pos;
+}
+
+template<class C>
+bool 
+VectorIteratorBase<C>::incrementable() const
+{
+    assert (theVector);
+    return pos != theVector->size();
+}
+
+template<class C>
+VectorIteratorBase<C> & VectorIteratorBase<C>:: operator ++()
+{
+    assert (theVector);
+    if (!incrementable())
+	fatal ("domain error");
+    ++pos;
+    return *this;
+}
+
+template<class C>
+VectorIteratorBase<C> VectorIteratorBase<C>:: operator ++(int)
+{
+    VectorIteratorBase result(*this);
+    ++*this;
+    return result;
+}
+
+template<class C>
+typename C::value_type & VectorIteratorBase<C>::operator *() const
+{
+    return theVector->items[pos];
+}
+
+template<class C>
+typename C::value_type * VectorIteratorBase<C>::operator -> () const
+{
+    return &theVector->items[pos];
+}
+
+template<class C>
+VectorIteratorBase<C>&
+VectorIteratorBase<C>::operator =(VectorIteratorBase const &old) {
+    pos = old.pos;
+    theVector = old.theVector;
+    return *this;
+}
+
+template<class C>
+ssize_t
+VectorIteratorBase<C>::operator - (VectorIteratorBase const &rhs) const
+{
+    assert(theVector == rhs.theVector);
+    return pos - rhs.pos;
+}
+#endif
 
 #endif /* SQUID_ARRAY_H */
