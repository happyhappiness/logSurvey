    }

    if (!reply) {
        /*
         * TODO: this occurs when a helper crashes. We should clean
         * up that helpers resources and queued requests.
         */
        fatal("authenticateNTLMHandleReply: called with no result string\n");
    }

    auth_user_request = r->auth_user_request;
