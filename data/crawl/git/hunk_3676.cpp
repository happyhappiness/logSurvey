 		return 0;
 	}
 
-	len = snprintf(line, sizeof(line), "%s %s\n",
-		       sha1_to_hex(entry->u.value.sha1), entry->name);
-	/* this should not happen but just being defensive */
-	if (len > sizeof(line))
-		die("too long a refname '%s'", entry->name);
-	write_or_die(*fd, line, len);
-	if (!peel_entry(entry)) {
-		/* This reference could be peeled; write the peeled value: */
-		if (snprintf(line, sizeof(line), "^%s\n",
-			     sha1_to_hex(entry->u.value.peeled)) !=
-		    PEELED_LINE_LENGTH)
-			die("internal error");
-		write_or_die(*fd, line, PEELED_LINE_LENGTH);
-	}
+	peel_status = peel_entry(entry);
+	write_packed_entry(*fd, entry->name, entry->u.value.sha1,
+			   peel_status == PEEL_PEELED ?
+			   entry->u.value.peeled : NULL);
 
 	return 0;
 }