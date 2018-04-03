    return elements;
}

template <class V>
typename Splay<V>::const_iterator
Splay<V>::begin() const
{
    return const_iterator(head);
}

template <class V>
typename Splay<V>::const_iterator
Splay<V>::end() const
{
    return const_iterator(NULL);
}

template <class V>

class SplayConstIterator
{

public:
    typedef const V value_type;
    SplayConstIterator (SplayNode<V> *aNode);
    bool operator == (SplayConstIterator const &right) const;
    SplayConstIterator operator ++ (int dummy);
    SplayConstIterator &operator ++ ();
    V const & operator * () const;

private:
    void advance();
    void addLeftPath(SplayNode<V> *aNode);
    void init(SplayNode<V> *);
    Stack<SplayNode<V> *> toVisit;
};

template <class V>
SplayConstIterator<V>::SplayConstIterator (SplayNode<V> *aNode)
{
    init(aNode);
}

template <class V>
bool
SplayConstIterator<V>::operator == (SplayConstIterator const &right) const
{
    return toVisit.top() == right.toVisit.top();
}

template <class V>
SplayConstIterator<V> &
SplayConstIterator<V>::operator ++ ()
{
    advance();
    return *this;
}

template <class V>
SplayConstIterator<V>
SplayConstIterator<V>::operator ++ (int dummy)
{
    SplayConstIterator<V> result = *this;
    advance();
    return result;
}

/* advance is simple enough:
* if the stack is empty, we're done.
* otherwise, pop the last visited node
* then, pop the next node to visit
* if that has a right child, add it and it's
* left-to-end path.
* then add the node back.
*/
template <class V>
void
SplayConstIterator<V>::advance()
{
    if (toVisit.size() == 0)
        return;

    toVisit.pop();

    if (toVisit.size() == 0)
        return;

    SplayNode<V> *currentNode = toVisit.pop();

    addLeftPath(currentNode->right);

    toVisit.push_back(currentNode);
}

template <class V>
void
SplayConstIterator<V>::addLeftPath(SplayNode<V> *aNode)
{
    if (aNode == NULL)
        return;

    do {
        toVisit.push_back(aNode);
        aNode = aNode->left;
    } while (aNode != NULL);
}

template <class V>
void
SplayConstIterator<V>::init(SplayNode<V> *head)
{
    addLeftPath(head);
}

template <class V>
V const &
SplayConstIterator<V>::operator * () const
{
    /* can't dereference when past the end */

    if (toVisit.size() == 0)
        fatal ("Attempt to dereference SplayConstIterator past-the-end\n");

    return toVisit.top()->data;
}

#endif /* cplusplus */

#endif /* SQUID_SPLAY_H */
