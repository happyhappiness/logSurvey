
    case 'a':

        if (r && r->auth_user_request)
            p = r->auth_user_request->username();

        if (!p)
            p = "-";

        break;

    case 'B':
        p = r ? ftpUrlWith2f(r) : "[no URL]";

        break;

    case 'c':
        p = errorPageName(err->type);

        break;

    case 'e':
        mb.Printf("%d", err->xerrno);

        break;

    case 'E':

        if (err->xerrno)
            mb.Printf("(%d) %s", err->xerrno, strerror(err->xerrno));
        else
            mb.Printf("[No Error]");

        break;

    case 'f':
        /* FTP REQUEST LINE */
        if (err->ftp.request)
            p = err->ftp.request;
        else
            p = "nothing";

        break;

    case 'F':
        /* FTP REPLY LINE */
        if (err->ftp.request)
            p = err->ftp.reply;
        else
            p = "nothing";

        break;

    case 'g':
        /* FTP SERVER MESSAGE */
        wordlistCat(err->ftp.server_msg, &mb);

        break;

