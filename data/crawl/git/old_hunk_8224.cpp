		if (remote) {
			struct refspec rs;
			rs.src = ref->name;
			remote_find_tracking(remote, &rs);
			if (rs.dst) {
				struct ref_lock *lock;
				fprintf(stderr, " Also local %s\n", rs.dst);
				if (will_delete_ref) {