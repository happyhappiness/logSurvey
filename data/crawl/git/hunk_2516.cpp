 		struct ewah_bitmap *bm = lookup_stored_bitmap(st);
 
 		fprintf(stderr, "Found bitmap for %s. %d bits / %08x checksum\n",
-			sha1_to_hex(root->sha1), (int)bm->bit_size, ewah_checksum(bm));
+			oid_to_hex(&root->oid), (int)bm->bit_size, ewah_checksum(bm));
 
 		result = ewah_to_bitmap(bm);
 	}
 
 	if (result == NULL)
-		die("Commit %s doesn't have an indexed bitmap", sha1_to_hex(root->sha1));
+		die("Commit %s doesn't have an indexed bitmap", oid_to_hex(&root->oid));
 
 	revs->tag_objects = 1;
 	revs->tree_objects = 1;
