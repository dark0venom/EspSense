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
encode_OCSPCertStatus(unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, const OCSPCertStatus *data, size_t *size)
{
size_t ret HEIMDAL_UNUSED_ATTRIBUTE = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int i HEIMDAL_UNUSED_ATTRIBUTE, e HEIMDAL_UNUSED_ATTRIBUTE;


switch((data)->element) {
case choice_OCSPCertStatus_unknown: {size_t Top_oldret = ret;
ret = 0;
/* NULL */
e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, PRIM, 2, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_oldret;
break;
}
case choice_OCSPCertStatus_revoked: {size_t Top_oldret = ret;
ret = 0;
/* revocationReason */
if((&((data))->u.revoked)->revocationReason) {
size_t revoked_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = encode_CRLReason(p, len, (&((data))->u.revoked)->revocationReason, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 0, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += revoked_tag_oldret;
}
/* revocationTime */
{
size_t revoked_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = der_put_generalized_time(p, len, &(&((data))->u.revoked)->revocationTime, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, PRIM, UT_GeneralizedTime, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += revoked_tag_oldret;
}
e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 1, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_oldret;
break;
}
case choice_OCSPCertStatus_good: {size_t Top_oldret = ret;
ret = 0;
/* NULL */
e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, PRIM, 0, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_oldret;
break;
}
};
*size = ret;
return 0;
}

int ASN1CALL
decode_OCSPCertStatus(const unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, OCSPCertStatus *data, size_t *size)
{
size_t ret = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int e HEIMDAL_UNUSED_ATTRIBUTE;

memset(data, 0, sizeof(*data));
if (der_match_tag(p, len, ASN1_C_CONTEXT, PRIM, 0, NULL) == 0) {
{
size_t good_datalen, good_oldlen;
Der_type good_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &good_type, 0, &good_datalen, &l);
if (e == 0 && good_type != PRIM) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
good_oldlen = len;
if (good_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = good_datalen;
/* NULL */
len = good_oldlen - good_datalen;
}
(data)->element = choice_OCSPCertStatus_good;
}
else if (der_match_tag(p, len, ASN1_C_CONTEXT, CONS, 1, NULL) == 0) {
{
size_t revoked_datalen, revoked_oldlen;
Der_type revoked_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &revoked_type, 1, &revoked_datalen, &l);
if (e == 0 && revoked_type != CONS) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
revoked_oldlen = len;
if (revoked_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = revoked_datalen;
{
size_t revocationTime_datalen, revocationTime_oldlen;
Der_type revocationTime_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &revocationTime_type, UT_GeneralizedTime, &revocationTime_datalen, &l);
if (e == 0 && revocationTime_type != PRIM) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
revocationTime_oldlen = len;
if (revocationTime_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = revocationTime_datalen;
e = der_get_generalized_time(p, len, &(&(data)->u.revoked)->revocationTime, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = revocationTime_oldlen - revocationTime_datalen;
}
{
size_t revocationReason_datalen, revocationReason_oldlen;
Der_type revocationReason_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &revocationReason_type, 0, &revocationReason_datalen, &l);
if (e == 0 && revocationReason_type != CONS) { e = ASN1_BAD_ID; }
if(e) {
(&(data)->u.revoked)->revocationReason = NULL;
} else {
(&(data)->u.revoked)->revocationReason = calloc(1, sizeof(*(&(data)->u.revoked)->revocationReason));
if ((&(data)->u.revoked)->revocationReason == NULL) { e = ENOMEM; goto fail; }
p += l; len -= l; ret += l;
revocationReason_oldlen = len;
if (revocationReason_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = revocationReason_datalen;
e = decode_CRLReason(p, len, (&(data)->u.revoked)->revocationReason, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = revocationReason_oldlen - revocationReason_datalen;
}
}
len = revoked_oldlen - revoked_datalen;
}
(data)->element = choice_OCSPCertStatus_revoked;
}
else if (der_match_tag(p, len, ASN1_C_CONTEXT, PRIM, 2, NULL) == 0) {
{
size_t unknown_datalen, unknown_oldlen;
Der_type unknown_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &unknown_type, 2, &unknown_datalen, &l);
if (e == 0 && unknown_type != PRIM) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
unknown_oldlen = len;
if (unknown_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = unknown_datalen;
/* NULL */
len = unknown_oldlen - unknown_datalen;
}
(data)->element = choice_OCSPCertStatus_unknown;
}
else {
e = ASN1_PARSE_ERROR;
goto fail;
}
if(size) *size = ret;
return 0;
fail:
free_OCSPCertStatus(data);
return e;
}

void ASN1CALL
free_OCSPCertStatus(OCSPCertStatus *data)
{
switch((data)->element) {
case choice_OCSPCertStatus_good:
break;
case choice_OCSPCertStatus_revoked:
if((&(data)->u.revoked)->revocationReason) {
free_CRLReason((&(data)->u.revoked)->revocationReason);
free((&(data)->u.revoked)->revocationReason);
(&(data)->u.revoked)->revocationReason = NULL;
}
break;
case choice_OCSPCertStatus_unknown:
break;
}
}

size_t ASN1CALL
length_OCSPCertStatus(const OCSPCertStatus *data)
{
size_t ret = 0;
switch((data)->element) {
case choice_OCSPCertStatus_good:
{
size_t Top_oldret = ret;
ret = 0;
/* NULL */
ret += 1 + der_length_len (ret);
ret += Top_oldret;
}
break;
case choice_OCSPCertStatus_revoked:
{
size_t Top_oldret = ret;
ret = 0;
{
size_t revoked_tag_oldret = ret;
ret = 0;
ret += der_length_generalized_time(&(&(data)->u.revoked)->revocationTime);
ret += 1 + der_length_len (ret);
ret += revoked_tag_oldret;
}
if((&(data)->u.revoked)->revocationReason){
size_t revoked_tag_oldret = ret;
ret = 0;
ret += length_CRLReason((&(data)->u.revoked)->revocationReason);
ret += 1 + der_length_len (ret);
ret += revoked_tag_oldret;
}
ret += 1 + der_length_len (ret);
ret += Top_oldret;
}
break;
case choice_OCSPCertStatus_unknown:
{
size_t Top_oldret = ret;
ret = 0;
/* NULL */
ret += 1 + der_length_len (ret);
ret += Top_oldret;
}
break;
}
return ret;
}

int ASN1CALL
copy_OCSPCertStatus(const OCSPCertStatus *from, OCSPCertStatus *to)
{
memset(to, 0, sizeof(*to));
(to)->element = (from)->element;
switch((from)->element) {
case choice_OCSPCertStatus_good:
break;
case choice_OCSPCertStatus_revoked:
*(&(&(to)->u.revoked)->revocationTime) = *(&(&(from)->u.revoked)->revocationTime);
if((&(from)->u.revoked)->revocationReason) {
(&(to)->u.revoked)->revocationReason = malloc(sizeof(*(&(to)->u.revoked)->revocationReason));
if((&(to)->u.revoked)->revocationReason == NULL) goto fail;
if(copy_CRLReason((&(from)->u.revoked)->revocationReason, (&(to)->u.revoked)->revocationReason)) goto fail;
}else
(&(to)->u.revoked)->revocationReason = NULL;
break;
case choice_OCSPCertStatus_unknown:
break;
}
return 0;
fail:
free_OCSPCertStatus(to);
return ENOMEM;
}



