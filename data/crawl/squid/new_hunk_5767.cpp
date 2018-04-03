	authenticateStateFree(r);
	debug(29, 9) ("NTLM HandleReply, telling stateful helper : %d\n", S_HELPER_RELEASE);
	return S_HELPER_RELEASE;
    }
    if (!reply) {
	fatal("authenticateNTLMHandleReply: called with no result string\n");
    }
    /* seperate out the useful data */
    if (strncasecmp(reply, "TT ", 3) == 0) {
	reply += 3;
