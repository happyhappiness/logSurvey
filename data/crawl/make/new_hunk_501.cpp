            pattern_percent = find_percent_cached (&target->name);
            pattern = target->name;
            if (pattern_percent == 0)
              fatal (fstart, _("target pattern contains no '%%'"));
            free_ns (target);
          }
        else
