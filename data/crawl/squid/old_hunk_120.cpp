        if ( *line == '\0' || *line == '\n' ) continue;

        // test line
        std::string tmpLine(line);
        if (!std::regex_search(tmpLine, subs, rexp))
            continue;

        // match, please record
        memset( &cd, 0, sizeof(cd) );
        if ( debug ) fprintf( debug, "# match '%s' on line %s", subs[0].str().c_str(), line);

        // extract information. If 6th parenthesis is filled, this is
        // a new squid with disk types, otherwise it is an older version
        int offset = 2;
        if (subs[6].str().empty()) {
            // old version, disk type at position 2 is always UFS
            cd.type = CacheDir::CDT_UFS;
        } else {
            // new version, disk type at position 2
            if ( debug ) fprintf( debug, "# match '%s' in \"%s\"\n", subs[offset].str().c_str(), subs[0].str().c_str());
            static const std::string ufsDir("ufs",3);
            static const std::string aufsDir("aufs",4);
            static const std::string asyncUfsDir("asyncufs",8);
            static const std::string diskdDir("diskd",5);
            if (subs[offset] == ufsDir)
                cd.type = CacheDir::CDT_UFS;
            else if (subs[offset] == aufsDir || subs[offset] == asyncUfsDir)
                cd.type = CacheDir::CDT_AUFS;
            else if (subs[offset] == diskdDir)
                cd.type = CacheDir::CDT_DISKD;
            else
                cd.type = CacheDir::CDT_OTHER;
            ++offset;
        }

        // extract base directory
        if ( debug ) fprintf( debug, "# match '%s' in \"%s\"\n", subs[offset].str().c_str(), subs[0].str().c_str());
        cd.base = xstrdup(subs[offset].str().c_str());
        ++offset;

        // extract size information
        if ( debug ) fprintf( debug, "# match '%s' in \"%s\"\n", subs[offset].str().c_str(), subs[0].str().c_str());
        cd.size = strtoul(subs[offset].str().c_str(), 0, 10);
        ++offset;

        // extract 1st level directories
        if ( debug ) fprintf( debug, "# match '%s' in \"%s\"\n", subs[offset].str().c_str(), subs[0].str().c_str());
        cd.level[0] = strtoul(subs[offset].str().c_str(), 0, 10);
        ++offset;

        // extract 2nd level directories
        if ( debug ) fprintf( debug, "# match '%s' in \"%s\"\n", subs[offset].str().c_str(), subs[0].str().c_str());
        cd.level[1] = strtoul(subs[offset].str().c_str(), 0, 10);
        ++offset;

        cachedir.push_back( cd );
    }

    cfgin.close();
    return cachedir.size();
}

