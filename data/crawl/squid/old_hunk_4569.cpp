}

void
SqString::append(SqString const &old)
{
    append (old.c_str(), old.size());
}

const char&
SqString::operator [](unsigned int pos) const
{
    assert(pos < size_ );

    return buf_[pos];
}

char&
SqString::operator [](unsigned int pos)
{
    assert(pos < size_ );

    return buf_[pos];
}

#if DEBUGSTRINGS
void
SqString::stat(StoreEntry *entry) const
{
    storeAppendPrintf(entry, "%p : %d/%d \"%s\"\n",this,len_, size_, c_str());
}

SqStringRegistry &
SqStringRegistry::Instance()
{
    return Instance_;
}
