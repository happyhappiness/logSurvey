			}
		}
		hashcpy(ref->new_sha1, ref->peer_ref->new_sha1);
		if (is_zero_sha1(ref->new_sha1)) {
			error("cannot happen anymore");
			rc = -3;
			continue;
		}
		new_refs++;
		strcpy(old_hex, sha1_to_hex(ref->old_sha1));
		new_hex = sha1_to_hex(ref->new_sha1);