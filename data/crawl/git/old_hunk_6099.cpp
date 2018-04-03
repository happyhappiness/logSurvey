			continue;
		}
		else if (data->files[i]->is_unmerged) {
			show_name(options->file, prefix, name, len, reset, set);
			fprintf(options->file, "  Unmerged\n");
			continue;
		}
