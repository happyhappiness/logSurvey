			if (lookup_object(sha1))
				continue;

			strbuf_addf(path, "/%s", de->d_name);
			prune_object(path->buf, sha1);
			strbuf_setlen(path, baselen);
			continue;
		}
		if (!prefixcmp(de->d_name, "tmp_obj_")) {
			strbuf_addf(path, "/%s", de->d_name);
			prune_tmp_file(path->buf);
			strbuf_setlen(path, baselen);
			continue;
		}
		fprintf(stderr, "bad sha1 file: %s/%s\n", path->buf, de->d_name);
	}
	closedir(dir);
	if (!show_only)
		rmdir(path->buf);
	return 0;
}

static void prune_object_dir(const char *path)
{
	struct strbuf buf = STRBUF_INIT;
	size_t baselen;
	int i;

	strbuf_addstr(&buf, path);
	strbuf_addch(&buf, '/');
	baselen = buf.len;

	for (i = 0; i < 256; i++) {
		strbuf_addf(&buf, "%02x", i);
		prune_dir(i, &buf);
		strbuf_setlen(&buf, baselen);
	}
}

