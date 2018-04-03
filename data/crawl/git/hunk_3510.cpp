 			continue;
 		}
 
-		o = deref_tag(parse_object(sha1), *argv, 0);
-		if (!o || o->type != OBJ_COMMIT) {
-			fprintf(stderr, "Could not get commit for %s. Skipping.\n",
+		commit = NULL;
+		object = parse_object(sha1);
+		if (object) {
+			struct object *peeled = deref_tag(object, *argv, 0);
+			if (peeled && peeled->type == OBJ_COMMIT)
+				commit = (struct commit *)peeled;
+		}
+
+		if (!object) {
+			fprintf(stderr, "Could not get object for %s. Skipping.\n",
 					*argv);
 			continue;
 		}
 
-		commit = (struct commit *)o;
-		if (cutoff > commit->date)
-			cutoff = commit->date;
-		add_object_array((struct object *)commit, *argv, &revs);
+		if (commit) {
+			if (cutoff > commit->date)
+				cutoff = commit->date;
+		}
+		add_object_array(object, *argv, &revs);
 	}
 
 	if (cutoff)
