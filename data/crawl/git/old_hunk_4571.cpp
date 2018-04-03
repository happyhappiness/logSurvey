	}
	fclose(fp);
	rerere(allow_rerere_auto);
	printf("Automatic merge failed; "
			"fix conflicts and then commit the result.\n");
	return 1;
}

