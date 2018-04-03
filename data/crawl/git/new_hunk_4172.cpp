	if (o->verbosity >= 4)
		printf("Finalized notes merge commit: %s\n",
			sha1_to_hex(result_sha1));
	strbuf_release(&path);
	closedir(dir);
	return 0;
}

