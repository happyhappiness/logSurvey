
    assert(!EBIT_TEST(flags, RELEASE_REQUEST));

    adjustVary();
    forcePublicKey(calcPublicKey(scope));
}

void
StoreEntry::clearPublicKeyScope()
{
    if (!key || EBIT_TEST(flags, KEY_PRIVATE))
        return; // probably the old public key was deleted or made private

    // TODO: adjustVary() when collapsed revalidation supports that

    const cache_key *newKey = calcPublicKey(ksDefault);
    if (!storeKeyHashCmp(key, newKey))
        return; // probably another collapsed revalidation beat us to this change

    forcePublicKey(newKey);
}

/// Unconditionally sets public key for this store entry.
/// Releases the old entry with the same public key (if any).
void
StoreEntry::forcePublicKey(const cache_key *newkey)
{
    if (StoreEntry *e2 = (StoreEntry *)hash_lookup(store_table, newkey)) {
        assert(e2 != this);
        debugs(20, 3, "Making old " << *e2 << " private.");
        e2->setPrivateKey();
        e2->release();
    }

    if (key)
