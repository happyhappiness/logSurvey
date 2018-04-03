			 stupidly; but if you work for Athena, that's how
			 you write your makefiles.)  */

		      DB (DB_EXTRA,
                          (_("Makefile `%s' might loop; not remaking it.\n"),
                           f->name));

		      if (last == 0)
			read_makefiles = d->next;
