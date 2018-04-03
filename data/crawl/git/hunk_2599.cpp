 			if (!(object->flags & (CLIENT_SHALLOW|NOT_SHALLOW))) {
 				packet_write(1, "shallow %s",
 						sha1_to_hex(object->sha1));
-				register_shallow(object->sha1);
+				register_shallow(get_object_hash(*object));
 				shallow_nr++;
 			}
 			result = result->next;
