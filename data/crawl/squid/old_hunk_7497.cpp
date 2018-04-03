    return hptr ? (netdbEntry *) hptr->item : NULL;
}

static netdbEntry *
netdbLookupAddr(struct in_addr addr)
{
