	}
}

/*
 * C-style name quoting.
 *
 * Does one of three things:
 *
 * (1) if outbuf and outfp are both NULL, inspect the input name and
 *     counts the number of bytes that are needed to hold c_style
 *     quoted version of name, counting the double quotes around
 *     it but not terminating NUL, and returns it.  However, if name
 *     does not need c_style quoting, it returns 0.
 *
 * (2) if outbuf is not NULL, it must point at a buffer large enough
 *     to hold the c_style quoted version of name, enclosing double
 *     quotes, and terminating NUL.  Fills outbuf with c_style quoted
 *     version of name enclosed in double-quote pair.  Return value
 *     is undefined.
 *
 * (3) if outfp is not NULL, outputs c_style quoted version of name,
 *     but not enclosed in double-quote pair.  Return value is undefined.
 */

static int quote_c_style_counted(const char *name, int namelen,
				 char *outbuf, FILE *outfp, int no_dq)
{
#undef EMIT
#define EMIT(c) \
	(outbuf ? (*outbuf++ = (c)) : outfp ? fputc(c, outfp) : (count++))

#define EMITQ() EMIT('\\')

	const char *sp;
	unsigned char ch;
	int count = 0, needquote = 0;

	if (!no_dq)
		EMIT('"');
	for (sp = name; sp < name + namelen; sp++) {
		ch = *sp;
		if (!ch)
			break;
		if ((ch < ' ') || (ch == '"') || (ch == '\\') ||
		    (quote_path_fully && (ch >= 0177))) {
			needquote = 1;
			switch (ch) {
			case '\a': EMITQ(); ch = 'a'; break;
			case '\b': EMITQ(); ch = 'b'; break;
			case '\f': EMITQ(); ch = 'f'; break;
			case '\n': EMITQ(); ch = 'n'; break;
			case '\r': EMITQ(); ch = 'r'; break;
			case '\t': EMITQ(); ch = 't'; break;
			case '\v': EMITQ(); ch = 'v'; break;

			case '\\': /* fallthru */
			case '"': EMITQ(); break;
			default:
				/* octal */
				EMITQ();
				EMIT(((ch >> 6) & 03) + '0');
				EMIT(((ch >> 3) & 07) + '0');
				ch = (ch & 07) + '0';
				break;
			}
		}
		EMIT(ch);
	}
	if (!no_dq)
		EMIT('"');
	if (outbuf)
		*outbuf = 0;

	return needquote ? count : 0;
}

int quote_c_style(const char *name, char *outbuf, FILE *outfp, int no_dq)
{
	int cnt = strlen(name);
	return quote_c_style_counted(name, cnt, outbuf, outfp, no_dq);
}

/*
