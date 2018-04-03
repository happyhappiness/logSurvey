				fputs(line, stdout);
				fflush(stdout);
			}
			else
				diff_tree_stdin(line);
		}
	}

	return diff_result_code(&opt->diffopt, 0);
