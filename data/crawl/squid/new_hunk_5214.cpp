VectorIteratorBase<C> & VectorIteratorBase<C>:: operator ++()
{
    assert (theVector);

    if (!incrementable())
        fatal ("domain error");

    ++pos;

    return *this;
}

