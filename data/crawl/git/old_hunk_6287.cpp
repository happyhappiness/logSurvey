		}
		strbuf_release(&buf);
	} else {
		if (graph_show_remainder(revs.graph))
			putchar('\n');
	}
	maybe_flush_or_die(stdout, "stdout");
	finish_commit(commit);
}

static void finish_commit(struct commit *commit)
{
	if (commit->parents) {
		free_commit_list(commit->parents);
