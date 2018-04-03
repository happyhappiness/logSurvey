		entry->array_flag ? "[0]" : ""
		);
	}
	if (entry->ifdef)
	    fprintf(fp, "#endif\n");
    }