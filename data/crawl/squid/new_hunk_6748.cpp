#define	LEFTPAREN   32
#define RIGHTPAREN  33
#define COMMA	    34
/* For SNMPv2 SMI pseudo-compliance */
#define DESCRIPTION 35
#define INDEX       36
#define QUOTE       37

struct tok {
	char *name;			/* token name */
	int len;			/* length not counting nul */
	int token;			/* value */
	int hash;			/* hash of name */
	struct tok *next;		/* pointer to next in hash table */
};


struct tok tokens[] = {
	{ "obsolete", sizeof ("obsolete")-1, OBSOLETE },
	{ "Opaque", sizeof ("Opaque")-1, OPAQUE },
	{ "recommended", sizeof("recommended")-1, RECOMMENDED }, 
	{ "optional", sizeof ("optional")-1, OPTIONAL },
	{ "mandatory", sizeof ("mandatory")-1, MANDATORY },
	{ "current", sizeof ("current")-1, MANDATORY },
	{ "not-accessible", sizeof ("not-accessible")-1, NOACCESS },
	{ "write-only", sizeof ("write-only")-1, WRITEONLY },
	{ "read-write", sizeof ("read-write")-1, READWRITE },
	{ "TimeTicks", sizeof ("TimeTicks")-1, TIMETICKS },
	{ "OBJECTIDENTIFIER", sizeof ("OBJECTIDENTIFIER")-1, OBJID },
	/*
	 * This CONTINUE appends the next word onto OBJECT,
	 * hopefully matching OBJECTIDENTIFIER above.
	 */
	{ "OBJECT", sizeof ("OBJECT")-1, CONTINUE },
	{ "NetworkAddress", sizeof ("NetworkAddress")-1, NETADDR },
	{ "Gauge", sizeof ("Gauge")-1, GAUGE },
	{ "OCTETSTRING", sizeof ("OCTETSTRING")-1, OCTETSTR },
	{ "OCTET", sizeof ("OCTET")-1, -1 },
	{ "OF", sizeof ("OF")-1, OF },
	{ "SEQUENCE", sizeof ("SEQUENCE")-1, SEQUENCE },
	{ "NULL", sizeof ("NULL")-1, NUL },
	{ "IpAddress", sizeof ("IpAddress")-1, IPADDR },
	{ "INTEGER", sizeof ("INTEGER")-1, INTEGER },
	{ "Counter", sizeof ("Counter")-1, COUNTER },
	{ "read-only", sizeof ("read-only")-1, READONLY },
	{ "ACCESS", sizeof ("ACCESS")-1, ACCESS },
	{ "MAX-ACCESS", sizeof ("MAX-ACCESS")-1, ACCESS },
	{ "STATUS", sizeof ("STATUS")-1, STATUS },
	{ "SYNTAX", sizeof ("SYNTAX")-1, SYNTAX },
	{ "OBJECT-TYPE", sizeof ("OBJECT-TYPE")-1, OBJTYPE },
	{ "{", sizeof ("{")-1, LEFTBRACKET },
	{ "}", sizeof ("}")-1, RIGHTBRACKET },
	{ "::=", sizeof ("::=")-1, EQUALS },
	{ "(", sizeof ("(")-1, LEFTPAREN },
	{ ")", sizeof (")")-1, RIGHTPAREN },
	{ ",", sizeof (",")-1, COMMA },
	{ "DESCRIPTION", sizeof ("DESCRIPTION")-1, DESCRIPTION },
	{ "INDEX", sizeof ("INDEX")-1, INDEX },
	{ "\"", sizeof ("\"")-1, QUOTE },
/* Hacks for easier MIBFILE coercing */
	{ "read-create", sizeof ("read-create")-1, READWRITE },
	{ NULL }
};

#define	HASHSIZE	32
#define	BUCKET(x)	(x & 0x01F)

static struct tok	*buckets[HASHSIZE];

static void
hash_init()
{
	register struct tok	*tp;
	register char	*cp;
	register int	h;
	register int	b;

	memset((char *)buckets, '\0', sizeof(buckets));
	for (tp = tokens; tp->name; tp++) {
		for (h = 0, cp = tp->name; *cp; cp++)
			h += *cp;
		tp->hash = h;
		b = BUCKET(h);
		if (buckets[b])
		    tp->next = buckets[b]; /* BUG ??? */
		buckets[b] = tp;
	}
}

#define NHASHSIZE    128
#define NBUCKET(x)   (x & 0x7F)
struct node *nbuckets[NHASHSIZE];

static void init_node_hash(nodes)
     struct node *nodes;
{
     register struct node *np, *nextp;
     register char *cp;
     register int hash;

     memset((char *)nbuckets, '\0', sizeof(nbuckets));
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


static void
print_error(string, token, type)
    char *string;
    char *token;
    int type;
{
    if (type == ENDOFFILE)
	snmplib_debug(0, "%s(EOF): On or around line %d\n", string, Line);
    else if (token)
	snmplib_debug(0, "%s(%s): On or around line %d\n", string, token, Line);
    else
	snmplib_debug(0, "%s: On or around line %d\n", string, Line);
}

#ifdef TEST
print_subtree(tree, count)
    struct snmp_mib_tree *tree;
    int count;
{
    struct snmp_mib_tree *tp;
    int i;

    for(i = 0; i < count; i++)
	printf("  ");
    printf("Children of %s:\n", tree->label);
    count++;
    for(tp = tree->child_list; tp; tp = tp->next_peer){
	for(i = 0; i < count; i++)
	    printf("  ");
	printf("%s\n", tp->label);
    }
    for(tp = tree->child_list; tp; tp = tp->next_peer){
	print_subtree(tp, count);
    }
}
#endif /* TEST */

int translation_table[40];

static void build_translation_table(){
    int count;

    for(count = 0; count < 40; count++){
	switch(count){
	    case OBJID:
		translation_table[count] = TYPE_OBJID;
		break;
	    case OCTETSTR:
		translation_table[count] = TYPE_OCTETSTR;
		break;
	    case INTEGER:
		translation_table[count] = TYPE_INTEGER;
		break;
	    case NETADDR:
		translation_table[count] = TYPE_IPADDR;
		break;
	    case IPADDR:
		translation_table[count] = TYPE_IPADDR;
		break;
	    case COUNTER:
		translation_table[count] = TYPE_COUNTER;
		break;
	    case GAUGE:
		translation_table[count] = TYPE_GAUGE;
		break;
	    case TIMETICKS:
		translation_table[count] = TYPE_TIMETICKS;
		break;
	    case OPAQUE:
		translation_table[count] = TYPE_OPAQUE;
		break;
	    case NUL:
		translation_table[count] = TYPE_NULL;
		break;
	    default:
		translation_table[count] = TYPE_OTHER;
		break;
	}
    }
}

/*
 * Find all the children of root in the list of nodes.  Link them into the
 * tree and out of the nodes list.
 */
static void
do_subtree(root, nodes)
    struct snmp_mib_tree *root;
    struct node **nodes;
{
    register struct snmp_mib_tree *tp;
    struct snmp_mib_tree *peer = NULL;
    register struct node *np=NULL , **headp=NULL;
    struct node *oldnp = NULL, *child_list = NULL, *childp = NULL;
    char *cp;
    int hash;
    
    tp = root;
    hash = 0;
    for(cp = tp->label; *cp; cp++)
        hash += *cp;
    headp = &nbuckets[NBUCKET(hash)];
    /*
     * Search each of the nodes for one whose parent is root, and
     * move each into a separate list.
     */
    for(np = *headp; np; np = np->next){
	if ((*tp->label != *np->parent) || strcmp(tp->label, np->parent)){
	    if ((*tp->label == *np->label) && !strcmp(tp->label, np->label)){
		/* if there is another node with the same label, assume that
		 * any children after this point in the list belong to the other node.
		 * This adds some scoping to the table and allows vendors to
