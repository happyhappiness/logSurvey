	/* Output the replacement string.  */
	o = variable_buffer_output (o, replace, rlen);

      /* Advance T past the string to be replaced; adjust tlen.  */
      {
        char *nt = p + slen;
        tlen -= nt - t;
        t = nt;
      }
    } while (*t != '\0');
