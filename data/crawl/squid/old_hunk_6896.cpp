	    continue;
	if (strcmp(entry->name, "comment") == 0)
	    continue;
	fprintf(fp, "\tdump_%s(entry, \"%s\", %s);\n",
	    entry->type,
	    entry->name,
	    entry->loc);
    }
    fprintf(fp, "}\n\n");
}
