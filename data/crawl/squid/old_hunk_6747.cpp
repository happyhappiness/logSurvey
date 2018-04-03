	 * If we didn't find the entry, punt...
	 */
	if (tp == NULL) {
	    fprintf(stderr, "sub-identifier not found: %s\n", buf);
	    return (0);
	}
    }

  found:
    if (subid > (u_long) MAX_SUBID) {
	fprintf(stderr, "sub-identifier too large: %s\n", buf);
	return (0);
    }
    if ((*out_len)-- <= 0) {
	fprintf(stderr, "object identifier too long\n");
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

void
sprint_objid(char *buf, oid * objid, int objidlen)
{
    char tempbuf[2048], *cp;
    struct tree *subtree = Mib;
    *tempbuf = '.';		/* this is a fully qualified name */
    get_symbol(objid, objidlen, subtree, tempbuf + 1);
    if (Suffix) {
	for (cp = tempbuf; *cp; cp++);
	while (cp >= tempbuf) {
	    if (isalpha(*cp))
		break;
	    cp--;
	}
	while (cp >= tempbuf) {
	    if (*cp == '.')
		break;
	    cp--;
	}
	cp++;
	if (cp < tempbuf)
	    cp = tempbuf;
    } else {
	cp = tempbuf;
	if ((strlen(tempbuf) > strlen((char *) RFC1213_MIB_text))
	    && !bcmp(tempbuf, (char *) RFC1213_MIB_text,
		strlen((char *) RFC1213_MIB_text))) {
	    cp += sizeof(RFC1213_MIB_text);
	}
	if ((strlen(tempbuf) > strlen((char *) EXPERIMENTAL_MIB_text))
	    && !bcmp(tempbuf, (char *) EXPERIMENTAL_MIB_text,
		strlen((char *) EXPERIMENTAL_MIB_text))) {
	    cp += sizeof(EXPERIMENTAL_MIB_text);
	}
	if ((strlen(tempbuf) > strlen((char *) PRIVATE_MIB_text))
	    && !bcmp(tempbuf, (char *) PRIVATE_MIB_text,
		strlen((char *) PRIVATE_MIB_text))) {
	    cp += sizeof(PRIVATE_MIB_text);
	}
	if ((strlen(tempbuf) > strlen((char *) PARTY_MIB_text))
	    && !bcmp(tempbuf, (char *) PARTY_MIB_text,
		strlen((char *) PARTY_MIB_text))) {
	    cp += sizeof(PARTY_MIB_text);
	}
	if ((strlen(tempbuf) > strlen((char *) SECRETS_MIB_text))
	    && !bcmp(tempbuf, (char *) SECRETS_MIB_text,
		strlen((char *) SECRETS_MIB_text))) {
	    cp += sizeof(SECRETS_MIB_text);
	}
    }
    strcpy(buf, cp);
}

void
print_objid(oid * objid, int objidlen)
{
    char buf[256];

    sprint_objid(buf, objid, objidlen);
    printf("%s\n", buf);
}


void
print_variable(oid * objid, int objidlen, struct variable_list *variable)
{
    char buf[2048];

    sprint_variable(buf, objid, objidlen, variable);
    printf("%s", buf);
}

static void
sprint_variable(char *buf, oid * objid, int objidlen, struct variable_list *variable)
{
    char tempbuf[2048];
    struct tree *subtree = Mib;

    sprint_objid(buf, objid, objidlen);
    buf += strlen(buf);
    strcat(buf, " = ");
    buf += strlen(buf);

    if (variable->type == SNMP_NOSUCHOBJECT)
	sprintf(buf, "No Such Object available on this agent\n");
    else if (variable->type == SNMP_NOSUCHINSTANCE)
	sprintf(buf, "No Such Instance currently exists\n");
    else if (variable->type == SNMP_ENDOFMIBVIEW)
	sprintf(buf, "No more variables left in this MIB View\n");
    else {
	*tempbuf = '.';		/* this is a fully qualified name */
	subtree = get_symbol(objid, objidlen, subtree, tempbuf + 1);
	buf += strlen(buf);
	if (subtree->printer)
	    (*subtree->printer) (buf, variable, subtree->enums);
	else {
	    sprint_by_type(buf, variable, subtree->enums);
	}
	strcat(buf, "\n");
    }
}

void
sprint_value(char *buf, oid * objid, int objidlen, struct variable_list *variable)
{
    char tempbuf[2048];
    struct tree *subtree = Mib;

    if (variable->type == SNMP_NOSUCHOBJECT)
	sprintf(buf, "No Such Object available on this agent\n");
    else if (variable->type == SNMP_NOSUCHINSTANCE)
	sprintf(buf, "No Such Instance currently exists\n");
    else if (variable->type == SNMP_ENDOFMIBVIEW)
	sprintf(buf, "No more variables left in this MIB View\n");
    else {
	subtree = get_symbol(objid, objidlen, subtree, tempbuf);
	if (subtree->printer)
	    (*subtree->printer) (buf, variable, subtree->enums);
	else {
	    sprint_by_type(buf, variable, subtree->enums);
	}
    }
}

void
print_value(oid * objid, int objidlen, struct variable_list *variable)
{
    char tempbuf[2048];

    sprint_value(tempbuf, objid, objidlen, variable);
    printf("%s\n", tempbuf);
}

static struct tree *
get_symbol(oid * objid, int objidlen, struct tree *subtree, char *buf)
{
    struct tree *return_tree = NULL;

    for (; subtree; subtree = subtree->next_peer) {
	if (*objid == subtree->subid) {
	    strcpy(buf, subtree->label);
	    goto found;
	}
    }

    /* subtree not found */
    while (objidlen--) {	/* output rest of name, uninterpreted */
	sprintf(buf, "%lu.", *objid++);
	while (*buf)
	    buf++;
    }
    *(buf - 1) = '\0';		/* remove trailing dot */
    return NULL;

  found:
    if (objidlen > 1) {
	while (*buf)
	    buf++;
	*buf++ = '.';
	*buf = '\0';
	return_tree = get_symbol(objid + 1, objidlen - 1, subtree->child_list,
	    buf);
    }
    if (return_tree != NULL)
	return return_tree;
    else
	return subtree;
}


static int
lc_cmp(char *s1, char *s2)
{
    char c1, c2;

    while (*s1 && *s2) {
	if (isupper(*s1))
	    c1 = tolower(*s1);
	else
	    c1 = *s1;
	if (isupper(*s2))
	    c2 = tolower(*s2);
	else
	    c2 = *s2;
	if (c1 != c2)
	    return ((c1 - c2) > 0 ? 1 : -1);
	s1++;
	s2++;
    }

    if (*s1)
	return -1;
    if (*s2)
	return 1;
    return 0;
}

/*
 * Clone of get_symbol that doesn't take a buffer argument
 */
static struct tree *
get_tree(oid * objid, int objidlen, struct tree *subtree)
{
    struct tree *return_tree = NULL;

    for (; subtree; subtree = subtree->next_peer) {
	if (*objid == subtree->subid)
	    goto found;
    }

    return NULL;

  found:
    if (objidlen > 1)
	return_tree = get_tree(objid + 1, objidlen - 1, subtree->child_list);
    if (return_tree != NULL)
	return return_tree;
    else
	return subtree;
}


#if 0
static char *
get_description(oid * objid, int objidlen)
{
    struct tree *subtree = Mib;

    subtree = get_tree(objid, objidlen, subtree);
    if (subtree)
	return (subtree->description);
    else
	return NULL;
}
#endif


#if 0
static void
print_description(oid * objid, int objidlen)
{
    char *desc = get_description(objid, objidlen);

    if (desc && desc[0] != '\0')
	printf("Description: \"%s\"\n", desc);
    else
	printf("No description\n");
}
#endif


static struct tree *
find_node(char *name, struct tree *subtree)
{
    struct tree *tp, *ret;

    for (tp = subtree; tp; tp = tp->next_peer) {
	if (!strcasecmp(name, tp->label))
	    return tp;
	ret = find_node(name, tp->child_list);
	if (ret)
	    return ret;
    }
    return 0;
}


#if 0
static int
get_node(char *name, oid * objid, int *objidlen)
{
    struct tree *tp;
    oid newname[64], *op;

    tp = find_node(name, Mib);
    if (tp) {
	for (op = newname + 63; op >= newname; op--) {
	    *op = tp->subid;
	    tp = tp->parent;
	    if (tp == NULL)
		break;
	}
	if (newname + 64 - op > *objidlen)
	    return 0;
	*objidlen = newname + 64 - op;
	xmemcpy(objid, op, (newname + 64 - op) * sizeof(oid));
	return 1;
    } else {
	return 0;
    }


}
#endif
