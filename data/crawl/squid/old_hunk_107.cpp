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
{ }

void
Auth::Negotiate::Config::parse(Auth::Config * scheme, int n_configured, char *param_str)
{
    if (strcmp(param_str, "program") == 0) {
        if (authenticateProgram)
            wordlistDestroy(&authenticateProgram);

        parse_wordlist(&authenticateProgram);

        requirePathnameExists("auth_param negotiate program", authenticateProgram->key);
    } else if (strcmp(param_str, "keep_alive") == 0) {
        parse_onoff(&keep_alive);
    } else
        Auth::Config::parse(scheme, n_configured, param_str);
}

const char *
Auth::Negotiate::Config::type() const
{
