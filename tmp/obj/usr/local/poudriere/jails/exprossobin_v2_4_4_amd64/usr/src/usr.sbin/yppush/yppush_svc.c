/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "yp.h"
#include <stdio.h>
#include <stdlib.h> /* getenv, exit */
#include <rpc/pmap_clnt.h> /* for pmap_unset */
#include <string.h> /* strcmp */
#include <rpc/rpc_com.h>
#include <fcntl.h> /* open */
#include <unistd.h> /* fork / setsid */
#include <sys/types.h>
#include <string.h>
#include <sys/resource.h> /* rlimit */
#include <syslog.h>

#ifdef DEBUG
#define	RPC_SVC_FG
#endif
#include <sys/cdefs.h>
__FBSDID("$FreeBSD$");

void
yppush_xfrrespprog_1(struct svc_req *rqstp, SVCXPRT *transp)
{
	union {
		yppushresp_xfr yppushproc_xfrresp_1_arg;
	} argument;
	char *result;
	xdrproc_t xdr_argument, xdr_result;
	char *(*local)(char *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case YPPUSHPROC_NULL:
		xdr_argument = (xdrproc_t) xdr_void;
		xdr_result = (xdrproc_t) xdr_void;
		local = (char *(*)(char *, struct svc_req *)) yppushproc_null_1_svc;
		break;

	case YPPUSHPROC_XFRRESP:
		xdr_argument = (xdrproc_t) xdr_yppushresp_xfr;
		xdr_result = (xdrproc_t) xdr_void;
		local = (char *(*)(char *, struct svc_req *)) yppushproc_xfrresp_1_svc;
		break;

	default:
		svcerr_noproc(transp);
		return;
	}
	(void) memset((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs(transp, xdr_argument, (char *)(caddr_t) &argument)) {
		svcerr_decode(transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, xdr_result, result)) {
		svcerr_systemerr(transp);
	}
	if (!svc_freeargs(transp, xdr_argument, (char *)(caddr_t) &argument)) {
		fprintf(stderr, "unable to free arguments");
		exit(1);
	}
	return;
}