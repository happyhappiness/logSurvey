    }
    FILE *FH = fopen(filename, "r");
    if (!FH) {
        fprintf(stderr, "%s: FATAL: Unable to open file '%s': %s", program_name, filename, xstrerror());
        exit(1);
    }
    current_entry = load_dict(FH);
