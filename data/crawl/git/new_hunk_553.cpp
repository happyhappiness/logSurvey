			uint32_t offset = htonl(obj->offset);
			sha1write(f, &offset, 4);
		}
		sha1write(f, obj->oid.hash, 20);
		if ((opts->flags & WRITE_IDX_STRICT) &&
		    (i && !oidcmp(&list[-2]->oid, &obj->oid)))
			die("The same object %s appears twice in the pack",
			    oid_to_hex(&obj->oid));
	}

	if (index_version >= 2) {
