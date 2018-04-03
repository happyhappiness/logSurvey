dump_refreshpattern(StoreEntry * entry, const char *name, refresh_t * head)
{
    while (head != NULL) {
	storeAppendPrintf(entry, "%s%s %s %d %d%% %d%s%s\n",
	    name,
	    head->flags.icase ? " -i" : null_string,
	    head->pattern,
	    (int) head->min / 60,
	    (int) (100.0 * head->pct + 0.5),
	    (int) head->max / 60,
	    head->flags.override_expire ? " override_expire" : null_string,
	    head->flags.override_lastmod ? " override_lastmod" : null_string);
	head = head->next;
    }
}
