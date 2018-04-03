			continue;
		}

		if (!check_ref(name, flags))
			continue;
		ref = alloc_ref(buffer + GIT_SHA1_HEXSZ + 1);
		oidcpy(&ref->old_oid, &old_oid);
		*list = ref;
