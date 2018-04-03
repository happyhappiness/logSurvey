	 * answer, as it may have been deleted since the index was
	 * loaded!
	 */
	if (!is_pack_valid(p)) {
		warning("packfile %s cannot be accessed", p->pack_name);
		return 0;
	}
	e->offset = offset;
	e->p = p;
	hashcpy(e->sha1, sha1);