    debugs(29, DBG_IMPORTANT, "Reconfigure: Negotiate authentication configuration cleared.");
}

void
Auth::Negotiate::Config::dump(StoreEntry * entry, const char *name, Auth::Config * scheme)
{
    wordlist *list = authenticateProgram;
    storeAppendPrintf(entry, "%s %s", name, "negotiate");

    while (list != NULL) {
        storeAppendPrintf(entry, " %s", list->key);
        list = list->next;
    }

    storeAppendPrintf(entry, "\n%s %s keep_alive %s\n", name, "negotiate", keep_alive ? "on" : "off");
    Auth::Config::dump(entry, name, scheme);
}

Auth::Negotiate::Config::Config() : keep_alive(1)
