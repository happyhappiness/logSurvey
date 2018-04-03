		"\t\tparse_%s();\n",
		entry->type
		);
	} else {
	    fprintf(fp,
		"\t\tparse_%s(&%s);\n",
		entry->type, entry->loc
