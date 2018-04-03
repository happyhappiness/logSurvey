	const char *o_name;
	const unsigned char *o_sha1;

	init_tree_desc(&desc, item->buffer, item->size);

	o_mode = 0;
