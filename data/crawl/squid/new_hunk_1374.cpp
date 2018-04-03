    debugs(29, DBG_IMPORTANT, "Reconfigure: Negotiate authentication configuration cleared.");
}

bool
Auth::Negotiate::Config::dump(StoreEntry * entry, const char *name, Auth::Config * scheme) const
{
    if (!Auth::Config::dump(entry, name, scheme))
        return false;

    storeAppendPrintf(entry, "%s negotiate keep_alive %s\n", name, keep_alive ? "on" : "off");
    return true;
}

Auth::Negotiate::Config::Config() : keep_alive(1)
