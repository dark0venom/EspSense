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
encode_OCSPRequest(unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, const OCSPRequest *data, size_t *size)
{
size_t ret HEIMDAL_UNUSED_ATTRIBUTE = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int i HEIMDAL_UNUSED_ATTRIBUTE, e HEIMDAL_UNUSED_ATTRIBUTE;

/* optionalSignature */
if((data)->optionalSignature) {
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = encode_OCSPSignature(p, len, (data)->optionalSignature, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 0, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* tbsRequest */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = encode_OCSPTBSRequest(p, len, &(data)->tbsRequest, &l);
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
decode_OCSPRequest(const unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, OCSPRequest *data, size_t *size)
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
e = decode_OCSPTBSRequest(p, len, &(data)->tbsRequest, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
{
size_t optionalSignature_datalen, optionalSignature_oldlen;
Der_type optionalSignature_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &optionalSignature_type, 0, &optionalSignature_datalen, &l);
if (e == 0 && optionalSignature_type != CONS) { e = ASN1_BAD_ID; }
if(e) {
(data)->optionalSignature = NULL;
} else {
(data)->optionalSignature = calloc(1, sizeof(*(data)->optionalSignature));
if ((data)->optionalSignature == NULL) { e = ENOMEM; goto fail; }
p += l; len -= l; ret += l;
optionalSignature_oldlen = len;
if (optionalSignature_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = optionalSignature_datalen;
e = decode_OCSPSignature(p, len, (data)->optionalSignature, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = optionalSignature_oldlen - optionalSignature_datalen;
}
}
len = Top_oldlen - Top_datalen;
}
if(size) *size = ret;
return 0;
fail:
free_OCSPRequest(data);
return e;
}

void ASN1CALL
free_OCSPRequest(OCSPRequest *data)
{
free_OCSPTBSRequest(&(data)->tbsRequest);
if((data)->optionalSignature) {
free_OCSPSignature((data)->optionalSignature);
free((data)->optionalSignature);
(data)->optionalSignature = NULL;
}
}

size_t ASN1CALL
length_OCSPRequest(const OCSPRequest *data)
{
size_t ret = 0;
{
size_t Top_tag_oldret = ret;
ret = 0;
ret += length_OCSPTBSRequest(&(data)->tbsRequest);
ret += Top_tag_oldret;
}
if((data)->optionalSignature){
size_t Top_tag_oldret = ret;
ret = 0;
ret += length_OCSPSignature((data)->optionalSignature);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
ret += 1 + der_length_len (ret);
return ret;
}

int ASN1CALL
copy_OCSPRequest(const OCSPRequest *from, OCSPRequest *to)
{
memset(to, 0, sizeof(*to));
if(copy_OCSPTBSRequest(&(from)->tbsRequest, &(to)->tbsRequest)) goto fail;
if((from)->optionalSignature) {
(to)->optionalSignature = malloc(sizeof(*(to)->optionalSignature));
if((to)->optionalSignature == NULL) goto fail;
if(copy_OCSPSignature((from)->optionalSignature, (to)->optionalSignature)) goto fail;
}else
(to)->optionalSignature = NULL;
return 0;
fail:
free_OCSPRequest(to);
return ENOMEM;
}



