	return res;
}

static void flush_rewritten_pending(void) {
	struct strbuf buf = STRBUF_INIT;
	unsigned char newsha1[20];
	FILE *out;

	if (strbuf_read_file(&buf, rebase_path_rewritten_pending(), 82) > 0 &&
			!get_sha1("HEAD", newsha1) &&
			(out = fopen(rebase_path_rewritten_list(), "a"))) {
		char *bol = buf.buf, *eol;

		while (*bol) {
			eol = strchrnul(bol, '\n');
			fprintf(out, "%.*s %s\n", (int)(eol - bol),
					bol, sha1_to_hex(newsha1));
			if (!*eol)
				break;
			bol = eol + 1;
		}
		fclose(out);
		unlink(rebase_path_rewritten_pending());
	}
	strbuf_release(&buf);
}

static void record_in_rewritten(struct object_id *oid,
		enum todo_command next_command) {
	FILE *out = fopen(rebase_path_rewritten_pending(), "a");

	if (!out)
		return;

	fprintf(out, "%s\n", oid_to_hex(oid));
	fclose(out);

	if (!is_fixup(next_command))
		flush_rewritten_pending();
}

static int do_pick_commit(enum todo_command command, struct commit *commit,
		struct replay_opts *opts, int final_fixup)
{
