    (*L)->data = xstrdup(str);
}

static void
checkDepend(const char *directive, const char *name, const Type *types, const Entry *entries)
{
    const Type *type;
    for (type = types; type; type = type->next) {
	const TypeDep *dep;
	if (strcmp(type->name, name) != 0)
	    continue;
	for (dep = type->depend; dep; dep = dep->next) {
	    const Entry *entry;
	    for (entry = entries; entry; entry = entry->next) {
		if (strcmp(entry->name, dep->name) == 0)
		    break;
	    }
	    if (!entry) {
		fprintf(stderr, "ERROR: '%s' (%s) depends on '%s'\n", directive, name, dep->name);
		exit(1);
	    }
	}
	return;
    }
    fprintf(stderr, "ERROR: Dependencies for cf.data type '%s' used in '%s' not defined\n", name, directive);
    exit(1);
}

int
main(int argc, char *argv[])
{
    FILE *fp;
    char *input_filename = argv[1];
    const char *output_filename = _PATH_PARSER;
    const char *conf_filename = _PATH_SQUID_CONF;
    const char *type_depend = argv[2];
    int linenum = 0;
    Entry *entries = NULL;
    Entry *curr = NULL;
    Type *types = NULL;
    enum State state;
    int rc = 0;
    char *ptr = NULL;
