            end = strchr (beg, closeparen);
            if (end == 0)
              /* Unterminated variable reference.  */
              O (fatal, *expanding_var, _("unterminated variable reference"));
            p1 = lindex (beg, end, '$');
            if (p1 != 0)
              {
