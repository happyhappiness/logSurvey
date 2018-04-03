			if (!packlist_find(&to_pack, oid.hash, NULL) &&
			    !has_sha1_pack_kept_or_nonlocal(&oid) &&
			    !loosened_object_can_be_discarded(&oid, p->mtime))
				if (force_object_loose(oid.hash, p->mtime))
					die("unable to force loose object");
		}
	}
