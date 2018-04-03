 		if (!*ref->name)
 			die("cannot fetch by sha1 over smart http");
 		packet_buf_write(&preamble, "%s %s\n",
-				 sha1_to_hex(ref->old_sha1), ref->name);
+				 oid_to_hex(&ref->old_oid), ref->name);
 	}
 	packet_buf_flush(&preamble);
 
