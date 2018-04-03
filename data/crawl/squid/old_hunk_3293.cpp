        debug("Trying to validate; %s %s\n", username, password);

        if (Valid_User(username, password, NTGroup) == NTV_NO_ERROR)
            puts("OK");
        else
            printf("ERR %s\n", errormsg);
error:
        err = 0;
        fflush(stdout);
    }
