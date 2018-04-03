      if (ar_member_date (file->name) != file_date)
        {
          if (on_behalf_of)
            error (NILF, _("*** [%s] Archive member '%s' may be bogus; not deleted"),
                   on_behalf_of, file->name);
          else
            error (NILF, _("*** Archive member '%s' may be bogus; not deleted"),
                   file->name);
        }
      return;
    }
