		get_remote_heads(data->fd[0], NULL, 0, &tmp_refs, REF_NORMAL, NULL, NULL);
		data->got_remote_heads = 1;
	}

	memset(&args, 0, sizeof(args));
	args.send_mirror = !!(flags & TRANSPORT_PUSH_MIRROR);