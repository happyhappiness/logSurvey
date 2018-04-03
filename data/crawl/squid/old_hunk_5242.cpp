        if (node->children != DEFAULT_EXTERNAL_ACL_CHILDREN)
            storeAppendPrintf(sentry, " children=%d", node->children);

        for (format = node->format; format; format = format->next) {
            switch (format->type) {

