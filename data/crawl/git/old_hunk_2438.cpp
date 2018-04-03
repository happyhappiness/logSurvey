			if (!(object->flags & (CLIENT_SHALLOW|NOT_SHALLOW))) {
				packet_write(1, "shallow %s",
						oid_to_hex(&object->oid));
				register_shallow(get_object_hash(*object));
				shallow_nr++;
			}
			result = result->next;
