 		int zret = Z_OK;
 		readlen = read_istream(st, ibuf, sizeof(ibuf));
 		if (readlen == -1)
-			die(_("unable to read %s"), sha1_to_hex(sha1));
+			die(_("unable to read %s"), oid_to_hex(oid));
 
 		stream.next_in = ibuf;
 		stream.avail_in = readlen;
