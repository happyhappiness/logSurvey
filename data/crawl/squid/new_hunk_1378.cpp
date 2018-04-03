
    storeAppendPrintf(entry, "\n");

    storeAppendPrintf(entry, "%s basic credentialsttl %d seconds\n", name, (int) credentialsTTL);
    storeAppendPrintf(entry, "%s basic casesensitive %s\n", name, casesensitive ? "on" : "off");
    Auth::Config::dump(entry, name, scheme);
