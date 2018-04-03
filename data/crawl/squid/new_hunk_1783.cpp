        }
    }

    if (Config.Program.store_id) {
        if (Config.storeIdChildren.n_max < 1) {
            Config.storeIdChildren.n_max = 0;
            wordlistDestroy(&Config.Program.store_id);
        }
    }

    if (Config.appendDomain)
        if (*Config.appendDomain != '.')
            fatal("append_domain must begin with a '.'");
