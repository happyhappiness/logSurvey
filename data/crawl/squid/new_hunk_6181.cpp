	EBIT_TEST(r->cache_control->mask, CC_ONLY_IF_CACHED);
}

StoreEntry *
clientCreateStoreEntry(clientHttpRequest * h, method_t m, request_flags flags)
{
