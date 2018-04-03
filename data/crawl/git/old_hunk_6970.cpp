			fprintf(stderr, "warning: ref '%s' ignored\n", ref);
			continue;
		}
		if (!path_list_has_path(&existing_refs, ref)) {
			printf("%s\n", buf);
		}
	}
