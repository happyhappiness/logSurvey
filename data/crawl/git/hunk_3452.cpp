 	}
 	info->nr_ours = dst;
 }
+
+define_commit_slab(ref_bitmap, uint32_t *);
+
+struct paint_info {
+	struct ref_bitmap ref_bitmap;
+	unsigned nr_bits;
+	char **slab;
+	char *free, *end;
+	unsigned slab_count;
+};
+
+static uint32_t *paint_alloc(struct paint_info *info)
+{
+	unsigned nr = (info->nr_bits + 31) / 32;
+	unsigned size = nr * sizeof(uint32_t);
+	void *p;
+	if (!info->slab_count || info->free + size > info->end) {
+		info->slab_count++;
+		info->slab = xrealloc(info->slab,
+				      info->slab_count * sizeof(*info->slab));
+		info->free = xmalloc(COMMIT_SLAB_SIZE);
+		info->slab[info->slab_count - 1] = info->free;
+		info->end = info->free + COMMIT_SLAB_SIZE;
+	}
+	p = info->free;
+	info->free += size;
+	return p;
+}
+
+/*
+ * Given a commit SHA-1, walk down to parents until either SEEN,
+ * UNINTERESTING or BOTTOM is hit. Set the id-th bit in ref_bitmap for
+ * all walked commits.
+ */
+static void paint_down(struct paint_info *info, const unsigned char *sha1,
+		       int id)
+{
+	unsigned int i, nr;
+	struct commit_list *head = NULL;
+	int bitmap_nr = (info->nr_bits + 31) / 32;
+	int bitmap_size = bitmap_nr * sizeof(uint32_t);
+	uint32_t *tmp = xmalloc(bitmap_size); /* to be freed before return */
+	uint32_t *bitmap = paint_alloc(info);
+	struct commit *c = lookup_commit_reference_gently(sha1, 1);
+	if (!c)
+		return;
+	memset(bitmap, 0, bitmap_size);
+	bitmap[id / 32] |= (1 << (id % 32));
+	commit_list_insert(c, &head);
+	while (head) {
+		struct commit_list *p;
+		struct commit *c = head->item;
+		uint32_t **refs = ref_bitmap_at(&info->ref_bitmap, c);
+
+		p = head;
+		head = head->next;
+		free(p);
+
+		/* XXX check "UNINTERESTING" from pack bitmaps if available */
+		if (c->object.flags & (SEEN | UNINTERESTING))
+			continue;
+		else
+			c->object.flags |= SEEN;
+
+		if (*refs == NULL)
+			*refs = bitmap;
+		else {
+			memcpy(tmp, *refs, bitmap_size);
+			for (i = 0; i < bitmap_nr; i++)
+				tmp[i] |= bitmap[i];
+			if (memcmp(tmp, *refs, bitmap_size)) {
+				*refs = paint_alloc(info);
+				memcpy(*refs, tmp, bitmap_size);
+			}
+		}
+
+		if (c->object.flags & BOTTOM)
+			continue;
+
+		if (parse_commit(c))
+			die("unable to parse commit %s",
+			    sha1_to_hex(c->object.sha1));
+
+		for (p = c->parents; p; p = p->next) {
+			uint32_t **p_refs = ref_bitmap_at(&info->ref_bitmap,
+							  p->item);
+			if (p->item->object.flags & SEEN)
+				continue;
+			if (*p_refs == NULL || *p_refs == *refs)
+				*p_refs = *refs;
+			commit_list_insert(p->item, &head);
+		}
+	}
+
+	nr = get_max_object_index();
+	for (i = 0; i < nr; i++) {
+		struct object *o = get_indexed_object(i);
+		if (o && o->type == OBJ_COMMIT)
+			o->flags &= ~SEEN;
+	}
+
+	free(tmp);
+}
+
+static int mark_uninteresting(const char *refname,
+			      const unsigned char *sha1,
+			      int flags, void *cb_data)
+{
+	struct commit *commit = lookup_commit_reference_gently(sha1, 1);
+	if (!commit)
+		return 0;
+	commit->object.flags |= UNINTERESTING;
+	mark_parents_uninteresting(commit);
+	return 0;
+}
+
+static void post_assign_shallow(struct shallow_info *info,
+				struct ref_bitmap *ref_bitmap,
+				int *ref_status);
+/*
+ * Step 6(+7), associate shallow commits with new refs
+ *
+ * info->ref must be initialized before calling this function.
+ *
+ * If used is not NULL, it's an array of info->shallow->nr
+ * bitmaps. The n-th bit set in the m-th bitmap if ref[n] needs the
+ * m-th shallow commit from info->shallow.
+ *
+ * If used is NULL, "ours" and "theirs" are updated. And if ref_status
+ * is not NULL it's an array of ref->nr ints. ref_status[i] is true if
+ * the ref needs some shallow commits from either info->ours or
+ * info->theirs.
+ */
+void assign_shallow_commits_to_refs(struct shallow_info *info,
+				    uint32_t **used, int *ref_status)
+{
+	unsigned char (*sha1)[20] = info->shallow->sha1;
+	struct sha1_array *ref = info->ref;
+	unsigned int i, nr;
+	int *shallow, nr_shallow = 0;
+	struct paint_info pi;
+
+	trace_printf_key(TRACE_KEY, "shallow: assign_shallow_commits_to_refs\n");
+	shallow = xmalloc(sizeof(*shallow) * (info->nr_ours + info->nr_theirs));
+	for (i = 0; i < info->nr_ours; i++)
+		shallow[nr_shallow++] = info->ours[i];
+	for (i = 0; i < info->nr_theirs; i++)
+		shallow[nr_shallow++] = info->theirs[i];
+
+	/*
+	 * Prepare the commit graph to track what refs can reach what
+	 * (new) shallow commits.
+	 */
+	nr = get_max_object_index();
+	for (i = 0; i < nr; i++) {
+		struct object *o = get_indexed_object(i);
+		if (!o || o->type != OBJ_COMMIT)
+			continue;
+
+		o->flags &= ~(UNINTERESTING | BOTTOM | SEEN);
+	}
+
+	memset(&pi, 0, sizeof(pi));
+	init_ref_bitmap(&pi.ref_bitmap);
+	pi.nr_bits = ref->nr;
+
+	/*
+	 * "--not --all" to cut short the traversal if new refs
+	 * connect to old refs. If not (e.g. force ref updates) it'll
+	 * have to go down to the current shallow commits.
+	 */
+	head_ref(mark_uninteresting, NULL);
+	for_each_ref(mark_uninteresting, NULL);
+
+	/* Mark potential bottoms so we won't go out of bound */
+	for (i = 0; i < nr_shallow; i++) {
+		struct commit *c = lookup_commit(sha1[shallow[i]]);
+		c->object.flags |= BOTTOM;
+	}
+
+	for (i = 0; i < ref->nr; i++)
+		paint_down(&pi, ref->sha1[i], i);
+
+	if (used) {
+		int bitmap_size = ((pi.nr_bits + 31) / 32) * sizeof(uint32_t);
+		memset(used, 0, sizeof(*used) * info->shallow->nr);
+		for (i = 0; i < nr_shallow; i++) {
+			const struct commit *c = lookup_commit(sha1[shallow[i]]);
+			uint32_t **map = ref_bitmap_at(&pi.ref_bitmap, c);
+			if (*map)
+				used[shallow[i]] = xmemdupz(*map, bitmap_size);
+		}
+		/*
+		 * unreachable shallow commits are not removed from
+		 * "ours" and "theirs". The user is supposed to run
+		 * step 7 on every ref separately and not trust "ours"
+		 * and "theirs" any more.
+		 */
+	} else
+		post_assign_shallow(info, &pi.ref_bitmap, ref_status);
+
+	clear_ref_bitmap(&pi.ref_bitmap);
+	for (i = 0; i < pi.slab_count; i++)
+		free(pi.slab[i]);
+	free(pi.slab);
+	free(shallow);
+}
+
+struct commit_array {
+	struct commit **commits;
+	int nr, alloc;
+};
+
+static int add_ref(const char *refname,
+		   const unsigned char *sha1, int flags, void *cb_data)
+{
+	struct commit_array *ca = cb_data;
+	ALLOC_GROW(ca->commits, ca->nr + 1, ca->alloc);
+	ca->commits[ca->nr] = lookup_commit_reference_gently(sha1, 1);
+	if (ca->commits[ca->nr])
+		ca->nr++;
+	return 0;
+}
+
+static void update_refstatus(int *ref_status, int nr, uint32_t *bitmap)
+{
+	int i;
+	if (!ref_status)
+		return;
+	for (i = 0; i < nr; i++)
+		if (bitmap[i / 32] & (1 << (i % 32)))
+			ref_status[i]++;
+}
+
+/*
+ * Step 7, reachability test on "ours" at commit level
+ */
+static void post_assign_shallow(struct shallow_info *info,
+				struct ref_bitmap *ref_bitmap,
+				int *ref_status)
+{
+	unsigned char (*sha1)[20] = info->shallow->sha1;
+	struct commit *c;
+	uint32_t **bitmap;
+	int dst, i, j;
+	int bitmap_nr = (info->ref->nr + 31) / 32;
+	struct commit_array ca;
+
+	trace_printf_key(TRACE_KEY, "shallow: post_assign_shallow\n");
+	if (ref_status)
+		memset(ref_status, 0, sizeof(*ref_status) * info->ref->nr);
+
+	/* Remove unreachable shallow commits from "theirs" */
+	for (i = dst = 0; i < info->nr_theirs; i++) {
+		if (i != dst)
+			info->theirs[dst] = info->theirs[i];
+		c = lookup_commit(sha1[info->theirs[i]]);
+		bitmap = ref_bitmap_at(ref_bitmap, c);
+		if (!*bitmap)
+			continue;
+		for (j = 0; j < bitmap_nr; j++)
+			if (bitmap[0][j]) {
+				update_refstatus(ref_status, info->ref->nr, *bitmap);
+				dst++;
+				break;
+			}
+	}
+	info->nr_theirs = dst;
+
+	memset(&ca, 0, sizeof(ca));
+	head_ref(add_ref, &ca);
+	for_each_ref(add_ref, &ca);
+
+	/* Remove unreachable shallow commits from "ours" */
+	for (i = dst = 0; i < info->nr_ours; i++) {
+		if (i != dst)
+			info->ours[dst] = info->ours[i];
+		c = lookup_commit(sha1[info->ours[i]]);
+		bitmap = ref_bitmap_at(ref_bitmap, c);
+		if (!*bitmap)
+			continue;
+		for (j = 0; j < bitmap_nr; j++)
+			if (bitmap[0][j] &&
+			    /* Step 7, reachability test at commit level */
+			    !in_merge_bases_many(c, ca.nr, ca.commits)) {
+				update_refstatus(ref_status, info->ref->nr, *bitmap);
+				dst++;
+				break;
+			}
+	}
+	info->nr_ours = dst;
+
+	free(ca.commits);
+}