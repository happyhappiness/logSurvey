	FILE *f = fopen(path, "w");
	if (!f)
		die("cannot open pid file %s: %s", path, strerror(errno));
	fprintf(f, "%d\n", getpid());
	fclose(f);
}

static int serve(char *listen_addr, int listen_port, struct passwd *pass, gid_t gid)