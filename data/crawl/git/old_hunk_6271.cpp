	commit->buffer = NULL;
}

static void show_object(struct object_array_entry *p)
{
	/* An object with name "foo\n0000000..." can be used to
	 * confuse downstream git-pack-objects very badly.
	 */
	const char *ep = strchr(p->name, '\n');
	if (ep) {
		fprintf(pack_pipe, "%s %.*s\n", sha1_to_hex(p->item->sha1),
		       (int) (ep - p->name),
		       p->name);
	}
	else
		fprintf(pack_pipe, "%s %s\n",
				sha1_to_hex(p->item->sha1), p->name);
}

static void show_edge(struct commit *commit)