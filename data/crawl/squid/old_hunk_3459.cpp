        list = list->next;
    }

    storeAppendPrintf(entry, "\n%s negotiate children %d\n",
                      name, authenticateChildren);
    storeAppendPrintf(entry, "%s %s keep_alive %s\n", name, "negotiate", keep_alive ? "on" : "off");

}

AuthNegotiateConfig::AuthNegotiateConfig() : authenticateChildren(5), keep_alive(1)
{ }

void
