          implicit_percent = find_percent_cached (&name);

          if (implicit_percent == 0)
            fatal (flocp, _("mixed implicit and normal rules"));

          targets[c] = name;
          target_pats[c] = implicit_percent;
