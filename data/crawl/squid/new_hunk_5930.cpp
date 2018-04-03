	    continue;
	if (entry->ifdef)
	    fprintf(fp, "#if %s\n", entry->ifdef);
	fprintf(fp, "\tfree_%s(&%s%s);\n",
	    entry->type, entry->loc,
	    entry->array_flag ? "[0]" : "");
	if (entry->ifdef)
	    fprintf(fp, "#endif\n");
    }