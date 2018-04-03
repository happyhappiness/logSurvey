			del = scale_linear(del, width, max_change);
			total = add + del;
		}
		show_name(prefix, name, len, reset, set);
		printf("%5d ", added + deleted);
		show_graph('+', add, add_c, reset);
		show_graph('-', del, del_c, reset);
		putchar('\n');
	}
	printf("%s %d files changed, %d insertions(+), %d deletions(-)%s\n",
	       set, total_files, adds, dels, reset);
}

static void show_shortstats(struct diffstat_t* data)
{
	int i, adds = 0, dels = 0, total_files = data->nr;

