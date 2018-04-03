    return 0;
}

SQUIDCEXTERN void aclChecklistFree(ACLChecklist *)
{
    fatal ("dummy function\n");
}

SQUIDCEXTERN void fatal (char const *msg)
{
    printf ("%s\n",msg);