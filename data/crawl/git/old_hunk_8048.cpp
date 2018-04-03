		i = posn + 1;
	}

	got_alternates = 1;
}

static void fetch_alternates(const char *base)
{
	struct buffer buffer;
	char *url;
	char *data;
	struct active_request_slot *slot;
	struct alternates_request alt_req;

	/* If another request has already started fetching alternates,
	   wait for them to arrive and return to processing this request's
	   curl message */
#ifdef USE_CURL_MULTI
	while (got_alternates == 0) {
		step_active_slots();
	}
#endif

	/* Nothing to do if they've already been fetched */
	if (got_alternates == 1)
		return;

	/* Start the fetch */
	got_alternates = 0;

	data = xmalloc(4096);
	buffer.size = 4096;
	buffer.posn = 0;
	buffer.buffer = data;

	if (get_verbosely)
		fprintf(stderr, "Getting alternates list for %s\n", base);

	url = xmalloc(strlen(base) + 31);
