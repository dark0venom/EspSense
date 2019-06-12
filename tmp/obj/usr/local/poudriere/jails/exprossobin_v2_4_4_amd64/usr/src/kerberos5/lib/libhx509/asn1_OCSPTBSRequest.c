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
encode_OCSPTBSRequest(unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, const OCSPTBSRequest *data, size_t *size)
{
size_t ret HEIMDAL_UNUSED_ATTRIBUTE = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int i HEIMDAL_UNUSED_ATTRIBUTE, e HEIMDAL_UNUSED_ATTRIBUTE;

/* requestExtensions */
if((data)->requestExtensions) {
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = encode_Extensions(p, len, (data)->requestExtensions, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 2, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* requestList */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
for(i = (int)(&(data)->requestList)->len - 1; i >= 0; --i) {
size_t requestList_tag_for_oldret = ret;
ret = 0;
e = encode_OCSPInnerRequest(p, len, &(&(data)->requestList)->val[i], &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += requestList_tag_for_oldret;
}
e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, CONS, UT_Sequence, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* requestorName */
if((data)->requestorName) {
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = encode_GeneralName(p, len, (data)->requestorName, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 1, &l);
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
decode_OCSPTBSRequest(const unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, OCSPTBSRequest *data, size_t *size)
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
{
size_t requestorName_datalen, requestorName_oldlen;
Der_type requestorName_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &requestorName_type, 1, &requestorName_datalen, &l);
if (e == 0 && requestorName_type != CONS) { e = ASN1_BAD_ID; }
if(e) {
(data)->requestorName = NULL;
} else {
(data)->requestorName = calloc(1, sizeof(*(data)->requestorName));
if ((data)->requestorName == NULL) { e = ENOMEM; goto fail; }
p += l; len -= l; ret += l;
requestorName_oldlen = len;
if (requestorName_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = requestorName_datalen;
e = decode_GeneralName(p, len, (data)->requestorName, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = requestorName_oldlen - requestorName_datalen;
}
}
{
size_t requestList_datalen, requestList_oldlen;
Der_type requestList_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &requestList_type, UT_Sequence, &requestList_datalen, &l);
if (e == 0 && requestList_type != CONS) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
requestList_oldlen = len;
if (requestList_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = requestList_datalen;
{
size_t requestList_Tag_origlen = len;
size_t requestList_Tag_oldret = ret;
size_t requestList_Tag_olen = 0;
void *requestList_Tag_tmp;
ret = 0;
(&(data)->requestList)->len = 0;
(&(data)->requestList)->val = NULL;
while(ret < requestList_Tag_origlen) {
size_t requestList_Tag_nlen = requestList_Tag_olen + sizeof(*((&(data)->requestList)->val));
if (requestList_Tag_olen > requestList_Tag_nlen) { e = ASN1_OVERFLOW; goto fail; }
requestList_Tag_olen = requestList_Tag_nlen;
requestList_Tag_tmp = realloc((&(data)->requestList)->val, requestList_Tag_olen);
if (requestList_Tag_tmp == NULL) { e = ENOMEM; goto fail; }
(&(data)->requestList)->val = requestList_Tag_tmp;
e = decode_OCSPInnerRequest(p, len, &(&(data)->requestList)->val[(&(data)->requestList)->len], &l);
if(e) goto fail;
p += l; len -= l; ret += l;
(&(data)->requestList)->len++;
len = requestList_Tag_origlen - ret;
}
ret += requestList_Tag_oldret;
}
len = requestList_oldlen - requestList_datalen;
}
{
size_t requestExtensions_datalen, requestExtensions_oldlen;
Der_type requestExtensions_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &requestExtensions_type, 2, &requestExtensions_datalen, &l);
if (e == 0 && requestExtensions_type != CONS) { e = ASN1_BAD_ID; }
if(e) {
(data)->requestExtensions = NULL;
} else {
(data)->requestExtensions = calloc(1, sizeof(*(data)->requestExtensions));
if ((data)->requestExtensions == NULL) { e = ENOMEM; goto fail; }
p += l; len -= l; ret += l;
requestExtensions_oldlen = len;
if (requestExtensions_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = requestExtensions_datalen;
e = decode_Extensions(p, len, (data)->requestExtensions, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = requestExtensions_oldlen - requestExtensions_datalen;
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
free_OCSPTBSRequest(data);
return e;
}

void ASN1CALL
free_OCSPTBSRequest(OCSPTBSRequest *data)
{
der_free_octet_string(&data->_save);
if((data)->version) {
free_OCSPVersion((data)->version);
free((data)->version);
(data)->version = NULL;
}
if((data)->requestorName) {
free_GeneralName((data)->requestorName);
free((data)->requestorName);
(data)->requestorName = NULL;
}
while((&(data)->requestList)->len){
free_OCSPInnerRequest(&(&(data)->requestList)->val[(&(data)->requestList)->len-1]);
(&(data)->requestList)->len--;
}
free((&(data)->requestList)->val);
(&(data)->requestList)->val = NULL;
if((data)->requestExtensions) {
free_Extensions((data)->requestExtensions);
free((data)->requestExtensions);
(data)->requestExtensions = NULL;
}
}

size_t ASN1CALL
length_OCSPTBSRequest(const OCSPTBSRequest *data)
{
size_t ret = 0;
if((data)->version){
size_t Top_tag_oldret = ret;
ret = 0;
ret += length_OCSPVersion((data)->version);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
if((data)->requestorName){
size_t Top_tag_oldret = ret;
ret = 0;
ret += length_GeneralName((data)->requestorName);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
{
size_t Top_tag_oldret = ret;
ret = 0;
{
size_t requestList_tag_oldret = ret;
int i;
ret = 0;
for(i = (&(data)->requestList)->len - 1; i >= 0; --i){
size_t requestList_tag_for_oldret = ret;
ret = 0;
ret += length_OCSPInnerRequest(&(&(data)->requestList)->val[i]);
ret += requestList_tag_for_oldret;
}
ret += requestList_tag_oldret;
}
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
if((data)->requestExtensions){
size_t Top_tag_oldret = ret;
ret = 0;
ret += length_Extensions((data)->requestExtensions);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
ret += 1 + der_length_len (ret);
return ret;
}

int ASN1CALL
copy_OCSPTBSRequest(const OCSPTBSRequest *from, OCSPTBSRequest *to)
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
if((from)->requestorName) {
(to)->requestorName = malloc(sizeof(*(to)->requestorName));
if((to)->requestorName == NULL) goto fail;
if(copy_GeneralName((from)->requestorName, (to)->requestorName)) goto fail;
}else
(to)->requestorName = NULL;
if(((&(to)->requestList)->val = malloc((&(from)->requestList)->len * sizeof(*(&(to)->requestList)->val))) == NULL && (&(from)->requestList)->len != 0)
goto fail;
for((&(to)->requestList)->len = 0; (&(to)->requestList)->len < (&(from)->requestList)->len; (&(to)->requestList)->len++){
if(copy_OCSPInnerRequest(&(&(from)->requestList)->val[(&(to)->requestList)->len], &(&(to)->requestList)->val[(&(to)->requestList)->len])) goto fail;
}
if((from)->requestExtensions) {
(to)->requestExtensions = malloc(sizeof(*(to)->requestExtensions));
if((to)->requestExtensions == NULL) goto fail;
if(copy_Extensions((from)->requestExtensions, (to)->requestExtensions)) goto fail;
}else
(to)->requestExtensions = NULL;
return 0;
fail:
free_OCSPTBSRequest(to);
return ENOMEM;
}



