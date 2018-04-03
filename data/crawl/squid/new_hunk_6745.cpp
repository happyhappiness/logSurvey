}

static void
sprint_ipaddress(buf, var, foo, quiet)
    char *buf;
    variable_list *var;
void *foo;
int quiet;
{
    u_char *ip;

    if (var->type != SMI_IPADDRESS){
	sprintf(buf, "Wrong Type (should be Ipaddress): ");
	buf += strlen(buf);
	sprint_by_type(buf, var, (struct enum_list *)NULL, quiet);
	return;
    }
    ip = var->val.string;
    if (!quiet) {
      sprintf(buf, "IPAddress:\t");
      buf += strlen(buf);
    }
    sprintf(buf, "%d.%d.%d.%d",ip[0], ip[1], ip[2], ip[3]);
}

#if 0
static void
sprint_unsigned_short(buf, var, foo, quiet)
    char *buf;
    variable_list *var;
void *foo;
    int quiet;
{
    if (var->type != SMI_INTEGER){
	sprintf(buf, "Wrong Type (should be INTEGER): ");
	buf += strlen(buf);
	sprint_by_type(buf, var, (struct enum_list *)NULL, quiet);
	return;
    }
    if (!quiet) {
      sprintf(buf, "INTEGER (0..65535): ");
      buf += strlen(buf);
    }
    sprintf(buf, "%u", *var->val.integer);
}
#endif 

static void
sprint_null(buf, var, foo, quiet)
    char *buf;
    variable_list *var;
void *foo;
int quiet;
{
    if (var->type != SMI_NULLOBJ){
	sprintf(buf, "Wrong Type (should be NULL): ");
	buf += strlen(buf);
	sprint_by_type(buf, var, (struct enum_list *)NULL, quiet);
	return;
    }
    sprintf(buf, "NULL");
}

static void
sprint_unknowntype(buf, var, foo, quiet)
    char *buf;
    variable_list *var;
void *foo;
int quiet;
{
/*    sprintf(buf, "Variable has bad type"); */
    sprint_by_type(buf, var, foo, quiet);
}

static void
sprint_badtype(buf)
    char *buf;
{
    sprintf(buf, "Variable has bad type");
}

static void
sprint_by_type(buf, var, enums, quiet)
    char *buf;
    variable_list *var;
    struct enum_list	    *enums;
    int quiet;
{
    switch (var->type){
	case SMI_INTEGER:
	    sprint_integer(buf, var, enums, quiet);
	    break;
	case SMI_STRING:
	    sprint_octet_string(buf, var, enums, quiet);
	    break;
	case SMI_OPAQUE:
	    sprint_opaque(buf, var, enums, quiet);
	    break;
	case SMI_OBJID:
	    sprint_object_identifier(buf, var, enums, quiet);
	    break;
	case SMI_TIMETICKS:
	    sprint_timeticks(buf, var, enums, quiet);
	    break;
	case SMI_GAUGE32:
	    sprint_gauge(buf, var, enums, quiet);
	    break;
	case SMI_COUNTER32:
	    sprint_counter(buf, var, enums, quiet);
	    break;
	case SMI_IPADDRESS:
	    sprint_ipaddress(buf, var, enums, quiet);
	    break;
	case SMI_NULLOBJ:
	    sprint_null(buf, var, enums, quiet);
	    break;
	default:
	    sprint_badtype(buf, enums, quiet);
	    break;
    }
}

static struct snmp_mib_tree *get_symbol();

oid RFC1066_MIB[] = { 1, 3, 6, 1, 2, 1 };
unsigned char RFC1066_MIB_text[] = ".iso.org.dod.internet.mgmt.mib";
struct snmp_mib_tree *Mib;

static void
set_functions(subtree)
    struct snmp_mib_tree *subtree;
{
    for(; subtree; subtree = subtree->next_peer){
	switch(subtree->type){
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
	    case TYPE_OTHER:
	    default:
		subtree->printer = sprint_unknowntype;
		break;
	}
	set_functions(subtree->child_list);
    }
}

void init_mib(char *file)
{
    if (snmplib_debug != NULL)
    	snmplib_debug(6, "init_mib: Called.\n");
    if (Mib != NULL)
	return;

    if (file != NULL)
	Mib = read_mib(file);
    set_functions(Mib);
}


static struct snmp_mib_tree *
find_rfc1066_mib(root)
    struct snmp_mib_tree *root;
{
    oid *op = RFC1066_MIB;
    struct snmp_mib_tree *tp;
    int len;

    for(len = sizeof(RFC1066_MIB)/sizeof(oid); len; len--, op++){
	for(tp = root; tp; tp = tp->next_peer){
	    if (tp->subid == *op){
		root = tp->child_list;
		break;
	    }
