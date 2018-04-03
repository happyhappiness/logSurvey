		entry->array_flag ? "[0]" : ""
		);
	}
	if (alias) {
	    name = alias->name;
	    alias = alias->next;
	    goto next_alias;
	}
	if (entry->ifdef)
	    fprintf(fp, "#endif\n");
    }

    fprintf(fp,
	"\telse\n"
	"\t\tresult = 0; /* failure */\n"
	"\treturn(result);\n"
	"}\n\n"
	);
}