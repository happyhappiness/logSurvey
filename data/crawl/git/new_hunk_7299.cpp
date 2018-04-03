			del = scale_linear(del, width, max_change);
			total = add + del;
		}
		show_name(options->file, prefix, name, len, reset, set);
		fprintf(options->file, "%5d ", added + deleted);
		show_graph(options->file, '+', add, add_c, reset);
		show_graph(options->file, '-', del, del_c, reset);
		fprintf(options->file, "\n");
	}
	fprintf(options->file,
	       "%s %d files changed, %d insertions(+), %d deletions(-)%s\n",
	       set, total_files, adds, dels, reset);
}

static void show_shortstats(struct diffstat_t* data, struct diff_options *options)
{
	int i, adds = 0, dels = 0, total_files = data->nr;

