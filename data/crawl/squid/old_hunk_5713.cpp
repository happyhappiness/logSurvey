	return S_HELPER_RELEASE;
    }
    if (!reply) {
	fatal("authenticateNTLMHandleReply: called with no result string\n");
    }
    /* seperate out the useful data */
