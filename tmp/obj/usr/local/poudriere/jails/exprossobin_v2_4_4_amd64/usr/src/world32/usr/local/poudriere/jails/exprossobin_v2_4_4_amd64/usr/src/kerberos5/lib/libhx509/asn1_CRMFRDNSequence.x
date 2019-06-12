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
encode_CRMFRDNSequence(unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, const CRMFRDNSequence *data, size_t *size)
{
size_t ret HEIMDAL_UNUSED_ATTRIBUTE = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int i HEIMDAL_UNUSED_ATTRIBUTE, e HEIMDAL_UNUSED_ATTRIBUTE;

for(i = (int)(data)->len - 1; i >= 0; --i) {
size_t Top_tag_for_oldret = ret;
ret = 0;
e = encode_RelativeDistinguishedName(p, len, &(data)->val[i], &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_for_oldret;
}
e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, CONS, UT_Sequence, &l);
if (e) return e;
p -= l; len -= l; ret += l;

*size = ret;
return 0;
}

int ASN1CALL
decode_CRMFRDNSequence(const unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, CRMFRDNSequence *data, size_t *size)
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
size_t Top_Tag_origlen = len;
size_t Top_Tag_oldret = ret;
size_t Top_Tag_olen = 0;
void *Top_Tag_tmp;
ret = 0;
(data)->len = 0;
(data)->val = NULL;
while(ret < Top_Tag_origlen) {
size_t Top_Tag_nlen = Top_Tag_olen + sizeof(*((data)->val));
if (Top_Tag_olen > Top_Tag_nlen) { e = ASN1_OVERFLOW; goto fail; }
Top_Tag_olen = Top_Tag_nlen;
Top_Tag_tmp = realloc((data)->val, Top_Tag_olen);
if (Top_Tag_tmp == NULL) { e = ENOMEM; goto fail; }
(data)->val = Top_Tag_tmp;
e = decode_RelativeDistinguishedName(p, len, &(data)->val[(data)->len], &l);
if(e) goto fail;
p += l; len -= l; ret += l;
(data)->len++;
len = Top_Tag_origlen - ret;
}
ret += Top_Tag_oldret;
}
len = Top_oldlen - Top_datalen;
}
if(size) *size = ret;
return 0;
fail:
free_CRMFRDNSequence(data);
return e;
}

void ASN1CALL
free_CRMFRDNSequence(CRMFRDNSequence *data)
{
while((data)->len){
free_RelativeDistinguishedName(&(data)->val[(data)->len-1]);
(data)->len--;
}
free((data)->val);
(data)->val = NULL;
}

size_t ASN1CALL
length_CRMFRDNSequence(const CRMFRDNSequence *data)
{
size_t ret = 0;
{
size_t Top_tag_oldret = ret;
int i;
ret = 0;
for(i = (data)->len - 1; i >= 0; --i){
size_t Top_tag_for_oldret = ret;
ret = 0;
ret += length_RelativeDistinguishedName(&(data)->val[i]);
ret += Top_tag_for_oldret;
}
ret += Top_tag_oldret;
}
ret += 1 + der_length_len (ret);
return ret;
}

int ASN1CALL
copy_CRMFRDNSequence(const CRMFRDNSequence *from, CRMFRDNSequence *to)
{
memset(to, 0, sizeof(*to));
if(((to)->val = malloc((from)->len * sizeof(*(to)->val))) == NULL && (from)->len != 0)
goto fail;
for((to)->len = 0; (to)->len < (from)->len; (to)->len++){
if(copy_RelativeDistinguishedName(&(from)->val[(to)->len], &(to)->val[(to)->len])) goto fail;
}
return 0;
fail:
free_CRMFRDNSequence(to);
return ENOMEM;
}



