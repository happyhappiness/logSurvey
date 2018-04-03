	struct commit_list *j;
	struct strbuf buf;

	args = xmalloc((4 + commit_list_count(common) +
			commit_list_count(remoteheads)) * sizeof(char *));
	strbuf_init(&buf, 0);
	strbuf_addf(&buf, "merge-%s", strategy);
	args[i++] = buf.buf;
	for (j = common; j; j = j->next)
		args[i++] = xstrdup(sha1_to_hex(j->item->object.sha1));
	args[i++] = "--";
	args[i++] = head_arg;
	for (j = remoteheads; j; j = j->next)
		args[i++] = xstrdup(sha1_to_hex(j->item->object.sha1));
	args[i] = NULL;
	ret = run_command_v_opt(args, RUN_GIT_CMD);
	strbuf_release(&buf);
	i = 1;
	for (j = common; j; j = j->next)
		free((void *)args[i++]);
	i += 2;
	for (j = remoteheads; j; j = j->next)
		free((void *)args[i++]);
	free(args);
	return -ret;
}

static void count_diff_files(struct diff_queue_struct *q,
