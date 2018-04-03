     char *data;
     int len;
{
    /* validity check -- sometimes it's called with bogus values */
    if (e == NULL)
	fatal_dump("storeAppend: NULL entry.");
    if (e->mem_obj == NULL)
	fatal_dump("storeAppend: NULL entry->mem_obj");
    if (e->mem_obj->data == NULL)
	fatal_dump("storeAppend: NULL entry->mem_obj->data");

    if (len) {
	debug(20, 5, "storeAppend: appending %d bytes for '%s'\n", len, e->key);
