        return false;
    }

    http->request = request.getRaw();
    HTTPMSGLOCK(http->request);

