    return NULL;
}

char *storeGeneratePrivateKey(url, type_id, num)
     char *url;
     int type_id;
     int num;
{
    if (key_counter == 0)
	key_counter++;
    if (num == 0)
	num = key_counter++;
    debug(20, 3, "storeGeneratePrivateKey: '%s'\n", url);
    key_temp_buffer[0] = '\0';
    sprintf(key_temp_buffer, "%d/%s/%s",
	num,
	RequestMethodStr[type_id],
	url);
    return key_temp_buffer;
}

char *storeGeneratePublicKey(url, request_type_id)
     char *url;
     int request_type_id;
{
    debug(20, 5, "storeGeneratePublicKey: type=%d %s\n", request_type_id, url);
    switch (request_type_id) {
    case METHOD_GET:
	return url;
	break;
    case METHOD_POST:
	sprintf(key_temp_buffer, "/post/%s", url);
	return key_temp_buffer;
	break;
    case METHOD_HEAD:
	sprintf(key_temp_buffer, "/head/%s", url);
	return key_temp_buffer;
	break;
    default:
	fatal_dump("storeGeneratePublicKey: Unsupported request method");
	break;
    }
    return NULL;
}

void storeSetPrivateKey(e)
     StoreEntry *e;
{
    StoreEntry *e2 = NULL;
    hash_link *table_entry = NULL;

    if (e->key && BIT_TEST(e->flag, KEY_PRIVATE))
	return;			/* is already private */

    if (e->key) {
	if ((table_entry = hash_lookup(table, e->key)))
	    e2 = (StoreEntry *) table_entry;
	if (e2 != e) {
	    debug(20, 0, "storeSetPrivateKey: non-unique key: '%s'\n", e->key);
	    return;
	}
	storeHashDelete(table_entry);
	if (!BIT_TEST(e->flag, KEY_URL))
	    safe_free(e->key);
    }
    e->key = xstrdup(storeGeneratePrivateKey(e->url, e->type_id, 0));
    storeHashInsert(e);
    BIT_RESET(e->flag, KEY_URL);
    BIT_SET(e->flag, KEY_CHANGE);
    BIT_SET(e->flag, KEY_PRIVATE);
}

void storeSetPublicKey(e)
     StoreEntry *e;
{
    StoreEntry *e2 = NULL;
    hash_link *table_entry = NULL;

    if (e->key && !BIT_TEST(e->flag, KEY_PRIVATE))
	return;			/* is already public */

    if (e->key) {
	if ((table_entry = hash_lookup(table, e->key)))
	    e2 = (StoreEntry *) table_entry;
	if (e2 != e) {
	    debug(20, 0, "storeSetPublicKey: non-unique key: '%s'\n", e->key);
	    return;
	}
	storeHashDelete(table_entry);
	if (!BIT_TEST(e->flag, KEY_URL))
	    safe_free(e->key);
    }
    if (e->type_id == METHOD_GET) {
	e->key = e->url;
	BIT_SET(e->flag, KEY_URL);
	BIT_RESET(e->flag, KEY_CHANGE);
    } else {
	e->key = xstrdup(storeGeneratePublicKey(e->url, e->type_id));
	BIT_RESET(e->flag, KEY_URL);
	BIT_SET(e->flag, KEY_CHANGE);
    }
    storeHashInsert(e);
}

StoreEntry *storeCreateEntry(url, req_hdr, flags, method)
     char *url;
     char *req_hdr;
     int flags;
     int method;
{
    StoreEntry *e = NULL;
    MemObject *m = NULL;
    debug(20, 5, "storeCreateEntry: '%s'\n", url);
    debug(20, 5, "storeCreateEntry: public=%d\n",
	BIT_TEST(flags, REQ_PUBLIC) ? 1 : 0);

    if (meta_data.hot_vm > store_hotobj_high)
	storeGetMemSpace(0, 1);
    e = new_StoreEntry(WITH_MEMOBJ);
    m = e->mem_obj;
    e->url = xstrdup(url);
    meta_data.url_strings += strlen(url);
    e->type_id = method;
    if (req_hdr)
	m->mime_hdr = xstrdup(req_hdr);
    if (BIT_TEST(flags, REQ_NOCACHE))
	BIT_SET(e->flag, REFRESH_REQUEST);
    if (BIT_TEST(flags, REQ_PUBLIC)) {
	BIT_SET(e->flag, CACHABLE);
	BIT_RESET(e->flag, RELEASE_REQUEST);
	BIT_RESET(e->flag, ENTRY_PRIVATE);
    } else {
	BIT_RESET(e->flag, CACHABLE);
	BIT_SET(e->flag, RELEASE_REQUEST);
	BIT_SET(e->flag, ENTRY_PRIVATE);
    }
    if (neighbors_do_private_keys || !BIT_TEST(flags, REQ_PUBLIC))
	storeSetPrivateKey(e);
    else
	storeSetPublicKey(e);
    if (BIT_TEST(flags, REQ_HTML))
	BIT_SET(e->flag, ENTRY_HTML);

    e->status = STORE_PENDING;
    storeSetMemStatus(e, NOT_IN_MEMORY);
    e->swap_status = NO_SWAP;
    e->swap_file_number = -1;
    e->lock_count = 0;
    m->data = new_MemObjectData();
    e->refcount = 0;
    e->lastref = cached_curtime;
    e->timestamp = 0;		/* set in storeSwapOutHandle() */
    e->ping_status = NOPING;

    /* allocate pending list */
    m->pending_list_size = MIN_PENDING;
    m->pending = (struct pentry **)
	xcalloc(m->pending_list_size, sizeof(struct pentry *));

    /* allocate client list */
    m->client_list_size = MIN_CLIENT;
    m->client_list = (ClientStatusEntry **)
	xcalloc(m->client_list_size, sizeof(ClientStatusEntry *));
    return e;

}

/* Add a new object to the cache with empty memory copy and pointer to disk
 * use to rebuild store from disk. */
