 			continue;
 		}
 
-		if (delete_ref(name, sha1)) {
+		if (delete_ref(name, sha1, 0)) {
 			error("Error deleting %sbranch '%s'", remote,
 			       argv[i]);
 			ret = 1;
