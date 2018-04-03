
  fprintf (usageto, _("Usage: %s [options] [target] ...\n"), program);

  fputs (_("Options:\n"), usageto);
  for (cs = switches; cs->c != '\0'; ++cs)
    {
      char buf[1024], shortarg[50], longarg[50], *p;

      if (!cs->description || cs->description[0] == '-')
	continue;

      switch (long_options[cs - switches].has_arg)
	{
	case no_argument:
	  shortarg[0] = longarg[0] = '\0';
	  break;
	case required_argument:
	  sprintf (longarg, "=%s", gettext (cs->argdesc));
	  sprintf (shortarg, " %s", gettext (cs->argdesc));
	  break;
	case optional_argument:
	  sprintf (longarg, "[=%s]", gettext (cs->argdesc));
	  sprintf (shortarg, " [%s]", gettext (cs->argdesc));
	  break;
	}

      p = buf;

      if (short_option (cs->c))
	{
	  sprintf (buf, "  -%c%s", cs->c, shortarg);
	  p += strlen (p);
	}
      if (cs->long_name != 0)
	{
	  unsigned int i;
	  sprintf (p, "%s--%s%s",
		   !short_option (cs->c) ? "  " : ", ",
		   cs->long_name, longarg);
	  p += strlen (p);
	  for (i = 0; i < (sizeof (long_option_aliases) /
			   sizeof (long_option_aliases[0]));
	       ++i)
	    if (long_option_aliases[i].val == cs->c)
	      {
		sprintf (p, ", --%s%s",
			 long_option_aliases[i].name, longarg);
		p += strlen (p);
	      }
	}
      {
	const struct command_switch *ncs = cs;
	while ((++ncs)->c != '\0')
	  if (ncs->description
              && ncs->description[0] == '-'
              && ncs->description[1] == cs->c)
	    {
	      /* This is another switch that does the same
		 one as the one we are processing.  We want
		 to list them all together on one line.  */
	      sprintf (p, ", -%c%s", ncs->c, shortarg);
	      p += strlen (p);
	      if (ncs->long_name != 0)
		{
		  sprintf (p, ", --%s%s", ncs->long_name, longarg);
		  p += strlen (p);
		}
	    }
      }

      if (p - buf > DESCRIPTION_COLUMN - 2)
	/* The list of option names is too long to fit on the same
	   line with the description, leaving at least two spaces.
	   Print it on its own line instead.  */
	{
	  fprintf (usageto, "%s\n", buf);
	  buf[0] = '\0';
	}

      fprintf (usageto, "%*s%s.\n",
	       - DESCRIPTION_COLUMN,
	       buf, gettext (cs->description));
    }

  if (!remote_description || *remote_description == '\0')
    fprintf (usageto, _("\nThis program built for %s"), make_host);
  else
    fprintf (usageto, "\nThis program built for %s (%s)", make_host, remote_description);

  fprintf (usageto, _("\nReport bugs to <bug-make@gnu.org>\n"));
}

/* Decode switches from ARGC and ARGV.
