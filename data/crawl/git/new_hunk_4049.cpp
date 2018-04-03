	putchar('\n');
}

void fast_export_note(const char *committish, const char *dataref)
{
	printf("N %s %s\n", dataref, committish);
}

static char gitsvnline[MAX_GITSVN_LINE_LEN];
void fast_export_begin_commit(uint32_t revision, const char *author,
			const struct strbuf *log,
