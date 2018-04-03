	    fprintf(fp, "\t}\n");
	}
	if (entry->ifdef)
	    fprintf(fp, "#endif\n");
    }
    fprintf(fp, "}\n\n");
}
