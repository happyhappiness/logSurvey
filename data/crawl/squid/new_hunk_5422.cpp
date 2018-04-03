    return 0;
}

void
ACLChecklist::operator delete (void *address)
{
    safe_free( address);
}

ACLChecklist::~ACLChecklist(){}

SQUIDCEXTERN void fatal (char const *msg)
{
    printf ("%s\n",msg);