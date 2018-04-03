		show_graph('+', add, add_c, reset);
		show_graph('-', del, del_c, reset);
		putchar('\n');
	free_diffstat_file:
		free(data->files[i]->name);
		free(data->files[i]);
	}
	free(data->files);
	printf("%s %d files changed, %d insertions(+), %d deletions(-)%s\n",
	       set, total_files, adds, dels, reset);
}
