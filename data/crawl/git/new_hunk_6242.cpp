	if (parse_tree(tree) < 0)
		die("bad tree object %s", sha1_to_hex(obj->sha1));
	obj->flags |= SEEN;
	add_object(obj, p, path, name);
	me.up = path;
	me.elem = name;
