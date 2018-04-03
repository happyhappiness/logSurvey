                    bad = 0;
                }
              if (bad)
                O (fatal, NILF,
                   _("Couldn't change back to original directory."));
            }

          ++restarts;
