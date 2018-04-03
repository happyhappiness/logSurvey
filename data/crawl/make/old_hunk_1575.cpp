		}
	  }

	  if (p - buf >= 30)
	    {
	      fprintf (stderr, "%s\n", buf);
	      buf[0] = '\0';
	    }

	  fprintf (stderr, "%-30s%s.\n", buf, cs->description);
	}

      die (1);
