        usage(program_name);
        exit(1);
    }
    FH = fopen(filename, "r");
    current_entry = load_dict(FH);

    while (fgets(line, HELPER_INPUT_BUFFER, stdin)) {