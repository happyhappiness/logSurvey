    e->setPublicKey();
    e->buffer();

    const MasterXaction::Pointer mx = new MasterXaction(XactionInitiator::initIcon);
    HttpRequestPointer r(HttpRequest::FromUrl(url_, mx));
    if (!r)
        fatalf("mimeLoadIcon: cannot parse internal URL: %s", url_);

    e->mem_obj->request = r;

    HttpReplyPointer reply(new HttpReply);