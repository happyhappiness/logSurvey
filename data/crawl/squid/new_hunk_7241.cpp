static int
storeCopy(const StoreEntry * e, int stateoffset, int maxSize, char *buf, int *size)
{
    MemObject *mem = e->mem_obj;
    size_t s;
    assert(stateoffset >= mem->e_lowest_offset);
    s = memCopy(mem->data, stateoffset, buf, maxSize);
    return *size = s;
}

