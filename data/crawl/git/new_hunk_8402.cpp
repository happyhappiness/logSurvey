			fprintf(stderr, "\n  from %s\n  to   %s\n",
				old_hex, new_hex);
		}
		if (remote) {
			struct refspec rs;
			rs.src = ref->name;
			remote_find_tracking(remote, &rs);
			if (rs.dst) {
				struct ref_lock *lock;
				fprintf(stderr, " Also local %s\n", rs.dst);
				if (will_delete_ref) {
					if (delete_ref(rs.dst, NULL)) {
						error("Failed to delete");
					}
				} else {
					lock = lock_any_ref_for_update(rs.dst, NULL, 0);
					if (!lock)
						error("Failed to lock");
					else
						write_ref_sha1(lock, ref->new_sha1,
							       "update by push");
				}
				free(rs.dst);
			}
		}
	}

	packet_flush(out);
