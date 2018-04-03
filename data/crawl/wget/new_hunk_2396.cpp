      struct url_list *list;
      const char *url = (const char *) iter.key;
          
      logprintf (LOG_NOTQUIET, _("%s\n"), url);
    }
  logputs (LOG_NOTQUIET, "\n");
}
