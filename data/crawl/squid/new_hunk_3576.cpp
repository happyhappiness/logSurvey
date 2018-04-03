    cbdataFree(gopherState);
}

/**
 \ingroup ServerProtocolGopherInternal
 * Create MIME Header for Gopher Data
 */
static void
gopherMimeCreate(GopherStateData * gopherState)
{
    StoreEntry *entry = gopherState->entry;
    const char *mime_type = NULL;
    const char *mime_enc = NULL;

    switch (gopherState->type_id) {

