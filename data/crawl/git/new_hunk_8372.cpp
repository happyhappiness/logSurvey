	refspec_nr = nr;
}

static void set_refspecs(const char **refs, int nr)
{
	int i;
	for (i = 0; i < nr; i++) {
		const char *ref = refs[i];
		if (!strcmp("tag", ref)) {
			char *tag;
			int len;
			if (nr <= ++i)
				die("tag shorthand without <tag>");
			len = strlen(refs[i]) + 11;
			tag = xmalloc(len);
			strcpy(tag, "refs/tags/");
			strcat(tag, refs[i]);
			ref = tag;
		}
		add_refspec(ref);
	}
}

static int do_push(const char *repo)
