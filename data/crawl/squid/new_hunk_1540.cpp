                          ae->name,
                          ae->typeString(),
                          ae->flags.flagsStr());
        dump_SBufList(entry, ae->dump());
        ae = ae->next;
    }
}
