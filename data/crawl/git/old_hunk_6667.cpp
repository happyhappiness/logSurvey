			warning ("Allowing deletion of corrupt ref.");
			old_sha1 = NULL;
		}
		if (delete_ref(name, old_sha1)) {
			error("failed to delete %s", name);
			return "failed to delete";
		}
