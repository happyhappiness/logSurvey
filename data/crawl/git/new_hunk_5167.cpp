				       mime_boundary_leader,
				       rev.mime_boundary);
			else
				print_signature();
		}
		if (!use_stdout)
			fclose(stdout);
