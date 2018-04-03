    Must(s != NULL);
    return new Adaptation::Icap::ModXact(this, virgin.header, virgin.cause, s);
}

void Adaptation::Icap::ModXactLauncher::swanSong() {
    debugs(93, 5, HERE << "swan sings");
    updateHistory(false);
    Adaptation::Icap::Launcher::swanSong();
}

void Adaptation::Icap::ModXactLauncher::updateHistory(bool start) {
     HttpRequest *r = virgin.cause ?
         virgin.cause : dynamic_cast<HttpRequest*>(virgin.header);

     // r should never be NULL but we play safe; TODO: add Should()
     if (r) {
         Adaptation::Icap::History::Pointer h = r->icapHistory();
         if (h != NULL) {
             if (start)
                 h->start("ICAPModXactLauncher");
             else
                 h->stop("ICAPModXactLauncher");
         }
     }
}
