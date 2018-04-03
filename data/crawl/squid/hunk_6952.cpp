  */
 static struct node *
 parse(fp)
-    FILE *fp;
+     FILE *fp;
 {
     char token[MAXTOKEN];
     char name[MAXTOKEN];
-    int	type = 1;
+    int type = 1;
 #define BETWEEN_MIBS  	      1
 #define IN_MIB                2
     int state = BETWEEN_MIBS;
     struct node *np = 0, *root = NULL;
 
     hash_init();
-    quoted_string_buffer = (char *)calloc(1, MAXQUOTESTR);  /* free this later */
+    quoted_string_buffer = (char *) calloc(1, MAXQUOTESTR);	/* free this later */
     bzero(tclist, 64 * sizeof(struct tc));
 
-    while(type != ENDOFFILE){
+    while (type != ENDOFFILE) {
 	type = get_token(fp, token);
-skipget:
-	if (type == END){
-	    if (state != IN_MIB){
-		print_error("Error, end before start of MIB.", (char *)NULL, type);
+      skipget:
+	if (type == END) {
+	    if (state != IN_MIB) {
+		print_error("Error, end before start of MIB.", (char *) NULL, type);
 		return NULL;
 	    }
 	    state = BETWEEN_MIBS;
 	    continue;
-	} else if (type != LABEL){
-	    if (type == ENDOFFILE){
+	} else if (type != LABEL) {
+	    if (type == ENDOFFILE) {
 		return root;
 	    }
 	    print_error(token, "is a reserved word", type);
 	    return NULL;
 	}
 	strncpy(name, token, MAXTOKEN);
 	type = get_token(fp, token);
-	if (type == DEFINITIONS){
-	    if (state != BETWEEN_MIBS){
-		print_error("Error, nested MIBS.", (char *)NULL, type);
+	if (type == DEFINITIONS) {
+	    if (state != BETWEEN_MIBS) {
+		print_error("Error, nested MIBS.", (char *) NULL, type);
 		return NULL;
 	    }
 	    state = IN_MIB;
-	    if (!parse_mib_header(fp, name)){
-		print_error("Bad parse of module header", (char *)NULL, type);
+	    if (!parse_mib_header(fp, name)) {
+		print_error("Bad parse of module header", (char *) NULL, type);
 		return NULL;
 	    }
-       } else if (type == OBJTYPE){
-	    if (root == NULL){
+	} else if (type == OBJTYPE) {
+	    if (root == NULL) {
 		/* first link in chain */
 		np = root = parse_objecttype(fp, name);
-		if (np == NULL){
-		    print_error("Bad parse of object type", (char *)NULL,
-				type);
+		if (np == NULL) {
+		    print_error("Bad parse of object type", (char *) NULL,
+			type);
 		    return NULL;
 		}
 	    } else {
 		np->next = parse_objecttype(fp, name);
-		if (np->next == NULL){
-		    print_error("Bad parse of objecttype", (char *)NULL,
-				type);
+		if (np->next == NULL) {
+		    print_error("Bad parse of objecttype", (char *) NULL,
+			type);
 		    return NULL;
 		}
 	    }
 	    /* now find end of chain */
-	    while(np->next)
+	    while (np->next)
 		np = np->next;
-	} else if (type == OBJGROUP){
-	    if (root == NULL){
+	} else if (type == OBJGROUP) {
+	    if (root == NULL) {
 		/* first link in chain */
 		np = root = parse_objectgroup(fp, name);
-		if (np == NULL){
-		    print_error("Bad parse of object group", (char *)NULL,
-				type);
+		if (np == NULL) {
+		    print_error("Bad parse of object group", (char *) NULL,
+			type);
 		    return NULL;
 		}
 	    } else {
 		np->next = parse_objectgroup(fp, name);
-		if (np->next == NULL){
-		    print_error("Bad parse of objectgroup", (char *)NULL,
-				type);
+		if (np->next == NULL) {
+		    print_error("Bad parse of objectgroup", (char *) NULL,
+			type);
 		    return NULL;
 		}
 	    }
 	    /* now find end of chain */
-	    while(np->next)
+	    while (np->next)
 		np = np->next;
-	} else if (type == NOTIFTYPE){
-	    if (root == NULL){
+	} else if (type == NOTIFTYPE) {
+	    if (root == NULL) {
 		/* first link in chain */
 		np = root = parse_notificationDefinition(fp, name);
-		if (np == NULL){
+		if (np == NULL) {
 		    print_error("Bad parse of notification definition",
-				(char *)NULL, type);
+			(char *) NULL, type);
 		    return NULL;
 		}
 	    } else {
 		np->next = parse_notificationDefinition(fp, name);
-		if (np->next == NULL){
+		if (np->next == NULL) {
 		    print_error("Bad parse of notification definition",
-				(char *)NULL, type);
+			(char *) NULL, type);
 		    return NULL;
 		}
 	    }
 	    /* now find end of chain */
-	    while(np->next)
+	    while (np->next)
 		np = np->next;
-	} else if (type == COMPLIANCE){
-	    if (root == NULL){
+	} else if (type == COMPLIANCE) {
+	    if (root == NULL) {
 		/* first link in chain */
 		np = root = parse_compliance(fp, name);
-		if (np == NULL){
-		    print_error("Bad parse of module compliance", (char *)NULL,
-				type);
+		if (np == NULL) {
+		    print_error("Bad parse of module compliance", (char *) NULL,
+			type);
 		    return NULL;
 		}
 	    } else {
 		np->next = parse_compliance(fp, name);
-		if (np->next == NULL){
-		    print_error("Bad parse of module compliance", (char *)NULL,
-				type);
+		if (np->next == NULL) {
+		    print_error("Bad parse of module compliance", (char *) NULL,
+			type);
 		    return NULL;
 		}
 	    }
 	    /* now find end of chain */
-	    while(np->next)
+	    while (np->next)
 		np = np->next;
-	} else if (type == MODULEIDENTITY){
-	    if (root == NULL){
+	} else if (type == MODULEIDENTITY) {
+	    if (root == NULL) {
 		/* first link in chain */
 		np = root = parse_moduleIdentity(fp, name);
-		if (np == NULL){
-		    print_error("Bad parse of module identity", (char *)NULL,
-				type);
+		if (np == NULL) {
+		    print_error("Bad parse of module identity", (char *) NULL,
+			type);
 		    return NULL;
 		}
 	    } else {
 		np->next = parse_moduleIdentity(fp, name);
-		if (np->next == NULL){
-		    print_error("Bad parse of module identity", (char *)NULL,
-				type);
+		if (np->next == NULL) {
+		    print_error("Bad parse of module identity", (char *) NULL,
+			type);
 		    return NULL;
 		}
 	    }
 	    /* now find end of chain */
-	    while(np->next)
+	    while (np->next)
 		np = np->next;
-	} else if (type == OBJID){
-	    if (root == NULL){
+	} else if (type == OBJID) {
+	    if (root == NULL) {
 		/* first link in chain */
 		np = root = parse_objectid(fp, name);
-		if (np == NULL){
-		    print_error("Bad parse of object id", (char *)NULL, type);
+		if (np == NULL) {
+		    print_error("Bad parse of object id", (char *) NULL, type);
 		    return NULL;
 		}
 	    } else {
 		np->next = parse_objectid(fp, name);
-		if (np->next == NULL){
-		    print_error("Bad parse of object type", (char *)NULL,
-				type);
+		if (np->next == NULL) {
+		    print_error("Bad parse of object type", (char *) NULL,
+			type);
 		    return NULL;
 		}
 	    }
 	    /* now find end of chain */
-	    while(np->next)
+	    while (np->next)
 		np = np->next;
-	} else if (type == EQUALS){
-	    if (!parse_asntype(fp, name, &type, token)){
+	} else if (type == EQUALS) {
+	    if (!parse_asntype(fp, name, &type, token)) {
 		print_error("Bad parse of ASN type definition.", NULL, EQUALS);
 		return NULL;
 	    }
 	    goto skipget;
-	} else if (type == ENDOFFILE){
+	} else if (type == ENDOFFILE) {
 	    break;
 	} else {
-	    print_error("Bad operator", (char *)NULL, type);
+	    print_error("Bad operator", (char *) NULL, type);
 	    return NULL;
 	}
     }
 #ifdef TEST
-{
-    struct enum_list *ep;
-    
-    for(np = root; np; np = np->next){
-	printf("%s ::= { %s %d } (%d)\n", np->label, np->parent, np->subid,
+    {
+	struct enum_list *ep;
+
+	for (np = root; np; np = np->next) {
+	    printf("%s ::= { %s %d } (%d)\n", np->label, np->parent, np->subid,
 		np->type);
-	if (np->enums){
-	    printf("Enums: \n");
-	    for(ep = np->enums; ep; ep = ep->next){
-		printf("%s(%d)\n", ep->label, ep->value);
+	    if (np->enums) {
+		printf("Enums: \n");
+		for (ep = np->enums; ep; ep = ep->next) {
+		    printf("%s(%d)\n", ep->label, ep->value);
+		}
 	    }
 	}
     }
-}
 #endif /* TEST */
     return root;
 }
