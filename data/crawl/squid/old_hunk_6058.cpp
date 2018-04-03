	    continue;
	if (entry->ifdef)
	    fprintf(fp, "#if %s\n", entry->ifdef);
	fprintf(fp,
	    "\tif (check_null_%s(%s))\n"
	    "\t\tdefault_line(\"%s %s\");\n",
	    entry->type,
	    entry->loc,
	    entry->name,
	    entry->default_if_none);
	if (entry->ifdef)
	    fprintf(fp, "#endif\n");
    }
    fprintf(fp, "}\n\n");
}
