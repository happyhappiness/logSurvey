      const char *domain = iter.key;
      struct cookie *cookie = iter.value;
      for (; cookie; cookie = cookie->next)
	{
	  if (!cookie->permanent && !opt.keep_session_cookies)
	    continue;
	  if (cookie_expired_p (cookie))
	    continue;
	  if (!cookie->domain_exact)
	    fputc ('.', fp);
	  fputs (domain, fp);
	  if (cookie->port != PORT_ANY)
	    fprintf (fp, ":%d", cookie->port);
	  fprintf (fp, "\t%s\t%s\t%s\t%.0f\t%s\t%s\n",
		   cookie->domain_exact ? "FALSE" : "TRUE",
		   cookie->path, cookie->secure ? "TRUE" : "FALSE",
		   (double)cookie->expiry_time,
		   cookie->attr, cookie->value);
	  if (ferror (fp))
	    goto out;
	}
    }
 out:
  if (ferror (fp))
    logprintf (LOG_NOTQUIET, _("Error writing to `%s': %s\n"),
	       file, strerror (errno));
  if (fclose (fp) < 0)
    logprintf (LOG_NOTQUIET, _("Error closing `%s': %s\n"),
	       file, strerror (errno));

  DEBUGP (("Done saving cookies.\n"));
}
