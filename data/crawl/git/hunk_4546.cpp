 		strcpy(hex, find_unique_abbrev(head, DEFAULT_ABBREV));
 
 		if (verbosity >= 0)
-			printf("Updating %s..%s\n",
+			printf(_("Updating %s..%s\n"),
 				hex,
 				find_unique_abbrev(remoteheads->item->object.sha1,
 				DEFAULT_ABBREV));
