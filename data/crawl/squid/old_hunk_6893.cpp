	assert(entry->loc);
	if (entry->default_if_none == NULL)
	    continue;
	fprintf(fp,
	    "\tif (check_null_%s(%s))\n"
	    "\t\tdefault_line(\"%s %s\");\n",
	    entry->type,
	    entry->loc,
	    entry->name,
	    entry->default_if_none);
    }
    fprintf(fp, "}\n\n");
}
