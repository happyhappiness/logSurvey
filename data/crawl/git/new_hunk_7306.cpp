	b_two = quote_two(o->b_prefix, name_b + (*name_b == '/'));
	lbl[0] = DIFF_FILE_VALID(one) ? a_one : "/dev/null";
	lbl[1] = DIFF_FILE_VALID(two) ? b_two : "/dev/null";
	fprintf(o->file, "%sdiff --git %s %s%s\n", set, a_one, b_two, reset);
	if (lbl[0][0] == '/') {
		/* /dev/null */
		fprintf(o->file, "%snew file mode %06o%s\n", set, two->mode, reset);
		if (xfrm_msg && xfrm_msg[0])
			fprintf(o->file, "%s%s%s\n", set, xfrm_msg, reset);
	}
	else if (lbl[1][0] == '/') {
		fprintf(o->file, "%sdeleted file mode %06o%s\n", set, one->mode, reset);
		if (xfrm_msg && xfrm_msg[0])
			fprintf(o->file, "%s%s%s\n", set, xfrm_msg, reset);
	}
	else {
		if (one->mode != two->mode) {
			fprintf(o->file, "%sold mode %06o%s\n", set, one->mode, reset);
			fprintf(o->file, "%snew mode %06o%s\n", set, two->mode, reset);
		}
		if (xfrm_msg && xfrm_msg[0])
			fprintf(o->file, "%s%s%s\n", set, xfrm_msg, reset);
		/*
		 * we do not run diff between different kind
		 * of objects.
