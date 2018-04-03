}

ESIElement::Pointer
esiLiteral::makeUsable(esiTreeParentPtr , ESIVarState &newVarState) const
{
    debug (86,5)("esiLiteral::makeUsable: Creating usable literal\n");
    esiLiteral * result = new esiLiteral (*this);
    result->varState = cbdataReference (&newVarState);
    return result;
}

/* esiRemove */
void
esiRemoveFree (void *data)
{
    esiRemove *thisNode = (esiRemove *)data;
    debug (86,5)("esiRemoveFree %p\n", thisNode);
}

void *
esiRemove::operator new(size_t byteCount)
{
    assert (byteCount == sizeof (esiRemove));
    void *rv;
    CBDATA_INIT_TYPE_FREECB(esiRemove, esiRemoveFree);
    rv = (void *)cbdataAlloc (esiRemove);
    return rv;
}

void
esiRemove::operator delete (void *address)
{
    cbdataFree (address);
}

void
esiRemove::deleteSelf() const
{
    delete this;
}

ESIElement *
esiRemoveNew ()
{
    return new esiRemove;
}

esiRemove::esiRemove()
{}

void
esiRemove::finish()
{}

void
esiRemove::render(ESISegment::Pointer output)
{
    /* Removes do nothing dude */
    debug (86, 5)("esiRemoveRender: Rendering remove %p\n", this);
}

/* Accept non-ESI children */
bool
esiRemove::addElement (ESIElement::Pointer element)
{
    if (!dynamic_cast<esiLiteral*>(element.getRaw())) {
        debug (86,5)("esiRemoveAdd: Failed for %p\n",this);
        return false;
    }

    return true;
}

ESIElement::Pointer
esiRemove::makeCacheable() const
{
    debug (86,5)("esiRemove::makeCacheable: Returning NULL\n");
    return NULL;
}

ESIElement::Pointer
esiRemove::makeUsable(esiTreeParentPtr, ESIVarState &) const
{
    fatal ("esiRemove::Usable: unreachable code!\n");
    return NULL;
}

/* esiTry */
esiTry::~esiTry()
{
    debug (86,5)("esiTry::~esiTry %p\n", this);
}

void *
esiTry::operator new(size_t byteCount)
{
    assert (byteCount == sizeof (esiTry));

    if (!Pool)
        Pool = memPoolCreate ("esiTry", sizeof(esiTry));

    return memPoolAlloc (Pool);
}

void
esiTry::operator delete (void *address)
{
    memPoolFree (Pool, address);
}
