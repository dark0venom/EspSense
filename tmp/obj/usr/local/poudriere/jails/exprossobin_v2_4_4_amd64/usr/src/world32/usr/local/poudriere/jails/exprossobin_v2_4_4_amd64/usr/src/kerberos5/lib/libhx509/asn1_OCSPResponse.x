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
encode_OCSPResponse(unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, const OCSPResponse *data, size_t *size)
{
size_t ret HEIMDAL_UNUSED_ATTRIBUTE = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int i HEIMDAL_UNUSED_ATTRIBUTE, e HEIMDAL_UNUSED_ATTRIBUTE;

/* responseBytes */
if((data)->responseBytes) {
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = encode_OCSPResponseBytes(p, len, (data)->responseBytes, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 0, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* responseStatus */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = encode_OCSPResponseStatus(p, len, &(data)->responseStatus, &l);
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
decode_OCSPResponse(const unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, OCSPResponse *data, size_t *size)
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
e = decode_OCSPResponseStatus(p, len, &(data)->responseStatus, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
{
size_t responseBytes_datalen, responseBytes_oldlen;
Der_type responseBytes_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &responseBytes_type, 0, &responseBytes_datalen, &l);
if (e == 0 && responseBytes_type != CONS) { e = ASN1_BAD_ID; }
if(e) {
(data)->responseBytes = NULL;
} else {
(data)->responseBytes = calloc(1, sizeof(*(data)->responseBytes));
if ((data)->responseBytes == NULL) { e = ENOMEM; goto fail; }
p += l; len -= l; ret += l;
responseBytes_oldlen = len;
if (responseBytes_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = responseBytes_datalen;
e = decode_OCSPResponseBytes(p, len, (data)->responseBytes, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = responseBytes_oldlen - responseBytes_datalen;
}
}
len = Top_oldlen - Top_datalen;
}
if(size) *size = ret;
return 0;
fail:
free_OCSPResponse(data);
return e;
}

void ASN1CALL
free_OCSPResponse(OCSPResponse *data)
{
free_OCSPResponseStatus(&(data)->responseStatus);
if((data)->responseBytes) {
free_OCSPResponseBytes((data)->responseBytes);
free((data)->responseBytes);
(data)->responseBytes = NULL;
}
}

size_t ASN1CALL
length_OCSPResponse(const OCSPResponse *data)
{
size_t ret = 0;
{
size_t Top_tag_oldret = ret;
ret = 0;
ret += length_OCSPResponseStatus(&(data)->responseStatus);
ret += Top_tag_oldret;
}
if((data)->responseBytes){
size_t Top_tag_oldret = ret;
ret = 0;
ret += length_OCSPResponseBytes((data)->responseBytes);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
ret += 1 + der_length_len (ret);
return ret;
}

int ASN1CALL
copy_OCSPResponse(const OCSPResponse *from, OCSPResponse *to)
{
memset(to, 0, sizeof(*to));
if(copy_OCSPResponseStatus(&(from)->responseStatus, &(to)->responseStatus)) goto fail;
if((from)->responseBytes) {
(to)->responseBytes = malloc(sizeof(*(to)->responseBytes));
if((to)->responseBytes == NULL) goto fail;
if(copy_OCSPResponseBytes((from)->responseBytes, (to)->responseBytes)) goto fail;
}else
(to)->responseBytes = NULL;
return 0;
fail:
free_OCSPResponse(to);
return ENOMEM;
}


