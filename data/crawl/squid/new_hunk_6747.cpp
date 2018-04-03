	 * If we didn't find the entry, punt...
	 */
	if (tp == NULL) {
	    snmplib_debug(0, "sub-identifier not found: %s\n", buf);
	    return (0);
	}
    }

found:
    if(subid > (u_int)MAX_SUBID){
	snmplib_debug(0, "sub-identifier too large: %s\n", buf);
	return (0);
    }

    if ((*out_len)-- <= 0){
	snmplib_debug(0, "object identifier too long\n");
	return (0);
    }
    *output++ = subid;

    if (*input != '.')
	return (1);
    if ((*out_len =
	 parse_subtree(tp ? tp->child_list : NULL, ++input, output, out_len)) == 0)
	return (0);
    return (++*out_len);
}

int read_objid(input, output, out_len)
    char *input;
    oid *output;
    int	*out_len;   /* number of subid's in "output" */
{
    struct snmp_mib_tree *root = Mib;
    oid *op = output;
    int i;

    if (*input == '.')
	input++;
    else {
	root = find_rfc1066_mib(root);
	for (i = 0; i < sizeof (RFC1066_MIB)/sizeof(oid); i++) {
	    if ((*out_len)-- > 0)
		*output++ = RFC1066_MIB[i];
	    else {
		snmplib_debug(0, "object identifier too long\n");
		return (0);
	    }
	}
    }

    if (root == NULL){
	snmplib_debug(0, "Mib not initialized.  Exiting.\n");
	exit(1);
    }
    if ((*out_len =
	 parse_subtree(root, input, output, out_len)) == 0)
	return (0);
    *out_len += output - op;

    return (1);
}

void print_objid(objid, objidlen)
    oid	    *objid;
    int	    objidlen;	/* number of subidentifiers */
{
    char    buf[256];
    struct snmp_mib_tree    *subtree = Mib;

    *buf = '.';	/* this is a fully qualified name */
    get_symbol(objid, objidlen, subtree, buf + 1);
    snmplib_debug(7, "%s\n", buf);
        
}

void sprint_objid(buf, objid, objidlen)
    char *buf;
    oid	    *objid;
    int	    objidlen;	/* number of subidentifiers */
{
    struct snmp_mib_tree    *subtree = Mib;

    *buf = '.';	/* this is a fully qualified name */
    get_symbol(objid, objidlen, subtree, buf + 1);
}


void print_variable(objid, objidlen, pvariable)
    oid     *objid;
    int	    objidlen;
    struct  variable_list *pvariable;
{
    char    buf[1024], *cp;
    struct snmp_mib_tree    *subtree = Mib;

    *buf = '.';	/* this is a fully qualified name */
    subtree = get_symbol(objid, objidlen, subtree, buf + 1);
    cp = buf;
    if ((strlen(buf) >= strlen((char *)RFC1066_MIB_text)) && !memcmp(buf, (char *)RFC1066_MIB_text,
	strlen((char *)RFC1066_MIB_text))){
	    cp += sizeof(RFC1066_MIB_text);
    }
    printf("Name: %s -> ", cp);
    *buf = '\0';
    if (subtree->printer)
	(*subtree->printer)(buf, pvariable, subtree->enums, 0);
    else {
	sprint_by_type(buf, pvariable, subtree->enums, 0);
    }
    printf("%s\n", buf);
}


void sprint_variable(buf, objid, objidlen, pvariable)
    char *buf;
    oid     *objid;
    int	    objidlen;
    struct  variable_list *pvariable;
{
    char    tempbuf[512], *cp;
    struct snmp_mib_tree    *subtree = Mib;

    *tempbuf = '.';	/* this is a fully qualified name */
    subtree = get_symbol(objid, objidlen, subtree, tempbuf + 1);
    cp = tempbuf;
    if ((strlen(buf) >= strlen((char *)RFC1066_MIB_text)) && !memcmp(buf, (char *)RFC1066_MIB_text,
	strlen((char *)RFC1066_MIB_text))){
	    cp += sizeof(RFC1066_MIB_text);
    }
    sprintf(buf, "Name: %s -> ", cp);
    buf += strlen(buf);
    if (subtree->printer)
	(*subtree->printer)(buf, pvariable, subtree->enums, 0);
    else {
	sprint_by_type(buf, pvariable, subtree->enums, 0);
    }
    strcat(buf, "\n");
}

void sprint_value(buf, objid, objidlen, pvariable)
    char *buf;
    oid     *objid;
    int	    objidlen;
    struct  variable_list *pvariable;
{
    char    tempbuf[512];
    struct snmp_mib_tree    *subtree = Mib;

    subtree = get_symbol(objid, objidlen, subtree, tempbuf);
    if (subtree->printer)
	(*subtree->printer)(buf, pvariable, subtree->enums, 0);
    else {
	sprint_by_type(buf, pvariable, subtree->enums, 0);
    }
}

void print_value(objid, objidlen, pvariable)
    oid     *objid;
    int	    objidlen;
    struct  variable_list *pvariable;
{
    char    tempbuf[512];
    struct snmp_mib_tree    *subtree = Mib;

    subtree = get_symbol(objid, objidlen, subtree, tempbuf);
    if (subtree->printer)
	(*subtree->printer)(tempbuf, pvariable, subtree->enums, 0);
    else {
	sprint_by_type(tempbuf, pvariable, subtree->enums, 0);
    }
    printf("%s\n", tempbuf);
}

static struct snmp_mib_tree *
get_symbol(objid, objidlen, subtree, buf)
    oid	    *objid;
    int	    objidlen;
    struct snmp_mib_tree    *subtree;
    char    *buf;
{
    struct snmp_mib_tree    *return_tree = NULL;

    for(; subtree; subtree = subtree->next_peer){
	if (*objid == subtree->subid){
	    strcpy(buf, subtree->label);
	    goto found;
	}
    }

    /* subtree not found */
    while(objidlen--){	/* output rest of name, uninterpreted */
	sprintf(buf, "%u.", *objid++);
	while(*buf)
	    buf++;
    }
    *(buf - 1) = '\0'; /* remove trailing dot */
    return NULL;

found:
    if (objidlen > 1){
	while(*buf)
	    buf++;
	*buf++ = '.';
	*buf = '\0';
	return_tree = get_symbol(objid + 1, objidlen - 1, subtree->child_list, buf);
    } 
    if (return_tree != NULL)
	return return_tree;
    else
	return subtree;
}






void print_variable_list(variable_list *V)
{
  print_variable(V->name, V->name_length, V);
}


void print_variable_list_value(variable_list *pvariable)
{
  char    buf[512];
  struct snmp_mib_tree    *subtree = Mib;

  *buf = '.';	/* this is a fully qualified name */
  subtree = get_symbol(pvariable->name, pvariable->name_length, subtree, buf + 1);
  *buf = '\0';

  if (subtree->printer)
    (*subtree->printer)(buf, pvariable, subtree->enums, 1);
  else {
    sprint_by_type(buf, pvariable, subtree->enums, 1);
  }
  printf("%s", buf);
}

void print_type(variable_list *var)
{
  switch (var->type){
  case SMI_INTEGER:
    printf("Integer");
    break;
  case SMI_STRING:
    printf("Octet String");
    break;
  case SMI_OPAQUE:
    printf("Opaque");
    break;
  case SMI_OBJID:
    printf("Object Identifier");
    break;
  case SMI_TIMETICKS:
    printf("Timeticks");
    break;
  case SMI_GAUGE32:
    printf("Gauge");
    break;
  case SMI_COUNTER32:
    printf("Counter");
    break;
  case SMI_IPADDRESS:
    printf("IP Address");
    break;
  case SMI_NULLOBJ:
    printf("NULL");
    break;
  default:
    printf("Unknown type %d\n", var->type);
    break;
  }
}

void print_oid_nums(oid *O, int len)
{
  int x;

  for (x=0;x<len;x++)
    printf(".%u", O[x]);
}
