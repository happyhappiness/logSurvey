    }

    if (!reply) {
        debug(29, 1) ("authenticateNegotiateHandleReply: Helper '%p' crashed!.\n", lastserver);
        reply = "BH Internal error";
    }

    auth_user_request = r->auth_user_request;
