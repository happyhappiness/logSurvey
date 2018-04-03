        }

      if (newer[0] == '\0')
        message (0, _("%s: target `%s' does not exist"), nm, c->file->name);
      else
        message (0, _("%s: update target `%s' due to: %s"), nm,
                 c->file->name, newer);

      free (newer);
