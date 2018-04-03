
void
print_variable(objid, objidlen, variable)
     oid *objid;
     int objidlen;
     struct variable_list *variable;
{
    char buf[2048];

    sprint_variable(buf, objid, objidlen, variable);
    printf("%s", buf);
}

static void
sprint_variable(buf, objid, objidlen, variable)
     char *buf;
     oid *objid;
     int objidlen;
     struct variable_list *variable;
{
    char tempbuf[2048];
    struct tree *subtree = Mib;

    sprint_objid(buf, objid, objidlen);
    buf += strlen(buf);
