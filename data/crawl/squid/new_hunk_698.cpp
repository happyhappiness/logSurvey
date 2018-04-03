        if (node->quote == external_acl::QUOTE_METHOD_SHELL)
            storeAppendPrintf(sentry, " protocol=2.5");

        node->format.dump(sentry, NULL, false);

        for (word = node->cmdline; word; word = word->next)
            storeAppendPrintf(sentry, " %s", word->key);
