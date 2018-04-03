 	}
 
 	entry->type = sha1_object_info(entry->idx.sha1, &entry->size);
-	if (entry->type < 0)
-		die("unable to get type of object %s",
-		    sha1_to_hex(entry->idx.sha1));
+	/*
+	 * The error condition is checked in prepare_pack().  This is
+	 * to permit a missing preferred base object to be ignored
+	 * as a preferred base.  Doing so can result in a larger
+	 * pack file, but the transfer will still take place.
+	 */
 }
 
 static int pack_offset_sort(const void *_a, const void *_b)
