    get_symbol(objid, objidlen, subtree, buf + 1);
}

#if 0
void
print_variable(objid, objidlen, pvariable)
     oid *objid;
     int objidlen;
     struct variable_list *pvariable;
{
    char buf[1024], *cp;
    struct snmp_mib_tree *subtree = Mib;

    *buf = '.';			/* this is a fully qualified name */
    subtree = get_symbol(objid, objidlen, subtree, buf + 1);
    cp = buf;
    if ((strlen(buf) >= strlen((char *) RFC1066_MIB_text)) && !memcmp(buf, (char *) RFC1066_MIB_text,
	    strlen((char *) RFC1066_MIB_text))) {
	cp += sizeof(RFC1066_MIB_text);
    }
    printf("Name: %s -> ", cp);
    *buf = '\0';
    if (subtree->printer)
	(*subtree->printer) (buf, pvariable, subtree->enums, 0);
    else {
	sprint_by_type(buf, pvariable, subtree->enums, 0);
    }
    printf("%s\n", buf);
}


void
sprint_variable(buf, objid, objidlen, pvariable)
     char *buf;
     oid *objid;
     int objidlen;
     struct variable_list *pvariable;
{
    char tempbuf[512], *cp;
    struct snmp_mib_tree *subtree = Mib;

    *tempbuf = '.';		/* this is a fully qualified name */
    subtree = get_symbol(objid, objidlen, subtree, tempbuf + 1);
    cp = tempbuf;
    if ((strlen(buf) >= strlen((char *) RFC1066_MIB_text)) && !memcmp(buf, (char *) RFC1066_MIB_text,
	    strlen((char *) RFC1066_MIB_text))) {
	cp += sizeof(RFC1066_MIB_text);
    }
    sprintf(buf, "Name: %s -> ", cp);
    buf += strlen(buf);
    if (subtree->printer)
	(*subtree->printer) (buf, pvariable, subtree->enums, 0);
    else {
	sprint_by_type(buf, pvariable, subtree->enums, 0);
    }
    strcat(buf, "\n");
}

void
sprint_value(buf, objid, objidlen, pvariable)
     char *buf;
     oid *objid;
     int objidlen;
     struct variable_list *pvariable;
{
    char tempbuf[512];
    struct snmp_mib_tree *subtree = Mib;

    subtree = get_symbol(objid, objidlen, subtree, tempbuf);
    if (subtree->printer)
	(*subtree->printer) (buf, pvariable, subtree->enums, 0);
    else {
	sprint_by_type(buf, pvariable, subtree->enums, 0);
    }
}

void
print_value(objid, objidlen, pvariable)
     oid *objid;
     int objidlen;
     struct variable_list *pvariable;
{
    char tempbuf[512];
    struct snmp_mib_tree *subtree = Mib;

    subtree = get_symbol(objid, objidlen, subtree, tempbuf);
    if (subtree->printer)
	(*subtree->printer) (tempbuf, pvariable, subtree->enums, 0);
    else {
	sprint_by_type(tempbuf, pvariable, subtree->enums, 0);
    }
    printf("%s\n", tempbuf);
}
#endif

static struct snmp_mib_tree *
get_symbol(objid, objidlen, subtree, buf)
     oid *objid;
