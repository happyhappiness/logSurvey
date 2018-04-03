}

static void
print_error(char *string, char *token, int type)
{
    if (type == ENDOFFILE)
	fprintf(stderr, "%s(EOF): On or around line %d\n", string, Line);
