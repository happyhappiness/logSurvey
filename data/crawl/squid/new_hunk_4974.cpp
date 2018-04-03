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

