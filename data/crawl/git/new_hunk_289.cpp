		return 0;
	return 1;
}

static int for_each_object_in_pack(struct packed_git *p, each_packed_object_fn cb, void *data)
{
	uint32_t i;
	int r = 0;

	for (i = 0; i < p->num_objects; i++) {
		struct object_id oid;

		if (!nth_packed_object_oid(&oid, p, i))
			return error("unable to get sha1 of object %u in %s",
				     i, p->pack_name);

		r = cb(&oid, p, i, data);
		if (r)
			break;
	}
	return r;
}

int for_each_packed_object(each_packed_object_fn cb, void *data, unsigned flags)
{
	struct packed_git *p;
	int r = 0;
	int pack_errors = 0;

	prepare_packed_git();
	for (p = packed_git; p; p = p->next) {
		if ((flags & FOR_EACH_OBJECT_LOCAL_ONLY) && !p->pack_local)
			continue;
		if (open_pack_index(p)) {
			pack_errors = 1;
			continue;
		}
		r = for_each_object_in_pack(p, cb, data);
		if (r)
			break;
	}
	return r ? r : pack_errors;
}
