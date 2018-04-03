    if (do_quote)
        p = html_quote(p);

    return p;
}

HttpReply *
ErrorState::BuildHttpReply()
{
