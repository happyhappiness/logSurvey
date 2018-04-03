 			continue;
 		}
 		else if (data->files[i]->is_unmerged) {
+			fprintf(options->file, "%s", line_prefix);
 			show_name(options->file, prefix, name, len);
 			fprintf(options->file, "  Unmerged\n");
 			continue;
