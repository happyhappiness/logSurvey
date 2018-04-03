
    case 'a':

        if (request && request->auth_user_request)
            p = request->auth_user_request->username();

        if (!p)
            p = "-";

        break;

    case 'B':
        p = request ? ftpUrlWith2f(request) : "[no URL]";

        break;

    case 'c':
        p = errorPageName(type);

        break;

    case 'e':
        mb.Printf("%d", xerrno);

        break;

    case 'E':

        if (xerrno)
            mb.Printf("(%d) %s", xerrno, strerror(xerrno));
        else
            mb.Printf("[No Error]");

        break;

    case 'f':
        /* FTP REQUEST LINE */
        if (ftp.request)
            p = ftp.request;
        else
            p = "nothing";

        break;

    case 'F':
        /* FTP REPLY LINE */
        if (ftp.request)
            p = ftp.reply;
        else
            p = "nothing";

        break;

    case 'g':
        /* FTP SERVER MESSAGE */
        wordlistCat(ftp.server_msg, &mb);

        break;

