		if (!use_stdout)
			rev.shown_one = 0;
		if (shown) {
			print_bases(&bases, rev.diffopt.file);
			if (rev.mime_boundary)
				fprintf(rev.diffopt.file, "\n--%s%s--\n\n\n",
				       mime_boundary_leader,
				       rev.mime_boundary);
			else
				print_signature(rev.diffopt.file);
		}
		if (!use_stdout)
			fclose(rev.diffopt.file);
