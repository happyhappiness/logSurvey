		}
		else
			printf("[%s] ",
			       find_unique_abbrev(get_object_hash(commit->object),
						  DEFAULT_ABBREV));
	}
	puts(pretty_str);
