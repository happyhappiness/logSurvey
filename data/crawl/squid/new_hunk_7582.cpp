     char *data;
     int len;
{
    /* sanity check */
    if (e == NULL) {
	debug_trap("storeAppend: NULL entry.");
	return;
    } else if (e->mem_obj == NULL) {
	debug_trap("storeAppend: NULL entry->mem_obj");
	return;
    } else if (e->mem_obj->data == NULL) {
	debug_trap("storeAppend: NULL entry->mem_obj->data");
	return;
    }

    if (len) {
	debug(20, 5, "storeAppend: appending %d bytes for '%s'\n", len, e->key);
