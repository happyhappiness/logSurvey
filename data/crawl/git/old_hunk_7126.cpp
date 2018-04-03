			continue;
		if (i == 0)
			printf("from :%d\n", mark);
		else if (i == 1)
			printf("merge :%d", mark);
		else
			printf(" :%d", mark);
		i++;
	}
	if (i > 1)
		printf("\n");

	log_tree_diff_flush(rev);
	rev->diffopt.output_format = saved_output_format;