init_node_hash(nodes)
     struct node *nodes;
{
     struct node *np, *nextp;
     char *cp;
     int hash;

     bzero((char *)nbuckets,sizeof(nbuckets));
     for(np = nodes; np;){
         nextp = np->next;
         hash = 0;
	 for(cp = np->parent; *cp; cp++)
	     hash += *cp;
	 np->next = nbuckets[NBUCKET(hash)];
	 nbuckets[NBUCKET(hash)] = np;
	 np = nextp;
     }
}

static char *
Malloc(num)
    unsigned num;
{
#ifndef linux
    char* calloc();
#endif
    
    /* this is to fix (what seems to be) a problem with the IBM RT C
       library malloc */
    if (num < 16)
	num = 16;
    return (char *)calloc(1, num);
}

static void
print_error(string, token, type)
    char *string;
    char *token;
    int type;
{
    if (type == ENDOFFILE)
	fprintf(stderr, "%s(EOF): On or around line %d\n", string, Line);
