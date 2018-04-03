 			nr_deltas++;
 			if (entry->type < 0)
 				die("unable to get type of object %s",
-				    sha1_to_hex(entry->idx.sha1));
+				    oid_to_hex(&entry->idx.oid));
 		} else {
 			if (entry->type < 0) {
 				/*
