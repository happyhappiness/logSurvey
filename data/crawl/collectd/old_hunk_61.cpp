	 if (strcmp ($1.key, $2) != 0)
	 {
		printf ("block_begin = %s; block_end = %s;\n", $1.key, $2);
		yyerror ("Block not closed..\n");
		exit (1);
	 }
	 free ($2); $2 = NULL;
	 $$ = $1;
