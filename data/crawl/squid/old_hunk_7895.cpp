    return NULL;
}

char *storeGenerateKey(url, request_type_id)
     char *url;
     int request_type_id;
{
    debug(20, 5, "storeGenerateKey: type=%d %s\n", request_type_id, url);
    switch (request_type_id) {
    case REQUEST_OP_GET:
	return url;
	break;
    case REQUEST_OP_POST:
	sprintf(key_temp_buffer, "/post/%s", url);
	return key_temp_buffer;
	break;
    case REQUEST_OP_HEAD:
	sprintf(key_temp_buffer, "/head/%s", url);
	return key_temp_buffer;
	break;
    default:
	fatal_dump("storeGenerateKey: Unsupported request_type_id\n");
	break;
    }
    return NULL;
}

StoreEntry *storeCreateEntry(url, req_hdr, cachable, html_req, method)
     char *url;
     char *req_hdr;
     int cachable;
     int html_req;
     int method;
{
    StoreEntry *e = NULL;
    MemObject *m = NULL;
    debug(20, 5, "storeCreateEntry: '%s'\n", url);
    debug(20, 5, "storeCreateEntry: cachable=%d\n", cachable);

    if (meta_data.hot_vm > store_hotobj_high)
	storeGetMemSpace(0, 1);
    e = new_StoreEntry(WITH_MEMOBJ);
    m = e->mem_obj;
    e->url = xstrdup(url);
    meta_data.url_strings += strlen(url);
    e->type_id = method;
    if (req_hdr) {
	m->mime_hdr = xstrdup(req_hdr);
	if (mime_refresh_request(req_hdr))
	    BIT_SET(e->flag, REFRESH_REQUEST);
    }
    if (cachable)
	BIT_SET(e->flag, CACHABLE);
    else
	BIT_SET(e->flag, RELEASE_REQUEST);

    if (html_req)
	BIT_SET(e->flag, REQ_HTML);

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

static void storeSetKey(e)
     StoreEntry *e;
{
    debug(20, 3, "storeSetKey: '%s'\n", e->url);
    if (e->type_id == REQUEST_OP_GET) {
	e->key = e->url;
	BIT_SET(e->flag, KEY_URL);
	return;
    }
    e->key = xstrdup(storeGenerateKey(e->url, e->type_id));
    BIT_RESET(e->flag, KEY_URL);
}

void storeAddEntry(e)
     StoreEntry *e;
{
    debug(20, 3, "storeAddEntry: '%s'\n", e->url);
    if (!BIT_TEST(e->flag, CACHABLE)) {
	debug(20, 0, "storeAddEntry: Called for UN-CACHABLE '%s'\n",
	    e->url);
	return;
    }
    storeSetKey(e);
    storeHashInsert(e);
}


#ifdef OLD_CODE
/*
 * Add a new object to the cache.
 * 
 * storeAdd() is only called by icpProcessMISS()
 */
StoreEntry *storeAdd(url, type_notused, mime_hdr, cachable, html_request, request_type_id)
     char *url;
     char *type_notused;
     char *mime_hdr;
     int cachable;
     int html_request;
     int request_type_id;
{
    static char key[MAX_URL + 16];
    StoreEntry *e = NULL;

    debug(20, 5, "storeAdd: %s\n", url);

    meta_data.store_entries++;
    meta_data.url_strings += strlen(url);

    if (meta_data.hot_vm > store_hotobj_high)
	storeGetMemSpace(0, 1);
    e = create_StoreEntry();
    e->url = xstrdup(url);
    e->key = NULL;
    e->flag = 0;
    e->type_id = request_type_id;
    if (mime_hdr) {
	e->mem_obj->mime_hdr = xstrdup(mime_hdr);
	if (mime_refresh_request(mime_hdr))
	    BIT_SET(e->flag, REFRESH_REQUEST);
	else
	    BIT_RESET(e->flag, REFRESH_REQUEST);
    }
    if (cachable) {
	BIT_SET(e->flag, CACHABLE);
	BIT_RESET(e->flag, RELEASE_REQUEST);
    } else {
	BIT_RESET(e->flag, CACHABLE);
	BIT_SET(e->flag, RELEASE_REQUEST);
	/*after a lock is release, it will be released by storeUnlock */
    }

    if (html_request)
	BIT_SET(e->flag, REQ_HTML);
    else
	BIT_RESET(e->flag, REQ_HTML);

    e->status = STORE_PENDING;
    storeSetMemStatus(e, NOT_IN_MEMORY);
    e->swap_status = NO_SWAP;
    e->swap_file_number = -1;
    e->lock_count = 0;
    BIT_RESET(e->flag, KEY_CHANGE);
    BIT_RESET(e->flag, CLIENT_ABORT_REQUEST);
    e->mem_obj->data = memInit();
    meta_data.hot_vm++;
    e->refcount = 0;
    e->lastref = cached_curtime;
    e->timestamp = 0;		/* set in storeSwapOutHandle() */
    e->ping_status = NOPING;

    if (e->flag & CACHABLE) {
	if (request_type_id == REQUEST_OP_GET) {
	    e->key = e->url;
	    BIT_SET(e->flag, KEY_URL);
	} else {
	    e->key = xstrdup(storeGenerateKey(e->url, request_type_id));
	    BIT_RESET(e->flag, KEY_URL);
	}
    } else {
	/* prepend a uncache count number to url for a key */
	key[0] = '\0';
	sprintf(key, "/%d/%s", uncache_count, url);
	uncache_count++;
	e->key = xstrdup(key);
	BIT_RESET(e->flag, KEY_URL);
    }

    /* allocate pending list */
    e->mem_obj->pending_list_size = MIN_PENDING;
    e->mem_obj->pending = (struct pentry **)
	xcalloc(e->mem_obj->pending_list_size, sizeof(struct pentry *));

    /* allocate client list */
    e->mem_obj->client_list_size = MIN_CLIENT;
    e->mem_obj->client_list = (ClientStatusEntry **)
	xcalloc(e->mem_obj->client_list_size, sizeof(ClientStatusEntry *));

    storeHashInsert(e);

    /* Change the key to something private until we know it is safe
     * to share */
    if (!strncmp(url, "http", 4))
	storeChangeKey(e);

    return e;
}
#endif

/* Add a new object to the cache with empty memory copy and pointer to disk
 * use to rebuild store from disk. */
