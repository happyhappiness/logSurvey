				 * format doesn't explicitly end in a newline.)
				 */
				if (buf.len && buf.buf[buf.len - 1] == '\n')
					graph_show_padding(revs->graph);
				putchar('\n');
			} else {
				/*
				 * If the message buffer is empty, just show
				 * the rest of the graph output for this
				 * commit.
				 */
				if (graph_show_remainder(revs->graph))
					putchar('\n');
			}
		} else {
			if (buf.len)
				printf("%s%c", buf.buf, info->hdr_termination);
		}
		strbuf_release(&buf);
	} else {
		if (graph_show_remainder(revs->graph))
			putchar('\n');
	}
	maybe_flush_or_die(stdout, "stdout");
	finish_commit(commit, data);
}

static void finish_commit(struct commit *commit, void *data)
{
	if (commit->parents) {
		free_commit_list(commit->parents);
