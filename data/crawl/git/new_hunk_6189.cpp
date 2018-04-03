	if (query) {
		transport = transport_get(NULL, states->remote->url_nr > 0 ?
			states->remote->url[0] : NULL);
		remote_refs = transport_get_remote_refs(transport);
		transport_disconnect(transport);

		states->queried = 1;
		if (query & GET_REF_STATES)
			get_ref_states(remote_refs, states);
		if (query & GET_HEAD_NAMES)
			get_head_names(remote_refs, states);
		if (query & GET_PUSH_REF_STATES)
			get_push_ref_states(remote_refs, states);
	} else {
		for_each_ref(append_ref_to_tracked_list, states);
		sort_string_list(&states->tracked);
		get_push_ref_states_noquery(states);
	}

	return 0;
}

struct show_info {
	struct string_list *list;
	struct ref_states *states;
	int width, width2;
	int any_rebase;
};

int add_remote_to_show_info(struct string_list_item *item, void *cb_data)
{
	struct show_info *info = cb_data;
	int n = strlen(item->string);
	if (n > info->width)
		info->width = n;
	string_list_insert(item->string, info->list);
	return 0;
}

int show_remote_info_item(struct string_list_item *item, void *cb_data)
{
	struct show_info *info = cb_data;
	struct ref_states *states = info->states;
	const char *name = item->string;

	if (states->queried) {
		const char *fmt = "%s";
		const char *arg = "";
		if (string_list_has_string(&states->new, name)) {
			fmt = " new (next fetch will store in remotes/%s)";
			arg = states->remote->name;
		} else if (string_list_has_string(&states->tracked, name))
			arg = " tracked";
		else if (string_list_has_string(&states->stale, name))
			arg = " stale (use 'git remote prune' to remove)";
		else
			arg = " ???";
		printf("    %-*s", info->width, name);
		printf(fmt, arg);
		printf("\n");
	} else
		printf("    %s\n", name);

	return 0;
}

int add_local_to_show_info(struct string_list_item *branch_item, void *cb_data)
{
	struct show_info *show_info = cb_data;
	struct ref_states *states = show_info->states;
	struct branch_info *branch_info = branch_item->util;
	struct string_list_item *item;
	int n;

	if (!branch_info->merge.nr || !branch_info->remote_name ||
	    strcmp(states->remote->name, branch_info->remote_name))
		return 0;
	if ((n = strlen(branch_item->string)) > show_info->width)
		show_info->width = n;
	if (branch_info->rebase)
		show_info->any_rebase = 1;

	item = string_list_insert(branch_item->string, show_info->list);
	item->util = branch_info;

	return 0;
}

int show_local_info_item(struct string_list_item *item, void *cb_data)
{
	struct show_info *show_info = cb_data;
	struct branch_info *branch_info = item->util;
	struct string_list *merge = &branch_info->merge;
	const char *also;
	int i;

	if (branch_info->rebase && branch_info->merge.nr > 1) {
		error("invalid branch.%s.merge; cannot rebase onto > 1 branch",
			item->string);
		return 0;
	}

	printf("    %-*s ", show_info->width, item->string);
	if (branch_info->rebase) {
		printf("rebases onto remote %s\n", merge->items[0].string);
		return 0;
	} else if (show_info->any_rebase) {
		printf(" merges with remote %s\n", merge->items[0].string);
		also = "    and with remote";
	} else {
		printf("merges with remote %s\n", merge->items[0].string);
		also = "   and with remote";
	}
	for (i = 1; i < merge->nr; i++)
		printf("    %-*s %s %s\n", show_info->width, "", also,
		       merge->items[i].string);

	return 0;
}

int add_push_to_show_info(struct string_list_item *push_item, void *cb_data)
{
	struct show_info *show_info = cb_data;
	struct push_info *push_info = push_item->util;
	struct string_list_item *item;
	int n;
	if ((n = strlen(push_item->string)) > show_info->width)
		show_info->width = n;
	if ((n = strlen(push_info->dest)) > show_info->width2)
		show_info->width2 = n;
	item = string_list_append(push_item->string, show_info->list);
	item->util = push_item->util;
	return 0;
}

/*
 * Sorting comparison for a string list that has push_info
 * structs in its util field
 */
static int cmp_string_with_push(const void *va, const void *vb)
{
	const struct string_list_item *a = va;
	const struct string_list_item *b = vb;
	const struct push_info *a_push = a->util;
	const struct push_info *b_push = b->util;
	int cmp = strcmp(a->string, b->string);
	return cmp ? cmp : strcmp(a_push->dest, b_push->dest);
}

int show_push_info_item(struct string_list_item *item, void *cb_data)
{
	struct show_info *show_info = cb_data;
	struct push_info *push_info = item->util;
	char *src = item->string, *status = NULL;

	switch (push_info->status) {
	case PUSH_STATUS_CREATE:
		status = "create";
		break;
	case PUSH_STATUS_DELETE:
		status = "delete";
		src = "(none)";
		break;
	case PUSH_STATUS_UPTODATE:
		status = "up to date";
		break;
	case PUSH_STATUS_FASTFORWARD:
		status = "fast forwardable";
		break;
	case PUSH_STATUS_OUTOFDATE:
		status = "local out of date";
		break;
	case PUSH_STATUS_NOTQUERIED:
		break;
	}
	if (status)
		printf("    %-*s %s to %-*s (%s)\n", show_info->width, src,
			push_info->forced ? "forces" : "pushes",
			show_info->width2, push_info->dest, status);
	else
		printf("    %-*s %s to %s\n", show_info->width, src,
			push_info->forced ? "forces" : "pushes",
			push_info->dest);
	return 0;
}

static int show(int argc, const char **argv)
{
	int no_query = 0, result = 0, query_flag = 0;
	struct option options[] = {
		OPT_GROUP("show specific options"),
		OPT_BOOLEAN('n', NULL, &no_query, "do not query remotes"),
		OPT_END()
	};
	struct ref_states states;
	struct string_list info_list = { NULL, 0, 0, 0 };
	struct show_info info;

	argc = parse_options(argc, argv, options, builtin_remote_usage, 0);

	if (argc < 1)
		return show_all();

	if (!no_query)
		query_flag = (GET_REF_STATES | GET_HEAD_NAMES | GET_PUSH_REF_STATES);

	memset(&states, 0, sizeof(states));
	memset(&info, 0, sizeof(info));
	info.states = &states;
	info.list = &info_list;
	for (; argc; argc--, argv++) {
		int i;

		get_remote_ref_states(*argv, &states, query_flag);

		printf("* remote %s\n  URL: %s\n", *argv,
			states.remote->url_nr > 0 ?
				states.remote->url[0] : "(no URL)");
		if (no_query)
			printf("  HEAD branch: (not queried)\n");
		else if (!states.heads.nr)
			printf("  HEAD branch: (unknown)\n");
		else if (states.heads.nr == 1)
			printf("  HEAD branch: %s\n", states.heads.items[0].string);
		else {
			printf("  HEAD branch (remote HEAD is ambiguous,"
			       " may be one of the following):\n");
			for (i = 0; i < states.heads.nr; i++)
				printf("    %s\n", states.heads.items[i].string);
		}

		/* remote branch info */
		info.width = 0;
		for_each_string_list(add_remote_to_show_info, &states.new, &info);
		for_each_string_list(add_remote_to_show_info, &states.tracked, &info);
		for_each_string_list(add_remote_to_show_info, &states.stale, &info);
		if (info.list->nr)
			printf("  Remote branch%s:%s\n",
			       info.list->nr > 1 ? "es" : "",
				no_query ? " (status not queried)" : "");
		for_each_string_list(show_remote_info_item, info.list, &info);
		string_list_clear(info.list, 0);

		/* git pull info */
		info.width = 0;
		info.any_rebase = 0;
		for_each_string_list(add_local_to_show_info, &branch_list, &info);
		if (info.list->nr)
			printf("  Local branch%s configured for 'git pull':\n",
			       info.list->nr > 1 ? "es" : "");
		for_each_string_list(show_local_info_item, info.list, &info);
		string_list_clear(info.list, 0);

		/* git push info */
		if (states.remote->mirror)
			printf("  Local refs will be mirrored by 'git push'\n");

		info.width = info.width2 = 0;
		for_each_string_list(add_push_to_show_info, &states.push, &info);
		qsort(info.list->items, info.list->nr,
			sizeof(*info.list->items), cmp_string_with_push);
		if (info.list->nr)
			printf("  Local ref%s configured for 'git push'%s:\n",
				info.list->nr > 1 ? "s" : "",
				no_query ? " (status not queried)" : "");
		for_each_string_list(show_push_info_item, info.list, &info);
		string_list_clear(info.list, 0);

		free_remote_ref_states(&states);
	}

	return result;
}

static int set_head(int argc, const char **argv)
{
	int i, opt_a = 0, opt_d = 0, result = 0;
	struct strbuf buf = STRBUF_INIT, buf2 = STRBUF_INIT;
	char *head_name = NULL;

	struct option options[] = {
		OPT_GROUP("set-head specific options"),
		OPT_BOOLEAN('a', "auto", &opt_a,
			    "set refs/remotes/<name>/HEAD according to remote"),
		OPT_BOOLEAN('d', "delete", &opt_d,
			    "delete refs/remotes/<name>/HEAD"),
		OPT_END()
	};
	argc = parse_options(argc, argv, options, builtin_remote_usage, 0);
	if (argc)
		strbuf_addf(&buf, "refs/remotes/%s/HEAD", argv[0]);

	if (!opt_a && !opt_d && argc == 2) {
		head_name = xstrdup(argv[1]);
	} else if (opt_a && !opt_d && argc == 1) {
		struct ref_states states;
		memset(&states, 0, sizeof(states));
		get_remote_ref_states(argv[0], &states, GET_HEAD_NAMES);
		if (!states.heads.nr)
			result |= error("Cannot determine remote HEAD");
		else if (states.heads.nr > 1) {
			result |= error("Multiple remote HEAD branches. "
					"Please choose one explicitly with:");
			for (i = 0; i < states.heads.nr; i++)
				fprintf(stderr, "  git remote set-head %s %s\n",
					argv[0], states.heads.items[i].string);
		} else
			head_name = xstrdup(states.heads.items[0].string);
		free_remote_ref_states(&states);
	} else if (opt_d && !opt_a && argc == 1) {
		if (delete_ref(buf.buf, NULL, REF_NODEREF))
			result |= error("Could not delete %s", buf.buf);
	} else
		usage_with_options(builtin_remote_usage, options);

	if (head_name) {
		unsigned char sha1[20];
		strbuf_addf(&buf2, "refs/remotes/%s/%s", argv[0], head_name);
		/* make sure it's valid */
		if (!resolve_ref(buf2.buf, sha1, 1, NULL))
			result |= error("Not a valid ref: %s", buf2.buf);
		else if (create_symref(buf.buf, buf2.buf, "remote set-head"))
			result |= error("Could not setup %s", buf.buf);
		if (opt_a)
			printf("%s/HEAD set to %s\n", argv[0], head_name);
		free(head_name);
	}

	strbuf_release(&buf);
	strbuf_release(&buf2);
	return result;
}

