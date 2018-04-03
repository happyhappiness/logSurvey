              ep++;
            }
        }
#endif
      fprintf (outfile, "$ %.*s_ = f$verify(%.*s_1)\n", tmpstrlen, tmpstr, tmpstrlen, tmpstr);

      /* TODO: give 78 a name! Whether 78 is a good number is another question.
