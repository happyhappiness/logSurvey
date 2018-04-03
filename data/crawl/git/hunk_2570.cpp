 		}
 		else
 			printf("[%s] ",
-			       find_unique_abbrev(commit->object.sha1,
+			       find_unique_abbrev(get_object_hash(commit->object),
 						  DEFAULT_ABBREV));
 	}
 	puts(pretty_str);
