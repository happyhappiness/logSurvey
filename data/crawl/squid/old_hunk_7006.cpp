    return key_counter;
}

unsigned int
storeReqnum(StoreEntry * entry, method_t method)
{
    unsigned int k;
    if (BIT_TEST(entry->flag, KEY_PRIVATE))
	k = atoi(entry->key);
    else
	k = getKeyCounter();
    if (method == METHOD_GET)
	return k;
    return (method << 24) | k;
}

const char *
storeGeneratePrivateKey(const char *url, method_t method, int num)
{
    if (num == 0)
	num = getKeyCounter();
    else if (num & 0xFF000000) {
	method = (method_t) (num >> 24);
	num &= 0x00FFFFFF;
    }
    debug(20, 3) ("storeGeneratePrivateKey: '%s'\n", url);
    key_temp_buffer[0] = '\0';
    snprintf(key_temp_buffer, MAX_URL + 100, "%d/%s/%s",
	num,
	RequestMethodStr[method],
	url);
    return key_temp_buffer;
}

const char *
storeGeneratePublicKey(const char *url, method_t method)
{
    debug(20, 3) ("storeGeneratePublicKey: type=%d %s\n", method, url);
    switch (method) {
    case METHOD_GET:
	return url;
	/* NOTREACHED */
	break;
    case METHOD_POST:
    case METHOD_PUT:
    case METHOD_HEAD:
    case METHOD_CONNECT:
    case METHOD_TRACE:
	snprintf(key_temp_buffer, MAX_URL + 100, "/%s/%s", RequestMethodStr[method], url);
	return key_temp_buffer;
	/* NOTREACHED */
	break;
    default:
	fatal_dump("storeGeneratePublicKey: Unsupported request method");
	break;
    }
    return NULL;
}

static void
storeSetPrivateKey(StoreEntry * e)
{
    const char *newkey = NULL;
    if (e->key && BIT_TEST(e->flag, KEY_PRIVATE))
	return;			/* is already private */
    newkey = storeGeneratePrivateKey(e->url, e->method, 0);
    assert(hash_lookup(store_table, newkey) == NULL);
    if (e->key)
	storeHashDelete(e);
    if (e->key && !BIT_TEST(e->flag, KEY_URL))
	safe_free(e->key);
    e->key = xstrdup(newkey);
    storeHashInsert(e);
    BIT_CLR(e->flag, KEY_URL);
    BIT_SET(e->flag, KEY_CHANGE);
    BIT_SET(e->flag, KEY_PRIVATE);
}

void
storeSetPublicKey(StoreEntry * e)
{
    StoreEntry *e2 = NULL;
    hash_link *table_entry = NULL;
    const char *newkey = NULL;
    int loop_detect = 0;
    if (e->key && !BIT_TEST(e->flag, KEY_PRIVATE))
	return;			/* is already public */
    newkey = storeGeneratePublicKey(e->url, e->method);
    while ((table_entry = hash_lookup(store_table, newkey))) {
	debug(20, 3) ("storeSetPublicKey: Making old '%s' private.\n", newkey);
	e2 = (StoreEntry *) table_entry;
	storeSetPrivateKey(e2);
	storeRelease(e2);
	assert(++loop_detect < 10);
	newkey = storeGeneratePublicKey(e->url, e->method);
    }
    if (e->key)
	storeHashDelete(e);
    if (e->key && !BIT_TEST(e->flag, KEY_URL))
	safe_free(e->key);
    if (e->method == METHOD_GET) {
	e->key = e->url;
	BIT_SET(e->flag, KEY_URL);
	BIT_CLR(e->flag, KEY_CHANGE);
    } else {
	e->key = xstrdup(newkey);
	BIT_CLR(e->flag, KEY_URL);
	BIT_SET(e->flag, KEY_CHANGE);
    }
    BIT_CLR(e->flag, KEY_PRIVATE);
    storeHashInsert(e);
}

StoreEntry *
