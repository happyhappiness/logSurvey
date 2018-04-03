                                     PARSEFS_NOGLOB);
            ++p2;
            if (target == 0)
              O (fatal, fstart, _("missing target pattern"));
            else if (target->next != 0)
              O (fatal, fstart, _("multiple target patterns"));
            pattern_percent = find_percent_cached (&target->name);
            pattern = target->name;
            if (pattern_percent == 0)
              O (fatal, fstart, _("target pattern contains no '%%'"));
            free_ns (target);
          }
        else
