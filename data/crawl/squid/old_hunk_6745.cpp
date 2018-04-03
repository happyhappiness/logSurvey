}

static void
sprint_ipaddress(char *buf, struct variable_list *var, struct enum_list *enums)
{
    u_char *ip;

    if (var->type != IPADDRESS) {
	sprintf(buf, "Wrong Type (should be Ipaddress): ");
	buf += strlen(buf);
	sprint_by_type(buf, var, (struct enum_list *) NULL);
	return;
    }
    ip = var->val.string;
    sprintf(buf, "IpAddress: %d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
}

#if 0
static void
sprint_unsigned_short(char *buf, struct variable_list *var, struct enum_list *enums)
{
    if (var->type != ASN_INTEGER) {
	sprintf(buf, "Wrong Type (should be INTEGER): ");
	buf += strlen(buf);
	sprint_by_type(buf, var, (struct enum_list *) NULL);
	return;
    }
    sprintf(buf, "INT: %lu", *var->val.integer);
}
#endif

static void
sprint_null(char *buf, struct variable_list *var, struct enum_list *enums)
{
    if (var->type != ASN_NULL) {
	sprintf(buf, "Wrong Type (should be NULL): ");
	buf += strlen(buf);
	sprint_by_type(buf, var, (struct enum_list *) NULL);
	return;
    }
    sprintf(buf, "NULL");
}

static void
sprint_bitstring(char *buf, struct variable_list *var, struct enum_list *enums)
{
    int len, bit;
    u_char *cp;
    char *enum_string;

    if (var->type != ASN_BIT_STR) {
	sprintf(buf, "Wrong Type (should be BIT STRING): ");
	buf += strlen(buf);
	sprint_by_type(buf, var, (struct enum_list *) NULL);
	return;
    }
    sprintf(buf, "BIT_STRING: ");
    buf += strlen(buf);
    sprint_hexstring(buf, var->val.bitstring, var->val_len);
    buf += strlen(buf);

    cp = var->val.bitstring + 1;
    for (len = 0; len < var->val_len - 1; len++) {
	for (bit = 0; bit < 8; bit++) {
	    if (*cp & (0x80 >> bit)) {
		enum_string = NULL;
		for (; enums; enums = enums->next)
		    if (enums->value == (len * 8) + bit) {
			enum_string = enums->label;
			break;
		    }
		if (enum_string == NULL)
		    sprintf(buf, "%d ", (len * 8) + bit);
		else
		    sprintf(buf, "%s(%d) ", enum_string, (len * 8) + bit);
		buf += strlen(buf);
	    }
	}
	cp++;
    }
}

static void
sprint_nsapaddress(char *buf, struct variable_list *var, struct enum_list *enums)
{
    if (var->type != NSAP) {
	sprintf(buf, "Wrong Type (should be NsapAddress): ");
	buf += strlen(buf);
	sprint_by_type(buf, var, (struct enum_list *) NULL);
	return;
    }
    sprintf(buf, "NsapAddress: ");
    buf += strlen(buf);
    sprint_hexstring(buf, var->val.string, var->val_len);
}

static void
sprint_counter64(char *buf, struct variable_list *var, struct enum_list *enums)
{
    if (var->type != COUNTER64) {
	sprintf(buf, "Wrong Type (should be Counter64): ");
	buf += strlen(buf);
	sprint_by_type(buf, var, (struct enum_list *) NULL);
	return;
    }
/* XXX */
    sprintf(buf, "Counter64: ");
    buf += strlen(buf);

    sprint_hexstring(buf, (unsigned char *) &var->val.counter64->high,
	sizeof(var->val.counter64->high));
    buf += strlen(buf);
    sprint_hexstring(buf, (unsigned char *) &var->val.counter64->low,
	sizeof(var->val.counter64->low));
}


static void
sprint_unknowntype(char *buf, struct variable_list *var, struct enum_list *enums)
{
/*    sprintf(buf, "Variable has bad type"); */
    sprint_by_type(buf, var, NULL);
}

static void
sprint_badtype(char *buf, struct variable_list *var, struct enum_list *enums)
{
    sprintf(buf, "Variable has bad type");
}

static void
sprint_by_type(char *buf, struct variable_list *var, struct enum_list *enums)
{
    switch (var->type) {
    case ASN_INTEGER:
	sprint_integer(buf, var, enums);
	break;
    case ASN_OCTET_STR:
	sprint_octet_string(buf, var, enums);
	break;
    case OPAQUE:
	sprint_opaque(buf, var, enums);
	break;
    case ASN_OBJECT_ID:
	sprint_object_identifier(buf, var, enums);
	break;
    case TIMETICKS:
	sprint_timeticks(buf, var, enums);
	break;
    case GAUGE:
	sprint_gauge(buf, var, enums);
	break;
    case COUNTER:
	sprint_counter(buf, var, enums);
	break;
    case IPADDRESS:
	sprint_ipaddress(buf, var, enums);
	break;
    case ASN_NULL:
	sprint_null(buf, var, enums);
	break;
    case UINTEGER:
	sprint_uinteger(buf, var, enums);
	break;
    default:
	sprint_badtype(buf, var, enums);
	break;
    }
}

struct tree *get_symbol();

oid RFC1213_MIB[] =
{1, 3, 6, 1, 2, 1};
unsigned char RFC1213_MIB_text[] = ".iso.org.dod.internet.mgmt.mib-2";
unsigned char EXPERIMENTAL_MIB_text[] = ".iso.org.dod.internet.experimental";
unsigned char PRIVATE_MIB_text[] = ".iso.org.dod.internet.private";
unsigned char PARTY_MIB_text[] = ".iso.org.dod.internet.snmpParties";
unsigned char SECRETS_MIB_text[] = ".iso.org.dod.internet.snmpSecrets";
struct tree *Mib = 0;

static char Standard_Prefix[] = ".1.3.6.1.2.1.";
static char Prefix[256];
static int Suffix;

void
init_mib(const char *file)
{
    char *prefix;
    if (Mib != NULL)
	return;

    Mib = 0;
    if (file)
	Mib = read_mib(file);
    if (!Mib)
	Mib = read_mib("mib.txt");
#ifdef MIBFILEPATH
    if (!Mib) {
	char tmp[1024];
	sprintf(tmp, "%s/mib.txt", MIBFILEPATH);
	Mib = read_mib(tmp);
    }
#endif
    if (!Mib)
	Mib = read_mib("/etc/mib.txt");
    if (!Mib) {
	fprintf(stderr, "Couldn't find mib file\n");
	exit(2);
    }
    prefix = getenv("PREFIX");
    if (!prefix) {
	prefix = Standard_Prefix;
    }
    /* save prefix: */
    snmp_new_prefix(prefix);

    if (getenv("SUFFIX"))
	Suffix = TRUE;
    else
	Suffix = FALSE;
    set_functions(Mib);
}


/* 
 * Phil Wood <cpw@lanl.gov>:
 *
 * [...] I made an addition to mib.c to accomodate some old perl snmp
 * code for a program called vulture that used a global pointer to the
 * prefix to change things.  
 */

char *
snmp_new_prefix(char *prefix)
{
    char *lastchar;
    int plen;

    if (prefix) {
	lastchar = ".";
	if (*prefix == '.') {
	    prefix++;
	}
	if ((plen = strlen(prefix))) {
	    lastchar = prefix + plen - 1;
	}
	strncpy(Prefix, prefix, sizeof(Prefix) - 2);
	Prefix[sizeof(Prefix) - 2] = 0;
	if (*lastchar != '.') {
	    Prefix[plen++] = '.';
	    Prefix[plen] = 0;
	}
	return Prefix;
    }
    return (char *) NULL;
}



static void
set_functions(subtree)
     struct tree *subtree;
{
    for (; subtree; subtree = subtree->next_peer) {
	switch (subtree->type) {
	case TYPE_OBJID:
	    subtree->printer = sprint_object_identifier;
	    break;
	case TYPE_OCTETSTR:
	    subtree->printer = sprint_octet_string;
	    break;
	case TYPE_INTEGER:
	    subtree->printer = sprint_integer;
	    break;
	case TYPE_NETADDR:
	    subtree->printer = sprint_networkaddress;
	    break;
	case TYPE_IPADDR:
	    subtree->printer = sprint_ipaddress;
	    break;
	case TYPE_COUNTER:
	    subtree->printer = sprint_counter;
	    break;
	case TYPE_GAUGE:
	    subtree->printer = sprint_gauge;
	    break;
	case TYPE_TIMETICKS:
	    subtree->printer = sprint_timeticks;
	    break;
	case TYPE_OPAQUE:
	    subtree->printer = sprint_opaque;
	    break;
	case TYPE_NULL:
	    subtree->printer = sprint_null;
	    break;
	case TYPE_BITSTRING:
	    subtree->printer = sprint_bitstring;
	    break;
	case TYPE_NSAPADDRESS:
	    subtree->printer = sprint_nsapaddress;
	    break;
	case TYPE_COUNTER64:
	    subtree->printer = sprint_counter64;
	    break;
	case TYPE_UINTEGER:
	    subtree->printer = sprint_uinteger;
	    break;
	case TYPE_OTHER:
	default:
	    subtree->printer = sprint_unknowntype;
	    break;
	}
	set_functions(subtree->child_list);
    }
}

#ifdef testing
int snmp_dump_packet = 0;

main(argc, argv)
     int argc;
     char *argv[];
{
    oid objid[64];
    int objidlen = sizeof(objid);
    int count;
    struct variable variable;

    init_mib();
    if (argc < 2)
	print_subtree(Mib, 0);
    variable.type = ASN_INTEGER;
    variable.val.integer = 3;
    variable.val_len = 4;
    for (argc--; argc; argc--, argv++) {
	objidlen = sizeof(objid);
	printf("read_objid(%s) = %d\n",
	    argv[1], read_objid(argv[1], objid, &objidlen));
	for (count = 0; count < objidlen; count++)
	    printf("%d.", objid[count]);
	printf("\n");
	print_variable(objid, objidlen, &variable);
    }
}

#endif /* testing */


#if 0
static struct tree *
find_rfc1213_mib(root)
     struct tree *root;
{
    oid *op = RFC1213_MIB;
    struct tree *tp;
    int len;

    for (len = sizeof(RFC1213_MIB) / sizeof(oid); len; len--, op++) {
	for (tp = root; tp; tp = tp->next_peer) {
	    if (tp->subid == *op) {
		root = tp->child_list;
		break;
	    }
