 			type = ' ';
 			msg = NULL;
 		}
-		strbuf_addstr(&quickref, status_abbrev(ref->new_sha1));
+		strbuf_addstr(&quickref, status_abbrev(ref->new_oid.hash));
 
 		print_ref_status(type, quickref.buf, ref, ref->peer_ref, msg, porcelain);
 		strbuf_release(&quickref);
