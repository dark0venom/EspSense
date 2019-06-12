/* Generated from /usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/crypto/heimdal/lib/hx509/crmf.asn1 */
/* Do not edit */

#define  ASN1_LIB

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <krb5-types.h>
#include <crmf_asn1.h>
#include <crmf_asn1-priv.h>
#include <asn1_err.h>
#include <der.h>
#include <der-private.h>
#include <asn1-template.h>
#include <parse_units.h>

int ASN1CALL
encode_CertReqMsg(unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, const CertReqMsg *data, size_t *size)
{
size_t ret HEIMDAL_UNUSED_ATTRIBUTE = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int i HEIMDAL_UNUSED_ATTRIBUTE, e HEIMDAL_UNUSED_ATTRIBUTE;

/* regInfo */
if((data)->regInfo) {
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
for(i = (int)((data)->regInfo)->len - 1; i >= 0; --i) {
size_t regInfo_tag_for_oldret = ret;
ret = 0;
e = encode_AttributeTypeAndValue(p, len, &((data)->regInfo)->val[i], &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += regInfo_tag_for_oldret;
}
e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, CONS, UT_Sequence, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* popo */
if((data)->popo) {
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = encode_ProofOfPossession(p, len, (data)->popo, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* certReq */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = encode_CertRequest(p, len, &(data)->certReq, &l);
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
decode_CertReqMsg(const unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, CertReqMsg *data, size_t *size)
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
e = decode_CertRequest(p, len, &(data)->certReq, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
(data)->popo = calloc(1, sizeof(*(data)->popo));
if ((data)->popo == NULL) goto fail;
e = decode_ProofOfPossession(p, len, (data)->popo, &l);
if(e) {
free((data)->popo);
(data)->popo = NULL;
} else {
p += l; len -= l; ret += l;
}
{
size_t regInfo_datalen, regInfo_oldlen;
Der_type regInfo_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &regInfo_type, UT_Sequence, &regInfo_datalen, &l);
if (e == 0 && regInfo_type != CONS) { e = ASN1_BAD_ID; }
if(e) {
(data)->regInfo = NULL;
} else {
(data)->regInfo = calloc(1, sizeof(*(data)->regInfo));
if ((data)->regInfo == NULL) { e = ENOMEM; goto fail; }
p += l; len -= l; ret += l;
regInfo_oldlen = len;
if (regInfo_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = regInfo_datalen;
{
size_t regInfo_Tag_origlen = len;
size_t regInfo_Tag_oldret = ret;
size_t regInfo_Tag_olen = 0;
void *regInfo_Tag_tmp;
ret = 0;
((data)->regInfo)->len = 0;
((data)->regInfo)->val = NULL;
while(ret < regInfo_Tag_origlen) {
size_t regInfo_Tag_nlen = regInfo_Tag_olen + sizeof(*(((data)->regInfo)->val));
if (regInfo_Tag_olen > regInfo_Tag_nlen) { e = ASN1_OVERFLOW; goto fail; }
regInfo_Tag_olen = regInfo_Tag_nlen;
regInfo_Tag_tmp = realloc(((data)->regInfo)->val, regInfo_Tag_olen);
if (regInfo_Tag_tmp == NULL) { e = ENOMEM; goto fail; }
((data)->regInfo)->val = regInfo_Tag_tmp;
e = decode_AttributeTypeAndValue(p, len, &((data)->regInfo)->val[((data)->regInfo)->len], &l);
if(e) goto fail;
p += l; len -= l; ret += l;
((data)->regInfo)->len++;
len = regInfo_Tag_origlen - ret;
}
ret += regInfo_Tag_oldret;
}
len = regInfo_oldlen - regInfo_datalen;
}
}
len = Top_oldlen - Top_datalen;
}
if(size) *size = ret;
return 0;
fail:
free_CertReqMsg(data);
return e;
}

void ASN1CALL
free_CertReqMsg(CertReqMsg *data)
{
free_CertRequest(&(data)->certReq);
if((data)->popo) {
free_ProofOfPossession((data)->popo);
free((data)->popo);
(data)->popo = NULL;
}
if((data)->regInfo) {
while(((data)->regInfo)->len){
free_AttributeTypeAndValue(&((data)->regInfo)->val[((data)->regInfo)->len-1]);
((data)->regInfo)->len--;
}
free(((data)->regInfo)->val);
((data)->regInfo)->val = NULL;
free((data)->regInfo);
(data)->regInfo = NULL;
}
}

size_t ASN1CALL
length_CertReqMsg(const CertReqMsg *data)
{
size_t ret = 0;
{
size_t Top_tag_oldret = ret;
ret = 0;
ret += length_CertRequest(&(data)->certReq);
ret += Top_tag_oldret;
}
if((data)->popo){
size_t Top_tag_oldret = ret;
ret = 0;
ret += length_ProofOfPossession((data)->popo);
ret += Top_tag_oldret;
}
if((data)->regInfo){
size_t Top_tag_oldret = ret;
ret = 0;
{
size_t regInfo_tag_oldret = ret;
int i;
ret = 0;
for(i = ((data)->regInfo)->len - 1; i >= 0; --i){
size_t regInfo_tag_for_oldret = ret;
ret = 0;
ret += length_AttributeTypeAndValue(&((data)->regInfo)->val[i]);
ret += regInfo_tag_for_oldret;
}
ret += regInfo_tag_oldret;
}
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
ret += 1 + der_length_len (ret);
return ret;
}

int ASN1CALL
copy_CertReqMsg(const CertReqMsg *from, CertReqMsg *to)
{
memset(to, 0, sizeof(*to));
if(copy_CertRequest(&(from)->certReq, &(to)->certReq)) goto fail;
if((from)->popo) {
(to)->popo = malloc(sizeof(*(to)->popo));
if((to)->popo == NULL) goto fail;
if(copy_ProofOfPossession((from)->popo, (to)->popo)) goto fail;
}else
(to)->popo = NULL;
if((from)->regInfo) {
(to)->regInfo = malloc(sizeof(*(to)->regInfo));
if((to)->regInfo == NULL) goto fail;
if((((to)->regInfo)->val = malloc(((from)->regInfo)->len * sizeof(*((to)->regInfo)->val))) == NULL && ((from)->regInfo)->len != 0)
goto fail;
for(((to)->regInfo)->len = 0; ((to)->regInfo)->len < ((from)->regInfo)->len; ((to)->regInfo)->len++){
if(copy_AttributeTypeAndValue(&((from)->regInfo)->val[((to)->regInfo)->len], &((to)->regInfo)->val[((to)->regInfo)->len])) goto fail;
}
}else
(to)->regInfo = NULL;
return 0;
fail:
free_CertReqMsg(to);
return ENOMEM;
}



