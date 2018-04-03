int
storeRegister(StoreEntry * e, int fd, PIF handler, void *data)
{
    int i;
    MemObject *mem = e->mem_obj;
    debug(20, 3, "storeRegister: FD %d '%s'\n", fd, e->key);
    if ((i = storeClientListSearch(mem, fd)) < 0)
	i = storeClientListAdd(e, fd, 0);
    if (mem->clients[i].callback)
	fatal_dump("storeRegister: handler already exists");
    mem->clients[i].callback = handler;
    mem->clients[i].callback_data = data;
    return 0;
}

int
storeUnregister(StoreEntry * e, int fd)
{
    int i;
    MemObject *mem = e->mem_obj;
    if (mem == NULL)
	return 0;
    debug(20, 3, "storeUnregister: called for FD %d '%s'\n", fd, e->key);
    if ((i = storeClientListSearch(mem, fd)) < 0)
	return 0;
    mem->clients[i].fd = -1;
    mem->clients[i].last_offset = 0;
    mem->clients[i].callback = NULL;
    mem->clients[i].callback_data = NULL;
    if (mem->fd_of_first_client == fd)
	mem->fd_of_first_client = -1;
    debug(20, 9, "storeUnregister: returning 1\n");
    return 1;
}

int
