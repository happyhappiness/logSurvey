	return sz;
}

static FILE *pack_pipe = NULL;
static void show_commit(struct commit *commit, void *data)
{
	if (commit->object.flags & BOUNDARY)
		fputc('-', pack_pipe);
	if (fputs(sha1_to_hex(commit->object.sha1), pack_pipe) < 0)
		die("broken output pipe");
	fputc('\n', pack_pipe);
	fflush(pack_pipe);
	free(commit->buffer);
	commit->buffer = NULL;
}

static void show_object(struct object *obj,
			const struct name_path *path, const char *component,
			void *cb_data)
{
	show_object_with_name(pack_pipe, obj, path, component);
}

static void show_edge(struct commit *commit)
{
	fprintf(pack_pipe, "-%s\n", sha1_to_hex(commit->object.sha1));
}

static int do_rev_list(int in, int out, void *user_data)
{
	int i;
	struct rev_info revs;

	pack_pipe = xfdopen(out, "w");
	init_revisions(&revs, NULL);
	revs.tag_objects = 1;
	revs.tree_objects = 1;
	revs.blob_objects = 1;
	if (use_thin_pack)
		revs.edge_hint = 1;

	for (i = 0; i < want_obj.nr; i++) {
		struct object *o = want_obj.objects[i].item;
		/* why??? */
		o->flags &= ~UNINTERESTING;
		add_pending_object(&revs, o, NULL);
	}
	for (i = 0; i < have_obj.nr; i++) {
		struct object *o = have_obj.objects[i].item;
		o->flags |= UNINTERESTING;
		add_pending_object(&revs, o, NULL);
	}
	setup_revisions(0, NULL, &revs, NULL);
	if (prepare_revision_walk(&revs))
		die("revision walk setup failed");
	mark_edges_uninteresting(revs.commits, &revs, show_edge);
	if (use_thin_pack)
		for (i = 0; i < extra_edge_obj.nr; i++)
			fprintf(pack_pipe, "-%s\n", sha1_to_hex(
					extra_edge_obj.objects[i].item->sha1));
	traverse_commit_list(&revs, show_commit, show_object, NULL);
	fflush(pack_pipe);
	fclose(pack_pipe);
	return 0;
}

static void create_pack_file(void)
{
	struct async rev_list;
	struct child_process pack_objects;
	char data[8193], progress[128];
	char abort_msg[] = "aborting due to possible repository "
		"corruption on the remote side.";
	int buffered = -1;
	ssize_t sz;
	const char *argv[10];
	int arg = 0;

	argv[arg++] = "pack-objects";
	if (!shallow_nr) {
		argv[arg++] = "--revs";
		if (use_thin_pack)
			argv[arg++] = "--thin";
	}

	argv[arg++] = "--stdout";
	if (!no_progress)
