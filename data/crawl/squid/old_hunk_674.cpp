            }
        }
        if (!found)
            fatalf("Unknown SSL flag '" SQUIDSBUFPH "'", SQUIDSBUFPRINT(tok.remaining()));
        fl |= found;
    } while (tok.skipOne(delims));

