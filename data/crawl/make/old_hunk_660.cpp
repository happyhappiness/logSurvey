              fatal (fstart, _("missing target pattern"));
            else if (target->next != 0)
              fatal (fstart, _("multiple target patterns"));
            pattern = target->name;
            pattern_percent = find_percent (pattern);
            if (pattern_percent == 0)
              fatal (fstart, _("target pattern contains no `%%'"));
            free (target);
