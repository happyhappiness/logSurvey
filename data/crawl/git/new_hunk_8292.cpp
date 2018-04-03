			printf("[%s] ",
			       find_unique_abbrev(commit->object.sha1, 7));
	}
	puts(pretty_str);
	free(pretty);
}

static char *ref_name[MAX_REVS + 1];
