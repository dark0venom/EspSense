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
encode_CertRequest(unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, const CertRequest *data, size_t *size)
{
size_t ret HEIMDAL_UNUSED_ATTRIBUTE = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int i HEIMDAL_UNUSED_ATTRIBUTE, e HEIMDAL_UNUSED_ATTRIBUTE;

/* controls */
if((data)->controls) {
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = encode_Controls(p, len, (data)->controls, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* certTemplate */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = encode_CertTemplate(p, len, &(data)->certTemplate, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* certReqId */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = der_put_heim_integer(p, len, &(data)->certReqId, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, PRIM, UT_Integer, &l);
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
decode_CertRequest(const unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, CertRequest *data, size_t *size)
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
{
size_t certReqId_datalen, certReqId_oldlen;
Der_type certReqId_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &certReqId_type, UT_Integer, &certReqId_datalen, &l);
if (e == 0 && certReqId_type != PRIM) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
certReqId_oldlen = len;
if (certReqId_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = certReqId_datalen;
e = der_get_heim_integer(p, len, &(data)->certReqId, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = certReqId_oldlen - certReqId_datalen;
}
e = decode_CertTemplate(p, len, &(data)->certTemplate, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
(data)->controls = calloc(1, sizeof(*(data)->controls));
if ((data)->controls == NULL) goto fail;
e = decode_Controls(p, len, (data)->controls, &l);
if(e) {
free((data)->controls);
(data)->controls = NULL;
} else {
p += l; len -= l; ret += l;
}
len = Top_oldlen - Top_datalen;
}
if(size) *size = ret;
return 0;
fail:
free_CertRequest(data);
return e;
}

void ASN1CALL
free_CertRequest(CertRequest *data)
{
der_free_heim_integer(&(data)->certReqId);
free_CertTemplate(&(data)->certTemplate);
if((data)->controls) {
free_Controls((data)->controls);
free((data)->controls);
(data)->controls = NULL;
}
}

size_t ASN1CALL
length_CertRequest(const CertRequest *data)
{
size_t ret = 0;
{
size_t Top_tag_oldret = ret;
ret = 0;
ret += der_length_heim_integer(&(data)->certReqId);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
{
size_t Top_tag_oldret = ret;
ret = 0;
ret += length_CertTemplate(&(data)->certTemplate);
ret += Top_tag_oldret;
}
if((data)->controls){
size_t Top_tag_oldret = ret;
ret = 0;
ret += length_Controls((data)->controls);
ret += Top_tag_oldret;
}
ret += 1 + der_length_len (ret);
return ret;
}

int ASN1CALL
copy_CertRequest(const CertRequest *from, CertRequest *to)
{
memset(to, 0, sizeof(*to));
if(der_copy_heim_integer(&(from)->certReqId, &(to)->certReqId)) goto fail;
if(copy_CertTemplate(&(from)->certTemplate, &(to)->certTemplate)) goto fail;
if((from)->controls) {
(to)->controls = malloc(sizeof(*(to)->controls));
if((to)->controls == NULL) goto fail;
if(copy_Controls((from)->controls, (to)->controls)) goto fail;
}else
(to)->controls = NULL;
return 0;
fail:
free_CertRequest(to);
return ENOMEM;
}



