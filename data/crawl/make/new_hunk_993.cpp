      return 0;
    }

  DBF (DB_BASIC, _("Must remake target `%s'.\n"));

  /* It needs to be remade.  If it's VPATH and not reset via GPATH, toss the
     VPATH.  */
  if (!streq(file->name, file->hname))
    {
      DB (DB_BASIC, (_("  Ignoring VPATH name `%s'.\n"), file->hname));
      file->ignore_vpath = 1;
    }

