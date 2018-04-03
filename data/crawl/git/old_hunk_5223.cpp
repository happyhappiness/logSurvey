			continue;
		}
		else if (data->files[i]->is_unmerged) {
			show_name(options->file, prefix, name, len);
			fprintf(options->file, "  Unmerged\n");
			continue;
