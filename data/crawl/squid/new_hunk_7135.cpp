	assert(entry->name);
	if (entry->loc == NULL) {
	    fprintf(stderr, "NO LOCATION FOR %s\n", entry->name);
	    rc |= 1;
	    continue;
	}
	if (entry->default_value == NULL) {
	    fprintf(stderr, "NO DEFAULT FOR %s\n", entry->name);
	    rc |= 1;
	    continue;
	}
	assert(entry->default_value);
	if (strcmp(entry->default_value, "none") == 0) {
	    fprintf(fp, "\t/* No default for %s */\n", entry->name);
	} else {
	    fprintf(fp, "\tparse_line(\"%s %s\");\n",
		entry->name,
		entry->default_value);
	}
    }
    fprintf(fp, "}\n\n");
    return rc;
}

static void
