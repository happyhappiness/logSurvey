    strtok(cfgline, w_space);
    String unEscaped;
    ConfigParser::ParseQuotedString(&unEscaped);
    
    const bool interpOk = (unEscaped.cmp(expectInterp) == 0);
    if (!interpOk) {
        printf("%25s: %s\n%25s: %s\n%25s: %s\n",
