     time_t change_time = -1;
     char buf[HELPER_INPUT_BUFFER];
     char *user, *passwd, *p;
-    user_data *u;
     setbuf(stdout, NULL);
     if (argc != 2) {
         fprintf(stderr, "Usage: ncsa_auth <passwordfile>\n");
