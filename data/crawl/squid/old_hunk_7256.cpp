
/* Register interest in an object currently being retrieved. */
int
storeRegister(StoreEntry * e, int fd, PIF * handler, void *data)
{
    int i;
    MemObject *mem = e->mem_obj;
    debug(20, 3, "storeRegister: FD %d '%s'\n", fd, e->key);
    if ((i = storeClientListSearch(mem, fd)) < 0)
	i = storeClientListAdd(e, fd, 0);
    if (mem->clients[i].callback)
	fatal_dump("storeRegister: handler already exists");
