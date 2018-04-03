			if (!lookup_commit_reference_gently(&oid, 1)) {
				enum object_type type = sha1_object_info(oid.hash, NULL);
				return error(_("%s: can't cherry-pick a %s"),
					name, typename(type));
			}
		} else
			return error(_("%s: bad revision"), name);
