}

StoreSearch *
CossSwapDir::search(string const url, HttpRequest *)
{
    if (url.size())
        fatal ("Cannot search by url yet\n");
