	commit->buffer = NULL;
}

static void show_object(struct object *obj, const char *name)
{
	/* An object with name "foo\n0000000..." can be used to
	 * confuse downstream git-pack-objects very badly.
	 */
	const char *ep = strchr(name, '\n');
	if (ep) {
		fprintf(pack_pipe, "%s %.*s\n", sha1_to_hex(obj->sha1),
		       (int) (ep - name),
		       name);
	}
	else
		fprintf(pack_pipe, "%s %s\n",
				sha1_to_hex(obj->sha1), name);
}

static void show_edge(struct commit *commit)