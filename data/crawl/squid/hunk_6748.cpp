 #define	LEFTPAREN   32
 #define RIGHTPAREN  33
 #define COMMA	    34
+/* For SNMPv2 SMI pseudo-compliance */
 #define DESCRIPTION 35
-#define QUOTESTRING 36
-#define INDEX       37
-#define DEFVAL      38
-#define DEPRECATED  39
-#define SIZE        40
-#define BITSTRING   (41 | SYNTAX_MASK)
-#define NSAPADDRESS (42 | SYNTAX_MASK)
-#define COUNTER64   (43 | SYNTAX_MASK)
-#define OBJGROUP    44
-#define NOTIFTYPE   45
-#define AUGMENTS    46
-#define COMPLIANCE  47
-#define READCREATE  48
-#define UNITS       49
-#define REFERENCE   50
-#define NUM_ENTRIES 51
-#define MODULEIDENTITY 52
-#define LASTUPDATED 53
-#define ORGANIZATION 54
-#define CONTACTINFO 55
-#define UINTEGER32 (56 | SYNTAX_MASK)
-#define CURRENT	    57
-#define DEFINITIONS 58
-#define END         59
-#define SEMI        60
+#define INDEX       36
+#define QUOTE       37
 
 struct tok {
-    char *name;			/* token name */
-    int len;			/* length not counting nul */
-    int token;			/* value */
-    int hash;			/* hash of name */
-    struct tok *next;		/* pointer to next in hash table */
+	char *name;			/* token name */
+	int len;			/* length not counting nul */
+	int token;			/* value */
+	int hash;			/* hash of name */
+	struct tok *next;		/* pointer to next in hash table */
 };
 
 
-struct tok tokens[] =
-{
-    {"obsolete", sizeof("obsolete") - 1, OBSOLETE},
-    {"Opaque", sizeof("Opaque") - 1, OPAQUE},
-/*      { "recommended", sizeof("recommended")-1, RECOMMENDED },  */
-    {"optional", sizeof("optional") - 1, OPTIONAL},
-    {"LAST-UPDATED", sizeof("LAST-UPDATED") - 1, LASTUPDATED},
-    {"ORGANIZATION", sizeof("ORGANIZATION") - 1, ORGANIZATION},
-    {"CONTACT-INFO", sizeof("CONTACT-INFO") - 1, CONTACTINFO},
-    {"MODULE-IDENTITY", sizeof("MODULE-IDENTITY") - 1, MODULEIDENTITY},
-    {"MODULE-COMPLIANCE", sizeof("MODULE-COMPLIANCE") - 1, COMPLIANCE},
-    {"DEFINITIONS", sizeof("DEFINITIONS") - 1, DEFINITIONS},
-    {"END", sizeof("END") - 1, END},
-    {";", sizeof(";") - 1, SEMI},
-    {"AUGMENTS", sizeof("AUGMENTS") - 1, AUGMENTS},
-    {"not-accessible", sizeof("not-accessible") - 1, NOACCESS},
-    {"write-only", sizeof("write-only") - 1, WRITEONLY},
-    {"NsapAddress", sizeof("NsapAddress") - 1, NSAPADDRESS},
-    {"UNITS", sizeof("Units") - 1, UNITS},
-    {"REFERENCE", sizeof("REFERENCE") - 1, REFERENCE},
-    {"NUM-ENTRIES", sizeof("NUM-ENTRIES") - 1, NUM_ENTRIES},
-    {"BITSTRING", sizeof("BitString") - 1, BITSTRING},
-    {"BIT", sizeof("BIT") - 1, CONTINUE},
-    {"Counter64", sizeof("Counter64") - 1, COUNTER64},
-    {"TimeTicks", sizeof("TimeTicks") - 1, TIMETICKS},
-    {"NOTIFICATION-TYPE", sizeof("NOTIFICATION-TYPE") - 1, NOTIFTYPE},
-    {"OBJECT-GROUP", sizeof("OBJECT-GROUP") - 1, OBJGROUP},
-    {"OBJECTIDENTIFIER", sizeof("OBJECTIDENTIFIER") - 1, OBJID},
+struct tok tokens[] = {
+	{ "obsolete", sizeof ("obsolete")-1, OBSOLETE },
+	{ "Opaque", sizeof ("Opaque")-1, OPAQUE },
+	{ "recommended", sizeof("recommended")-1, RECOMMENDED }, 
+	{ "optional", sizeof ("optional")-1, OPTIONAL },
+	{ "mandatory", sizeof ("mandatory")-1, MANDATORY },
+	{ "current", sizeof ("current")-1, MANDATORY },
+	{ "not-accessible", sizeof ("not-accessible")-1, NOACCESS },
+	{ "write-only", sizeof ("write-only")-1, WRITEONLY },
+	{ "read-write", sizeof ("read-write")-1, READWRITE },
+	{ "TimeTicks", sizeof ("TimeTicks")-1, TIMETICKS },
+	{ "OBJECTIDENTIFIER", sizeof ("OBJECTIDENTIFIER")-1, OBJID },
 	/*
 	 * This CONTINUE appends the next word onto OBJECT,
 	 * hopefully matching OBJECTIDENTIFIER above.
 	 */
-    {"OBJECT", sizeof("OBJECT") - 1, CONTINUE},
-    {"NetworkAddress", sizeof("NetworkAddress") - 1, NETADDR},
-    {"Gauge", sizeof("Gauge") - 1, GAUGE},
-    {"read-write", sizeof("read-write") - 1, READWRITE},
-    {"read-create", sizeof("read-create") - 1, READCREATE},
-    {"OCTETSTRING", sizeof("OCTETSTRING") - 1, OCTETSTR},
-    {"OCTET", sizeof("OCTET") - 1, -1},
-    {"OF", sizeof("OF") - 1, OF},
-    {"SEQUENCE", sizeof("SEQUENCE") - 1, SEQUENCE},
-    {"NULL", sizeof("NULL") - 1, NUL},
-    {"IpAddress", sizeof("IpAddress") - 1, IPADDR},
-    {"UInteger32", sizeof("UInteger32") - 1, UINTEGER32},
-    {"INTEGER", sizeof("INTEGER") - 1, INTEGER},
-    {"Counter", sizeof("Counter") - 1, COUNTER},
-    {"read-only", sizeof("read-only") - 1, READONLY},
-    {"DESCRIPTION", sizeof("DESCRIPTION") - 1, DESCRIPTION},
-    {"INDEX", sizeof("INDEX") - 1, INDEX},
-    {"DEFVAL", sizeof("DEFVAL") - 1, DEFVAL},
-    {"deprecated", sizeof("deprecated") - 1, DEPRECATED},
-    {"SIZE", sizeof("SIZE") - 1, SIZE},
-    {"MAX-ACCESS", sizeof("MAX-ACCESS") - 1, ACCESS},
-    {"ACCESS", sizeof("ACCESS") - 1, ACCESS},
-    {"mandatory", sizeof("mandatory") - 1, MANDATORY},
-    {"current", sizeof("current") - 1, CURRENT},
-    {"STATUS", sizeof("STATUS") - 1, STATUS},
-    {"SYNTAX", sizeof("SYNTAX") - 1, SYNTAX},
-    {"OBJECT-TYPE", sizeof("OBJECT-TYPE") - 1, OBJTYPE},
-    {"{", sizeof("{") - 1, LEFTBRACKET},
-    {"}", sizeof("}") - 1, RIGHTBRACKET},
-    {"::=", sizeof("::=") - 1, EQUALS},
-    {"(", sizeof("(") - 1, LEFTPAREN},
-    {")", sizeof(")") - 1, RIGHTPAREN},
-    {",", sizeof(",") - 1, COMMA},
-    {NULL}
+	{ "OBJECT", sizeof ("OBJECT")-1, CONTINUE },
+	{ "NetworkAddress", sizeof ("NetworkAddress")-1, NETADDR },
+	{ "Gauge", sizeof ("Gauge")-1, GAUGE },
+	{ "OCTETSTRING", sizeof ("OCTETSTRING")-1, OCTETSTR },
+	{ "OCTET", sizeof ("OCTET")-1, -1 },
+	{ "OF", sizeof ("OF")-1, OF },
+	{ "SEQUENCE", sizeof ("SEQUENCE")-1, SEQUENCE },
+	{ "NULL", sizeof ("NULL")-1, NUL },
+	{ "IpAddress", sizeof ("IpAddress")-1, IPADDR },
+	{ "INTEGER", sizeof ("INTEGER")-1, INTEGER },
+	{ "Counter", sizeof ("Counter")-1, COUNTER },
+	{ "read-only", sizeof ("read-only")-1, READONLY },
+	{ "ACCESS", sizeof ("ACCESS")-1, ACCESS },
+	{ "MAX-ACCESS", sizeof ("MAX-ACCESS")-1, ACCESS },
+	{ "STATUS", sizeof ("STATUS")-1, STATUS },
+	{ "SYNTAX", sizeof ("SYNTAX")-1, SYNTAX },
+	{ "OBJECT-TYPE", sizeof ("OBJECT-TYPE")-1, OBJTYPE },
+	{ "{", sizeof ("{")-1, LEFTBRACKET },
+	{ "}", sizeof ("}")-1, RIGHTBRACKET },
+	{ "::=", sizeof ("::=")-1, EQUALS },
+	{ "(", sizeof ("(")-1, LEFTPAREN },
+	{ ")", sizeof (")")-1, RIGHTPAREN },
+	{ ",", sizeof (",")-1, COMMA },
+	{ "DESCRIPTION", sizeof ("DESCRIPTION")-1, DESCRIPTION },
+	{ "INDEX", sizeof ("INDEX")-1, INDEX },
+	{ "\"", sizeof ("\"")-1, QUOTE },
+/* Hacks for easier MIBFILE coercing */
+	{ "read-create", sizeof ("read-create")-1, READWRITE },
+	{ NULL }
 };
 
 #define	HASHSIZE	32
 #define	BUCKET(x)	(x & 0x01F)
 
-struct tok *buckets[HASHSIZE];
-
-static void do_subtree();
-static int get_token();
-static int parseQuoteString();
-static int tossObjectIdentifier();
+static struct tok	*buckets[HASHSIZE];
 
 static void
-hash_init(void)
+hash_init()
 {
-    struct tok *tp;
-    char *cp;
-    int h;
-    int b;
-
-    memset(buckets, '\0', sizeof(buckets));
-    for (tp = tokens; tp->name; tp++) {
-	for (h = 0, cp = tp->name; *cp; cp++)
-	    h += *cp;
-	tp->hash = h;
-	b = BUCKET(h);
-	if (buckets[b])
-	    tp->next = buckets[b];	/* BUG ??? */
-	buckets[b] = tp;
-    }
+	register struct tok	*tp;
+	register char	*cp;
+	register int	h;
+	register int	b;
+
+	memset((char *)buckets, '\0', sizeof(buckets));
+	for (tp = tokens; tp->name; tp++) {
+		for (h = 0, cp = tp->name; *cp; cp++)
+			h += *cp;
+		tp->hash = h;
+		b = BUCKET(h);
+		if (buckets[b])
+		    tp->next = buckets[b]; /* BUG ??? */
+		buckets[b] = tp;
+	}
 }
 
 #define NHASHSIZE    128
 #define NBUCKET(x)   (x & 0x7F)
 struct node *nbuckets[NHASHSIZE];
 
-void
-init_node_hash(struct node *nodes)
+static void init_node_hash(nodes)
+     struct node *nodes;
 {
-    struct node *np, *nextp;
-    char *cp;
-    int hash;
-
-    memset(nbuckets, '\0', sizeof(nbuckets));
-    for (np = nodes; np;) {
-	nextp = np->next;
-	hash = 0;
-	for (cp = np->parent; *cp; cp++)
-	    hash += *cp;
-	np->next = nbuckets[NBUCKET(hash)];
-	nbuckets[NBUCKET(hash)] = np;
-	np = nextp;
-    }
+     register struct node *np, *nextp;
+     register char *cp;
+     register int hash;
+
+     memset((char *)nbuckets, '\0', sizeof(nbuckets));
+     for(np = nodes; np;){
+         nextp = np->next;
+         hash = 0;
+	 for(cp = np->parent; *cp; cp++)
+	     hash += *cp;
+	 np->next = nbuckets[NBUCKET(hash)];
+	 nbuckets[NBUCKET(hash)] = np;
+	 np = nextp;
+     }
 }
 
-static char *
-Malloc(unsigned int num)
-{
-    /* this is to fix (what seems to be) a problem with the IBM RT C
-     * library malloc */
-    if (num < 16)
-	num = 16;
-    return xcalloc(1, num);
-}
 
 static void
-print_error(char *string, char *token, int type)
+print_error(string, token, type)
+    char *string;
+    char *token;
+    int type;
 {
     if (type == ENDOFFILE)
-	fprintf(stderr, "%s(EOF): On or around line %d\n", string, Line);
+	snmplib_debug(0, "%s(EOF): On or around line %d\n", string, Line);
     else if (token)
-	fprintf(stderr, "%s(%s): On or around line %d\n", string, token, Line);
+	snmplib_debug(0, "%s(%s): On or around line %d\n", string, token, Line);
     else
-	fprintf(stderr, "%s: On or around line %d\n", string, Line);
+	snmplib_debug(0, "%s: On or around line %d\n", string, Line);
 }
 
 #ifdef TEST
-print_subtree(struct tree *tree, int count)
+print_subtree(tree, count)
+    struct snmp_mib_tree *tree;
+    int count;
 {
-    struct tree *tp;
+    struct snmp_mib_tree *tp;
     int i;
 
-    for (i = 0; i < count; i++)
+    for(i = 0; i < count; i++)
 	printf("  ");
     printf("Children of %s:\n", tree->label);
     count++;
-    for (tp = tree->child_list; tp; tp = tp->next_peer) {
-	for (i = 0; i < count; i++)
+    for(tp = tree->child_list; tp; tp = tp->next_peer){
+	for(i = 0; i < count; i++)
 	    printf("  ");
 	printf("%s\n", tp->label);
     }
-    for (tp = tree->child_list; tp; tp = tp->next_peer) {
+    for(tp = tree->child_list; tp; tp = tp->next_peer){
 	print_subtree(tp, count);
     }
 }
 #endif /* TEST */
 
-int translation_table[256];
+int translation_table[40];
 
-void
-build_translation_table(void)
-{
+static void build_translation_table(){
     int count;
 
-    for (count = 0; count < 256; count++) {
-	switch (count) {
-	case OBJID:
-	    translation_table[count] = TYPE_OBJID;
-	    break;
-	case OCTETSTR:
-	    translation_table[count] = TYPE_OCTETSTR;
-	    break;
-	case INTEGER:
-	    translation_table[count] = TYPE_INTEGER;
-	    break;
-	case NETADDR:
-	    translation_table[count] = TYPE_IPADDR;
-	    break;
-	case IPADDR:
-	    translation_table[count] = TYPE_IPADDR;
-	    break;
-	case COUNTER:
-	    translation_table[count] = TYPE_COUNTER;
-	    break;
-	case GAUGE:
-	    translation_table[count] = TYPE_GAUGE;
-	    break;
-	case TIMETICKS:
-	    translation_table[count] = TYPE_TIMETICKS;
-	    break;
-	case OPAQUE:
-	    translation_table[count] = TYPE_OPAQUE;
-	    break;
-	case NUL:
-	    translation_table[count] = TYPE_NULL;
-	    break;
-	case COUNTER64:
-	    translation_table[count] = TYPE_COUNTER64;
-	    break;
-	case BITSTRING:
-	    translation_table[count] = TYPE_BITSTRING;
-	    break;
-	case NSAPADDRESS:
-	    translation_table[count] = TYPE_NSAPADDRESS;
-	    break;
-	case UINTEGER32:
-	    translation_table[count] = TYPE_UINTEGER;
-	    break;
-	default:
-	    translation_table[count] = TYPE_OTHER;
-	    break;
-	}
-    }
-}
-
-static struct tree *
-build_tree(struct node *nodes)
-{
-    struct node *np;
-    struct tree *tp, *lasttp;
-    int bucket, nodes_left = 0;
-
-    build_translation_table();
-    /* grow tree from this root node */
-    init_node_hash(nodes);
-
-    /* build root node */
-    tp = (struct tree *) Malloc(sizeof(struct tree));
-    tp->parent = NULL;
-    tp->next_peer = NULL;
-    tp->child_list = NULL;
-    tp->enums = NULL;
-    strcpy(tp->label, "joint-iso-ccitt");
-    tp->subid = 2;
-    tp->type = 0;
-    tp->description = 0;
-    /* XXX nodes isn't needed in do_subtree() ??? */
-    do_subtree(tp, &nodes);
-    lasttp = tp;
-
-    /* build root node */
-    tp = (struct tree *) Malloc(sizeof(struct tree));
-    tp->parent = NULL;
-    tp->next_peer = lasttp;
-    tp->child_list = NULL;
-    tp->enums = NULL;
-    strcpy(tp->label, "ccitt");
-    tp->subid = 0;
-    tp->type = 0;
-    tp->description = 0;
-    /* XXX nodes isn't needed in do_subtree() ??? */
-    do_subtree(tp, &nodes);
-    lasttp = tp;
-
-    /* build root node */
-    tp = (struct tree *) Malloc(sizeof(struct tree));
-    tp->parent = NULL;
-    tp->next_peer = lasttp;
-    tp->child_list = NULL;
-    tp->enums = NULL;
-    strcpy(tp->label, "iso");
-    tp->subid = 1;
-    tp->type = 0;
-    tp->description = 0;
-    /* XXX nodes isn't needed in do_subtree() ??? */
-    do_subtree(tp, &nodes);
-
-
-#ifdef TEST
-    print_subtree(tp, 0);
-#endif /* TEST */
-    /* If any nodes are left, the tree is probably inconsistent */
-    for (bucket = 0; bucket < NHASHSIZE; bucket++) {
-	if (nbuckets[bucket]) {
-	    nodes_left = 1;
-	    break;
-	}
-    }
-    if (nodes_left) {
-	fprintf(stderr, "The mib description doesn't seem to be consistent.\n");
-	fprintf(stderr, "Some nodes couldn't be linked under the \"iso\" tree.\n");
-	fprintf(stderr, "these nodes are left:\n");
-	for (bucket = 0; bucket < NHASHSIZE; bucket++) {
-	    for (np = nbuckets[bucket]; np; np = np->next)
-		fprintf(stderr, "%s ::= { %s %ld } (%d)\n", np->label,
-		    np->parent, np->subid, np->type);
+    for(count = 0; count < 40; count++){
+	switch(count){
+	    case OBJID:
+		translation_table[count] = TYPE_OBJID;
+		break;
+	    case OCTETSTR:
+		translation_table[count] = TYPE_OCTETSTR;
+		break;
+	    case INTEGER:
+		translation_table[count] = TYPE_INTEGER;
+		break;
+	    case NETADDR:
+		translation_table[count] = TYPE_IPADDR;
+		break;
+	    case IPADDR:
+		translation_table[count] = TYPE_IPADDR;
+		break;
+	    case COUNTER:
+		translation_table[count] = TYPE_COUNTER;
+		break;
+	    case GAUGE:
+		translation_table[count] = TYPE_GAUGE;
+		break;
+	    case TIMETICKS:
+		translation_table[count] = TYPE_TIMETICKS;
+		break;
+	    case OPAQUE:
+		translation_table[count] = TYPE_OPAQUE;
+		break;
+	    case NUL:
+		translation_table[count] = TYPE_NULL;
+		break;
+	    default:
+		translation_table[count] = TYPE_OTHER;
+		break;
 	}
     }
-    return tp;
 }
 
 /*
  * Find all the children of root in the list of nodes.  Link them into the
  * tree and out of the nodes list.
  */
 static void
-do_subtree(struct tree *root, struct node **nodes)
+do_subtree(root, nodes)
+    struct snmp_mib_tree *root;
+    struct node **nodes;
 {
-    struct tree *tp;
-    struct tree *peer = NULL;
-    struct node *np, **headp;
+    register struct snmp_mib_tree *tp;
+    struct snmp_mib_tree *peer = NULL;
+    register struct node *np=NULL , **headp=NULL;
     struct node *oldnp = NULL, *child_list = NULL, *childp = NULL;
     char *cp;
     int hash;
-
+    
     tp = root;
     hash = 0;
-    for (cp = tp->label; *cp; cp++)
-	hash += *cp;
+    for(cp = tp->label; *cp; cp++)
+        hash += *cp;
     headp = &nbuckets[NBUCKET(hash)];
     /*
      * Search each of the nodes for one whose parent is root, and
      * move each into a separate list.
      */
-    for (np = *headp; np; np = np->next) {
-	if ((*tp->label != *np->parent) || strcmp(tp->label, np->parent)) {
-	    if ((*tp->label == *np->label) && !strcmp(tp->label, np->label)) {
+    for(np = *headp; np; np = np->next){
+	if ((*tp->label != *np->parent) || strcmp(tp->label, np->parent)){
+	    if ((*tp->label == *np->label) && !strcmp(tp->label, np->label)){
 		/* if there is another node with the same label, assume that
 		 * any children after this point in the list belong to the other node.
 		 * This adds some scoping to the table and allows vendors to
