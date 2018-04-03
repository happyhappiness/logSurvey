		if (obj) {
			obj->used = 1;
			mark_object_reachable(obj);
		} else {
			error("%s: invalid reflog entry %s", refname, sha1_to_hex(sha1));
			errors_found |= ERROR_REACHABLE;
		}
	}
}
