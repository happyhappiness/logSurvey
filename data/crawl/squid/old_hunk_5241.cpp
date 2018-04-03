        list = list->next;
    }

    storeAppendPrintf(entry, "\n%s %s realm %s\n%s %s children %d\n%s %s credentialsttl %d seconds\n",
                      name, "basic", config->basicAuthRealm,
                      name, "basic", config->authenticateChildren,
                      name, "basic", (int) config->credentialsTTL);

}

