      /* Check if the value is just whitespace.  */
      p = next_token (v->value);
      if (p != v->value && *p == '\0')
        /* All whitespace.  */
        printf ("$(subst ,,%s)", v->value);
      else if (v->recursive)
        fputs (v->value, stdout);
      else
        /* Double up dollar signs.  */
        for (p = v->value; *p != '\0'; ++p)
          {
            if (*p == '$')
              putchar ('$');
            putchar (*p);
          }
      putchar ('\n');
    }
}
