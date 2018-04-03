 * but the parent child relationship isn't implemented yet
 */
StoreEntry *

SwapDir::get
(const cache_key *key)
{
    return Store::Root().get(key);
}

void

SwapDir::get
(String const key, STOREGETCLIENT aCallback, void *aCallbackData)
{
    fatal("not implemented");
}
