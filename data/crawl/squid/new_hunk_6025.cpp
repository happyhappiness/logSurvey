		free(line->data);
		free(line);
	    }
	    blank = 1;
	}
	if (entry->nocomment && blank)
	    fprintf(fp, "#\n");
