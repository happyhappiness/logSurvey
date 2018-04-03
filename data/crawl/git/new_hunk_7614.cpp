			printf("%s\n", c_reset);
		}
		if (added)
			dump_quoted_path("--- ", "", "/dev/null",
					 c_meta, c_reset);
		else
			dump_quoted_path("--- ", opt->a_prefix, elem->path,
					 c_meta, c_reset);
		if (deleted)
			dump_quoted_path("+++ ", "", "/dev/null",
					 c_meta, c_reset);
		else
			dump_quoted_path("+++ ", opt->b_prefix, elem->path,
					 c_meta, c_reset);
		dump_sline(sline, cnt, num_parent,
			   DIFF_OPT_TST(opt, COLOR_DIFF));
	}
	free(result);
