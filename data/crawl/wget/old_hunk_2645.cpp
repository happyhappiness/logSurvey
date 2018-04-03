      quote_char = *p;
      quote_flag = true;
      ++p;
      size -= 2;		/* disregard opening and closing quote */
    }
  putc (quote_char, fp);
  fputs (new_text, fp);
