    e->setPublicKey();
    e->buffer();

    e->mem_obj->request = r;

    HttpReplyPointer reply(new HttpReply);