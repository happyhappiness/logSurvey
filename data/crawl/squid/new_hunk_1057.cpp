}

void
MemStore::get(String const, STOREGETCLIENT, void *)
{
    // XXX: not needed but Store parent forces us to implement this
    fatal("MemStore::get(key,callback,data) should not be called");
