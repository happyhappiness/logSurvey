        } else if (EISDIR == errno && fatal_flag) {
            fatalf("Cannot open '%s' because it is a directory, not a file.\n", path);
        } else {
            debugs(50, DBG_IMPORTANT, "logfileOpen (stdio): " <<  path << ": " << xstrerror());
            return 0;
        }
    }