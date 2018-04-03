		rollback_lock_file(lock);
		return clean ? 0 : 1;
	} else {
		args = xmalloc((4 + xopts_nr + commit_list_count(common) +
					commit_list_count(remoteheads)) * sizeof(char *));
		strbuf_addf(&buf, "merge-%s", strategy);
		args[i++] = buf.buf;
		for (x = 0; x < xopts_nr; x++) {
			char *s = xmalloc(strlen(xopts[x])+2+1);
			strcpy(s, "--");
			strcpy(s+2, xopts[x]);
			args[i++] = s;
		}
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
		for (x = 0; x < xopts_nr; x++)
			free((void *)args[i++]);
		for (j = common; j; j = j->next)
			free((void *)args[i++]);
		i += 2;
		for (j = remoteheads; j; j = j->next)
			free((void *)args[i++]);
		free(args);
		discard_cache();
		if (read_cache() < 0)
			die("failed to read the cache");
		resolve_undo_clear();
		return ret;
	}
}
