    }
}

static void
dump_regexlist(StoreEntry * entry, const char *name, relist * var)
{
    storeAppendPrintf(entry, "%s", name);
    while (var != NULL) {
	storeAppendPrintf(entry, " %s", var->pattern);
	var = var->next;
    }
    storeAppendPrintf(entry, "\n");
}

static void
parse_regexlist(relist ** var)
{
    aclParseRegexList(var);
}

static void
free_regexlist(relist ** var)
{
    aclDestroyRegexList(*var);
    *var = NULL;
}

static void
dump_string(StoreEntry * entry, const char *name, char *var)
{
