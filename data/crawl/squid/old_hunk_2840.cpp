}

StoreEntry *

StoreController::get
(const cache_key *key)
{

    return swapDir->get
           (key);
}

void

StoreController::get
(String const key, STOREGETCLIENT aCallback, void *aCallbackData)
{
    fatal("not implemented");
}
