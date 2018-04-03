    }
    return root;
}
#endif

int
read_objid(input, output, out_len)
     char *input;
     oid *output;
     int *out_len;		/* number of subid's in "output" */
{
    struct tree *root = Mib;
    oid *op = output;
    char buf[512];

    memset(buf, '\0', sizeof(buf));

    if (*input == '.')
	input++;
    else {
	strcpy(buf, Prefix);
	strcat(buf, input);
	input = buf;
    }

    if (root == NULL) {
	fprintf(stderr, "Mib not initialized.  Exiting.\n");
	exit(1);
    }
    if ((*out_len =
	    parse_subtree(root, input, output, out_len)) == 0)
	return (0);
    *out_len += output - op;

    return (1);
}

#ifdef notdef
int
read_objid(input, output, out_len)
     char *input;
     oid *output;
     int *out_len;		/* number of subid's in "output" */
{
    struct tree *root = Mib;
    oid *op = output;
    int i;

    if (*input == '.')
	input++;
    else {
	root = find_rfc1213_mib(root);
	for (i = 0; i < sizeof(RFC1213_MIB) / sizeof(oid); i++) {
	    if ((*out_len)-- > 0)
		*output++ = RFC1213_MIB[i];
	    else {
		fprintf(stderr, "object identifier too long\n");
		return (0);
	    }
	}
    }

    if (root == NULL) {
	fprintf(stderr, "Mib not initialized.  Exiting.\n");
	exit(1);
    }
    if ((*out_len =
	    parse_subtree(root, input, output, out_len)) == 0)
	return (0);
    *out_len += output - op;

    return (1);
}
#endif

static int
parse_subtree(subtree, input, output, out_len)
     struct tree *subtree;
     char *input;
     oid *output;
     int *out_len;		/* number of subid's */
{
    char buf[128], *to = buf;
    u_long subid = 0;
    struct tree *tp;

    /*
     * No empty strings.  Can happen if there is a trailing '.' or two '.'s
