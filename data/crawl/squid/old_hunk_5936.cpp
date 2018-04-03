	if (strcmp(r->typestr, settings->type) == 0)
	    return r->create(settings->args);
    }
    debug(20, 1) ("Unknown policy %s\n", settings->type);
    return NULL;
}

#if 0