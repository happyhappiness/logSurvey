 	 * resolving deltas in the same order as their position in the pack.
 	 */
 	sorted_by_pos = xmalloc(nr_unresolved * sizeof(*sorted_by_pos));
-	for (i = 0; i < nr_deltas; i++) {
-		if (objects[deltas[i].obj_no].real_type != OBJ_REF_DELTA)
-			continue;
-		sorted_by_pos[n++] = &deltas[i];
-	}
+	for (i = 0; i < nr_ref_deltas; i++)
+		sorted_by_pos[n++] = &ref_deltas[i];
 	qsort(sorted_by_pos, n, sizeof(*sorted_by_pos), delta_pos_compare);
 
 	for (i = 0; i < n; i++) {
-		struct delta_entry *d = sorted_by_pos[i];
+		struct ref_delta_entry *d = sorted_by_pos[i];
 		enum object_type type;
 		struct base_data *base_obj = alloc_base_data();
 
 		if (objects[d->obj_no].real_type != OBJ_REF_DELTA)
 			continue;
-		base_obj->data = read_sha1_file(d->base.sha1, &type, &base_obj->size);
+		base_obj->data = read_sha1_file(d->sha1, &type, &base_obj->size);
 		if (!base_obj->data)
 			continue;
 
-		if (check_sha1_signature(d->base.sha1, base_obj->data,
+		if (check_sha1_signature(d->sha1, base_obj->data,
 				base_obj->size, typename(type)))
-			die(_("local object %s is corrupt"), sha1_to_hex(d->base.sha1));
-		base_obj->obj = append_obj_to_pack(f, d->base.sha1,
+			die(_("local object %s is corrupt"), sha1_to_hex(d->sha1));
+		base_obj->obj = append_obj_to_pack(f, d->sha1,
 					base_obj->data, base_obj->size, type);
 		find_unresolved_deltas(base_obj);
 		display_progress(progress, nr_resolved_deltas);
