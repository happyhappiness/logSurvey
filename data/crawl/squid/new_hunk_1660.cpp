    storeAppendPrintf(entry, "\n%s ntlm children %d startup=%d idle=%d concurrency=%d\n",
                      name, authenticateChildren.n_max, authenticateChildren.n_startup, authenticateChildren.n_idle, authenticateChildren.concurrency);
    storeAppendPrintf(entry, "%s %s keep_alive %s\n", name, "ntlm", keep_alive ? "on" : "off");
    Auth::Config::dump(entry, name, scheme);
}

Auth::Ntlm::Config::Config() : keep_alive(1)
