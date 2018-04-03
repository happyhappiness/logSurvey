		if (strlen(name) == toplen &&
		    !memcmp(name, prefix, toplen)) {
			if (!S_ISDIR(mode))
				die("entry %s in tree %s is not a tree",
				    name, sha1_to_hex(hash1));
			rewrite_here = (unsigned char *) oid->hash;
			break;
		}
		update_tree_entry(&desc);
	}
	if (!rewrite_here)
		die("entry %.*s not found in tree %s",
		    toplen, prefix, sha1_to_hex(hash1));
	if (*subpath) {
		status = splice_tree(rewrite_here, subpath, hash2, subtree);
		if (status)
			return status;
		rewrite_with = subtree;
	}
	else
		rewrite_with = hash2;
	hashcpy(rewrite_here, rewrite_with);
	status = write_sha1_file(buf, sz, tree_type, result);
	free(buf);
	return status;
}
