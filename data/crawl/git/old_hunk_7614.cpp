			printf("%s\n", c_reset);
		}
		if (added)
			dump_quoted_path("--- /dev/", "null", c_meta, c_reset);
		else
			dump_quoted_path("--- a/", elem->path, c_meta, c_reset);
		if (deleted)
			dump_quoted_path("+++ /dev/", "null", c_meta, c_reset);
		else
			dump_quoted_path("+++ b/", elem->path, c_meta, c_reset);
		dump_sline(sline, cnt, num_parent, DIFF_OPT_TST(opt, COLOR_DIFF));
	}
	free(result);
