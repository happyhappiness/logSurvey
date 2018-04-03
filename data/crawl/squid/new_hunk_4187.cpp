#include "squid.h"
#include <libecap/common/area.h>
#include <libecap/common/delay.h>
#include <libecap/adapter/xaction.h>
#include "TextException.h"
#include "assert.h"
#include "HttpRequest.h"
#include "HttpReply.h"
#include "eCAP/XactionRep.h"

// CBDATA_CLASS_INIT(Ecap::XactionRep);
// TODO: add CBDATA_NAMESPACED_CLASS_INIT(namespace, classname)
cbdata_type Ecap::XactionRep::CBDATA_XactionRep = CBDATA_UNKNOWN;


Ecap::XactionRep::XactionRep(Adaptation::Initiator *anInitiator,
    HttpMsg *virginHeader, HttpRequest *virginCause,
    const Adaptation::ServicePointer &aService):
    AsyncJob("Ecap::XactionRep"),
    Adaptation::Initiate("Ecap::XactionRep", anInitiator, aService),
    theVirginRep(virginHeader), theCauseRep(NULL),
    proxyingVb(opUndecided), proxyingAb(opUndecided), canAccessVb(false)
{
    if (virginCause)
        theCauseRep = new MessageRep(virginCause);
}

Ecap::XactionRep::~XactionRep()
{
    assert(!theMaster);
    delete theCauseRep;
    theAnswerRep.reset();
}

void
Ecap::XactionRep::master(const AdapterXaction &x)
{
    Must(!theMaster);
    Must(x != NULL);
    theMaster = x;
}

void
Ecap::XactionRep::start()
{
    Must(theMaster);

    if (theVirginRep.raw().body_pipe != NULL)
        canAccessVb = true; /// assumes nobody is consuming; \todo check
    else
        proxyingVb = opNever;

    theMaster->start();
}

void
Ecap::XactionRep::swanSong()
{
    // clear body_pipes, if any
    // this code does not maintain proxying* and canAccessVb states; should it?

    if (theAnswerRep != NULL) {
        BodyPipe::Pointer body_pipe = answer().body_pipe;
        if (body_pipe != NULL) {
            Must(body_pipe->stillProducing(this));
            stopProducingFor(body_pipe, false);
        }
    }

    {
        BodyPipe::Pointer body_pipe = theVirginRep.raw().body_pipe;
        if (body_pipe != NULL) {
            Must(body_pipe->stillConsuming(this));
            stopConsumingFrom(body_pipe);
        }
    }

    terminateMaster();
    Adaptation::Initiate::swanSong();
}

libecap::Message &
Ecap::XactionRep::virgin()
{
    return theVirginRep;
}

const libecap::Message &
Ecap::XactionRep::cause()
{
    Must(theCauseRep != NULL);
    return *theCauseRep;
}

libecap::Message &
Ecap::XactionRep::adapted()
{
    Must(theAnswerRep != NULL);
    return *theAnswerRep;
}

Adaptation::Message &
Ecap::XactionRep::answer()
{
    MessageRep *rep = dynamic_cast<MessageRep*>(theAnswerRep.get());
    Must(rep);
    return rep->raw();
}

void
Ecap::XactionRep::terminateMaster()
{
    if (theMaster) {
        AdapterXaction x = theMaster;
        theMaster.reset();
        x->stop();
    }
}

bool
Ecap::XactionRep::doneAll() const
{
    return proxyingVb >= opComplete && proxyingAb >= opComplete &&
        Adaptation::Initiate::doneAll();
}

// stops receiving virgin and enables auto-consumption
void
Ecap::XactionRep::dropVirgin(const char *reason)
{
    debugs(93,4, HERE << "because " << reason << "; status:" << status());
    Must(proxyingVb = opOn);

    BodyPipePointer &p = theVirginRep.raw().body_pipe;
    Must(p != NULL);
    Must(p->stillConsuming(this));
    stopConsumingFrom(p);
    p->enableAutoConsumption();
    proxyingVb = opComplete;
    canAccessVb = false;

    // called from adapter handler so does not inform adapter
}

void 
Ecap::XactionRep::useVirgin()
{
    debugs(93,3, HERE << status());
    Must(proxyingAb == opUndecided);
    proxyingAb = opNever;

    BodyPipePointer &vbody_pipe = theVirginRep.raw().body_pipe;

    HttpMsg *clone = theVirginRep.raw().header->clone();
    // check that clone() copies the pipe so that we do not have to
    Must(!vbody_pipe == !clone->body_pipe);

    if (proxyingVb == opOn) {
        Must(vbody_pipe->stillConsuming(this));
        // if libecap consumed, we cannot shortcircuit
        Must(!vbody_pipe->consumedSize());
        stopConsumingFrom(vbody_pipe);
        canAccessVb = false;
        proxyingVb = opComplete;
    } else
    if (proxyingVb == opUndecided) {
        vbody_pipe = NULL; // it is not our pipe anymore
        proxyingVb = opNever;
    }

    sendAnswer(clone);
    Must(done());
}

void 
Ecap::XactionRep::useAdapted(const libecap::shared_ptr<libecap::Message> &m)
{
    debugs(93,3, HERE << status());
    Must(m);
    theAnswerRep = m;
    Must(proxyingAb == opUndecided);

    HttpMsg *msg = answer().header;
    if (!theAnswerRep->body()) { // final, bodyless answer
        proxyingAb = opNever;
        sendAnswer(msg);
    } else { // got answer headers but need to handle body
        proxyingAb = opOn;
        Must(!msg->body_pipe); // only host can set body pipes
        MessageRep *rep = dynamic_cast<MessageRep*>(theAnswerRep.get());
        Must(rep);
        rep->tieBody(this); // sets us as a producer
        Must(msg->body_pipe != NULL); // check tieBody

        sendAnswer(msg);

        debugs(93,4, HERE << "adapter will produce body" << status());
        theMaster->abMake(); // libecap will produce
    }
}

void
Ecap::XactionRep::vbDiscard()
{
    Must(proxyingVb == opUndecided);
    // if adapter does not need vb, we do not need to send it
    dropVirgin("vbDiscard");
    Must(proxyingVb == opNever);
}

void
Ecap::XactionRep::vbMake()
{
    Must(proxyingVb == opUndecided);
    BodyPipePointer &p = theVirginRep.raw().body_pipe;
    Must(p != NULL);
    Must(p->setConsumerIfNotLate(this)); // to make vb, we must receive vb
    proxyingVb = opOn;
}

void
Ecap::XactionRep::vbStopMaking()
{
    // if adapter does not need vb, we do not need to receive it
    if (proxyingVb == opOn)
        dropVirgin("vbStopMaking");
    Must(proxyingVb == opComplete);
}

void
Ecap::XactionRep::vbMakeMore()
{
    Must(proxyingVb == opOn); // cannot make more if done proxying
    // we cannot guarantee more vb, but we can check that there is a chance
    Must(!theVirginRep.raw().body_pipe->exhausted());
}

libecap::Area
Ecap::XactionRep::vbContent(libecap::size_type o, libecap::size_type s)
{
    Must(canAccessVb);
    // We may not be proxyingVb yet. It should be OK, but see vbContentShift().

    const BodyPipePointer &p = theVirginRep.raw().body_pipe;
    Must(p != NULL);

    // TODO: make MemBuf use size_t?
    const size_t haveSize = static_cast<size_t>(p->buf().contentSize());

    // convert to Squid types; XXX: check for overflow
    const uint64_t offset = static_cast<uint64_t>(o);
    Must(offset <= haveSize); // equal iff at the end of content

    // nsize means no size limit: all content starting from offset
    const size_t size = s == libecap::nsize ?
        haveSize - offset : static_cast<size_t>(s);

    // XXX: optimize by making theBody a shared_ptr (see Area::FromTemp*() src)
    return libecap::Area::FromTempBuffer(p->buf().content() + offset,
        min(static_cast<size_t>(haveSize - offset), size));
}

void
Ecap::XactionRep::vbContentShift(libecap::size_type n)
{
    Must(canAccessVb);
    // We may not be proxyingVb yet. It should be OK now, but if BodyPipe
    // consume() requirements change, we would have to return empty vbContent
    // until the adapter registers as a consumer

    BodyPipePointer &p = theVirginRep.raw().body_pipe;
    Must(p != NULL);
    const size_t size = static_cast<size_t>(n); // XXX: check for overflow
    const size_t haveSize = static_cast<size_t>(p->buf().contentSize()); // TODO: make MemBuf use size_t?
    p->consume(min(size, haveSize));
}

void
Ecap::XactionRep::noteAbContentDone(bool atEnd)
{
    Must(proxyingAb == opOn);
    stopProducingFor(answer().body_pipe, atEnd);
    proxyingAb = opComplete;
}

void
Ecap::XactionRep::noteAbContentAvailable()
{
    Must(proxyingAb == opOn);
    moveAbContent();
}

#if 0 /* XXX: implement */
void
Ecap::XactionRep::setAdaptedBodySize(const libecap::BodySize &size)
{
    Must(answer().body_pipe != NULL);
    if (size.known())
        answer().body_pipe->setBodySize(size.value());
    // else the piped body size is unknown by default
}
#endif

void
Ecap::XactionRep::adaptationDelayed(const libecap::Delay &d)
{
    debugs(93,3, HERE << "adapter needs time: " <<
       d.state << '/' << d.progress);
    // XXX: set timeout?
}

void 
Ecap::XactionRep::adaptationAborted()
{
    tellQueryAborted(true); // should eCAP support retries?
    mustStop("adaptationAborted");
}

bool
Ecap::XactionRep::callable() const
{
    return !done();
}

void 
Ecap::XactionRep::noteMoreBodySpaceAvailable(RefCount<BodyPipe> bp)
{
    Must(proxyingAb == opOn);
    moveAbContent();
}

void 
Ecap::XactionRep::noteBodyConsumerAborted(RefCount<BodyPipe> bp)
{
    Must(proxyingAb == opOn);
    stopProducingFor(answer().body_pipe, false);
    Must(theMaster);
    theMaster->abStopMaking();
    proxyingAb = opComplete;
}

void
Ecap::XactionRep::noteMoreBodyDataAvailable(RefCount<BodyPipe> bp)
{
    Must(proxyingVb == opOn);
    Must(theMaster);
    theMaster->noteVbContentAvailable();
}

void
Ecap::XactionRep::noteBodyProductionEnded(RefCount<BodyPipe> bp)
{
    Must(proxyingVb == opOn);
    Must(theMaster);
    theMaster->noteVbContentDone(true);
    proxyingVb = opComplete;
}

void
Ecap::XactionRep::noteBodyProducerAborted(RefCount<BodyPipe> bp)
{
    Must(proxyingVb == opOn);
    Must(theMaster);
    theMaster->noteVbContentDone(false);
    proxyingVb = opComplete;
}

void
Ecap::XactionRep::noteInitiatorAborted()
{
    mustStop("initiator aborted");
}

// get content from the adapter and put it into the adapted pipe
void
Ecap::XactionRep::moveAbContent()
{
    Must(proxyingAb == opOn);
    const libecap::Area c = theMaster->abContent(0, libecap::nsize);
    debugs(93,5, HERE << " up to " << c.size << " bytes");
    if (const size_t used = answer().body_pipe->putMoreData(c.start, c.size))
        theMaster->abContentShift(used);
}

const char *
Ecap::XactionRep::status() const
{
    static MemBuf buf;
    buf.reset();

    buf.append(" [", 2);

    if (proxyingVb == opOn) {
        const BodyPipePointer &vp = theVirginRep.raw().body_pipe;
        if (!canAccessVb)
            buf.append("x", 1);
        if (vp != NULL && vp->stillConsuming(this)) {
            buf.append("Vb", 2);
            buf.append(vp->status(), strlen(vp->status())); // XXX
        } else
            buf.append("V.", 2);
    }

    if (proxyingAb == opOn) {
        MessageRep *rep = dynamic_cast<MessageRep*>(theAnswerRep.get());
        Must(rep);
        const BodyPipePointer &ap = rep->raw().body_pipe;
        if (ap != NULL && ap->stillProducing(this)) {
            buf.append(" Ab", 3);
            buf.append(ap->status(), strlen(ap->status())); // XXX
        } else
            buf.append(" A.", 3);
    }

    buf.Printf(" ecapx%d]", id);

    buf.terminate();

    return buf.content();
}
