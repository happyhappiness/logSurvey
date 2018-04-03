        break;

    default:
        mb.appendf("%%%c", token);
        do_quote = 0;
        break;
    }
