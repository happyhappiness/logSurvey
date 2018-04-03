	return conflicts ? -1 : 1;
}

int notes_merge(struct notes_merge_options *o,
		struct notes_tree *local_tree,
		unsigned char *result_sha1)
