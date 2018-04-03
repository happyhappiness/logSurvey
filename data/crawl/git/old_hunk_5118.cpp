		i++;
	}

	log_tree_diff_flush(rev);
	rev->diffopt.output_format = saved_output_format;

