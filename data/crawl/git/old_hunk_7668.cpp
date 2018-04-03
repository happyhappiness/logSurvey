			printf("%s%d%s", add_c, added, reset);
			printf(" bytes");
			printf("\n");
			goto free_diffstat_file;
		}
		else if (data->files[i]->is_unmerged) {
			show_name(prefix, name, len, reset, set);
			printf("  Unmerged\n");
			goto free_diffstat_file;
		}
		else if (!data->files[i]->is_renamed &&
			 (added + deleted == 0)) {
			total_files--;
			goto free_diffstat_file;
		}

		/*
