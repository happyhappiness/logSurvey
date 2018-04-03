          sh_found = 1;
      }

      if (sh_found)
        DB (DB_EXTRA,
            (_("find_and_set_shell path search set default_shell = %s\n"),
             default_shell));
    }
  }

