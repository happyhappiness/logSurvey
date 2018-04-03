    debugs(29, DBG_IMPORTANT, "Reconfigure: NTLM authentication configuration cleared.");
}

bool
Auth::Ntlm::Config::dump(StoreEntry * entry, const char *name, Auth::Config * scheme) const
{
    if (!Auth::Config::dump(entry, name, scheme))
        return false;

    storeAppendPrintf(entry, "%s ntlm keep_alive %s\n", name, keep_alive ? "on" : "off");
    return true;
}

Auth::Ntlm::Config::Config() : keep_alive(1)
