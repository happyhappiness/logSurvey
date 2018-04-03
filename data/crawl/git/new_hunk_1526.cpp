			     flags));
}

/*
 * Represent a group of changed lines in an xdfile_t (i.e., a contiguous group
 * of lines that was inserted or deleted from the corresponding version of the
 * file). We consider there to be such a group at the beginning of the file, at
 * the end of the file, and between any two unchanged lines, though most such
 * groups will usually be empty.
 *
 * If the first line in a group is equal to the line following the group, then
 * the group can be slid down. Similarly, if the last line in a group is equal
 * to the line preceding the group, then the group can be slid up. See
 * group_slide_down() and group_slide_up().
 *
 * Note that loops that are testing for changed lines in xdf->rchg do not need
 * index bounding since the array is prepared with a zero at position -1 and N.
 */
struct group {
	/*
	 * The index of the first changed line in the group, or the index of
	 * the unchanged line above which the (empty) group is located.
	 */
	long start;

	/*
	 * The index of the first unchanged line after the group. For an empty
	 * group, end is equal to start.
	 */
	long end;
};

/*
 * Initialize g to point at the first group in xdf.
 */
static void group_init(xdfile_t *xdf, struct group *g)
{
	g->start = g->end = 0;
	while (xdf->rchg[g->end])
		g->end++;
}

/*
 * Move g to describe the next (possibly empty) group in xdf and return 0. If g
 * is already at the end of the file, do nothing and return -1.
 */
static inline int group_next(xdfile_t *xdf, struct group *g)
{
	if (g->end == xdf->nrec)
		return -1;

	g->start = g->end + 1;
	for (g->end = g->start; xdf->rchg[g->end]; g->end++)
		;

	return 0;
}

/*
 * Move g to describe the previous (possibly empty) group in xdf and return 0.
 * If g is already at the beginning of the file, do nothing and return -1.
 */
static inline int group_previous(xdfile_t *xdf, struct group *g)
{
	if (g->start == 0)
		return -1;

	g->end = g->start - 1;
	for (g->start = g->end; xdf->rchg[g->start - 1]; g->start--)
		;

	return 0;
}

/*
 * If g can be slid toward the end of the file, do so, and if it bumps into a
 * following group, expand this group to include it. Return 0 on success or -1
 * if g cannot be slid down.
 */
static int group_slide_down(xdfile_t *xdf, struct group *g, long flags)
{
	if (g->end < xdf->nrec &&
	    recs_match(xdf->recs[g->start], xdf->recs[g->end], flags)) {
		xdf->rchg[g->start++] = 0;
		xdf->rchg[g->end++] = 1;

		while (xdf->rchg[g->end])
			g->end++;

		return 0;
	} else {
		return -1;
	}
}

/*
 * If g can be slid toward the beginning of the file, do so, and if it bumps
 * into a previous group, expand this group to include it. Return 0 on success
 * or -1 if g cannot be slid up.
 */
static int group_slide_up(xdfile_t *xdf, struct group *g, long flags)
{
	if (g->start > 0 &&
	    recs_match(xdf->recs[g->start - 1], xdf->recs[g->end - 1], flags)) {
		xdf->rchg[--g->start] = 1;
		xdf->rchg[--g->end] = 0;

		while (xdf->rchg[g->start - 1])
			g->start--;

		return 0;
	} else {
		return -1;
	}
}

static void xdl_bug(const char *msg)
{
	fprintf(stderr, "BUG: %s\n", msg);
	exit(1);
}

/*
 * Move back and forward change groups for a consistent and pretty diff output.
 * This also helps in finding joinable change groups and reducing the diff
 * size.
 */
int xdl_change_compact(xdfile_t *xdf, xdfile_t *xdfo, long flags) {
	struct group g, go;
	long earliest_end, end_matching_other;
	long groupsize;
	unsigned int blank_lines;

	group_init(xdf, &g);
	group_init(xdfo, &go);

	while (1) {
		/* If the group is empty in the to-be-compacted file, skip it: */
		if (g.end == g.start)
			goto next;

		/*
		 * Now shift the change up and then down as far as possible in
		 * each direction. If it bumps into any other changes, merge them.
		 */
		do {
			groupsize = g.end - g.start;

			/*
			 * Keep track of the last "end" index that causes this
			 * group to align with a group of changed lines in the
			 * other file. -1 indicates that we haven't found such
			 * a match yet:
			 */
			end_matching_other = -1;

			/*
			 * Boolean value that records whether there are any blank
			 * lines that could be made to be the last line of this
			 * group.
			 */
			blank_lines = 0;

			/* Shift the group backward as much as possible: */
			while (!group_slide_up(xdf, &g, flags))
				if (group_previous(xdfo, &go))
					xdl_bug("group sync broken sliding up");

			/*
			 * This is this highest that this group can be shifted.
			 * Record its end index:
			 */
			earliest_end = g.end;

			if (go.end > go.start)
				end_matching_other = g.end;

			/* Now shift the group forward as far as possible: */
			while (1) {
				if (!blank_lines)
					blank_lines = is_blank_line(
							xdf->recs[g.end - 1],
							flags);

				if (group_slide_down(xdf, &g, flags))
					break;
				if (group_next(xdfo, &go))
					xdl_bug("group sync broken sliding down");

				if (go.end > go.start)
					end_matching_other = g.end;
			}
		} while (groupsize != g.end - g.start);

		if (g.end == earliest_end) {
			/* no shifting was possible */
		} else if (end_matching_other != -1) {
			/*
			 * Move the possibly merged group of changes back to line
			 * up with the last group of changes from the other file
			 * that it can align with.
			 */
			while (go.end == go.start) {
				if (group_slide_up(xdf, &g, flags))
					xdl_bug("match disappeared");
				if (group_previous(xdfo, &go))
					xdl_bug("group sync broken sliding to match");
			}
		} else if ((flags & XDF_COMPACTION_HEURISTIC) && blank_lines) {
			/*
			 * Compaction heuristic: if it is possible to shift the
			 * group to make its bottom line a blank line, do so.
			 *
			 * As we already shifted the group forward as far as
			 * possible in the earlier loop, we only need to handle
			 * backward shifts, not forward ones.
			 */
			while (!is_blank_line(xdf->recs[g.end - 1], flags)) {
				if (group_slide_up(xdf, &g, flags))
					xdl_bug("blank line disappeared");
				if (group_previous(xdfo, &go))
					xdl_bug("group sync broken sliding to blank line");
			}
		}

	next:
		/* Move past the just-processed group: */
		if (group_next(xdf, &g))
			break;
		if (group_next(xdfo, &go))
			xdl_bug("group sync broken moving to next group");
	}

	if (!group_next(xdfo, &go))
		xdl_bug("group sync broken at end of file");

	return 0;
}
