
ACLChecklist::~ACLChecklist(){}

SQUIDCEXTERN void fatal (char const *msg)
{
    printf ("%s\n",msg);
    exit (1);
}

SQUIDCEXTERN ACLChecklist *aclChecklistCreate(const acl_access *,
        request_t *,
        const char *ident)
