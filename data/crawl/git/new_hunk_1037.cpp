		while (result) {
			struct object *object = &result->item->object;
			if (!(object->flags & (CLIENT_SHALLOW|NOT_SHALLOW))) {
				packet_write_fmt(1, "shallow %s",
						oid_to_hex(&object->oid));
				register_shallow(object->oid.hash);
				shallow_nr++;
