				continue;
		}
		if (check_ref_format(ref)) {
			fprintf(stderr, "warning: ref '%s' ignored\n", ref);
			continue;
		}
		if (!string_list_has_string(&existing_refs, ref)) {