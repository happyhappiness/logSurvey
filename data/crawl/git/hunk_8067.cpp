 	}
 }
 
+#define OBJECT_ADDED (1u<<20)
+
 static void show_commit(struct commit *commit)
 {
 	add_object_entry(commit->object.sha1, OBJ_COMMIT, NULL, 0);
+	commit->object.flags |= OBJECT_ADDED;
 }
 
 static void show_object(struct object_array_entry *p)
 {
 	add_preferred_base_object(p->name);
 	add_object_entry(p->item->sha1, p->item->type, p->name, 0);
+	p->item->flags |= OBJECT_ADDED;
 }
 
 static void show_edge(struct commit *commit)
 {
 	add_preferred_base(commit->object.sha1);
 }
 
+struct in_pack_object {
+	off_t offset;
+	struct object *object;
+};
+
+struct in_pack {
+	int alloc;
+	int nr;
+	struct in_pack_object *array;
+};
+
+static void mark_in_pack_object(struct object *object, struct packed_git *p, struct in_pack *in_pack)
+{
+	in_pack->array[in_pack->nr].offset = find_pack_entry_one(object->sha1, p);
+	in_pack->array[in_pack->nr].object = object;
+	in_pack->nr++;
+}
+
+/*
+ * Compare the objects in the offset order, in order to emulate the
+ * "git-rev-list --objects" output that produced the pack originally.
+ */
+static int ofscmp(const void *a_, const void *b_)
+{
+	struct in_pack_object *a = (struct in_pack_object *)a_;
+	struct in_pack_object *b = (struct in_pack_object *)b_;
+
+	if (a->offset < b->offset)
+		return -1;
+	else if (a->offset > b->offset)
+		return 1;
+	else
+		return hashcmp(a->object->sha1, b->object->sha1);
+}
+
+static void add_objects_in_unpacked_packs(struct rev_info *revs)
+{
+	struct packed_git *p;
+	struct in_pack in_pack;
+	uint32_t i;
+
+	memset(&in_pack, 0, sizeof(in_pack));
+
+	for (p = packed_git; p; p = p->next) {
+		const unsigned char *sha1;
+		struct object *o;
+
+		for (i = 0; i < revs->num_ignore_packed; i++) {
+			if (matches_pack_name(p, revs->ignore_packed[i]))
+				break;
+		}
+		if (revs->num_ignore_packed <= i)
+			continue;
+		if (open_pack_index(p))
+			die("cannot open pack index");
+
+		ALLOC_GROW(in_pack.array,
+			   in_pack.nr + p->num_objects,
+			   in_pack.alloc);
+
+		for (i = 0; i < p->num_objects; i++) {
+			sha1 = nth_packed_object_sha1(p, i);
+			o = lookup_unknown_object(sha1);
+			if (!(o->flags & OBJECT_ADDED))
+				mark_in_pack_object(o, p, &in_pack);
+			o->flags |= OBJECT_ADDED;
+		}
+	}
+
+	if (in_pack.nr) {
+		qsort(in_pack.array, in_pack.nr, sizeof(in_pack.array[0]),
+		      ofscmp);
+		for (i = 0; i < in_pack.nr; i++) {
+			struct object *o = in_pack.array[i].object;
+			add_object_entry(o->sha1, o->type, "", 0);
+		}
+	}
+	free(in_pack.array);
+}
+
 static void get_object_list(int ac, const char **av)
 {
 	struct rev_info revs;
