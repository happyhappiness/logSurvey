 		while (c & 128) {
 			base_offset += 1;
 			if (!base_offset || MSB(base_offset, 7))
-				die("offset value overflow for delta base object");
+				return 0;  /* overflow */
 			c = base_info[used++];
 			base_offset = (base_offset << 7) + (c & 127);
 		}
 		base_offset = delta_obj_offset - base_offset;
 		if (base_offset >= delta_obj_offset)
-			die("delta base offset out of bound");
+			return 0;  /* out of bound */
 		*curpos += used;
 	} else if (type == OBJ_REF_DELTA) {
 		/* The base entry _must_ be in the same pack */
 		base_offset = find_pack_entry_one(base_info, p);
-		if (!base_offset)
-			die("failed to find delta-pack base object %s",
-				sha1_to_hex(base_info));
 		*curpos += 20;
 	} else
 		die("I am totally screwed");
