    return e;
}

void
Transients::get(String const, STOREGETCLIENT, void *)
{
    // XXX: not needed but Store parent forces us to implement this
    fatal("Transients::get(key,callback,data) should not be called");
}

StoreEntry *
Transients::findCollapsed(const sfileno index)
{
