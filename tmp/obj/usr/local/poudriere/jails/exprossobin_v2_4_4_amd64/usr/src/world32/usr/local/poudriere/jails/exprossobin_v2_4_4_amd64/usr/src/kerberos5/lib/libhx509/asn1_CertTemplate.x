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
encode_CertTemplate(unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, const CertTemplate *data, size_t *size)
{
size_t ret HEIMDAL_UNUSED_ATTRIBUTE = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int i HEIMDAL_UNUSED_ATTRIBUTE, e HEIMDAL_UNUSED_ATTRIBUTE;

/* extensions */
if((data)->extensions) {
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
for(i = (int)((data)->extensions)->len - 1; i >= 0; --i) {
size_t extensions_tag_for_oldret = ret;
ret = 0;
e = encode_Extension(p, len, &((data)->extensions)->val[i], &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += extensions_tag_for_oldret;
}
e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 9, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* subjectUID */
if((data)->subjectUID) {
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = der_put_bit_string(p, len, (data)->subjectUID, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, PRIM, 8, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* issuerUID */
if((data)->issuerUID) {
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = der_put_bit_string(p, len, (data)->issuerUID, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, PRIM, 7, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* publicKey */
if((data)->publicKey) {
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
/* subjectPublicKey */
if(((data)->publicKey)->subjectPublicKey) {
size_t publicKey_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = der_put_bit_string(p, len, ((data)->publicKey)->subjectPublicKey, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, PRIM, UT_BitString, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += publicKey_tag_oldret;
}
/* algorithm */
{
size_t publicKey_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = encode_AlgorithmIdentifier(p, len, &((data)->publicKey)->algorithm, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += publicKey_tag_oldret;
}
e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 6, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* subject */
if((data)->subject) {
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;

switch(((data)->subject)->element) {
case choice_CertTemplate_subject_rdnSequence: {size_t subject_tag_oldret = ret;
ret = 0;
e = encode_CRMFRDNSequence(p, len, &(((data)->subject))->u.rdnSequence, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += subject_tag_oldret;
break;
}
};
e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 5, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* validity */
if((data)->validity) {
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
/* notAfter */
if(((data)->validity)->notAfter) {
size_t validity_tag_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = encode_Time(p, len, ((data)->validity)->notAfter, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 1, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += validity_tag_tag_oldret;
}
/* notBefore */
if(((data)->validity)->notBefore) {
size_t validity_tag_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = encode_Time(p, len, ((data)->validity)->notBefore, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 0, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += validity_tag_tag_oldret;
}
e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, CONS, UT_Sequence, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 4, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* issuer */
if((data)->issuer) {
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;

switch(((data)->issuer)->element) {
case choice_CertTemplate_issuer_rdnSequence: {size_t issuer_tag_oldret = ret;
ret = 0;
e = encode_CRMFRDNSequence(p, len, &(((data)->issuer))->u.rdnSequence, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += issuer_tag_oldret;
break;
}
};
e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 3, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* signingAlg */
if((data)->signingAlg) {
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
/* parameters */
if(((data)->signingAlg)->parameters) {
size_t signingAlg_tag_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = encode_heim_any(p, len, ((data)->signingAlg)->parameters, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += signingAlg_tag_tag_oldret;
}
/* algorithm */
{
size_t signingAlg_tag_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = der_put_oid(p, len, &((data)->signingAlg)->algorithm, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, PRIM, UT_OID, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += signingAlg_tag_tag_oldret;
}
e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, CONS, UT_Sequence, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 2, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* serialNumber */
if((data)->serialNumber) {
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = der_put_heim_integer(p, len, (data)->serialNumber, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, PRIM, UT_Integer, &l);
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
e = der_put_heim_integer(p, len, (data)->version, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, PRIM, UT_Integer, &l);
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
decode_CertTemplate(const unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, CertTemplate *data, size_t *size)
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
{
size_t version_Tag_datalen, version_Tag_oldlen;
Der_type version_Tag_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &version_Tag_type, UT_Integer, &version_Tag_datalen, &l);
if (e == 0 && version_Tag_type != PRIM) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
version_Tag_oldlen = len;
if (version_Tag_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = version_Tag_datalen;
e = der_get_heim_integer(p, len, (data)->version, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = version_Tag_oldlen - version_Tag_datalen;
}
len = version_oldlen - version_datalen;
}
}
{
size_t serialNumber_datalen, serialNumber_oldlen;
Der_type serialNumber_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &serialNumber_type, 1, &serialNumber_datalen, &l);
if (e == 0 && serialNumber_type != CONS) { e = ASN1_BAD_ID; }
if(e) {
(data)->serialNumber = NULL;
} else {
(data)->serialNumber = calloc(1, sizeof(*(data)->serialNumber));
if ((data)->serialNumber == NULL) { e = ENOMEM; goto fail; }
p += l; len -= l; ret += l;
serialNumber_oldlen = len;
if (serialNumber_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = serialNumber_datalen;
{
size_t serialNumber_Tag_datalen, serialNumber_Tag_oldlen;
Der_type serialNumber_Tag_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &serialNumber_Tag_type, UT_Integer, &serialNumber_Tag_datalen, &l);
if (e == 0 && serialNumber_Tag_type != PRIM) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
serialNumber_Tag_oldlen = len;
if (serialNumber_Tag_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = serialNumber_Tag_datalen;
e = der_get_heim_integer(p, len, (data)->serialNumber, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = serialNumber_Tag_oldlen - serialNumber_Tag_datalen;
}
len = serialNumber_oldlen - serialNumber_datalen;
}
}
{
size_t signingAlg_datalen, signingAlg_oldlen;
Der_type signingAlg_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &signingAlg_type, 2, &signingAlg_datalen, &l);
if (e == 0 && signingAlg_type != CONS) { e = ASN1_BAD_ID; }
if(e) {
(data)->signingAlg = NULL;
} else {
(data)->signingAlg = calloc(1, sizeof(*(data)->signingAlg));
if ((data)->signingAlg == NULL) { e = ENOMEM; goto fail; }
p += l; len -= l; ret += l;
signingAlg_oldlen = len;
if (signingAlg_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = signingAlg_datalen;
{
size_t signingAlg_Tag_datalen, signingAlg_Tag_oldlen;
Der_type signingAlg_Tag_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &signingAlg_Tag_type, UT_Sequence, &signingAlg_Tag_datalen, &l);
if (e == 0 && signingAlg_Tag_type != CONS) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
signingAlg_Tag_oldlen = len;
if (signingAlg_Tag_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = signingAlg_Tag_datalen;
{
size_t algorithm_datalen, algorithm_oldlen;
Der_type algorithm_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &algorithm_type, UT_OID, &algorithm_datalen, &l);
if (e == 0 && algorithm_type != PRIM) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
algorithm_oldlen = len;
if (algorithm_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = algorithm_datalen;
e = der_get_oid(p, len, &((data)->signingAlg)->algorithm, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = algorithm_oldlen - algorithm_datalen;
}
((data)->signingAlg)->parameters = calloc(1, sizeof(*((data)->signingAlg)->parameters));
if (((data)->signingAlg)->parameters == NULL) goto fail;
e = decode_heim_any(p, len, ((data)->signingAlg)->parameters, &l);
if(e) {
free(((data)->signingAlg)->parameters);
((data)->signingAlg)->parameters = NULL;
} else {
p += l; len -= l; ret += l;
}
len = signingAlg_Tag_oldlen - signingAlg_Tag_datalen;
}
len = signingAlg_oldlen - signingAlg_datalen;
}
}
{
size_t issuer_datalen, issuer_oldlen;
Der_type issuer_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &issuer_type, 3, &issuer_datalen, &l);
if (e == 0 && issuer_type != CONS) { e = ASN1_BAD_ID; }
if(e) {
(data)->issuer = NULL;
} else {
(data)->issuer = calloc(1, sizeof(*(data)->issuer));
if ((data)->issuer == NULL) { e = ENOMEM; goto fail; }
p += l; len -= l; ret += l;
issuer_oldlen = len;
if (issuer_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = issuer_datalen;
if (der_match_tag(p, len, ASN1_C_UNIV, CONS, UT_Sequence, NULL) == 0) {
e = decode_CRMFRDNSequence(p, len, &((data)->issuer)->u.rdnSequence, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
((data)->issuer)->element = choice_CertTemplate_issuer_rdnSequence;
}
else {
e = ASN1_PARSE_ERROR;
goto fail;
}
len = issuer_oldlen - issuer_datalen;
}
}
{
size_t validity_datalen, validity_oldlen;
Der_type validity_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &validity_type, 4, &validity_datalen, &l);
if (e == 0 && validity_type != CONS) { e = ASN1_BAD_ID; }
if(e) {
(data)->validity = NULL;
} else {
(data)->validity = calloc(1, sizeof(*(data)->validity));
if ((data)->validity == NULL) { e = ENOMEM; goto fail; }
p += l; len -= l; ret += l;
validity_oldlen = len;
if (validity_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = validity_datalen;
{
size_t validity_Tag_datalen, validity_Tag_oldlen;
Der_type validity_Tag_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &validity_Tag_type, UT_Sequence, &validity_Tag_datalen, &l);
if (e == 0 && validity_Tag_type != CONS) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
validity_Tag_oldlen = len;
if (validity_Tag_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = validity_Tag_datalen;
{
size_t notBefore_datalen, notBefore_oldlen;
Der_type notBefore_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &notBefore_type, 0, &notBefore_datalen, &l);
if (e == 0 && notBefore_type != CONS) { e = ASN1_BAD_ID; }
if(e) {
((data)->validity)->notBefore = NULL;
} else {
((data)->validity)->notBefore = calloc(1, sizeof(*((data)->validity)->notBefore));
if (((data)->validity)->notBefore == NULL) { e = ENOMEM; goto fail; }
p += l; len -= l; ret += l;
notBefore_oldlen = len;
if (notBefore_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = notBefore_datalen;
e = decode_Time(p, len, ((data)->validity)->notBefore, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = notBefore_oldlen - notBefore_datalen;
}
}
{
size_t notAfter_datalen, notAfter_oldlen;
Der_type notAfter_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &notAfter_type, 1, &notAfter_datalen, &l);
if (e == 0 && notAfter_type != CONS) { e = ASN1_BAD_ID; }
if(e) {
((data)->validity)->notAfter = NULL;
} else {
((data)->validity)->notAfter = calloc(1, sizeof(*((data)->validity)->notAfter));
if (((data)->validity)->notAfter == NULL) { e = ENOMEM; goto fail; }
p += l; len -= l; ret += l;
notAfter_oldlen = len;
if (notAfter_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = notAfter_datalen;
e = decode_Time(p, len, ((data)->validity)->notAfter, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = notAfter_oldlen - notAfter_datalen;
}
}
len = validity_Tag_oldlen - validity_Tag_datalen;
}
len = validity_oldlen - validity_datalen;
}
}
{
size_t subject_datalen, subject_oldlen;
Der_type subject_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &subject_type, 5, &subject_datalen, &l);
if (e == 0 && subject_type != CONS) { e = ASN1_BAD_ID; }
if(e) {
(data)->subject = NULL;
} else {
(data)->subject = calloc(1, sizeof(*(data)->subject));
if ((data)->subject == NULL) { e = ENOMEM; goto fail; }
p += l; len -= l; ret += l;
subject_oldlen = len;
if (subject_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = subject_datalen;
if (der_match_tag(p, len, ASN1_C_UNIV, CONS, UT_Sequence, NULL) == 0) {
e = decode_CRMFRDNSequence(p, len, &((data)->subject)->u.rdnSequence, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
((data)->subject)->element = choice_CertTemplate_subject_rdnSequence;
}
else {
e = ASN1_PARSE_ERROR;
goto fail;
}
len = subject_oldlen - subject_datalen;
}
}
{
size_t publicKey_datalen, publicKey_oldlen;
Der_type publicKey_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &publicKey_type, 6, &publicKey_datalen, &l);
if (e == 0 && publicKey_type != CONS) { e = ASN1_BAD_ID; }
if(e) {
(data)->publicKey = NULL;
} else {
(data)->publicKey = calloc(1, sizeof(*(data)->publicKey));
if ((data)->publicKey == NULL) { e = ENOMEM; goto fail; }
p += l; len -= l; ret += l;
publicKey_oldlen = len;
if (publicKey_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = publicKey_datalen;
e = decode_AlgorithmIdentifier(p, len, &((data)->publicKey)->algorithm, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
{
size_t subjectPublicKey_datalen, subjectPublicKey_oldlen;
Der_type subjectPublicKey_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &subjectPublicKey_type, UT_BitString, &subjectPublicKey_datalen, &l);
if (e == 0 && subjectPublicKey_type != PRIM) { e = ASN1_BAD_ID; }
if(e) {
((data)->publicKey)->subjectPublicKey = NULL;
} else {
((data)->publicKey)->subjectPublicKey = calloc(1, sizeof(*((data)->publicKey)->subjectPublicKey));
if (((data)->publicKey)->subjectPublicKey == NULL) { e = ENOMEM; goto fail; }
p += l; len -= l; ret += l;
subjectPublicKey_oldlen = len;
if (subjectPublicKey_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = subjectPublicKey_datalen;
e = der_get_bit_string(p, len, ((data)->publicKey)->subjectPublicKey, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = subjectPublicKey_oldlen - subjectPublicKey_datalen;
}
}
len = publicKey_oldlen - publicKey_datalen;
}
}
{
size_t issuerUID_datalen, issuerUID_oldlen;
Der_type issuerUID_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &issuerUID_type, 7, &issuerUID_datalen, &l);
if (e == 0 && issuerUID_type != PRIM) { e = ASN1_BAD_ID; }
if(e) {
(data)->issuerUID = NULL;
} else {
(data)->issuerUID = calloc(1, sizeof(*(data)->issuerUID));
if ((data)->issuerUID == NULL) { e = ENOMEM; goto fail; }
p += l; len -= l; ret += l;
issuerUID_oldlen = len;
if (issuerUID_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = issuerUID_datalen;
e = der_get_bit_string(p, len, (data)->issuerUID, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = issuerUID_oldlen - issuerUID_datalen;
}
}
{
size_t subjectUID_datalen, subjectUID_oldlen;
Der_type subjectUID_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &subjectUID_type, 8, &subjectUID_datalen, &l);
if (e == 0 && subjectUID_type != PRIM) { e = ASN1_BAD_ID; }
if(e) {
(data)->subjectUID = NULL;
} else {
(data)->subjectUID = calloc(1, sizeof(*(data)->subjectUID));
if ((data)->subjectUID == NULL) { e = ENOMEM; goto fail; }
p += l; len -= l; ret += l;
subjectUID_oldlen = len;
if (subjectUID_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = subjectUID_datalen;
e = der_get_bit_string(p, len, (data)->subjectUID, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = subjectUID_oldlen - subjectUID_datalen;
}
}
{
size_t extensions_datalen, extensions_oldlen;
Der_type extensions_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &extensions_type, 9, &extensions_datalen, &l);
if (e == 0 && extensions_type != CONS) { e = ASN1_BAD_ID; }
if(e) {
(data)->extensions = NULL;
} else {
(data)->extensions = calloc(1, sizeof(*(data)->extensions));
if ((data)->extensions == NULL) { e = ENOMEM; goto fail; }
p += l; len -= l; ret += l;
extensions_oldlen = len;
if (extensions_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = extensions_datalen;
{
size_t extensions_Tag_origlen = len;
size_t extensions_Tag_oldret = ret;
size_t extensions_Tag_olen = 0;
void *extensions_Tag_tmp;
ret = 0;
((data)->extensions)->len = 0;
((data)->extensions)->val = NULL;
while(ret < extensions_Tag_origlen) {
size_t extensions_Tag_nlen = extensions_Tag_olen + sizeof(*(((data)->extensions)->val));
if (extensions_Tag_olen > extensions_Tag_nlen) { e = ASN1_OVERFLOW; goto fail; }
extensions_Tag_olen = extensions_Tag_nlen;
extensions_Tag_tmp = realloc(((data)->extensions)->val, extensions_Tag_olen);
if (extensions_Tag_tmp == NULL) { e = ENOMEM; goto fail; }
((data)->extensions)->val = extensions_Tag_tmp;
e = decode_Extension(p, len, &((data)->extensions)->val[((data)->extensions)->len], &l);
if(e) goto fail;
p += l; len -= l; ret += l;
((data)->extensions)->len++;
len = extensions_Tag_origlen - ret;
}
ret += extensions_Tag_oldret;
}
len = extensions_oldlen - extensions_datalen;
}
}
len = Top_oldlen - Top_datalen;
}
if(size) *size = ret;
return 0;
fail:
free_CertTemplate(data);
return e;
}

void ASN1CALL
free_CertTemplate(CertTemplate *data)
{
if((data)->version) {
der_free_heim_integer((data)->version);
free((data)->version);
(data)->version = NULL;
}
if((data)->serialNumber) {
der_free_heim_integer((data)->serialNumber);
free((data)->serialNumber);
(data)->serialNumber = NULL;
}
if((data)->signingAlg) {
der_free_oid(&((data)->signingAlg)->algorithm);
if(((data)->signingAlg)->parameters) {
free_heim_any(((data)->signingAlg)->parameters);
free(((data)->signingAlg)->parameters);
((data)->signingAlg)->parameters = NULL;
}
free((data)->signingAlg);
(data)->signingAlg = NULL;
}
if((data)->issuer) {
switch(((data)->issuer)->element) {
case choice_CertTemplate_issuer_rdnSequence:
free_CRMFRDNSequence(&((data)->issuer)->u.rdnSequence);
break;
}
free((data)->issuer);
(data)->issuer = NULL;
}
if((data)->validity) {
if(((data)->validity)->notBefore) {
free_Time(((data)->validity)->notBefore);
free(((data)->validity)->notBefore);
((data)->validity)->notBefore = NULL;
}
if(((data)->validity)->notAfter) {
free_Time(((data)->validity)->notAfter);
free(((data)->validity)->notAfter);
((data)->validity)->notAfter = NULL;
}
free((data)->validity);
(data)->validity = NULL;
}
if((data)->subject) {
switch(((data)->subject)->element) {
case choice_CertTemplate_subject_rdnSequence:
free_CRMFRDNSequence(&((data)->subject)->u.rdnSequence);
break;
}
free((data)->subject);
(data)->subject = NULL;
}
if((data)->publicKey) {
free_AlgorithmIdentifier(&((data)->publicKey)->algorithm);
if(((data)->publicKey)->subjectPublicKey) {
der_free_bit_string(((data)->publicKey)->subjectPublicKey);
free(((data)->publicKey)->subjectPublicKey);
((data)->publicKey)->subjectPublicKey = NULL;
}
free((data)->publicKey);
(data)->publicKey = NULL;
}
if((data)->issuerUID) {
der_free_bit_string((data)->issuerUID);
free((data)->issuerUID);
(data)->issuerUID = NULL;
}
if((data)->subjectUID) {
der_free_bit_string((data)->subjectUID);
free((data)->subjectUID);
(data)->subjectUID = NULL;
}
if((data)->extensions) {
while(((data)->extensions)->len){
free_Extension(&((data)->extensions)->val[((data)->extensions)->len-1]);
((data)->extensions)->len--;
}
free(((data)->extensions)->val);
((data)->extensions)->val = NULL;
free((data)->extensions);
(data)->extensions = NULL;
}
}

size_t ASN1CALL
length_CertTemplate(const CertTemplate *data)
{
size_t ret = 0;
if((data)->version){
size_t Top_tag_oldret = ret;
ret = 0;
ret += der_length_heim_integer((data)->version);
ret += 1 + der_length_len (ret);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
if((data)->serialNumber){
size_t Top_tag_oldret = ret;
ret = 0;
ret += der_length_heim_integer((data)->serialNumber);
ret += 1 + der_length_len (ret);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
if((data)->signingAlg){
size_t Top_tag_oldret = ret;
ret = 0;
{
size_t signingAlg_tag_tag_oldret = ret;
ret = 0;
ret += der_length_oid(&((data)->signingAlg)->algorithm);
ret += 1 + der_length_len (ret);
ret += signingAlg_tag_tag_oldret;
}
if(((data)->signingAlg)->parameters){
size_t signingAlg_tag_tag_oldret = ret;
ret = 0;
ret += length_heim_any(((data)->signingAlg)->parameters);
ret += signingAlg_tag_tag_oldret;
}
ret += 1 + der_length_len (ret);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
if((data)->issuer){
size_t Top_tag_oldret = ret;
ret = 0;
switch(((data)->issuer)->element) {
case choice_CertTemplate_issuer_rdnSequence:
{
size_t issuer_tag_oldret = ret;
ret = 0;
ret += length_CRMFRDNSequence(&((data)->issuer)->u.rdnSequence);
ret += issuer_tag_oldret;
}
break;
}
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
if((data)->validity){
size_t Top_tag_oldret = ret;
ret = 0;
if(((data)->validity)->notBefore){
size_t validity_tag_tag_oldret = ret;
ret = 0;
ret += length_Time(((data)->validity)->notBefore);
ret += 1 + der_length_len (ret);
ret += validity_tag_tag_oldret;
}
if(((data)->validity)->notAfter){
size_t validity_tag_tag_oldret = ret;
ret = 0;
ret += length_Time(((data)->validity)->notAfter);
ret += 1 + der_length_len (ret);
ret += validity_tag_tag_oldret;
}
ret += 1 + der_length_len (ret);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
if((data)->subject){
size_t Top_tag_oldret = ret;
ret = 0;
switch(((data)->subject)->element) {
case choice_CertTemplate_subject_rdnSequence:
{
size_t subject_tag_oldret = ret;
ret = 0;
ret += length_CRMFRDNSequence(&((data)->subject)->u.rdnSequence);
ret += subject_tag_oldret;
}
break;
}
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
if((data)->publicKey){
size_t Top_tag_oldret = ret;
ret = 0;
{
size_t publicKey_tag_oldret = ret;
ret = 0;
ret += length_AlgorithmIdentifier(&((data)->publicKey)->algorithm);
ret += publicKey_tag_oldret;
}
if(((data)->publicKey)->subjectPublicKey){
size_t publicKey_tag_oldret = ret;
ret = 0;
ret += der_length_bit_string(((data)->publicKey)->subjectPublicKey);
ret += 1 + der_length_len (ret);
ret += publicKey_tag_oldret;
}
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
if((data)->issuerUID){
size_t Top_tag_oldret = ret;
ret = 0;
ret += der_length_bit_string((data)->issuerUID);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
if((data)->subjectUID){
size_t Top_tag_oldret = ret;
ret = 0;
ret += der_length_bit_string((data)->subjectUID);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
if((data)->extensions){
size_t Top_tag_oldret = ret;
ret = 0;
{
size_t extensions_tag_oldret = ret;
int i;
ret = 0;
for(i = ((data)->extensions)->len - 1; i >= 0; --i){
size_t extensions_tag_for_oldret = ret;
ret = 0;
ret += length_Extension(&((data)->extensions)->val[i]);
ret += extensions_tag_for_oldret;
}
ret += extensions_tag_oldret;
}
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
ret += 1 + der_length_len (ret);
return ret;
}

int ASN1CALL
copy_CertTemplate(const CertTemplate *from, CertTemplate *to)
{
memset(to, 0, sizeof(*to));
if((from)->version) {
(to)->version = malloc(sizeof(*(to)->version));
if((to)->version == NULL) goto fail;
if(der_copy_heim_integer((from)->version, (to)->version)) goto fail;
}else
(to)->version = NULL;
if((from)->serialNumber) {
(to)->serialNumber = malloc(sizeof(*(to)->serialNumber));
if((to)->serialNumber == NULL) goto fail;
if(der_copy_heim_integer((from)->serialNumber, (to)->serialNumber)) goto fail;
}else
(to)->serialNumber = NULL;
if((from)->signingAlg) {
(to)->signingAlg = malloc(sizeof(*(to)->signingAlg));
if((to)->signingAlg == NULL) goto fail;
if(der_copy_oid(&((from)->signingAlg)->algorithm, &((to)->signingAlg)->algorithm)) goto fail;
if(((from)->signingAlg)->parameters) {
((to)->signingAlg)->parameters = malloc(sizeof(*((to)->signingAlg)->parameters));
if(((to)->signingAlg)->parameters == NULL) goto fail;
if(copy_heim_any(((from)->signingAlg)->parameters, ((to)->signingAlg)->parameters)) goto fail;
}else
((to)->signingAlg)->parameters = NULL;
}else
(to)->signingAlg = NULL;
if((from)->issuer) {
(to)->issuer = malloc(sizeof(*(to)->issuer));
if((to)->issuer == NULL) goto fail;
((to)->issuer)->element = ((from)->issuer)->element;
switch(((from)->issuer)->element) {
case choice_CertTemplate_issuer_rdnSequence:
if(copy_CRMFRDNSequence(&((from)->issuer)->u.rdnSequence, &((to)->issuer)->u.rdnSequence)) goto fail;
break;
}
}else
(to)->issuer = NULL;
if((from)->validity) {
(to)->validity = malloc(sizeof(*(to)->validity));
if((to)->validity == NULL) goto fail;
if(((from)->validity)->notBefore) {
((to)->validity)->notBefore = malloc(sizeof(*((to)->validity)->notBefore));
if(((to)->validity)->notBefore == NULL) goto fail;
if(copy_Time(((from)->validity)->notBefore, ((to)->validity)->notBefore)) goto fail;
}else
((to)->validity)->notBefore = NULL;
if(((from)->validity)->notAfter) {
((to)->validity)->notAfter = malloc(sizeof(*((to)->validity)->notAfter));
if(((to)->validity)->notAfter == NULL) goto fail;
if(copy_Time(((from)->validity)->notAfter, ((to)->validity)->notAfter)) goto fail;
}else
((to)->validity)->notAfter = NULL;
}else
(to)->validity = NULL;
if((from)->subject) {
(to)->subject = malloc(sizeof(*(to)->subject));
if((to)->subject == NULL) goto fail;
((to)->subject)->element = ((from)->subject)->element;
switch(((from)->subject)->element) {
case choice_CertTemplate_subject_rdnSequence:
if(copy_CRMFRDNSequence(&((from)->subject)->u.rdnSequence, &((to)->subject)->u.rdnSequence)) goto fail;
break;
}
}else
(to)->subject = NULL;
if((from)->publicKey) {
(to)->publicKey = malloc(sizeof(*(to)->publicKey));
if((to)->publicKey == NULL) goto fail;
if(copy_AlgorithmIdentifier(&((from)->publicKey)->algorithm, &((to)->publicKey)->algorithm)) goto fail;
if(((from)->publicKey)->subjectPublicKey) {
((to)->publicKey)->subjectPublicKey = malloc(sizeof(*((to)->publicKey)->subjectPublicKey));
if(((to)->publicKey)->subjectPublicKey == NULL) goto fail;
if(der_copy_bit_string(((from)->publicKey)->subjectPublicKey, ((to)->publicKey)->subjectPublicKey)) goto fail;
}else
((to)->publicKey)->subjectPublicKey = NULL;
}else
(to)->publicKey = NULL;
if((from)->issuerUID) {
(to)->issuerUID = malloc(sizeof(*(to)->issuerUID));
if((to)->issuerUID == NULL) goto fail;
if(der_copy_bit_string((from)->issuerUID, (to)->issuerUID)) goto fail;
}else
(to)->issuerUID = NULL;
if((from)->subjectUID) {
(to)->subjectUID = malloc(sizeof(*(to)->subjectUID));
if((to)->subjectUID == NULL) goto fail;
if(der_copy_bit_string((from)->subjectUID, (to)->subjectUID)) goto fail;
}else
(to)->subjectUID = NULL;
if((from)->extensions) {
(to)->extensions = malloc(sizeof(*(to)->extensions));
if((to)->extensions == NULL) goto fail;
if((((to)->extensions)->val = malloc(((from)->extensions)->len * sizeof(*((to)->extensions)->val))) == NULL && ((from)->extensions)->len != 0)
goto fail;
for(((to)->extensions)->len = 0; ((to)->extensions)->len < ((from)->extensions)->len; ((to)->extensions)->len++){
if(copy_Extension(&((from)->extensions)->val[((to)->extensions)->len], &((to)->extensions)->val[((to)->extensions)->len])) goto fail;
}
}else
(to)->extensions = NULL;
return 0;
fail:
free_CertTemplate(to);
return ENOMEM;
}



