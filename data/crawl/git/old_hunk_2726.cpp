	 * file_p partially may match that image.
	 */
	memset(split, 0, sizeof(struct blame_entry [3]));
	diff_hunks(file_p, &file_o, 1, handle_split_cb, &d);
	/* remainder, if any, all match the preimage */
	handle_split(sb, ent, d.tlno, d.plno, ent->num_lines, parent, split);
}