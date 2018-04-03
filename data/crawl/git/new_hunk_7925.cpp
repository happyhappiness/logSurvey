	return ret;
}

static void update_tracking_ref(struct remote *remote, struct ref *ref)
{
	struct refspec rs;
	int will_delete_ref;

	rs.src = ref->name;
	rs.dst = NULL;

	if (!ref->peer_ref)
		return;

	will_delete_ref = is_null_sha1(ref->peer_ref->new_sha1);

	if (!will_delete_ref &&
			!hashcmp(ref->old_sha1, ref->peer_ref->new_sha1))
		return;

	if (!remote_find_tracking(remote, &rs)) {
		fprintf(stderr, "updating local tracking ref '%s'\n", rs.dst);
		if (is_null_sha1(ref->peer_ref->new_sha1)) {
			if (delete_ref(rs.dst, NULL))
				error("Failed to delete");
		} else
			update_ref("update by push", rs.dst,
					ref->new_sha1, NULL, 0, 0);
		free(rs.dst);
	}
}

static int send_pack(int in, int out, struct remote *remote, int nr_refspec, char **refspec)
{
	struct ref *ref;
