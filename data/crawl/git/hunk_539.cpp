 				ofs += 1;
 				if (!ofs || MSB(ofs, 7)) {
 					error("delta base offset overflow in pack for %s",
-					      sha1_to_hex(entry->idx.sha1));
+					      oid_to_hex(&entry->idx.oid));
 					goto give_up;
 				}
 				c = buf[used_0++];
