        list = list->next;
    }

    storeAppendPrintf(entry, "\n%s ntlm children %d\n",
                      name, authenticateChildren);
    storeAppendPrintf(entry, "%s %s keep_alive %s\n", name, "ntlm", keep_alive ? "on" : "off");

}

AuthNTLMConfig::AuthNTLMConfig() : authenticateChildren(5), keep_alive(1)
{ }

void
AuthNTLMConfig::parse(AuthConfig * scheme, int n_configured, char *param_str)
