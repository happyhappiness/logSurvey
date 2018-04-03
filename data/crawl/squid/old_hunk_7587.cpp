 * Fetch aborted.  Tell all clients to go home.  Negatively cache
 * abort message, freeing the data for this object 
 */
int storeAbort(e, msg)
     StoreEntry *e;
     char *msg;
{
    LOCAL_ARRAY(char, mime_hdr, 300);
    LOCAL_ARRAY(char, abort_msg, 2000);
    MemObject *mem = e->mem_obj;

    if (e->store_status != STORE_PENDING)	/* XXX remove later */
	fatal_dump("storeAbort: bad store_status");
    if (mem == NULL)		/* XXX remove later */
	fatal_dump("storeAbort: null mem");

    debug(20, 6, "storeAbort: '%s'\n", e->key);
    storeNegativeCache(e);
