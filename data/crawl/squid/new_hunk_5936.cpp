	if (strcmp(r->typestr, settings->type) == 0)
	    return r->create(settings->args);
    }
    debug(20, 1) ("ERROR: Unknown policy %s\n", settings->type);
    debug(20, 1) ("ERROR: Be sure to have set cache_replacement_policy\n");
    debug(20, 1) ("ERROR:   and memory_replacement_policy in squid.conf!\n");
    fatalf("ERROR: Unknown policy %s\n", settings->type);
}

#if 0