 			continue;
 		}
 		if (line[0] == '-') {
-			if (get_sha1_hex(line+1, sha1))
-				die("expected edge sha1, got garbage:\n %s",
+			if (get_oid_hex(line+1, &oid))
+				die("expected edge object ID, got garbage:\n %s",
 				    line);
-			add_preferred_base(sha1);
+			add_preferred_base(&oid);
 			continue;
 		}
-		if (get_sha1_hex(line, sha1))
-			die("expected sha1, got garbage:\n %s", line);
+		if (parse_oid_hex(line, &oid, &p))
+			die("expected object ID, got garbage:\n %s", line);
 
-		add_preferred_base_object(line+41);
-		add_object_entry(sha1, 0, line+41, 0);
+		add_preferred_base_object(p + 1);
+		add_object_entry(&oid, 0, p + 1, 0);
 	}
 }
 
 #define OBJECT_ADDED (1u<<20)
 
 static void show_commit(struct commit *commit, void *data)
 {
-	add_object_entry(commit->object.oid.hash, OBJ_COMMIT, NULL, 0);
+	add_object_entry(&commit->object.oid, OBJ_COMMIT, NULL, 0);
 	commit->object.flags |= OBJECT_ADDED;
 
 	if (write_bitmap_index)
