    buf_ = newBuf;
}

#if DEBUGSTRINGS
void
String::stat(StoreEntry *entry) const
{
    storeAppendPrintf(entry, "%p : %d/%d \"%s\"\n",this,len_, size_, buf());
}

StringRegistry &
StringRegistry::Instance()
{
    return Instance_;
}

template <class C>
int
ptrcmp(C const &lhs, C const &rhs)
{
    return lhs - rhs;
}

void
StringRegistry::registerMe()
{
    registered = true;
    cachemgrRegister("strings",
                     "Strings in use in squid", Stat, 0, 1);
}

void

StringRegistry::add
    (String const *entry)
{
    if (!registered)
        registerMe();

    entries.insert(entry, ptrcmp);
}

void

StringRegistry::remove
    (String const *entry)
{
    entries.remove(entry, ptrcmp);
}

StringRegistry StringRegistry::Instance_;

extern size_t memStringCount();

void
StringRegistry::Stat(StoreEntry *entry)
{
    storeAppendPrintf(entry, "%lu entries, %lu reported from MemPool\n", (unsigned long) Instance().entries.elements, (unsigned long) memStringCount());
    Instance().entries.head->walk(Stater, entry);
}

void
StringRegistry::Stater(String const * const & nodedata, void *state)
{
    StoreEntry *entry = (StoreEntry *) state;
    nodedata->stat(entry);
}

#endif

#ifndef _USE_INLINE_
#include "String.cci"
#endif
