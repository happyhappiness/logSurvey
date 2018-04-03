 				ofs += 1;
 				if (!ofs || MSB(ofs, 7))
 					die("delta base offset overflow in pack for %s",
-					    sha1_to_hex(entry->sha1));
+					    sha1_to_hex(entry->idx.sha1));
 				c = buf[used_0++];
 				ofs = (ofs << 7) + (c & 127);
 			}
 			if (ofs >= entry->in_pack_offset)
 				die("delta base offset out of bound for %s",
-				    sha1_to_hex(entry->sha1));
+				    sha1_to_hex(entry->idx.sha1));
 			ofs = entry->in_pack_offset - ofs;
 			if (!no_reuse_delta && !entry->preferred_base)
 				base_ref = find_packed_object_name(p, ofs);
