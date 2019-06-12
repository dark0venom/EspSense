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
encode_OCSPResponseData(unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, const OCSPResponseData *data, size_t *size)
{
size_t ret HEIMDAL_UNUSED_ATTRIBUTE = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int i HEIMDAL_UNUSED_ATTRIBUTE, e HEIMDAL_UNUSED_ATTRIBUTE;

/* responseExtensions */
if((data)->responseExtensions) {
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = encode_Extensions(p, len, (data)->responseExtensions, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 1, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* responses */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
for(i = (int)(&(data)->responses)->len - 1; i >= 0; --i) {
size_t responses_tag_for_oldret = ret;
ret = 0;
e = encode_OCSPSingleResponse(p, len, &(&(data)->responses)->val[i], &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += responses_tag_for_oldret;
}
e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, CONS, UT_Sequence, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* producedAt */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = der_put_generalized_time(p, len, &(data)->producedAt, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, PRIM, UT_GeneralizedTime, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* responderID */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = encode_OCSPResponderID(p, len, &(data)->responderID, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* version */
if((data)->version) {
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = encode_OCSPVersion(p, len, (data)->version, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 0, &l);
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
decode_OCSPResponseData(const unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, OCSPResponseData *data, size_t *size)
{
size_t ret = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int e HEIMDAL_UNUSED_ATTRIBUTE;
const unsigned char *begin = p;

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
{
size_t version_datalen, version_oldlen;
Der_type version_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &version_type, 0, &version_datalen, &l);
if (e == 0 && version_type != CONS) { e = ASN1_BAD_ID; }
if(e) {
(data)->version = NULL;
} else {
(data)->version = calloc(1, sizeof(*(data)->version));
if ((data)->version == NULL) { e = ENOMEM; goto fail; }
p += l; len -= l; ret += l;
version_oldlen = len;
if (version_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = version_datalen;
e = decode_OCSPVersion(p, len, (data)->version, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = version_oldlen - version_datalen;
}
}
e = decode_OCSPResponderID(p, len, &(data)->responderID, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
{
size_t producedAt_datalen, producedAt_oldlen;
Der_type producedAt_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &producedAt_type, UT_GeneralizedTime, &producedAt_datalen, &l);
if (e == 0 && producedAt_type != PRIM) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
producedAt_oldlen = len;
if (producedAt_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = producedAt_datalen;
e = der_get_generalized_time(p, len, &(data)->producedAt, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = producedAt_oldlen - producedAt_datalen;
}
{
size_t responses_datalen, responses_oldlen;
Der_type responses_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &responses_type, UT_Sequence, &responses_datalen, &l);
if (e == 0 && responses_type != CONS) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
responses_oldlen = len;
if (responses_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = responses_datalen;
{
size_t responses_Tag_origlen = len;
size_t responses_Tag_oldret = ret;
size_t responses_Tag_olen = 0;
void *responses_Tag_tmp;
ret = 0;
(&(data)->responses)->len = 0;
(&(data)->responses)->val = NULL;
while(ret < responses_Tag_origlen) {
size_t responses_Tag_nlen = responses_Tag_olen + sizeof(*((&(data)->responses)->val));
if (responses_Tag_olen > responses_Tag_nlen) { e = ASN1_OVERFLOW; goto fail; }
responses_Tag_olen = responses_Tag_nlen;
responses_Tag_tmp = realloc((&(data)->responses)->val, responses_Tag_olen);
if (responses_Tag_tmp == NULL) { e = ENOMEM; goto fail; }
(&(data)->responses)->val = responses_Tag_tmp;
e = decode_OCSPSingleResponse(p, len, &(&(data)->responses)->val[(&(data)->responses)->len], &l);
if(e) goto fail;
p += l; len -= l; ret += l;
(&(data)->responses)->len++;
len = responses_Tag_origlen - ret;
}
ret += responses_Tag_oldret;
}
len = responses_oldlen - responses_datalen;
}
{
size_t responseExtensions_datalen, responseExtensions_oldlen;
Der_type responseExtensions_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &responseExtensions_type, 1, &responseExtensions_datalen, &l);
if (e == 0 && responseExtensions_type != CONS) { e = ASN1_BAD_ID; }
if(e) {
(data)->responseExtensions = NULL;
} else {
(data)->responseExtensions = calloc(1, sizeof(*(data)->responseExtensions));
if ((data)->responseExtensions == NULL) { e = ENOMEM; goto fail; }
p += l; len -= l; ret += l;
responseExtensions_oldlen = len;
if (responseExtensions_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = responseExtensions_datalen;
e = decode_Extensions(p, len, (data)->responseExtensions, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = responseExtensions_oldlen - responseExtensions_datalen;
}
}
len = Top_oldlen - Top_datalen;
}
data->_save.data = calloc(1, ret);
if (data->_save.data == NULL) { 
e = ENOMEM; goto fail; 
}
data->_save.length = ret;
memcpy(data->_save.data, begin, ret);
if(size) *size = ret;
return 0;
fail:
free_OCSPResponseData(data);
return e;
}

void ASN1CALL
free_OCSPResponseData(OCSPResponseData *data)
{
der_free_octet_string(&data->_save);
if((data)->version) {
free_OCSPVersion((data)->version);
free((data)->version);
(data)->version = NULL;
}
free_OCSPResponderID(&(data)->responderID);
while((&(data)->responses)->len){
free_OCSPSingleResponse(&(&(data)->responses)->val[(&(data)->responses)->len-1]);
(&(data)->responses)->len--;
}
free((&(data)->responses)->val);
(&(data)->responses)->val = NULL;
if((data)->responseExtensions) {
free_Extensions((data)->responseExtensions);
free((data)->responseExtensions);
(data)->responseExtensions = NULL;
}
}

size_t ASN1CALL
length_OCSPResponseData(const OCSPResponseData *data)
{
size_t ret = 0;
if((data)->version){
size_t Top_tag_oldret = ret;
ret = 0;
ret += length_OCSPVersion((data)->version);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
{
size_t Top_tag_oldret = ret;
ret = 0;
ret += length_OCSPResponderID(&(data)->responderID);
ret += Top_tag_oldret;
}
{
size_t Top_tag_oldret = ret;
ret = 0;
ret += der_length_generalized_time(&(data)->producedAt);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
{
size_t Top_tag_oldret = ret;
ret = 0;
{
size_t responses_tag_oldret = ret;
int i;
ret = 0;
for(i = (&(data)->responses)->len - 1; i >= 0; --i){
size_t responses_tag_for_oldret = ret;
ret = 0;
ret += length_OCSPSingleResponse(&(&(data)->responses)->val[i]);
ret += responses_tag_for_oldret;
}
ret += responses_tag_oldret;
}
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
if((data)->responseExtensions){
size_t Top_tag_oldret = ret;
ret = 0;
ret += length_Extensions((data)->responseExtensions);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
ret += 1 + der_length_len (ret);
return ret;
}

int ASN1CALL
copy_OCSPResponseData(const OCSPResponseData *from, OCSPResponseData *to)
{
memset(to, 0, sizeof(*to));
{ int ret;
ret = der_copy_octet_string(&(from)->_save, &(to)->_save);
if (ret) goto fail;
}
if((from)->version) {
(to)->version = malloc(sizeof(*(to)->version));
if((to)->version == NULL) goto fail;
if(copy_OCSPVersion((from)->version, (to)->version)) goto fail;
}else
(to)->version = NULL;
if(copy_OCSPResponderID(&(from)->responderID, &(to)->responderID)) goto fail;
*(&(to)->producedAt) = *(&(from)->producedAt);
if(((&(to)->responses)->val = malloc((&(from)->responses)->len * sizeof(*(&(to)->responses)->val))) == NULL && (&(from)->responses)->len != 0)
goto fail;
for((&(to)->responses)->len = 0; (&(to)->responses)->len < (&(from)->responses)->len; (&(to)->responses)->len++){
if(copy_OCSPSingleResponse(&(&(from)->responses)->val[(&(to)->responses)->len], &(&(to)->responses)->val[(&(to)->responses)->len])) goto fail;
}
if((from)->responseExtensions) {
(to)->responseExtensions = malloc(sizeof(*(to)->responseExtensions));
if((to)->responseExtensions == NULL) goto fail;
if(copy_Extensions((from)->responseExtensions, (to)->responseExtensions)) goto fail;
}else
(to)->responseExtensions = NULL;
return 0;
fail:
free_OCSPResponseData(to);
return ENOMEM;
}



