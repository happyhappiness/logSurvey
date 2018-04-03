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
		free(op->label);
	    op->label = 0;
	}
	return root;
    } else {
	print_error("Bad object identifier", (char *) NULL, type);
	return 0;
    }
}

static int
get_tc(descriptor, ep)
     char *descriptor;
     struct enum_list **ep;
{
    int i;

    for (i = 0; i < MAXTC; i++) {
	if (tclist[i].type == 0)
	    break;
	if (!strcmp(descriptor, tclist[i].descriptor)) {
	    *ep = tclist[i].enums;
	    return tclist[i].type;
	}
