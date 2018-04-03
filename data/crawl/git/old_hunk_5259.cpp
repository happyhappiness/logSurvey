}

/* Helpers for fetching packs */
static int fetch_pack_index(unsigned char *sha1, const char *base_url)
{
	int ret = 0;
	char *filename;
	char *url = NULL;
	struct strbuf buf = STRBUF_INIT;

	if (has_pack_index(sha1)) {
		ret = 0;
		goto cleanup;
	}

	if (http_is_verbose)
		fprintf(stderr, "Getting index for pack %s\n", sha1_to_hex(sha1));

	end_url_with_slash(&buf, base_url);
	strbuf_addf(&buf, "objects/pack/pack-%s.idx", sha1_to_hex(sha1));
	url = strbuf_detach(&buf, NULL);

	filename = sha1_pack_index_name(sha1);
	if (http_get_file(url, filename, 0) != HTTP_OK)
		ret = error("Unable to get pack index %s\n", url);

cleanup:
	free(url);
	return ret;
}

static int fetch_and_setup_pack_index(struct packed_git **packs_head,
	unsigned char *sha1, const char *base_url)
{
	struct packed_git *new_pack;

	if (fetch_pack_index(sha1, base_url))
		return -1;

	new_pack = parse_pack_index(sha1, sha1_pack_index_name(sha1));
	if (!new_pack)
		return -1; /* parse_pack_index() already issued error message */
	new_pack->next = *packs_head;
	*packs_head = new_pack;
	return 0;
