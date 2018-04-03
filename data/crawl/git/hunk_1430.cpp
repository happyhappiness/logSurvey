 	o->ancestor = "merged common ancestors";
 	clean = merge_trees(o, h1->tree, h2->tree, merged_common_ancestors->tree,
 			    &mrtree);
+	if (clean < 0) {
+		flush_output(o);
+		return clean;
+	}
 
 	if (o->call_depth) {
 		*result = make_virtual_commit(mrtree, "merged tree");
 		commit_list_insert(h1, &(*result)->parents);
 		commit_list_insert(h2, &(*result)->parents->next);
 	}
 	flush_output(o);
+	if (!o->call_depth && o->buffer_output < 2)
+		strbuf_release(&o->obuf);
 	if (show(o, 2))
 		diff_warn_rename_limit("merge.renamelimit",
 				       o->needed_rename_limit, 0);
 	return clean;
 }
 
-static struct commit *get_ref(const unsigned char *sha1, const char *name)
+static struct commit *get_ref(const struct object_id *oid, const char *name)
 {
 	struct object *object;
 
-	object = deref_tag(parse_object(sha1), name, strlen(name));
+	object = deref_tag(parse_object(oid->hash), name, strlen(name));
 	if (!object)
 		return NULL;
 	if (object->type == OBJ_TREE)
