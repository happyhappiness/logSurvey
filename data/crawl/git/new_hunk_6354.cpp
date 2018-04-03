	struct transfer_request *check_request = request_queue_head;
	struct active_request_slot *slot;

	target = find_sha1_pack(request->obj->sha1, repo->packs);
	if (!target) {
		fprintf(stderr, "Unable to fetch %s, will not be able to update server info refs\n", sha1_to_hex(request->obj->sha1));
		repo->can_update_info_refs = 0;
		release_request(request);
		return;
	}
