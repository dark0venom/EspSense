/* Generated from /usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/crypto/heimdal/lib/hx509/ocsp.asn1 */
/* Do not edit */

#define  ASN1_LIB

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <krb5-types.h>
#include <ocsp_asn1.h>
#include <ocsp_asn1-priv.h>
#include <asn1_err.h>
#include <der.h>
#include <der-private.h>
#include <asn1-template.h>
#include <parse_units.h>

int ASN1CALL
encode_OCSPCertID(unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, const OCSPCertID *data, size_t *size)
{
size_t ret HEIMDAL_UNUSED_ATTRIBUTE = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int i HEIMDAL_UNUSED_ATTRIBUTE, e HEIMDAL_UNUSED_ATTRIBUTE;

/* serialNumber */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = encode_CertificateSerialNumber(p, len, &(data)->serialNumber, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* issuerKeyHash */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = der_put_octet_string(p, len, &(data)->issuerKeyHash, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, PRIM, UT_OctetString, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* issuerNameHash */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = der_put_octet_string(p, len, &(data)->issuerNameHash, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, PRIM, UT_OctetString, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* hashAlgorithm */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = encode_AlgorithmIdentifier(p, len, &(data)->hashAlgorithm, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, CONS, UT_Sequence, &l);
if (e) return e;
p -= l; len -= l; ret += l;

*size = ret;
return 0;
}

int ASN1CALL
decode_OCSPCertID(const unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, OCSPCertID *data, size_t *size)
{
size_t ret = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int e HEIMDAL_UNUSED_ATTRIBUTE;

memset(data, 0, sizeof(*data));
{
size_t Top_datalen, Top_oldlen;
Der_type Top_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &Top_type, UT_Sequence, &Top_datalen, &l);
if (e == 0 && Top_type != CONS) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
Top_oldlen = len;
if (Top_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = Top_datalen;
e = decode_AlgorithmIdentifier(p, len, &(data)->hashAlgorithm, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
{
size_t issuerNameHash_datalen, issuerNameHash_oldlen;
Der_type issuerNameHash_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &issuerNameHash_type, UT_OctetString, &issuerNameHash_datalen, &l);
if (e == 0 && issuerNameHash_type != PRIM) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
issuerNameHash_oldlen = len;
if (issuerNameHash_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = issuerNameHash_datalen;
e = der_get_octet_string(p, len, &(data)->issuerNameHash, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = issuerNameHash_oldlen - issuerNameHash_datalen;
}
{
size_t issuerKeyHash_datalen, issuerKeyHash_oldlen;
Der_type issuerKeyHash_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &issuerKeyHash_type, UT_OctetString, &issuerKeyHash_datalen, &l);
if (e == 0 && issuerKeyHash_type != PRIM) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
issuerKeyHash_oldlen = len;
if (issuerKeyHash_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = issuerKeyHash_datalen;
e = der_get_octet_string(p, len, &(data)->issuerKeyHash, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = issuerKeyHash_oldlen - issuerKeyHash_datalen;
}
e = decode_CertificateSerialNumber(p, len, &(data)->serialNumber, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = Top_oldlen - Top_datalen;
}
if(size) *size = ret;
return 0;
fail:
free_OCSPCertID(data);
return e;
}

void ASN1CALL
free_OCSPCertID(OCSPCertID *data)
{
free_AlgorithmIdentifier(&(data)->hashAlgorithm);
der_free_octet_string(&(data)->issuerNameHash);
der_free_octet_string(&(data)->issuerKeyHash);
free_CertificateSerialNumber(&(data)->serialNumber);
}

size_t ASN1CALL
length_OCSPCertID(const OCSPCertID *data)
{
size_t ret = 0;
{
size_t Top_tag_oldret = ret;
ret = 0;
ret += length_AlgorithmIdentifier(&(data)->hashAlgorithm);
ret += Top_tag_oldret;
}
{
size_t Top_tag_oldret = ret;
ret = 0;
ret += der_length_octet_string(&(data)->issuerNameHash);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
{
size_t Top_tag_oldret = ret;
ret = 0;
ret += der_length_octet_string(&(data)->issuerKeyHash);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
{
size_t Top_tag_oldret = ret;
ret = 0;
ret += length_CertificateSerialNumber(&(data)->serialNumber);
ret += Top_tag_oldret;
}
ret += 1 + der_length_len (ret);
return ret;
}

int ASN1CALL
copy_OCSPCertID(const OCSPCertID *from, OCSPCertID *to)
{
memset(to, 0, sizeof(*to));
if(copy_AlgorithmIdentifier(&(from)->hashAlgorithm, &(to)->hashAlgorithm)) goto fail;
if(der_copy_octet_string(&(from)->issuerNameHash, &(to)->issuerNameHash)) goto fail;
if(der_copy_octet_string(&(from)->issuerKeyHash, &(to)->issuerKeyHash)) goto fail;
if(copy_CertificateSerialNumber(&(from)->serialNumber, &(to)->serialNumber)) goto fail;
return 0;
fail:
free_OCSPCertID(to);
return ENOMEM;
}



