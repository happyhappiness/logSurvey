        debugs(19, 1, "memCopy: could not find offset " << offset <<
               " in memory.");
        debugDump();
        /* we shouldn't ever ask for absent offsets */
        assert (0);
        return 0;
    }
