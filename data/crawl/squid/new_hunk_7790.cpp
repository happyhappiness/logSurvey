    printf("<OPTION SELECTED VALUE=\"info\">Cache Information\n");
    printf("<OPTION VALUE=\"squid.conf\">Cache Configuration File\n");
    printf("<OPTION VALUE=\"parameter\">Cache Parameters\n");
#ifdef MENU_SHOW_LOG
    printf("<OPTION VALUE=\"log\">Cache Log\n");
#endif
