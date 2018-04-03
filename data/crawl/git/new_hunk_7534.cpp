	memcpy(output, patch, plen);
	if (add_nl_to_tail)
		output[plen++] = '\n';
	if (fixed && count_error)
		applied_after_fixing_ws++;
	return output + plen - buf;
}

static void update_pre_post_images(struct image *preimage,
				   struct image *postimage,
				   char *buf,
				   size_t len)
{
	int i, ctx;
	char *new, *old, *fixed;
	struct image fixed_preimage;

	/*
	 * Update the preimage with whitespace fixes.  Note that we
	 * are not losing preimage->buf -- apply_one_fragment() will
	 * free "oldlines".
	 */
	prepare_image(&fixed_preimage, buf, len, 1);
	assert(fixed_preimage.nr == preimage->nr);
	for (i = 0; i < preimage->nr; i++)
		fixed_preimage.line[i].flag = preimage->line[i].flag;
	free(preimage->line_allocated);
	*preimage = fixed_preimage;

	/*
	 * Adjust the common context lines in postimage, in place.
	 * This is possible because whitespace fixing does not make
	 * the string grow.
	 */
	new = old = postimage->buf;
	fixed = preimage->buf;
	for (i = ctx = 0; i < postimage->nr; i++) {
		size_t len = postimage->line[i].len;
		if (!(postimage->line[i].flag & LINE_COMMON)) {
			/* an added line -- no counterparts in preimage */
			memmove(new, old, len);
			old += len;
			new += len;
			continue;
		}

		/* a common context -- skip it in the original postimage */
		old += len;

		/* and find the corresponding one in the fixed preimage */
		while (ctx < preimage->nr &&
		       !(preimage->line[ctx].flag & LINE_COMMON)) {
			fixed += preimage->line[ctx].len;
			ctx++;
		}
		if (preimage->nr <= ctx)
			die("oops");

		/* and copy it in, while fixing the line length */
		len = preimage->line[ctx].len;
		memcpy(new, fixed, len);
		new += len;
		fixed += len;
		postimage->line[i].len = len;
		ctx++;
	}

	/* Fix the length of the whole thing */
	postimage->len = new - postimage->buf;
}

static int match_fragment(struct image *img,
			  struct image *preimage,
			  struct image *postimage,
