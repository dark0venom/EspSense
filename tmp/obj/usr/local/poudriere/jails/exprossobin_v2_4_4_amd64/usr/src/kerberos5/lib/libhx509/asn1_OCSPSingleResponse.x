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
encode_OCSPSingleResponse(unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, const OCSPSingleResponse *data, size_t *size)
{
size_t ret HEIMDAL_UNUSED_ATTRIBUTE = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int i HEIMDAL_UNUSED_ATTRIBUTE, e HEIMDAL_UNUSED_ATTRIBUTE;

/* singleExtensions */
if((data)->singleExtensions) {
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = encode_Extensions(p, len, (data)->singleExtensions, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 1, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* nextUpdate */
if((data)->nextUpdate) {
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = der_put_generalized_time(p, len, (data)->nextUpdate, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, PRIM, UT_GeneralizedTime, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 0, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* thisUpdate */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = der_put_generalized_time(p, len, &(data)->thisUpdate, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, PRIM, UT_GeneralizedTime, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* certStatus */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = encode_OCSPCertStatus(p, len, &(data)->certStatus, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* certID */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = encode_OCSPCertID(p, len, &(data)->certID, &l);
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
decode_OCSPSingleResponse(const unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, OCSPSingleResponse *data, size_t *size)
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
e = decode_OCSPCertID(p, len, &(data)->certID, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
e = decode_OCSPCertStatus(p, len, &(data)->certStatus, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
{
size_t thisUpdate_datalen, thisUpdate_oldlen;
Der_type thisUpdate_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &thisUpdate_type, UT_GeneralizedTime, &thisUpdate_datalen, &l);
if (e == 0 && thisUpdate_type != PRIM) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
thisUpdate_oldlen = len;
if (thisUpdate_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = thisUpdate_datalen;
e = der_get_generalized_time(p, len, &(data)->thisUpdate, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = thisUpdate_oldlen - thisUpdate_datalen;
}
{
size_t nextUpdate_datalen, nextUpdate_oldlen;
Der_type nextUpdate_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &nextUpdate_type, 0, &nextUpdate_datalen, &l);
if (e == 0 && nextUpdate_type != CONS) { e = ASN1_BAD_ID; }
if(e) {
(data)->nextUpdate = NULL;
} else {
(data)->nextUpdate = calloc(1, sizeof(*(data)->nextUpdate));
if ((data)->nextUpdate == NULL) { e = ENOMEM; goto fail; }
p += l; len -= l; ret += l;
nextUpdate_oldlen = len;
if (nextUpdate_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = nextUpdate_datalen;
{
size_t nextUpdate_Tag_datalen, nextUpdate_Tag_oldlen;
Der_type nextUpdate_Tag_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &nextUpdate_Tag_type, UT_GeneralizedTime, &nextUpdate_Tag_datalen, &l);
if (e == 0 && nextUpdate_Tag_type != PRIM) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
nextUpdate_Tag_oldlen = len;
if (nextUpdate_Tag_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = nextUpdate_Tag_datalen;
e = der_get_generalized_time(p, len, (data)->nextUpdate, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = nextUpdate_Tag_oldlen - nextUpdate_Tag_datalen;
}
len = nextUpdate_oldlen - nextUpdate_datalen;
}
}
{
size_t singleExtensions_datalen, singleExtensions_oldlen;
Der_type singleExtensions_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &singleExtensions_type, 1, &singleExtensions_datalen, &l);
if (e == 0 && singleExtensions_type != CONS) { e = ASN1_BAD_ID; }
if(e) {
(data)->singleExtensions = NULL;
} else {
(data)->singleExtensions = calloc(1, sizeof(*(data)->singleExtensions));
if ((data)->singleExtensions == NULL) { e = ENOMEM; goto fail; }
p += l; len -= l; ret += l;
singleExtensions_oldlen = len;
if (singleExtensions_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = singleExtensions_datalen;
e = decode_Extensions(p, len, (data)->singleExtensions, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = singleExtensions_oldlen - singleExtensions_datalen;
}
}
len = Top_oldlen - Top_datalen;
}
if(size) *size = ret;
return 0;
fail:
free_OCSPSingleResponse(data);
return e;
}

void ASN1CALL
free_OCSPSingleResponse(OCSPSingleResponse *data)
{
free_OCSPCertID(&(data)->certID);
free_OCSPCertStatus(&(data)->certStatus);
if((data)->nextUpdate) {
free((data)->nextUpdate);
(data)->nextUpdate = NULL;
}
if((data)->singleExtensions) {
free_Extensions((data)->singleExtensions);
free((data)->singleExtensions);
(data)->singleExtensions = NULL;
}
}

size_t ASN1CALL
length_OCSPSingleResponse(const OCSPSingleResponse *data)
{
size_t ret = 0;
{
size_t Top_tag_oldret = ret;
ret = 0;
ret += length_OCSPCertID(&(data)->certID);
ret += Top_tag_oldret;
}
{
size_t Top_tag_oldret = ret;
ret = 0;
ret += length_OCSPCertStatus(&(data)->certStatus);
ret += Top_tag_oldret;
}
{
size_t Top_tag_oldret = ret;
ret = 0;
ret += der_length_generalized_time(&(data)->thisUpdate);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
if((data)->nextUpdate){
size_t Top_tag_oldret = ret;
ret = 0;
ret += der_length_generalized_time((data)->nextUpdate);
ret += 1 + der_length_len (ret);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
if((data)->singleExtensions){
size_t Top_tag_oldret = ret;
ret = 0;
ret += length_Extensions((data)->singleExtensions);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
ret += 1 + der_length_len (ret);
return ret;
}

int ASN1CALL
copy_OCSPSingleResponse(const OCSPSingleResponse *from, OCSPSingleResponse *to)
{
memset(to, 0, sizeof(*to));
if(copy_OCSPCertID(&(from)->certID, &(to)->certID)) goto fail;
if(copy_OCSPCertStatus(&(from)->certStatus, &(to)->certStatus)) goto fail;
*(&(to)->thisUpdate) = *(&(from)->thisUpdate);
if((from)->nextUpdate) {
(to)->nextUpdate = malloc(sizeof(*(to)->nextUpdate));
if((to)->nextUpdate == NULL) goto fail;
*((to)->nextUpdate) = *((from)->nextUpdate);
}else
(to)->nextUpdate = NULL;
if((from)->singleExtensions) {
(to)->singleExtensions = malloc(sizeof(*(to)->singleExtensions));
if((to)->singleExtensions == NULL) goto fail;
if(copy_Extensions((from)->singleExtensions, (to)->singleExtensions)) goto fail;
}else
(to)->singleExtensions = NULL;
return 0;
fail:
free_OCSPSingleResponse(to);
return ENOMEM;
}



