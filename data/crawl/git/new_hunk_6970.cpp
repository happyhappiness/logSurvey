			fprintf(stderr, "warning: ref '%s' ignored\n", ref);
			continue;
		}
		if (!string_list_has_string(&existing_refs, ref)) {
			printf("%s\n", buf);
		}
	}
