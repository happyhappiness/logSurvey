	return size;
}

static int post_rpc(struct rpc_state *rpc)
{
	struct active_request_slot *slot;
	struct slot_results results;
	struct curl_slist *headers = NULL;
	int use_gzip = rpc->gzip_request;
	char *gzip_body = NULL;
	int err = 0, large_request = 0;

	/* Try to load the entire request, if we can fit it into the
	 * allocated buffer space we can use HTTP/1.0 and avoid the
