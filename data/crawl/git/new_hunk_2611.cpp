		if (posn->symref)
			printf("@%s %s\n", posn->symref, posn->name);
		else
			printf("%s %s\n", oid_to_hex(&posn->old_oid), posn->name);
	}
	printf("\n");
	fflush(stdout);