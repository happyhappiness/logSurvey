    wordlist *list = config->authenticate;
    debug(29, 9) ("authDigestCfgDump: Dumping configuration\n");
    storeAppendPrintf(entry, "%s %s", name, "digest");
    while (list != NULL) {
	storeAppendPrintf(entry, " %s", list->key);
	list = list->next;
    }
    storeAppendPrintf(entry, "\n%s %s realm %s\n%s %s children %d\n%s %s nonce_max_count %d\n%s %s nonce_max_duration %d seconds\n%s %s nonce_garbage_interval %d seconds\n",
	name, "digest", config->digestAuthRealm,
	name, "digest", config->authenticateChildren,
	name, "digest", config->noncemaxuses,
	name, "digest", (int) config->noncemaxduration,
	name, "digest", (int) config->nonceGCInterval);
}

void
