		argv[argc++] = depth_arg;
	}
	argv[argc++] = url;
	for (i = 0; i < nr_heads; i++) {
		struct ref *ref = to_fetch[i];
		if (!ref->name || !*ref->name)
			die("cannot fetch by sha1 over smart http");
		argv[argc++] = ref->name;
	}
	argv[argc++] = NULL;

	memset(&rpc, 0, sizeof(rpc));
	rpc.service_name = "git-upload-pack",
	rpc.argv = argv;
	rpc.gzip_request = 1;

	err = rpc_service(&rpc, heads);
	if (rpc.result.len)
		safe_write(1, rpc.result.buf, rpc.result.len);
	strbuf_release(&rpc.result);
	free(argv);
	free(depth_arg);
	return err;
}