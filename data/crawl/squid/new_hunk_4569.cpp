}

void
String::append(String const &old)
{
    append (old.buf(), old.len_);
}

void
String::absorb(String &old)
{
    clean();
    size_ = old.size_;
    buf (old.buf_);
    len_ = old.len_;
    old.size_ = 0;
    old.buf_ = NULL;
    old.len_ = 0;
}

void
String::buf(char *newBuf)
{
    assert (buf_ == NULL);
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
