			continue;
		if (i == 0)
			printf("from :%d\n", mark);
		else
			printf("merge :%d\n", mark);
		i++;
	}

	log_tree_diff_flush(rev);
	rev->diffopt.output_format = saved_output_format;