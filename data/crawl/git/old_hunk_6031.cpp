			die("invalid quoting");
		path = strbuf_detach(&p_uq, NULL);
	}
	append_to_tree(mode, sha1, path);
}
