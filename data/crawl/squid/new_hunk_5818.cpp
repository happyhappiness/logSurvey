    return walker;
}

static void
lru_stats(RemovalPolicy * policy, StoreEntry * sentry)
{
    LruPolicyData *lru = policy->_data;
    LruNode *lru_node = (LruNode *)lru->list.head;

again:
    if (lru_node) {
	StoreEntry * entry = (StoreEntry *) lru_node->node.data;
	if (storeEntryLocked(entry)) {
	    lru_node = (LruNode *)lru_node->node.next;
	    goto again;
	}
	storeAppendPrintf(sentry, "LRU reference age: %.2f days\n", (double) (squid_curtime - entry->lastref) / (double) (24 * 60 * 60));
    }
}

static void
lru_free(RemovalPolicy * policy)
{
