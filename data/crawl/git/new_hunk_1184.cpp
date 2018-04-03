			continue;
		}

		if (!strcmp(name, "capabilities^{}")) {
			if (saw_response)
				die("protocol error: unexpected capabilities^{}");
			if (got_dummy_ref_with_capabilities_declaration)
				die("protocol error: multiple capabilities^{}");
			got_dummy_ref_with_capabilities_declaration = 1;
			continue;
		}

		if (!check_ref(name, flags))
			continue;

		if (got_dummy_ref_with_capabilities_declaration)
			die("protocol error: unexpected ref after capabilities^{}");

		ref = alloc_ref(buffer + GIT_SHA1_HEXSZ + 1);
		oidcpy(&ref->old_oid, &old_oid);
		*list = ref;
