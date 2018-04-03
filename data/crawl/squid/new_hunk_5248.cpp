
        break;

    case 5:
        result->typeLabel = "5";
        compositeCopy = new DelayTagged;
        break;

    default:
        fatal ("unknown delay pool class");
        return NULL;
