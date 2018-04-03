    m->e_current_len = 0;
}

/* Check if there is memory allocated for object in memory */
int has_mem_obj(e)
     StoreEntry *e;
{
    if (!e)
	fatal_dump("has_mem_obj: NULL Entry");
    if (e->mem_obj)
	return 1;
    return 0;
}

/* ----- INTERFACE BETWEEN STORAGE MANAGER AND HASH TABLE FUNCTIONS --------- */

/*
