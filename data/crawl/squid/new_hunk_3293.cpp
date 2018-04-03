        debug("Trying to validate; %s %s\n", username, password);

        if (Valid_User(username, password, NTGroup) == NTV_NO_ERROR)
            SEND_OK("");
        else
            SEND_ERR(errormsg);
        err = 0;
        fflush(stdout);
    }
