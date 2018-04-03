	 * anyway because we don't know if the error explanation part
	 * will be printed in update_local_ref)
	 */
	len = 21 /* flag and summary */ + rlen + 4 /* -> */ + llen;
	if (len >= max)
		return;

	if (refcol_width < rlen)
		refcol_width = rlen;
}

static void prepare_format_display(struct ref *ref_map)
{
	struct ref *rm;

	for (rm = ref_map; rm; rm = rm->next) {
		if (rm->status == REF_STATUS_REJECT_SHALLOW ||
