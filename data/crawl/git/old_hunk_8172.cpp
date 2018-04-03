		add_to_ref_list(sha1, isspace(delim) ?
				buffer + 41 + offset : "", list);
	}
	return fd;
}
