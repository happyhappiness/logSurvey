		if (0 < patch->is_new)
			sha1_ptr = null_sha1;
		else if (get_sha1(patch->old_sha1_prefix, sha1))
			die("sha1 information is lacking or useless (%s).",
			    name);
		else
			sha1_ptr = sha1;

