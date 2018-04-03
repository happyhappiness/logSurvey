	    continue;
	if (strcmp(entry->name, "comment") == 0)
	    continue;
	fprintf(fp, "\tfree_%s(&%s);\n", entry->type, entry->loc);
    }
    fprintf(fp, "}\n\n");
}
