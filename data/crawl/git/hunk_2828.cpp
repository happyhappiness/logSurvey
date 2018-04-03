 		struct object *object;
 		struct object_context oc;
 		if (get_sha1_with_context(revs->def, 0, sha1, &oc))
-			die("bad default revision '%s'", revs->def);
+			diagnose_missing_default(revs->def);
 		object = get_reference(revs, revs->def, sha1, 0);
 		add_pending_object_with_mode(revs, object, revs->def, oc.mode);
 	}
