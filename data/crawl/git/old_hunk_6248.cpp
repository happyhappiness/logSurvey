	return diff_flush_patch_id(options, sha1);
}

static uint32_t take2(const unsigned char *id)
{
	return ((id[0] << 8) | id[1]);
}

/*
 * Conventional binary search loop looks like this:
 *
 *      do {
 *              int mi = (lo + hi) / 2;
 *              int cmp = "entry pointed at by mi" minus "target";
 *              if (!cmp)
 *                      return (mi is the wanted one)
 *              if (cmp > 0)
 *                      hi = mi; "mi is larger than target"
 *              else
 *                      lo = mi+1; "mi is smaller than target"
 *      } while (lo < hi);
 *
 * The invariants are:
 *
 * - When entering the loop, lo points at a slot that is never
 *   above the target (it could be at the target), hi points at a
 *   slot that is guaranteed to be above the target (it can never
 *   be at the target).
 *
 * - We find a point 'mi' between lo and hi (mi could be the same
 *   as lo, but never can be the same as hi), and check if it hits
 *   the target.  There are three cases:
 *
 *    - if it is a hit, we are happy.
 *
 *    - if it is strictly higher than the target, we update hi with
 *      it.
 *
 *    - if it is strictly lower than the target, we update lo to be
 *      one slot after it, because we allow lo to be at the target.
 *
 * When choosing 'mi', we do not have to take the "middle" but
 * anywhere in between lo and hi, as long as lo <= mi < hi is
 * satisfied.  When we somehow know that the distance between the
 * target and lo is much shorter than the target and hi, we could
 * pick mi that is much closer to lo than the midway.
 */
static int patch_pos(struct patch_id **table, int nr, const unsigned char *id)
{
	int hi = nr;
	int lo = 0;
	int mi = 0;

	if (!nr)
		return -1;

	if (nr != 1) {
		unsigned lov, hiv, miv, ofs;

		for (ofs = 0; ofs < 18; ofs += 2) {
			lov = take2(table[0]->patch_id + ofs);
			hiv = take2(table[nr-1]->patch_id + ofs);
			miv = take2(id + ofs);
			if (miv < lov)
				return -1;
			if (hiv < miv)
				return -1 - nr;
			if (lov != hiv) {
				/*
				 * At this point miv could be equal
				 * to hiv (but id could still be higher);
				 * the invariant of (mi < hi) should be
				 * kept.
				 */
				mi = (nr-1) * (miv - lov) / (hiv - lov);
				if (lo <= mi && mi < hi)
					break;
				die("oops");
			}
		}
		if (18 <= ofs)
			die("cannot happen -- lo and hi are identical");
	}

	do {
		int cmp;
		cmp = hashcmp(table[mi]->patch_id, id);
		if (!cmp)
			return mi;
		if (cmp > 0)
			hi = mi;
		else
			lo = mi + 1;
		mi = (hi + lo) / 2;
	} while (lo < hi);
	return -lo-1;
}

#define BUCKET_SIZE 190 /* 190 * 21 = 3990, with slop close enough to 4K */
