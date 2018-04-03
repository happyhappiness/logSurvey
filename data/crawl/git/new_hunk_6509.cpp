
const char *system_path(const char *path)
{
#ifdef RUNTIME_PREFIX
	static const char *prefix;
#else
	static const char *prefix = PREFIX;
#endif
	struct strbuf d = STRBUF_INIT;

	if (is_absolute_path(path))
		return path;

#ifdef RUNTIME_PREFIX
	assert(argv0_path);
	assert(is_absolute_path(argv0_path));

	if (!prefix) {
		const char *strip[] = {
			GIT_EXEC_PATH,
			BINDIR,
			0
		};
		const char **s;

		for (s = strip; *s; s++) {
			const char *sargv = argv0_path + strlen(argv0_path);
			const char *ss = *s + strlen(*s);
			while (argv0_path < sargv && *s < ss
				&& (*sargv == *ss ||
				    (is_dir_sep(*sargv) && is_dir_sep(*ss)))) {
				sargv--;
				ss--;
			}
			if (*s == ss) {
				struct strbuf d = STRBUF_INIT;
				/* We also skip the trailing directory separator. */
				assert(sargv - argv0_path - 1 >= 0);
				strbuf_add(&d, argv0_path, sargv - argv0_path - 1);
				prefix = strbuf_detach(&d, NULL);
				break;
			}
		}
	}

	if (!prefix) {
		prefix = PREFIX;
		fprintf(stderr, "RUNTIME_PREFIX requested, "
				"but prefix computation failed.  "
				"Using static fallback '%s'.\n", prefix);
	}
#endif

	strbuf_addf(&d, "%s/%s", prefix, path);
	path = strbuf_detach(&d, NULL);
	return path;