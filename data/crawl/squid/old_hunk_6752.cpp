		    return NULL;
	    }
	} else {
	    print_error("Missing end of oid", (char *) NULL, type);
	    free_node(np);	/* the last node allocated wasn't used */
	    if (oldnp)
		oldnp->next = NULL;
	    return NULL;
	}
	/* free the oid array */
	for (count = 0, op = oid; count < length; count++, op++) {
	    if (op->label)
		xfree(op->label);
	    op->label = 0;
	}
	return root;
    } else {
	print_error("Bad object identifier", (char *) NULL, type);
	return 0;
    }
}

static int
get_tc(char *descriptor, struct enum_list **ep)
{
    int i;

    for (i = 0; i < MAXTC; i++) {
	if (tclist[i].type == 0)
	    break;
	if (!strcmp(descriptor, tclist[i].descriptor)) {
	    *ep = tclist[i].enums;
	    return tclist[i].type;
	}
    }
    return LABEL;
}

/*
 * Parses an asn type.  Structures are ignored by this parser.
 * Returns NULL on error.
 */
static int
parse_asntype(FILE * fp, char *name, int *ntype, char *ntoken)
{
    int type, i;
    char token[MAXTOKEN];
    struct enum_list *ep = 0;
    struct tc *tcp;
    int level;

    type = get_token(fp, token);
    if (type == SEQUENCE) {
	while ((type = get_token(fp, token)) != ENDOFFILE) {
	    if (type == RIGHTBRACKET) {
		*ntype = get_token(fp, ntoken);
		return 1;
	    }
	}
	print_error("Expected \"}\"", token, type);
	return 0;
    } else {
	if (!strcmp(token, "TEXTUAL-CONVENTION")) {
	    while (type != SYNTAX)
		type = get_token(fp, token);
	    type = get_token(fp, token);
	}
	/* textual convention */
	for (i = 0; i < MAXTC; i++) {
	    if (tclist[i].type == 0)
		break;
	}
	if (i == MAXTC) {
	    print_error("No more textual conventions possible.", token, type);
	    return 0;
	}
	tcp = &tclist[i];
	strcpy(tcp->descriptor, name);
	if (!(type & SYNTAX_MASK)) {
	    print_error("Textual convention doesn't map to real type.", token,
		type);
	    return 0;
	}
	tcp->type = type;
	*ntype = get_token(fp, ntoken);
	if (*ntype == LEFTPAREN) {
	    level = 1;
	    /* don't record any constraints for now */
	    while (level > 0) {
		*ntype = get_token(fp, ntoken);
		if (*ntype == LEFTPAREN)
		    level++;
		if (*ntype == RIGHTPAREN)
		    level--;
	    }
	    *ntype = get_token(fp, ntoken);
	} else if (*ntype == LEFTBRACKET) {
	    /* if there is an enumeration list, parse it */
	    while ((type = get_token(fp, token)) != ENDOFFILE) {
		if (type == RIGHTBRACKET)
		    break;
		if (type == LABEL) {
		    /* this is an enumerated label */
		    if (tcp->enums == 0) {
			ep = tcp->enums = (struct enum_list *)
			    Malloc(sizeof(struct enum_list));
		    } else {
			ep->next = (struct enum_list *)
			    Malloc(sizeof(struct enum_list));
			ep = ep->next;
		    }
		    ep->next = 0;
		    /* a reasonable approximation for the length */
		    ep->label =
			(char *) Malloc((unsigned) strlen(token) + 1);
		    strcpy(ep->label, token);
		    type = get_token(fp, token);
		    if (type != LEFTPAREN) {
			print_error("Expected \"(\"", token, type);
			/* free_node(np); */
			return 0;
		    }
		    type = get_token(fp, token);
		    if (type != NUMBER) {
			print_error("Expected integer", token, type);
			/* free_node(np); */
			return 0;
		    }
		    ep->value = atoi(token);
		    type = get_token(fp, token);
		    if (type != RIGHTPAREN) {
			print_error("Expected \")\"", token, type);
			/* free_node(np); */
			return 0;
		    }
		}
	    }
	    if (type == ENDOFFILE) {
		print_error("Expected \"}\"", token, type);
		/* free_node(np); */
		return 0;
	    }
	    *ntype = get_token(fp, ntoken);
	}
	return 1;
    }
}


/*
 * Parses an OBJECT TYPE macro.
 * Returns 0 on error.
 */
static struct node *
parse_objecttype(FILE * fp, char *name)
{
    int type;
    char token[MAXTOKEN];
    int count, length;
    struct subid oid[32];
    char syntax[MAXTOKEN];
    int nexttype, tctype;
    char nexttoken[MAXTOKEN];
    struct node *np;
    struct enum_list *ep = 0;

    type = get_token(fp, token);
    if (type != SYNTAX) {
	print_error("Bad format for OBJECT TYPE", token, type);
	return 0;
    }
    np = (struct node *) Malloc(sizeof(struct node));
    np->next = 0;
    np->enums = 0;
    np->description = NULL;	/* default to an empty description */
    type = get_token(fp, token);
    if (type == LABEL) {
	tctype = get_tc(token, &(np->enums));
#if 0
	if (tctype == LABEL) {
	    print_error("No known translation for type", token, type);
	    return 0;
	}
#endif
	type = tctype;
    }
    np->type = type;
    nexttype = get_token(fp, nexttoken);
    switch (type) {
    case SEQUENCE:
	strcpy(syntax, token);
	if (nexttype == OF) {
	    strcat(syntax, " ");
	    strcat(syntax, nexttoken);
	    nexttype = get_token(fp, nexttoken);
	    strcat(syntax, " ");
	    strcat(syntax, nexttoken);
	    nexttype = get_token(fp, nexttoken);
	}
	break;
    case INTEGER:
    case UINTEGER32:
	strcpy(syntax, token);
	if (nexttype == LEFTBRACKET) {
	    /* if there is an enumeration list, parse it */
	    while ((type = get_token(fp, token)) != ENDOFFILE) {
		if (type == RIGHTBRACKET)
		    break;
		if (type == LABEL) {
		    /* this is an enumerated label */
		    if (np->enums == 0) {
			ep = np->enums = (struct enum_list *)
			    Malloc(sizeof(struct enum_list));
		    } else {
			ep->next = (struct enum_list *)
			    Malloc(sizeof(struct enum_list));
			ep = ep->next;
		    }
		    ep->next = 0;
		    /* a reasonable approximation for the length */
		    ep->label =
			(char *) Malloc((unsigned) strlen(token) + 1);
		    strcpy(ep->label, token);
		    type = get_token(fp, token);
		    if (type != LEFTPAREN) {
			print_error("Expected \"(\"", token, type);
			free_node(np);
			return 0;
		    }
		    type = get_token(fp, token);
		    if (type != NUMBER) {
			print_error("Expected integer", token, type);
			free_node(np);
			return 0;
		    }
		    ep->value = atoi(token);
		    type = get_token(fp, token);
		    if (type != RIGHTPAREN) {
			print_error("Expected \")\"", token, type);
			free_node(np);
			return 0;
		    }
		}
	    }
	    if (type == ENDOFFILE) {
		print_error("Expected \"}\"", token, type);
		free_node(np);
		return 0;
	    }
	    nexttype = get_token(fp, nexttoken);
	} else if (nexttype == LEFTPAREN) {
	    /* ignore the "constrained integer" for now */
	    nexttype = get_token(fp, nexttoken);
	    nexttype = get_token(fp, nexttoken);
	    nexttype = get_token(fp, nexttoken);
	}
	break;
    case BITSTRING:
	strcpy(syntax, token);
	if (nexttype == LEFTBRACKET) {
	    /* if there is an enumeration list, parse it */
	    while ((type = get_token(fp, token)) != ENDOFFILE) {
		if (type == RIGHTBRACKET)
		    break;
		if (type == LABEL) {
		    /* this is an enumerated label */
		    if (np->enums == 0) {
			ep = np->enums = (struct enum_list *)
			    Malloc(sizeof(struct enum_list));
		    } else {
			ep->next = (struct enum_list *)
			    Malloc(sizeof(struct enum_list));
			ep = ep->next;
		    }
		    ep->next = 0;
		    /* a reasonable approximation for the length */
		    ep->label =
			(char *) Malloc((unsigned) strlen(token) + 1);
		    strcpy(ep->label, token);
		    type = get_token(fp, token);
		    if (type != LEFTPAREN) {
			print_error("Expected \"(\"", token, type);
			free_node(np);
			return 0;
		    }
		    type = get_token(fp, token);
		    if (type != NUMBER) {
			print_error("Expected integer", token, type);
			free_node(np);
			return 0;
		    }
		    ep->value = atoi(token);
		    type = get_token(fp, token);
		    if (type != RIGHTPAREN) {
			print_error("Expected \")\"", token, type);
			free_node(np);
			return 0;
		    }
		}
	    }
	    if (type == ENDOFFILE) {
		print_error("Expected \"}\"", token, type);
		free_node(np);
		return 0;
	    }
	    nexttype = get_token(fp, nexttoken);
	} else if (nexttype == LEFTPAREN) {
	    /* ignore the "constrained integer" for now */
	    nexttype = get_token(fp, nexttoken);
	    nexttype = get_token(fp, nexttoken);
	    nexttype = get_token(fp, nexttoken);
	}
	break;
    case OCTETSTR:
	strcpy(syntax, token);
	/* ignore the "constrained octet string" for now */
	if (nexttype == LEFTPAREN) {
	    nexttype = get_token(fp, nexttoken);
	    if (nexttype == SIZE) {
		nexttype = get_token(fp, nexttoken);
		if (nexttype == LEFTPAREN) {
		    nexttype = get_token(fp, nexttoken);	/* 0..255 */
		    nexttype = get_token(fp, nexttoken);	/* ) */
		    nexttype = get_token(fp, nexttoken);	/* ) */
		    if (nexttype == RIGHTPAREN) {
			nexttype = get_token(fp, nexttoken);
			break;
		    }
		}
	    }
	    print_error("Bad syntax", token, type);
	    free_node(np);
	    return 0;
	}
	break;
    case OBJID:
    case NETADDR:
    case IPADDR:
    case COUNTER:
    case GAUGE:
    case TIMETICKS:
    case OPAQUE:
    case NUL:
    case LABEL:
    case NSAPADDRESS:
    case COUNTER64:
	strcpy(syntax, token);
	break;
    default:
	print_error("Bad syntax", token, type);
	free_node(np);
	return 0;
    }
    if (nexttype == UNITS) {
	type = get_token(fp, token);
	if (type != QUOTESTRING) {
	    print_error("Bad DESCRIPTION", token, type);
	    free_node(np);
	    return 0;
	}
	nexttype = get_token(fp, nexttoken);
    }
    if (nexttype != ACCESS) {
	print_error("Should be ACCESS", nexttoken, nexttype);
	free_node(np);
	return 0;
    }
    type = get_token(fp, token);
    if (type != READONLY && type != READWRITE && type != WRITEONLY
	&& type != NOACCESS && type != READCREATE) {
	print_error("Bad access type", nexttoken, nexttype);
	free_node(np);
	return 0;
    }
    type = get_token(fp, token);
    if (type != STATUS) {
	print_error("Should be STATUS", token, nexttype);
	free_node(np);
	return 0;
    }
    type = get_token(fp, token);
    if (type != MANDATORY && type != CURRENT && type != OPTIONAL && type != OBSOLETE && type != DEPRECATED) {
	print_error("Bad status", token, type);
	free_node(np);
	return 0;
    }
    /*
     * Optional parts of the OBJECT-TYPE macro
     */
    type = get_token(fp, token);
    while (type != EQUALS) {
	switch (type) {
	case DESCRIPTION:
	    type = get_token(fp, token);
	    if (type != QUOTESTRING) {
		print_error("Bad DESCRIPTION", token, type);
		free_node(np);
		return 0;
	    }
#ifdef TEST
	    printf("Description== \"%.50s\"\n", quoted_string_buffer);
#endif
	    np->description = quoted_string_buffer;
	    quoted_string_buffer = xcalloc(1, MAXQUOTESTR);
	    break;

	case REFERENCE:
	    type = get_token(fp, token);
	    if (type != QUOTESTRING) {
		print_error("Bad DESCRIPTION", token, type);
		free_node(np);
		return 0;
	    }
	    break;
	case INDEX:
	case DEFVAL:
	case AUGMENTS:
	case NUM_ENTRIES:
	    if (tossObjectIdentifier(fp) != OBJID) {
		print_error("Bad Object Identifier", token, type);
		free_node(np);
		return 0;
	    }
	    break;

	default:
	    print_error("Bad format of optional clauses", token, type);
	    free_node(np);
	    return 0;

	}
	type = get_token(fp, token);
    }
    if (type != EQUALS) {
	print_error("Bad format", token, type);
	free_node(np);
	return 0;
    }
    length = getoid(fp, oid, 32);
    if (length > 1 && length <= 32) {
	/* just take the last pair in the oid list */
	if (oid[length - 2].label)
	    strncpy(np->parent, oid[length - 2].label, MAXLABEL);
	strcpy(np->label, name);
	if (oid[length - 1].subid != -1)
	    np->subid = oid[length - 1].subid;
	else
	    print_error("Warning: This entry is pretty silly", np->label, type);
    } else {
	print_error("No end to oid", (char *) NULL, type);
	free_node(np);
	np = 0;
    }
    /* free oid array */
    for (count = 0; count < length; count++) {
	if (oid[count].label)
	    xfree(oid[count].label);
	oid[count].label = 0;
    }
    return np;
}


/*
 * Parses an OBJECT GROUP macro.
 * Returns 0 on error.
 */
static struct node *
parse_objectgroup(FILE * fp, char *name)
{
    int type;
    char token[MAXTOKEN];
    int count, length;
    struct subid oid[32];
    struct node *np;

    np = (struct node *) Malloc(sizeof(struct node));
    np->type = 0;
    np->next = 0;
    np->enums = 0;
    np->description = NULL;	/* default to an empty description */
    type = get_token(fp, token);
    while (type != EQUALS) {
	switch (type) {
	case DESCRIPTION:
	    type = get_token(fp, token);
	    if (type != QUOTESTRING) {
		print_error("Bad DESCRIPTION", token, type);
		free_node(np);
		return 0;
	    }
#ifdef TEST
	    printf("Description== \"%.50s\"\n", quoted_string_buffer);
#endif
	    np->description = quoted_string_buffer;
	    quoted_string_buffer = xcalloc(1, MAXQUOTESTR);
	    break;

	default:
	    /* NOTHING */
	    break;
	}
	type = get_token(fp, token);
    }
    length = getoid(fp, oid, 32);
    if (length > 1 && length <= 32) {
	/* just take the last pair in the oid list */
	if (oid[length - 2].label)
	    strncpy(np->parent, oid[length - 2].label, MAXLABEL);
	strcpy(np->label, name);
	if (oid[length - 1].subid != -1)
	    np->subid = oid[length - 1].subid;
	else
	    print_error("Warning: This entry is pretty silly", np->label, type);
    } else {
	print_error("No end to oid", (char *) NULL, type);
	free_node(np);
	np = 0;
    }
    /* free oid array */
    for (count = 0; count < length; count++) {
	if (oid[count].label)
	    xfree(oid[count].label);
	oid[count].label = 0;
    }
    return np;
}

/*
 * Parses a NOTIFICATION-TYPE macro.
 * Returns 0 on error.
 */
static struct node *
parse_notificationDefinition(FILE * fp, char *name)
{
    int type;
    char token[MAXTOKEN];
    int count, length;
    struct subid oid[32];
    struct node *np;

    np = (struct node *) Malloc(sizeof(struct node));
    np->type = 0;
    np->next = 0;
    np->enums = 0;
    np->description = NULL;	/* default to an empty description */
    type = get_token(fp, token);
    while (type != EQUALS) {
	switch (type) {
	case DESCRIPTION:
	    type = get_token(fp, token);
	    if (type != QUOTESTRING) {
		print_error("Bad DESCRIPTION", token, type);
		free_node(np);
		return 0;
	    }
#ifdef TEST
	    printf("Description== \"%.50s\"\n", quoted_string_buffer);
#endif
	    np->description = quoted_string_buffer;
	    quoted_string_buffer = xcalloc(1, MAXQUOTESTR);
	    break;

	default:
	    /* NOTHING */
	    break;
	}
	type = get_token(fp, token);
    }
    length = getoid(fp, oid, 32);
    if (length > 1 && length <= 32) {
	/* just take the last pair in the oid list */
	if (oid[length - 2].label)
	    strncpy(np->parent, oid[length - 2].label, MAXLABEL);
	strcpy(np->label, name);
	if (oid[length - 1].subid != -1)
	    np->subid = oid[length - 1].subid;
	else
	    print_error("Warning: This entry is pretty silly", np->label, type);
    } else {
	print_error("No end to oid", (char *) NULL, type);
	free_node(np);
	np = 0;
    }
    /* free oid array */
    for (count = 0; count < length; count++) {
	if (oid[count].label)
	    xfree(oid[count].label);
	oid[count].label = 0;
    }
    return np;
}

/*
 * Parses a compliance macro
 * Returns 0 on error.
 */
static struct node *
parse_compliance(FILE * fp, char *name)
{
    int type;
    char token[MAXTOKEN];
    int count, length;
    struct subid oid[32];
    struct node *np;

    np = (struct node *) Malloc(sizeof(struct node));
    np->type = 0;
    np->next = 0;
    np->enums = 0;
    np->description = NULL;	/* default to an empty description */
    type = get_token(fp, token);
    while (type != EQUALS) {
	type = get_token(fp, token);
    }
    length = getoid(fp, oid, 32);
    if (length > 1 && length <= 32) {
	/* just take the last pair in the oid list */
	if (oid[length - 2].label)
	    strncpy(np->parent, oid[length - 2].label, MAXLABEL);
	strcpy(np->label, name);
	if (oid[length - 1].subid != -1)
	    np->subid = oid[length - 1].subid;
	else
	    print_error("Warning: This entry is pretty silly", np->label, type);
    } else {
	print_error("No end to oid", (char *) NULL, type);
	free_node(np);
	np = 0;
    }
    /* free oid array */
    for (count = 0; count < length; count++) {
	if (oid[count].label)
	    xfree(oid[count].label);
	oid[count].label = 0;
    }
    return np;
}



/*
 * Parses a module identity macro
 * Returns 0 on error.
 */
static struct node *
parse_moduleIdentity(FILE * fp, char *name)
{
    int type;
    char token[MAXTOKEN];
    int count, length;
    struct subid oid[32];
    struct node *np;

    np = (struct node *) Malloc(sizeof(struct node));
    np->type = 0;
    np->next = 0;
    np->enums = 0;
    np->description = NULL;	/* default to an empty description */
    type = get_token(fp, token);
    while (type != EQUALS) {
	type = get_token(fp, token);
    }
    length = getoid(fp, oid, 32);
    if (length > 1 && length <= 32) {
	/* just take the last pair in the oid list */
	if (oid[length - 2].label)
	    strncpy(np->parent, oid[length - 2].label, MAXLABEL);
	strcpy(np->label, name);
	if (oid[length - 1].subid != -1)
	    np->subid = oid[length - 1].subid;
	else
	    print_error("Warning: This entry is pretty silly", np->label, type);
    } else {
	print_error("No end to oid", (char *) NULL, type);
	free_node(np);
	np = 0;
    }
    /* free oid array */
    for (count = 0; count < length; count++) {
	if (oid[count].label)
	    xfree(oid[count].label);
	oid[count].label = 0;
    }
    return np;
}

int
parse_mib_header(FILE * fp, char *name)
{
    int type = DEFINITIONS;
    char token[MAXTOKEN];

    /* This probably isn't good enough.  If there is no
     * imports clause we can't go around waiting (forever) for a semicolon.
     * We need to check for semi following an EXPORTS clause or an IMPORTS
     * clause of both.  Look for BEGIN; in my initial MIBs to see those
     * that I needed to hack to get to parse because they didn't have
     * an IMPORTS or and EXPORTS clause.
     */
    while (type != SEMI && type != ENDOFFILE) {
	type = get_token(fp, token);
    }
    return (type == SEMI);
}



/*
 * Parses a mib file and returns a linked list of nodes found in the file.
 * Returns NULL on error.
 */
static struct node *
parse(FILE * fp)
{
    char token[MAXTOKEN];
    char name[MAXTOKEN];
    int type = 1;
#define BETWEEN_MIBS  	      1
#define IN_MIB                2
    int state = BETWEEN_MIBS;
    struct node *np = 0, *root = NULL;

    hash_init();
    quoted_string_buffer = xcalloc(1, MAXQUOTESTR);	/* free this later */
    memset(tclist, '\0', 64 * sizeof(struct tc));

    while (type != ENDOFFILE) {
	type = get_token(fp, token);
      skipget:
	if (type == END) {
	    if (state != IN_MIB) {
		print_error("Error, end before start of MIB.", (char *) NULL, type);
		return NULL;
	    }
	    state = BETWEEN_MIBS;
	    continue;
	} else if (type != LABEL) {
	    if (type == ENDOFFILE) {
		return root;
	    }
	    print_error(token, "is a reserved word", type);
	    return NULL;
	}
	strncpy(name, token, MAXTOKEN);
	type = get_token(fp, token);
	if (type == DEFINITIONS) {
	    if (state != BETWEEN_MIBS) {
		print_error("Error, nested MIBS.", (char *) NULL, type);
		return NULL;
	    }
	    state = IN_MIB;
	    if (!parse_mib_header(fp, name)) {
		print_error("Bad parse of module header", (char *) NULL, type);
		return NULL;
	    }
	} else if (type == OBJTYPE) {
	    if (root == NULL) {
		/* first link in chain */
		np = root = parse_objecttype(fp, name);
		if (np == NULL) {
		    print_error("Bad parse of object type", (char *) NULL,
			type);
		    return NULL;
		}
	    } else {
		np->next = parse_objecttype(fp, name);
		if (np->next == NULL) {
		    print_error("Bad parse of objecttype", (char *) NULL,
			type);
		    return NULL;
		}
	    }
	    /* now find end of chain */
	    while (np->next)
		np = np->next;
	} else if (type == OBJGROUP) {
	    if (root == NULL) {
		/* first link in chain */
		np = root = parse_objectgroup(fp, name);
		if (np == NULL) {
		    print_error("Bad parse of object group", (char *) NULL,
			type);
		    return NULL;
		}
	    } else {
		np->next = parse_objectgroup(fp, name);
		if (np->next == NULL) {
		    print_error("Bad parse of objectgroup", (char *) NULL,
			type);
		    return NULL;
		}
	    }
	    /* now find end of chain */
	    while (np->next)
		np = np->next;
	} else if (type == NOTIFTYPE) {
	    if (root == NULL) {
		/* first link in chain */
		np = root = parse_notificationDefinition(fp, name);
		if (np == NULL) {
		    print_error("Bad parse of notification definition",
			(char *) NULL, type);
		    return NULL;
		}
	    } else {
		np->next = parse_notificationDefinition(fp, name);
		if (np->next == NULL) {
		    print_error("Bad parse of notification definition",
			(char *) NULL, type);
		    return NULL;
		}
	    }
	    /* now find end of chain */
	    while (np->next)
		np = np->next;
	} else if (type == COMPLIANCE) {
	    if (root == NULL) {
		/* first link in chain */
		np = root = parse_compliance(fp, name);
		if (np == NULL) {
		    print_error("Bad parse of module compliance", (char *) NULL,
			type);
		    return NULL;
		}
	    } else {
		np->next = parse_compliance(fp, name);
		if (np->next == NULL) {
		    print_error("Bad parse of module compliance", (char *) NULL,
			type);
		    return NULL;
		}
	    }
	    /* now find end of chain */
	    while (np->next)
		np = np->next;
	} else if (type == MODULEIDENTITY) {
	    if (root == NULL) {
		/* first link in chain */
		np = root = parse_moduleIdentity(fp, name);
		if (np == NULL) {
		    print_error("Bad parse of module identity", (char *) NULL,
			type);
		    return NULL;
		}
	    } else {
		np->next = parse_moduleIdentity(fp, name);
		if (np->next == NULL) {
		    print_error("Bad parse of module identity", (char *) NULL,
			type);
		    return NULL;
		}
	    }
	    /* now find end of chain */
	    while (np->next)
		np = np->next;
	} else if (type == OBJID) {
	    if (root == NULL) {
		/* first link in chain */
		np = root = parse_objectid(fp, name);
		if (np == NULL) {
		    print_error("Bad parse of object id", (char *) NULL, type);
		    return NULL;
		}
	    } else {
		np->next = parse_objectid(fp, name);
		if (np->next == NULL) {
		    print_error("Bad parse of object type", (char *) NULL,
			type);
		    return NULL;
		}
	    }
	    /* now find end of chain */
	    while (np->next)
		np = np->next;
	} else if (type == EQUALS) {
	    if (!parse_asntype(fp, name, &type, token)) {
		print_error("Bad parse of ASN type definition.", NULL, EQUALS);
		return NULL;
	    }
	    goto skipget;
	} else if (type == ENDOFFILE) {
	    break;
	} else {
	    print_error("Bad operator", (char *) NULL, type);
	    return NULL;
	}
    }
#ifdef TEST
    {
	struct enum_list *ep;

	for (np = root; np; np = np->next) {
	    printf("%s ::= { %s %d } (%d)\n", np->label, np->parent, np->subid,
		np->type);
	    if (np->enums) {
		printf("Enums: \n");
		for (ep = np->enums; ep; ep = ep->next) {
		    printf("%s(%d)\n", ep->label, ep->value);
		}
	    }
	}
    }
#endif /* TEST */
    return root;
}

/*
 * Parses a token from the file.  The type of the token parsed is returned,
 * and the text is placed in the string pointed to by token.
 */
static int
get_token(FILE * fp, char *token)
{
    static char last = ' ';
    int ch;
    char *cp = token;
    int hash = 0;
    struct tok *tp;

    *cp = 0;
    ch = last;
    /* skip all white space */
    while (isspace(ch) && ch != -1) {
	ch = getc(fp);
	if (ch == '\n')
	    Line++;
    }
    if (ch == -1) {
	return ENDOFFILE;
    } else if (ch == '"') {
	return parseQuoteString(fp, token);
    }
    /*
     * Accumulate characters until end of token is found.  Then attempt to
     * match this token as a reserved word.  If a match is found, return the
     * type.  Else it is a label.
     */
    do {
	if (ch == '\n')
	    Line++;
	if (isspace(ch) || ch == '(' || ch == ')' || ch == '{' || ch == '}' ||
	    ch == ',' || ch == ';') {
	    if (!isspace(ch) && *token == 0) {
		hash += ch;
		*cp++ = ch;
		last = ' ';
	    } else {
		last = ch;
	    }
	    *cp = '\0';

	    for (tp = buckets[BUCKET(hash)]; tp; tp = tp->next) {
		if ((tp->hash == hash) && (strcmp(tp->name, token) == 0))
		    break;
	    }
	    if (tp) {
		if (tp->token == CONTINUE)
		    continue;
		return (tp->token);
	    }
	    if (token[0] == '-' && token[1] == '-') {
		/* strip comment */
		if (ch != '\n') {
		    while ((ch = getc(fp)) != -1)
			if (ch == '\n') {
			    Line++;
			    break;
			}
		}
		if (ch == -1)
		    return ENDOFFILE;
		last = ch;
		return get_token(fp, token);
	    }
	    for (cp = token; *cp; cp++)
		if (!isdigit(*cp))
		    return LABEL;
	    return NUMBER;
	} else {
	    hash += ch;
	    *cp++ = ch;
	    if (ch == '\n')
		Line++;
	}

    } while ((ch = getc(fp)) != -1);
    return ENDOFFILE;
}

struct tree *
read_mib(const char *filename)
{
    FILE *fp;
    struct node *nodes;
    struct tree *tree;

    fp = fopen(filename, "r");
    if (fp == NULL)
	return NULL;
    nodes = parse(fp);
    if (!nodes) {
	fprintf(stderr, "Mib table is bad.  Exiting\n");
	exit(1);
    }
    tree = build_tree(nodes);
    fclose(fp);
    return tree;
}


#ifdef TEST
main(int argc, char *argv[])
{
    FILE *fp;
    struct node *nodes;
    struct tree *tp;

    fp = fopen("mib.txt", "r");
    if (fp == NULL) {
	fprintf(stderr, "open failed\n");
	return 1;
    }
    nodes = parse(fp);
    tp = build_tree(nodes);
    print_subtree(tp, 0);
    fclose(fp);
}

#endif /* TEST */

static int
parseQuoteString(FILE * fp, char *token)
{
    int ch;

    ch = ' ';
    *token = '\0';		/* make the token empty */

    while (ch != -1) {
	ch = getc(fp);
	if (ch == '\n')
	    Line++;
	else if (ch == '"') {
	    return QUOTESTRING;
	}
    }

    return 0;
}

/*
 * This routine parses a string like  { blah blah blah } and returns OBJID if
 * it is well formed, and NULL if not.
 */
static int
tossObjectIdentifier(FILE * fp)
{
    int ch;

    ch = getc(fp);
/*    ch = last; = ' '? */
    /* skip all white space */
    while (isspace(ch) && ch != -1) {
	ch = getc(fp);
	if (ch == '\n')
	    Line++;
    }
    if (ch != '{')
	return 0;

    while (ch != -1) {
	ch = getc(fp);

	if (ch == '\n')
	    Line++;
	else if (ch == '}')
	    return OBJID;
    }

/*    last = ch; */
    return 0;
}
