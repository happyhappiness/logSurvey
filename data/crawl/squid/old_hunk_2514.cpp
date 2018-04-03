    /* check to see if the auth_user already has a request outstanding */
    if (user()->credentials() == Auth::Pending) {
        /* there is a request with the same credentials already being verified */
        basic_auth->queueRequest(this, handler, data);
        return;
    }

    basic_auth->submitRequest(this, handler, data);
}

