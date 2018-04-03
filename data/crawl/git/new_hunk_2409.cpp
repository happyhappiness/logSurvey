		}
		else
			printf("[%s] ",
			       find_unique_abbrev(commit->object.oid.hash,
						  DEFAULT_ABBREV));
	}
	puts(pretty_str);
