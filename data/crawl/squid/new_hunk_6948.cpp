 */
static struct node *
parse_notificationDefinition(fp, name)
     FILE *fp;
     char *name;
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
	    quoted_string_buffer = (char *) calloc(1, MAXQUOTESTR);
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
