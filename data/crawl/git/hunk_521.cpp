 		if (parse_feature_request(features, "include-tag"))
 			use_include_tag = 1;
 
-		o = parse_object(sha1_buf);
+		o = parse_object(oid_buf.hash);
 		if (!o) {
 			packet_write_fmt(1,
 					 "ERR upload-pack: not our ref %s",
-					 sha1_to_hex(sha1_buf));
+					 oid_to_hex(&oid_buf));
 			die("git upload-pack: not our ref %s",
-			    sha1_to_hex(sha1_buf));
+			    oid_to_hex(&oid_buf));
 		}
 		if (!(o->flags & WANTED)) {
 			o->flags |= WANTED;