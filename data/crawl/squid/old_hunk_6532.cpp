	strcmp(hier, "PASSTHROUGH_PARENT") &&
	strcmp(hier, "SSL_PARENT_MISS") &&
	strcmp(hier, "DEFAULT_PARENT");
    if (!entry->use_icp)
	return frMore;
    memcpy(entry->key, storeKeyPublic(url, method_id), sizeof(entry->key));
    /*fprintf(stdout, "%s:%d: %s %s %s %s\n",
	fname, count, method, storeKeyText(entry->key), url, hier); */
