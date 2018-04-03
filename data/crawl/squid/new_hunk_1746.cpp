void
dump_acl_list(StoreEntry * entry, ACLList * head)
{
    wordlist *values = head->dump();
    dump_wordlist(entry, values);
    wordlistDestroy(&values);
}

void
dump_acl_access(StoreEntry * entry, const char *name, acl_access * head)
{
    wordlist *lines = head->treeDump(name, NULL);
    dump_wordlist(entry, lines);
    wordlistDestroy(&lines);
}

static void
parse_acl_access(acl_access ** head)
{
    aclParseAccessLine(cfg_directive, LegacyParser, head);
}

static void
parse_acl_access(const char *directive, acl_access ** head)
{
    aclParseAccessLine(directive, LegacyParser, head);
}

static void
