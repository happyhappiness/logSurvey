	;

%%
static void yyerror(const char *s)
{
	const char *text;

	if (yytext == NULL)
		text = "<empty>";
	else if (*yytext == '\n')
		text = "<newline>";
	else
		text = yytext;

	fprintf(stderr, "Parse error in file `%s', line %i near `%s': %s\n",
		c_file, yylineno, text, s);
} /* int yyerror */

static char *unquote (const char *orig)