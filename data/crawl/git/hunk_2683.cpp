 			"[new branch]"),
 			ref, ref->peer_ref, NULL, porcelain);
 	else {
-		char quickref[84];
+		struct strbuf quickref = STRBUF_INIT;
 		char type;
 		const char *msg;
 
-		strcpy(quickref, status_abbrev(ref->old_sha1));
+		strbuf_addstr(&quickref, status_abbrev(ref->old_sha1));
 		if (ref->forced_update) {
-			strcat(quickref, "...");
+			strbuf_addstr(&quickref, "...");
 			type = '+';
 			msg = "forced update";
 		} else {
-			strcat(quickref, "..");
+			strbuf_addstr(&quickref, "..");
 			type = ' ';
 			msg = NULL;
 		}
-		strcat(quickref, status_abbrev(ref->new_sha1));
+		strbuf_addstr(&quickref, status_abbrev(ref->new_sha1));
 
-		print_ref_status(type, quickref, ref, ref->peer_ref, msg, porcelain);
+		print_ref_status(type, quickref.buf, ref, ref->peer_ref, msg, porcelain);
+		strbuf_release(&quickref);
 	}
 }
 