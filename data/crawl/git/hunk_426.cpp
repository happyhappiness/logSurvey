 	int blamed_lines;
 };
 
-static int diff_hunks(mmfile_t *file_a, mmfile_t *file_b,
-		      xdl_emit_hunk_consume_func_t hunk_func, void *cb_data, int xdl_opts)
-{
-	xpparam_t xpp = {0};
-	xdemitconf_t xecfg = {0};
-	xdemitcb_t ecb = {NULL};
-
-	xpp.flags = xdl_opts;
-	xecfg.hunk_func = hunk_func;
-	ecb.priv = cb_data;
-	return xdi_diff(file_a, file_b, &xpp, &xecfg, &ecb);
-}
-
-/*
- * Given an origin, prepare mmfile_t structure to be used by the
- * diff machinery
- */
-static void fill_origin_blob(struct diff_options *opt,
-			     struct blame_origin *o, mmfile_t *file, int *num_read_blob)
-{
-	if (!o->file.ptr) {
-		enum object_type type;
-		unsigned long file_size;
-
-		(*num_read_blob)++;
-		if (DIFF_OPT_TST(opt, ALLOW_TEXTCONV) &&
-		    textconv_object(o->path, o->mode, &o->blob_oid, 1, &file->ptr, &file_size))
-			;
-		else
-			file->ptr = read_sha1_file(o->blob_oid.hash, &type,
-						   &file_size);
-		file->size = file_size;
-
-		if (!file->ptr)
-			die("Cannot read blob %s for path %s",
-			    oid_to_hex(&o->blob_oid),
-			    o->path);
-		o->file = *file;
-	}
-	else
-		*file = o->file;
-}
-
-static void drop_origin_blob(struct blame_origin *o)
-{
-	if (o->file.ptr) {
-		free(o->file.ptr);
-		o->file.ptr = NULL;
-	}
-}
-
-/*
- * Any merge of blames happens on lists of blames that arrived via
- * different parents in a single suspect.  In this case, we want to
- * sort according to the suspect line numbers as opposed to the final
- * image line numbers.  The function body is somewhat longish because
- * it avoids unnecessary writes.
- */
-
-static struct blame_entry *blame_merge(struct blame_entry *list1,
-				       struct blame_entry *list2)
-{
-	struct blame_entry *p1 = list1, *p2 = list2,
-		**tail = &list1;
-
-	if (!p1)
-		return p2;
-	if (!p2)
-		return p1;
-
-	if (p1->s_lno <= p2->s_lno) {
-		do {
-			tail = &p1->next;
-			if ((p1 = *tail) == NULL) {
-				*tail = p2;
-				return list1;
-			}
-		} while (p1->s_lno <= p2->s_lno);
-	}
-	for (;;) {
-		*tail = p2;
-		do {
-			tail = &p2->next;
-			if ((p2 = *tail) == NULL)  {
-				*tail = p1;
-				return list1;
-			}
-		} while (p1->s_lno > p2->s_lno);
-		*tail = p1;
-		do {
-			tail = &p1->next;
-			if ((p1 = *tail) == NULL) {
-				*tail = p2;
-				return list1;
-			}
-		} while (p1->s_lno <= p2->s_lno);
-	}
-}
-
-static void *get_next_blame(const void *p)
-{
-	return ((struct blame_entry *)p)->next;
-}
-
-static void set_next_blame(void *p1, void *p2)
-{
-	((struct blame_entry *)p1)->next = p2;
-}
-
-/*
- * Final image line numbers are all different, so we don't need a
- * three-way comparison here.
- */
-
-static int compare_blame_final(const void *p1, const void *p2)
-{
-	return ((struct blame_entry *)p1)->lno > ((struct blame_entry *)p2)->lno
-		? 1 : -1;
-}
-
-static int compare_blame_suspect(const void *p1, const void *p2)
-{
-	const struct blame_entry *s1 = p1, *s2 = p2;
-	/*
-	 * to allow for collating suspects, we sort according to the
-	 * respective pointer value as the primary sorting criterion.
-	 * The actual relation is pretty unimportant as long as it
-	 * establishes a total order.  Comparing as integers gives us
-	 * that.
-	 */
-	if (s1->suspect != s2->suspect)
-		return (intptr_t)s1->suspect > (intptr_t)s2->suspect ? 1 : -1;
-	if (s1->s_lno == s2->s_lno)
-		return 0;
-	return s1->s_lno > s2->s_lno ? 1 : -1;
-}
-
 static int compare_commits_by_reverse_commit_date(const void *a,
 						  const void *b,
 						  void *c)
 {
 	return -compare_commits_by_commit_date(a, b, c);
 }
 
-static void blame_sort_final(struct blame_scoreboard *sb)
-{
-	sb->ent = llist_mergesort(sb->ent, get_next_blame, set_next_blame,
-				  compare_blame_final);
-}
-
-static void sanity_check_refcnt(struct blame_scoreboard *);
-
-/*
- * If two blame entries that are next to each other came from
- * contiguous lines in the same origin (i.e. <commit, path> pair),
- * merge them together.
- */
-static void blame_coalesce(struct blame_scoreboard *sb)
-{
-	struct blame_entry *ent, *next;
-
-	for (ent = sb->ent; ent && (next = ent->next); ent = next) {
-		if (ent->suspect == next->suspect &&
-		    ent->s_lno + ent->num_lines == next->s_lno) {
-			ent->num_lines += next->num_lines;
-			ent->next = next->next;
-			blame_origin_decref(next->suspect);
-			free(next);
-			ent->score = 0;
-			next = ent; /* again */
-		}
-	}
-
-	if (sb->debug) /* sanity */
-		sanity_check_refcnt(sb);
-}
-
-/*
- * Merge the given sorted list of blames into a preexisting origin.
- * If there were no previous blames to that commit, it is entered into
- * the commit priority queue of the score board.
- */
-
-static void queue_blames(struct blame_scoreboard *sb, struct blame_origin *porigin,
-			 struct blame_entry *sorted)
-{
-	if (porigin->suspects)
-		porigin->suspects = blame_merge(porigin->suspects, sorted);
-	else {
-		struct blame_origin *o;
-		for (o = porigin->commit->util; o; o = o->next) {
-			if (o->suspects) {
-				porigin->suspects = sorted;
-				return;
-			}
-		}
-		porigin->suspects = sorted;
-		prio_queue_put(&sb->commits, porigin->commit);
-	}
-}
-
 /*
  * Fill the blob_sha1 field of an origin if it hasn't, so that later
  * call to fill_origin_blob() can use it to locate the data.  blob_sha1
