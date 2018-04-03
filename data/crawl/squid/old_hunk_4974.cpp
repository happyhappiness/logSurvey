        break;

    case 'e':
        memBufPrintf(&mb, "%d", err->xerrno);

        break;

    case 'E':

        if (err->xerrno)
            memBufPrintf(&mb, "(%d) %s", err->xerrno, strerror(err->xerrno));
        else
            memBufPrintf(&mb, "[No Error]");

        break;

