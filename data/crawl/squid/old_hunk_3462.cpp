        if (node->grace)
            storeAppendPrintf(sentry, " grace=%d", node->grace);

        if (node->children != DEFAULT_EXTERNAL_ACL_CHILDREN)
            storeAppendPrintf(sentry, " children=%d", node->children);

        if (node->concurrency)
            storeAppendPrintf(sentry, " concurrency=%d", node->concurrency);

        if (node->cache)
            storeAppendPrintf(sentry, " cache=%d", node->cache_size);
