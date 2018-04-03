        break;

    case 'm':
        p = auth_user_request->denyMessage("[not available]");

        break;

    case 'M':
        p = request ? RequestMethodStr(request->method) : "[unknown method]";

        break;

