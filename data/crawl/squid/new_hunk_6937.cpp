		np->type = 0;
		np->enums = 0;
		/* set up next entry */
		np->next = (struct node *) Malloc(sizeof(*np->next));
		bzero((char *) np->next, sizeof(struct node));
		oldnp = np;
		np = np->next;
	    }
	}
	np->next = (struct node *) NULL;
	/*
	 * The above loop took care of all but the last pair.  This pair is taken
	 * care of here.  The name for this node is taken from the label for this
	 * entry.
	 * np still points to an unused entry.
	 */
	if (count == (length - 2)) {
	    if (op->label) {
		strcpy(np->parent, op->label);
		strcpy(np->label, name);
		if (nop->subid != -1)
		    np->subid = nop->subid;
		else
		    print_error("Warning: This entry is pretty silly",
			np->label, type);
	    } else {
		free_node(np);
		if (oldnp)
