 		}
 		else
 			printf("[%s] ",
-			       find_unique_abbrev(get_object_hash(commit->object),
+			       find_unique_abbrev(commit->object.oid.hash,
 						  DEFAULT_ABBREV));
 	}
 	puts(pretty_str);
