 		if (!prefixcmp(line, "have ")) {
 			switch (got_sha1(line+5, sha1)) {
 			case -1: /* they have what we do not */
-				if (multi_ack && ok_to_give_up())
-					packet_write(1, "ACK %s continue\n",
-						     sha1_to_hex(sha1));
+				if (multi_ack && ok_to_give_up()) {
+					const char *hex = sha1_to_hex(sha1);
+					if (multi_ack == 2)
+						packet_write(1, "ACK %s ready\n", hex);
+					else
+						packet_write(1, "ACK %s continue\n", hex);
+				}
 				break;
 			default:
-				memcpy(hex, sha1_to_hex(sha1), 41);
-				if (multi_ack) {
-					const char *msg = "ACK %s continue\n";
-					packet_write(1, msg, hex);
-					memcpy(last_hex, hex, 41);
-				}
+				memcpy(last_hex, sha1_to_hex(sha1), 41);
+				if (multi_ack == 2)
+					packet_write(1, "ACK %s common\n", last_hex);
+				else if (multi_ack)
+					packet_write(1, "ACK %s continue\n", last_hex);
 				else if (have_obj.nr == 1)
-					packet_write(1, "ACK %s\n", hex);
+					packet_write(1, "ACK %s\n", last_hex);
 				break;
 			}
 			continue;
