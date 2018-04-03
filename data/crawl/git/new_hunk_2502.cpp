
	target = find_sha1_pack(get_object_hash(*request->obj), repo->packs);
	if (!target) {
		fprintf(stderr, "Unable to fetch %s, will not be able to update server info refs\n", oid_to_hex(&request->obj->oid));
		repo->can_update_info_refs = 0;
		release_request(request);
		return;
	}

	fprintf(stderr,	"Fetching pack %s\n", sha1_to_hex(target->sha1));
	fprintf(stderr, " which contains %s\n", oid_to_hex(&request->obj->oid));

	preq = new_http_pack_request(target, repo->url);
	if (preq == NULL) {
