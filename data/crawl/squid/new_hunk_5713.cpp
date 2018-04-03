	return S_HELPER_RELEASE;
    }
    if (!reply) {
        /* TODO: this occurs when a helper crashes. We should clean up that helpers resources
	 * and queued requests.
	 */
	fatal("authenticateNTLMHandleReply: called with no result string\n");
    }
    /* seperate out the useful data */
