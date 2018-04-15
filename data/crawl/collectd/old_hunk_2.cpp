	 if (strcmp ($1.key, $3) != 0)
	 {
		printf ("block_begin = %s; block_end = %s;\n", $1.key, $3);
	 	yyerror ("Block not closed..\n");
		exit (1);
	 }
	 free ($3); $3 = NULL;
	 $$ = $1;
