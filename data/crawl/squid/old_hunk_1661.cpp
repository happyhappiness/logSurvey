        visitor.visit(Name(i->first), Area::FromTempString(i->second));
}

Adaptation::Ecap::ServiceRep::ServiceRep(const ServiceConfigPointer &cfg):
        /*AsyncJob("Adaptation::Ecap::ServiceRep"),*/ Adaptation::Service(cfg),
        isDetached(false)
