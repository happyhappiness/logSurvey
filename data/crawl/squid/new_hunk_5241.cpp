        list = list->next;
    }

    storeAppendPrintf(entry, "\n");

    storeAppendPrintf(entry, "%s basic realm %s\n", name, config->basicAuthRealm);
    storeAppendPrintf(entry, "%s basic children %d\n", name, config->authenticateChildren);
    storeAppendPrintf(entry, "%s basic concurrency %d\n", name, config->authenticateConcurrency);
    storeAppendPrintf(entry, "%s basic credentialsttl %d seconds\n", name, (int) config->credentialsTTL);

}

