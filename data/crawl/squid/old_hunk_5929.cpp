		);
	} else {
	    fprintf(fp,
		"\t\tparse_%s(&%s);\n",
		entry->type, entry->loc
		);
	}
	if (entry->ifdef)
