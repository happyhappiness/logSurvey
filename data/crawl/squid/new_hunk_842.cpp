        }
#endif
        if (!mb.contentSize())
            mb.append("[No Error Detail]", 17);
        break;

    case 'e':
        mb.appendf("%d", xerrno);
        break;

    case 'E':
        if (xerrno)
            mb.appendf("(%d) %s", xerrno, strerror(xerrno));
        else
            mb.append("[No Error]", 10);
        break;

    case 'f':
