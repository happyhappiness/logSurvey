            }
        }

        if (value) {
            switch (mode) {
            case MODE_ADD:
                op |= value;
                break;
           case MODE_REMOVE:
                op &= ~value;
                break;
            }
        } else {
            debugs(83, DBG_PARSE_NOTE(1), "ERROR: Unknown TLS option " << option);
        }

        static const CharacterSet delims("TLS-option-delim",":,");
