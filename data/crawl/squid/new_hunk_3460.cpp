        list = list->next;
    }

    storeAppendPrintf(entry, "\n%s ntlm children %d startup=%d idle=%d\n",
                      name, authenticateChildren.n_max, authenticateChildren.n_startup, authenticateChildren.n_idle);
    storeAppendPrintf(entry, "%s %s keep_alive %s\n", name, "ntlm", keep_alive ? "on" : "off");

}

AuthNTLMConfig::AuthNTLMConfig() : authenticateChildren(20,0,1,1), keep_alive(1)
{ }

void
