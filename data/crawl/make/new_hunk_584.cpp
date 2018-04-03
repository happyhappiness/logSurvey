        if (p != 0)
          {
            struct nameseq *target;
            target = PARSE_FILE_SEQ (&p2, struct nameseq, ':', NULL,
                                     PARSEFS_NOGLOB|PARSEFS_NOCACHE);
            ++p2;
            if (target == 0)
              fatal (fstart, _("missing target pattern"));
