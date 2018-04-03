        }

      if (newer[0] == '\0')
        OSS (message, 0,
             _("%s: target '%s' does not exist"), nm, c->file->name);
      else
        OSSS (message, 0,
              _("%s: update target '%s' due to: %s"), nm, c->file->name, newer);

      free (newer);
    }
