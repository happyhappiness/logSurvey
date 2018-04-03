                db_level |= DB_BASIC | DB_VERBOSE;
                break;
              default:
                OS (fatal, NILF,
                    _("unknown debug level specification '%s'"), p);
              }

            while (*(++p) != '\0')
