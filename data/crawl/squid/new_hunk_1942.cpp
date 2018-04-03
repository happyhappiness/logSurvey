        if (node->cache)
            storeAppendPrintf(sentry, " cache=%d", node->cache_size);

        if (node->quote == external_acl::QUOTE_METHOD_SHELL)
            storeAppendPrintf(sentry, " protocol=2.5");

        for (format = node->format; format; format = format->next) {
            switch (format->type) {

