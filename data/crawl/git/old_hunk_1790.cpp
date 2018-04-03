		}

		/* Now output a diff hunk for this range */
		printf("%s%s@@ -%ld,%ld +%ld,%ld @@%s\n",
		       prefix, c_frag,
		       p_start+1, p_end-p_start, t_start+1, t_end-t_start,
		       c_reset);
		while (j < diff->target.nr && diff->target.ranges[j].start < t_end) {
			int k;
			for (; t_cur < diff->target.ranges[j].start; t_cur++)
				print_line(prefix, ' ', t_cur, t_ends, pair->two->data,
					   c_context, c_reset);
			for (k = diff->parent.ranges[j].start; k < diff->parent.ranges[j].end; k++)
				print_line(prefix, '-', k, p_ends, pair->one->data,
					   c_old, c_reset);
			for (; t_cur < diff->target.ranges[j].end && t_cur < t_end; t_cur++)
				print_line(prefix, '+', t_cur, t_ends, pair->two->data,
					   c_new, c_reset);
			j++;
		}
		for (; t_cur < t_end; t_cur++)
			print_line(prefix, ' ', t_cur, t_ends, pair->two->data,
				   c_context, c_reset);
	}

	free(p_ends);
