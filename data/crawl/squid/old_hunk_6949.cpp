	else
	    print_error("Warning: This entry is pretty silly", np->label, type);
    } else {
	print_error("No end to oid", (char *)NULL, type);
	free_node(np);
	np = 0;
    }
    /* free oid array */
    for(count = 0; count < length; count++){
	if (oid[count].label)
	    free(oid[count].label);
	oid[count].label = 0;
