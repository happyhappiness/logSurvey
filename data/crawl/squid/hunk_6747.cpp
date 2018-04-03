 	 * If we didn't find the entry, punt...
 	 */
 	if (tp == NULL) {
-	    fprintf(stderr, "sub-identifier not found: %s\n", buf);
+	    snmplib_debug(0, "sub-identifier not found: %s\n", buf);
 	    return (0);
 	}
     }
 
-  found:
-    if (subid > (u_long) MAX_SUBID) {
-	fprintf(stderr, "sub-identifier too large: %s\n", buf);
+found:
+    if(subid > (u_int)MAX_SUBID){
+	snmplib_debug(0, "sub-identifier too large: %s\n", buf);
 	return (0);
     }
-    if ((*out_len)-- <= 0) {
-	fprintf(stderr, "object identifier too long\n");
+
+    if ((*out_len)-- <= 0){
+	snmplib_debug(0, "object identifier too long\n");
 	return (0);
     }
     *output++ = subid;
 
     if (*input != '.')
 	return (1);
     if ((*out_len =
-	    parse_subtree(tp ? tp->child_list : NULL, ++input, output, out_len)) == 0)
+	 parse_subtree(tp ? tp->child_list : NULL, ++input, output, out_len)) == 0)
 	return (0);
     return (++*out_len);
 }
 
-void
-sprint_objid(char *buf, oid * objid, int objidlen)
+int read_objid(input, output, out_len)
+    char *input;
+    oid *output;
+    int	*out_len;   /* number of subid's in "output" */
 {
-    char tempbuf[2048], *cp;
-    struct tree *subtree = Mib;
-    *tempbuf = '.';		/* this is a fully qualified name */
-    get_symbol(objid, objidlen, subtree, tempbuf + 1);
-    if (Suffix) {
-	for (cp = tempbuf; *cp; cp++);
-	while (cp >= tempbuf) {
-	    if (isalpha(*cp))
-		break;
-	    cp--;
-	}
-	while (cp >= tempbuf) {
-	    if (*cp == '.')
-		break;
-	    cp--;
-	}
-	cp++;
-	if (cp < tempbuf)
-	    cp = tempbuf;
-    } else {
-	cp = tempbuf;
-	if ((strlen(tempbuf) > strlen((char *) RFC1213_MIB_text))
-	    && !bcmp(tempbuf, (char *) RFC1213_MIB_text,
-		strlen((char *) RFC1213_MIB_text))) {
-	    cp += sizeof(RFC1213_MIB_text);
-	}
-	if ((strlen(tempbuf) > strlen((char *) EXPERIMENTAL_MIB_text))
-	    && !bcmp(tempbuf, (char *) EXPERIMENTAL_MIB_text,
-		strlen((char *) EXPERIMENTAL_MIB_text))) {
-	    cp += sizeof(EXPERIMENTAL_MIB_text);
-	}
-	if ((strlen(tempbuf) > strlen((char *) PRIVATE_MIB_text))
-	    && !bcmp(tempbuf, (char *) PRIVATE_MIB_text,
-		strlen((char *) PRIVATE_MIB_text))) {
-	    cp += sizeof(PRIVATE_MIB_text);
-	}
-	if ((strlen(tempbuf) > strlen((char *) PARTY_MIB_text))
-	    && !bcmp(tempbuf, (char *) PARTY_MIB_text,
-		strlen((char *) PARTY_MIB_text))) {
-	    cp += sizeof(PARTY_MIB_text);
-	}
-	if ((strlen(tempbuf) > strlen((char *) SECRETS_MIB_text))
-	    && !bcmp(tempbuf, (char *) SECRETS_MIB_text,
-		strlen((char *) SECRETS_MIB_text))) {
-	    cp += sizeof(SECRETS_MIB_text);
+    struct snmp_mib_tree *root = Mib;
+    oid *op = output;
+    int i;
+
+    if (*input == '.')
+	input++;
+    else {
+	root = find_rfc1066_mib(root);
+	for (i = 0; i < sizeof (RFC1066_MIB)/sizeof(oid); i++) {
+	    if ((*out_len)-- > 0)
+		*output++ = RFC1066_MIB[i];
+	    else {
+		snmplib_debug(0, "object identifier too long\n");
+		return (0);
+	    }
 	}
     }
-    strcpy(buf, cp);
+
+    if (root == NULL){
+	snmplib_debug(0, "Mib not initialized.  Exiting.\n");
+	exit(1);
+    }
+    if ((*out_len =
+	 parse_subtree(root, input, output, out_len)) == 0)
+	return (0);
+    *out_len += output - op;
+
+    return (1);
 }
 
-void
-print_objid(oid * objid, int objidlen)
+void print_objid(objid, objidlen)
+    oid	    *objid;
+    int	    objidlen;	/* number of subidentifiers */
 {
-    char buf[256];
+    char    buf[256];
+    struct snmp_mib_tree    *subtree = Mib;
 
-    sprint_objid(buf, objid, objidlen);
-    printf("%s\n", buf);
+    *buf = '.';	/* this is a fully qualified name */
+    get_symbol(objid, objidlen, subtree, buf + 1);
+    snmplib_debug(7, "%s\n", buf);
+        
 }
 
+void sprint_objid(buf, objid, objidlen)
+    char *buf;
+    oid	    *objid;
+    int	    objidlen;	/* number of subidentifiers */
+{
+    struct snmp_mib_tree    *subtree = Mib;
+
+    *buf = '.';	/* this is a fully qualified name */
+    get_symbol(objid, objidlen, subtree, buf + 1);
+}
 
-void
-print_variable(oid * objid, int objidlen, struct variable_list *variable)
+
+void print_variable(objid, objidlen, pvariable)
+    oid     *objid;
+    int	    objidlen;
+    struct  variable_list *pvariable;
 {
-    char buf[2048];
+    char    buf[1024], *cp;
+    struct snmp_mib_tree    *subtree = Mib;
 
-    sprint_variable(buf, objid, objidlen, variable);
-    printf("%s", buf);
+    *buf = '.';	/* this is a fully qualified name */
+    subtree = get_symbol(objid, objidlen, subtree, buf + 1);
+    cp = buf;
+    if ((strlen(buf) >= strlen((char *)RFC1066_MIB_text)) && !memcmp(buf, (char *)RFC1066_MIB_text,
+	strlen((char *)RFC1066_MIB_text))){
+	    cp += sizeof(RFC1066_MIB_text);
+    }
+    printf("Name: %s -> ", cp);
+    *buf = '\0';
+    if (subtree->printer)
+	(*subtree->printer)(buf, pvariable, subtree->enums, 0);
+    else {
+	sprint_by_type(buf, pvariable, subtree->enums, 0);
+    }
+    printf("%s\n", buf);
 }
 
-static void
-sprint_variable(char *buf, oid * objid, int objidlen, struct variable_list *variable)
+
+void sprint_variable(buf, objid, objidlen, pvariable)
+    char *buf;
+    oid     *objid;
+    int	    objidlen;
+    struct  variable_list *pvariable;
 {
-    char tempbuf[2048];
-    struct tree *subtree = Mib;
+    char    tempbuf[512], *cp;
+    struct snmp_mib_tree    *subtree = Mib;
 
-    sprint_objid(buf, objid, objidlen);
-    buf += strlen(buf);
-    strcat(buf, " = ");
+    *tempbuf = '.';	/* this is a fully qualified name */
+    subtree = get_symbol(objid, objidlen, subtree, tempbuf + 1);
+    cp = tempbuf;
+    if ((strlen(buf) >= strlen((char *)RFC1066_MIB_text)) && !memcmp(buf, (char *)RFC1066_MIB_text,
+	strlen((char *)RFC1066_MIB_text))){
+	    cp += sizeof(RFC1066_MIB_text);
+    }
+    sprintf(buf, "Name: %s -> ", cp);
     buf += strlen(buf);
-
-    if (variable->type == SNMP_NOSUCHOBJECT)
-	sprintf(buf, "No Such Object available on this agent\n");
-    else if (variable->type == SNMP_NOSUCHINSTANCE)
-	sprintf(buf, "No Such Instance currently exists\n");
-    else if (variable->type == SNMP_ENDOFMIBVIEW)
-	sprintf(buf, "No more variables left in this MIB View\n");
+    if (subtree->printer)
+	(*subtree->printer)(buf, pvariable, subtree->enums, 0);
     else {
-	*tempbuf = '.';		/* this is a fully qualified name */
-	subtree = get_symbol(objid, objidlen, subtree, tempbuf + 1);
-	buf += strlen(buf);
-	if (subtree->printer)
-	    (*subtree->printer) (buf, variable, subtree->enums);
-	else {
-	    sprint_by_type(buf, variable, subtree->enums);
-	}
-	strcat(buf, "\n");
+	sprint_by_type(buf, pvariable, subtree->enums, 0);
     }
+    strcat(buf, "\n");
 }
 
-void
-sprint_value(char *buf, oid * objid, int objidlen, struct variable_list *variable)
+void sprint_value(buf, objid, objidlen, pvariable)
+    char *buf;
+    oid     *objid;
+    int	    objidlen;
+    struct  variable_list *pvariable;
 {
-    char tempbuf[2048];
-    struct tree *subtree = Mib;
-
-    if (variable->type == SNMP_NOSUCHOBJECT)
-	sprintf(buf, "No Such Object available on this agent\n");
-    else if (variable->type == SNMP_NOSUCHINSTANCE)
-	sprintf(buf, "No Such Instance currently exists\n");
-    else if (variable->type == SNMP_ENDOFMIBVIEW)
-	sprintf(buf, "No more variables left in this MIB View\n");
+    char    tempbuf[512];
+    struct snmp_mib_tree    *subtree = Mib;
+
+    subtree = get_symbol(objid, objidlen, subtree, tempbuf);
+    if (subtree->printer)
+	(*subtree->printer)(buf, pvariable, subtree->enums, 0);
     else {
-	subtree = get_symbol(objid, objidlen, subtree, tempbuf);
-	if (subtree->printer)
-	    (*subtree->printer) (buf, variable, subtree->enums);
-	else {
-	    sprint_by_type(buf, variable, subtree->enums);
-	}
+	sprint_by_type(buf, pvariable, subtree->enums, 0);
     }
 }
 
-void
-print_value(oid * objid, int objidlen, struct variable_list *variable)
+void print_value(objid, objidlen, pvariable)
+    oid     *objid;
+    int	    objidlen;
+    struct  variable_list *pvariable;
 {
-    char tempbuf[2048];
+    char    tempbuf[512];
+    struct snmp_mib_tree    *subtree = Mib;
 
-    sprint_value(tempbuf, objid, objidlen, variable);
+    subtree = get_symbol(objid, objidlen, subtree, tempbuf);
+    if (subtree->printer)
+	(*subtree->printer)(tempbuf, pvariable, subtree->enums, 0);
+    else {
+	sprint_by_type(tempbuf, pvariable, subtree->enums, 0);
+    }
     printf("%s\n", tempbuf);
 }
 
-static struct tree *
-get_symbol(oid * objid, int objidlen, struct tree *subtree, char *buf)
+static struct snmp_mib_tree *
+get_symbol(objid, objidlen, subtree, buf)
+    oid	    *objid;
+    int	    objidlen;
+    struct snmp_mib_tree    *subtree;
+    char    *buf;
 {
-    struct tree *return_tree = NULL;
+    struct snmp_mib_tree    *return_tree = NULL;
 
-    for (; subtree; subtree = subtree->next_peer) {
-	if (*objid == subtree->subid) {
+    for(; subtree; subtree = subtree->next_peer){
+	if (*objid == subtree->subid){
 	    strcpy(buf, subtree->label);
 	    goto found;
 	}
     }
 
     /* subtree not found */
-    while (objidlen--) {	/* output rest of name, uninterpreted */
-	sprintf(buf, "%lu.", *objid++);
-	while (*buf)
+    while(objidlen--){	/* output rest of name, uninterpreted */
+	sprintf(buf, "%u.", *objid++);
+	while(*buf)
 	    buf++;
     }
-    *(buf - 1) = '\0';		/* remove trailing dot */
+    *(buf - 1) = '\0'; /* remove trailing dot */
     return NULL;
 
-  found:
-    if (objidlen > 1) {
-	while (*buf)
+found:
+    if (objidlen > 1){
+	while(*buf)
 	    buf++;
 	*buf++ = '.';
 	*buf = '\0';
-	return_tree = get_symbol(objid + 1, objidlen - 1, subtree->child_list,
-	    buf);
-    }
+	return_tree = get_symbol(objid + 1, objidlen - 1, subtree->child_list, buf);
+    } 
     if (return_tree != NULL)
 	return return_tree;
     else
 	return subtree;
 }
 
 
-static int
-lc_cmp(char *s1, char *s2)
-{
-    char c1, c2;
-
-    while (*s1 && *s2) {
-	if (isupper(*s1))
-	    c1 = tolower(*s1);
-	else
-	    c1 = *s1;
-	if (isupper(*s2))
-	    c2 = tolower(*s2);
-	else
-	    c2 = *s2;
-	if (c1 != c2)
-	    return ((c1 - c2) > 0 ? 1 : -1);
-	s1++;
-	s2++;
-    }
-
-    if (*s1)
-	return -1;
-    if (*s2)
-	return 1;
-    return 0;
-}
-
-/*
- * Clone of get_symbol that doesn't take a buffer argument
- */
-static struct tree *
-get_tree(oid * objid, int objidlen, struct tree *subtree)
-{
-    struct tree *return_tree = NULL;
-
-    for (; subtree; subtree = subtree->next_peer) {
-	if (*objid == subtree->subid)
-	    goto found;
-    }
 
-    return NULL;
 
-  found:
-    if (objidlen > 1)
-	return_tree = get_tree(objid + 1, objidlen - 1, subtree->child_list);
-    if (return_tree != NULL)
-	return return_tree;
-    else
-	return subtree;
-}
 
 
-#if 0
-static char *
-get_description(oid * objid, int objidlen)
+void print_variable_list(variable_list *V)
 {
-    struct tree *subtree = Mib;
-
-    subtree = get_tree(objid, objidlen, subtree);
-    if (subtree)
-	return (subtree->description);
-    else
-	return NULL;
+  print_variable(V->name, V->name_length, V);
 }
-#endif
 
 
-#if 0
-static void
-print_description(oid * objid, int objidlen)
+void print_variable_list_value(variable_list *pvariable)
 {
-    char *desc = get_description(objid, objidlen);
+  char    buf[512];
+  struct snmp_mib_tree    *subtree = Mib;
 
-    if (desc && desc[0] != '\0')
-	printf("Description: \"%s\"\n", desc);
-    else
-	printf("No description\n");
-}
-#endif
+  *buf = '.';	/* this is a fully qualified name */
+  subtree = get_symbol(pvariable->name, pvariable->name_length, subtree, buf + 1);
+  *buf = '\0';
 
+  if (subtree->printer)
+    (*subtree->printer)(buf, pvariable, subtree->enums, 1);
+  else {
+    sprint_by_type(buf, pvariable, subtree->enums, 1);
+  }
+  printf("%s", buf);
+}
 
-static struct tree *
-find_node(char *name, struct tree *subtree)
+void print_type(variable_list *var)
 {
-    struct tree *tp, *ret;
-
-    for (tp = subtree; tp; tp = tp->next_peer) {
-	if (!strcasecmp(name, tp->label))
-	    return tp;
-	ret = find_node(name, tp->child_list);
-	if (ret)
-	    return ret;
-    }
-    return 0;
+  switch (var->type){
+  case SMI_INTEGER:
+    printf("Integer");
+    break;
+  case SMI_STRING:
+    printf("Octet String");
+    break;
+  case SMI_OPAQUE:
+    printf("Opaque");
+    break;
+  case SMI_OBJID:
+    printf("Object Identifier");
+    break;
+  case SMI_TIMETICKS:
+    printf("Timeticks");
+    break;
+  case SMI_GAUGE32:
+    printf("Gauge");
+    break;
+  case SMI_COUNTER32:
+    printf("Counter");
+    break;
+  case SMI_IPADDRESS:
+    printf("IP Address");
+    break;
+  case SMI_NULLOBJ:
+    printf("NULL");
+    break;
+  default:
+    printf("Unknown type %d\n", var->type);
+    break;
+  }
 }
 
-
-#if 0
-static int
-get_node(char *name, oid * objid, int *objidlen)
+void print_oid_nums(oid *O, int len)
 {
-    struct tree *tp;
-    oid newname[64], *op;
-
-    tp = find_node(name, Mib);
-    if (tp) {
-	for (op = newname + 63; op >= newname; op--) {
-	    *op = tp->subid;
-	    tp = tp->parent;
-	    if (tp == NULL)
-		break;
-	}
-	if (newname + 64 - op > *objidlen)
-	    return 0;
-	*objidlen = newname + 64 - op;
-	xmemcpy(objid, op, (newname + 64 - op) * sizeof(oid));
-	return 1;
-    } else {
-	return 0;
-    }
-
+  int x;
 
+  for (x=0;x<len;x++)
+    printf(".%u", O[x]);
 }
-#endif
