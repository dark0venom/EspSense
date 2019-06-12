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
encode_OCSPInnerRequest(unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, const OCSPInnerRequest *data, size_t *size)
{
size_t ret HEIMDAL_UNUSED_ATTRIBUTE = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int i HEIMDAL_UNUSED_ATTRIBUTE, e HEIMDAL_UNUSED_ATTRIBUTE;

/* singleRequestExtensions */
if((data)->singleRequestExtensions) {
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = encode_Extensions(p, len, (data)->singleRequestExtensions, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 0, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* reqCert */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = encode_OCSPCertID(p, len, &(data)->reqCert, &l);
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
decode_OCSPInnerRequest(const unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, OCSPInnerRequest *data, size_t *size)
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
e = decode_OCSPCertID(p, len, &(data)->reqCert, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
{
size_t singleRequestExtensions_datalen, singleRequestExtensions_oldlen;
Der_type singleRequestExtensions_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &singleRequestExtensions_type, 0, &singleRequestExtensions_datalen, &l);
if (e == 0 && singleRequestExtensions_type != CONS) { e = ASN1_BAD_ID; }
if(e) {
(data)->singleRequestExtensions = NULL;
} else {
(data)->singleRequestExtensions = calloc(1, sizeof(*(data)->singleRequestExtensions));
if ((data)->singleRequestExtensions == NULL) { e = ENOMEM; goto fail; }
p += l; len -= l; ret += l;
singleRequestExtensions_oldlen = len;
if (singleRequestExtensions_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = singleRequestExtensions_datalen;
e = decode_Extensions(p, len, (data)->singleRequestExtensions, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = singleRequestExtensions_oldlen - singleRequestExtensions_datalen;
}
}
len = Top_oldlen - Top_datalen;
}
if(size) *size = ret;
return 0;
fail:
free_OCSPInnerRequest(data);
return e;
}

void ASN1CALL
free_OCSPInnerRequest(OCSPInnerRequest *data)
{
free_OCSPCertID(&(data)->reqCert);
if((data)->singleRequestExtensions) {
free_Extensions((data)->singleRequestExtensions);
free((data)->singleRequestExtensions);
(data)->singleRequestExtensions = NULL;
}
}

size_t ASN1CALL
length_OCSPInnerRequest(const OCSPInnerRequest *data)
{
size_t ret = 0;
{
size_t Top_tag_oldret = ret;
ret = 0;
ret += length_OCSPCertID(&(data)->reqCert);
ret += Top_tag_oldret;
}
if((data)->singleRequestExtensions){
size_t Top_tag_oldret = ret;
ret = 0;
ret += length_Extensions((data)->singleRequestExtensions);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
ret += 1 + der_length_len (ret);
return ret;
}

int ASN1CALL
copy_OCSPInnerRequest(const OCSPInnerRequest *from, OCSPInnerRequest *to)
{
memset(to, 0, sizeof(*to));
if(copy_OCSPCertID(&(from)->reqCert, &(to)->reqCert)) goto fail;
if((from)->singleRequestExtensions) {
(to)->singleRequestExtensions = malloc(sizeof(*(to)->singleRequestExtensions));
if((to)->singleRequestExtensions == NULL) goto fail;
if(copy_Extensions((from)->singleRequestExtensions, (to)->singleRequestExtensions)) goto fail;
}else
(to)->singleRequestExtensions = NULL;
return 0;
fail:
free_OCSPInnerRequest(to);
return ENOMEM;
}



