/*
 * Copyright (C) 1996-2016 The Squid Software Foundation and contributors
 *
 * Squid software is distributed under GPLv2+ license and includes
 * contributions from numerous individuals and organizations.
 * Please see the COPYING and CONTRIBUTORS files for details.
 */

/* DEBUG: section 83    SSL-Bump Server/Peer negotiation */

#include "squid.h"
#include "security/Handshake.h"
#if USE_OPENSSL
#include "ssl/support.h"
#endif

namespace Security {

// TODO: Replace with Anyp::ProtocolVersion and use for TlsDetails::tls*Version.
/// TLS Record Layer's protocol version from RFC 5246 Section 6.2.1
class ProtocolVersion
{
public:
    ProtocolVersion() {}
    explicit ProtocolVersion(BinaryTokenizer &tk);

    /// XXX: TlsDetails use "int" to manipulate version information.
    /// TODO: Use ProtocolVersion in TlsDetails and printTlsVersion().
    int toNumberXXX() const { return (vMajor << 8) | vMinor; }

    // the "v" prefix works around environments that #define major and minor
    uint8_t vMajor = 0;
    uint8_t vMinor = 0;
};

/* 
 * The types below represent various SSL and TLS protocol elements. Most names
 * are based on RFC 5264 and RFC 6066 terminology. Objects of these explicit
 * types are stored or passed around. Other protocol elements are simply parsed
 * in-place, without declaring a corresponding explicit class.
 */

/// TLS Record Layer's content types from RFC 5246 Section 6.2.1
enum ContentType {
    ctChangeCipherSpec = 20,
    ctAlert = 21,
    ctHandshake = 22,
    ctApplicationData = 23
};

/// TLS Record Layer's frame from RFC 5246 Section 6.2.1.
class TLSPlaintext
{
public:
    explicit TLSPlaintext(BinaryTokenizer &tk);

    uint8_t type; ///< see ContentType
    int version; ///< Record Layer, not necessarily the negotiated TLS version; TODO: Replace with Anyp::ProtocolVersion
    SBuf fragment; ///< possibly partial content
};

/// draft-hickman-netscape-ssl-00. Section 4.1. SSL Record Header Format
class Sslv2Record
{
public:
    explicit Sslv2Record(BinaryTokenizer &tk);

    SBuf fragment;
};

/// TLS Handshake protocol's handshake types from RFC 5246 Section 7.4
enum HandshakeType {
    hskClientHello = 1,
    hskServerHello = 2,
    hskCertificate = 11,
    hskServerHelloDone = 14
};

/// TLS Handshake Protocol frame from RFC 5246 Section 7.4.
class Handshake
{
public:
    explicit Handshake(BinaryTokenizer &tk);

    uint8_t msg_type; ///< see HandshakeType
    SBuf msg_body; ///< Handshake Protocol message
};

/// TLS Alert protocol frame from RFC 5246 Section 7.2.
class Alert
{
public:
    explicit Alert(BinaryTokenizer &tk);

    bool fatal() const { return level == 2; }

    uint8_t level; ///< warning or fatal
    uint8_t description; ///< close_notify, unexpected_message, etc.
};

/// The size of the TLS Random structure from RFC 5246 Section 7.4.1.2.
static const uint64_t HelloRandomSize = 32;

/// TLS Hello Extension from RFC 5246 Section 7.4.1.4.
class Extension
{
public:
    explicit Extension(BinaryTokenizer &tk);

    uint16_t type;
    SBuf data;
};

} // namespace Security

/// Convenience helper: We parse ProtocolVersion but store "int".
static int
ParseProtocolVersion(BinaryTokenizer &tk)
{
    const Security::ProtocolVersion version(tk);
    return version.toNumberXXX();
}


Security::ProtocolVersion::ProtocolVersion(BinaryTokenizer &tk)
{
    BinaryTokenizerContext context(tk, ".version");
    vMajor = tk.uint8(".major");
    vMinor = tk.uint8(".minor");
    // do not summarize context.success() to reduce debugging noise
}

Security::TLSPlaintext::TLSPlaintext(BinaryTokenizer &tk)
{
    BinaryTokenizerContext context(tk, "TLSPlaintext");
    type = tk.uint8(".type");
    Must(type >= ctChangeCipherSpec && type <= ctApplicationData);
    version = ParseProtocolVersion(tk);
    // TODO: Must(version.major == 3);
    fragment = tk.pstring16(".fragment");
    context.success();
}

Security::Handshake::Handshake(BinaryTokenizer &tk)
{
    BinaryTokenizerContext context(tk, "Handshake");
    msg_type = tk.uint8(".msg_type");
    msg_body = tk.pstring24(".msg_body");
    context.success();
}

Security::Alert::Alert(BinaryTokenizer &tk)
{
    BinaryTokenizerContext context(tk, "Alert");
    level = tk.uint8(".level");
    description = tk.uint8(".description");
    context.success();
}

Security::Extension::Extension(BinaryTokenizer &tk)
{
    BinaryTokenizerContext context(tk, "Extension");
    type = tk.uint16(".type");
    data = tk.pstring16(".data");
    context.success();
}

Security::Sslv2Record::Sslv2Record(BinaryTokenizer &tk)
{
    BinaryTokenizerContext context(tk, "Sslv2Record");
    const uint16_t head = tk.uint16(".head");
    const uint16_t length = head & 0x7FFF;
    Must((head & 0x8000) && length); // SSLv2 message [without padding]
    fragment = tk.area(length, ".fragment");
    context.success();
