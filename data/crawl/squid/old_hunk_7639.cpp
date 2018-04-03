    LOCAL_ARRAY(char, abort_msg, 2000);
    MemObject *mem = e->mem_obj;

    if (mem == NULL)		/* XXX remove later */
	fatal_dump("storeAbort: null mem");

