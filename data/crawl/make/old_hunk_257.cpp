      /* Reduce escaped percents.  If there are any unescaped it's an error  */
      name = filenames->name;
      if (find_percent_cached (&name))
        error (flocp, _("*** mixed implicit and normal rules: deprecated syntax"));
    }
}

