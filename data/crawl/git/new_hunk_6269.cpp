	if (parse_tree(tree) < 0)
		die("bad tree object %s", sha1_to_hex(obj->sha1));
	obj->flags |= SEEN;
	show(obj, path_name(path, name));
	me.up = path;
	me.elem = name;
	me.elem_len = strlen(name);
