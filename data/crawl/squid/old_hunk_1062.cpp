#include "wordlist.h"

void *
ACLIP::operator new (size_t byteCount)
{
    fatal ("ACLIP::operator new: unused");
    return (void *)1;
}

void
ACLIP::operator delete (void *address)
{
    fatal ("ACLIP::operator delete: unused");
}
