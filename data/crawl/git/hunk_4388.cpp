 		reset_timeout();
 
 		if (!len) {
+			if (multi_ack == 2 && got_common
+			    && !got_other && ok_to_give_up())
+				packet_write(1, "ACK %s ready\n", last_hex);
 			if (have_obj.nr == 0 || multi_ack)
 				packet_write(1, "NAK\n");
 			if (stateless_rpc)
 				exit(0);
+			got_common = 0;
+			got_other = 0;
 			continue;
 		}
 		strip(line, len);
 		if (!prefixcmp(line, "have ")) {
 			switch (got_sha1(line+5, sha1)) {
 			case -1: /* they have what we do not */
+				got_other = 1;
 				if (multi_ack && ok_to_give_up()) {
 					const char *hex = sha1_to_hex(sha1);
 					if (multi_ack == 2)
