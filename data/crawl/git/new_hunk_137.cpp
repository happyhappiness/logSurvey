		if (strlen(name) == toplen &&
		    !memcmp(name, prefix, toplen)) {
			if (!S_ISDIR(mode))
				die("entry %s in tree %s is not a tree", name,
				    oid_to_hex(oid1));
			rewrite_here = (struct object_id *)oid;
			break;
		}
		update_tree_entry(&desc);
	}
	if (!rewrite_here)
		die("entry %.*s not found in tree %s", toplen, prefix,
		    oid_to_hex(oid1));
	if (*subpath) {
		status = splice_tree(rewrite_here, subpath, oid2, &subtree);
		if (status)
			return status;
		rewrite_with = &subtree;
	} else {
		rewrite_with = oid2;
	}
	oidcpy(rewrite_here, rewrite_with);
	status = write_sha1_file(buf, sz, tree_type, result->hash);
	free(buf);
	return status;
}
