	free_commit_list(result);
}

static int check_ancestors(const char *prefix)
{
	struct rev_info revs;
	struct object_array pending_copy;
	int i, res;

	bisect_rev_setup(&revs, prefix, "^%s", "%s", 0);

	/* Save pending objects, so they can be cleaned up later. */
	memset(&pending_copy, 0, sizeof(pending_copy));
	for (i = 0; i < revs.pending.nr; i++)
		add_object_array(revs.pending.objects[i].item,
				 revs.pending.objects[i].name,
				 &pending_copy);

	bisect_common(&revs);
	res = (revs.commits != NULL);

	/* Clean up objects used, as they will be reused. */
	for (i = 0; i < pending_copy.nr; i++) {
		struct object *o = pending_copy.objects[i].item;
		unparse_commit((struct commit *)o);
	}

	return res;
}

/*
