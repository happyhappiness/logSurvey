}

/* Append incoming data from a primary server to an entry. */
int storeAppend(e, data, len)
     StoreEntry *e;
     char *data;
     int len;
{
    /* validity check -- sometimes it's called with bogus values */
    if (e == NULL || !has_mem_obj(e) || e->mem_obj->data == NULL) {
	debug(20, 0, "storeAppend (len = %d): Invalid StoreEntry, aborting...\n",
	    len);
	if (len < 512)
	    fwrite(data, len, 1, debug_log);
	debug(20, 0, "%s", storeToString(e));
	fatal_dump(NULL);
    }
    if (len) {
	debug(20, 5, "storeAppend: appending %d bytes for '%s'\n", len, e->key);

