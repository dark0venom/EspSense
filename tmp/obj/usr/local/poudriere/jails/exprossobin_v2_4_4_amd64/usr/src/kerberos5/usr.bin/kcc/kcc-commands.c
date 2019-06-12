#include <stdio.h>
#include <getarg.h>
#include <sl.h>
#include "kcc-commands.h"

static int
klist_wrap(int argc, char **argv)
{
    struct klist_options opt;
    int ret;
    int optidx = 0;
    struct getargs args[] = {
        { "cache", 'c', arg_string, NULL, "credential cache to list", NULL },
        { NULL, 'f', arg_flag, NULL, "list flags", NULL },
        { "test", 't', arg_flag, NULL, "test for having tickets", NULL },
        { NULL, 's', arg_flag, NULL, NULL, NULL },
        { "tokens", 'T', arg_flag, NULL, "display AFS tokens", NULL },
        { "v5", '5', arg_flag, NULL, "display v5 credential tokens", NULL },
        { "all-content", 'A', arg_flag, NULL, "List all caches with their content", NULL },
        { "list-all", 'l', arg_flag, NULL, "List all caches", NULL },
        { "verbose", 'v', arg_flag, NULL, "Verbose output", NULL },
        { NULL, 'a', arg_flag, NULL, NULL, NULL },
        { NULL, 'n', arg_flag, NULL, NULL, NULL },
        { "hidden", 0, arg_flag, NULL, "Verbose output", NULL },
        { "help", 'h', arg_flag, NULL, NULL, NULL }
    };
    int help_flag = 0;
    opt.cache_string = NULL;
    opt.flags_flag = 0;
    opt.test_flag = 0;
    opt.s_flag = 0;
    opt.tokens_flag = 0;
    opt.v5_flag = 1;
    opt.all_content_flag = 0;
    opt.list_all_flag = 0;
    opt.verbose_flag = 0;
    opt.a_flag = 0;
    opt.n_flag = 0;
    opt.hidden_flag = 0;
    args[0].value = &opt.cache_string;
    args[1].value = &opt.flags_flag;
    args[2].value = &opt.test_flag;
    args[3].value = &opt.s_flag;
    args[4].value = &opt.tokens_flag;
    args[5].value = &opt.v5_flag;
    args[6].value = &opt.all_content_flag;
    args[7].value = &opt.list_all_flag;
    args[8].value = &opt.verbose_flag;
    args[9].value = &opt.a_flag;
    args[10].value = &opt.n_flag;
    args[11].value = &opt.hidden_flag;
    args[12].value = &help_flag;
    if(getarg(args, 13, argc, argv, &optidx))
        goto usage;
    if(argc - optidx > 0) {
        fprintf(stderr, "Arguments given (%u) are more than expected (0).\n\n", argc - optidx);
        goto usage;
    }
    if(help_flag)
        goto usage;
    ret = klist(&opt, argc - optidx, argv + optidx);
    return ret;
usage:
    arg_printusage (args, 13, "klist", "");
    return 0;
}

static int
kgetcred_wrap(int argc, char **argv)
{
    struct kgetcred_options opt;
    int ret;
    int optidx = 0;
    struct getargs args[] = {
        { "enctype", 'e', arg_string, NULL, "Encryption type to use", "enctype" },
        { "cache", 'c', arg_string, NULL, "Credentials cache", "cachename" },
        { "help", 'h', arg_flag, NULL, NULL, NULL }
    };
    int help_flag = 0;
    opt.enctype_string = NULL;
    opt.cache_string = NULL;
    args[0].value = &opt.enctype_string;
    args[1].value = &opt.cache_string;
    args[2].value = &help_flag;
    if(getarg(args, 3, argc, argv, &optidx))
        goto usage;
    if(help_flag)
        goto usage;
    ret = kgetcred(&opt, argc - optidx, argv + optidx);
    return ret;
usage:
    arg_printusage (args, 3, "kgetcred", "");
    return 0;
}

static int
kswitch_wrap(int argc, char **argv)
{
    struct kswitch_options opt;
    int ret;
    int optidx = 0;
    struct getargs args[] = {
        { "type", 't', arg_string, NULL, "type of credential cache", NULL },
        { "cache", 'c', arg_string, NULL, "name of credential cache", NULL },
        { "principal", 'p', arg_string, NULL, "name of principal", NULL },
        { "interactive", 'i', arg_flag, NULL, "interactive selection", NULL },
        { "help", 'h', arg_flag, NULL, NULL, NULL }
    };
    int help_flag = 0;
    opt.type_string = NULL;
    opt.cache_string = NULL;
    opt.principal_string = NULL;
    opt.interactive_flag = 0;
    args[0].value = &opt.type_string;
    args[1].value = &opt.cache_string;
    args[2].value = &opt.principal_string;
    args[3].value = &opt.interactive_flag;
    args[4].value = &help_flag;
    if(getarg(args, 5, argc, argv, &optidx))
        goto usage;
    if(argc - optidx > 0) {
        fprintf(stderr, "Arguments given (%u) are more than expected (0).\n\n", argc - optidx);
        goto usage;
    }
    if(help_flag)
        goto usage;
    ret = kswitch(&opt, argc - optidx, argv + optidx);
    return ret;
usage:
    arg_printusage (args, 5, "kswitch", "");
    return 0;
}

static int
kvno_wrap(int argc, char **argv)
{
    struct kvno_options opt;
    int ret;
    int optidx = 0;
    struct getargs args[] = {
        { "enctype", 'e', arg_string, NULL, "Encryption type to use", "enctype" },
        { "cache", 'c', arg_string, NULL, "Credentials cache", "cachename" },
        { "keytab", 'k', arg_string, NULL, "Keytab to use", "keytabname" },
        { "server", 'S', arg_string, NULL, "Server to get ticket for", "principal" },
        { "quiet", 'q', arg_flag, NULL, "Quiet", NULL },
        { "help", 'h', arg_flag, NULL, NULL, NULL }
    };
    int help_flag = 0;
    opt.enctype_string = NULL;
    opt.cache_string = NULL;
    opt.keytab_string = NULL;
    opt.server_string = NULL;
    opt.quiet_flag = 0;
    args[0].value = &opt.enctype_string;
    args[1].value = &opt.cache_string;
    args[2].value = &opt.keytab_string;
    args[3].value = &opt.server_string;
    args[4].value = &opt.quiet_flag;
    args[5].value = &help_flag;
    if(getarg(args, 6, argc, argv, &optidx))
        goto usage;
    if(help_flag)
        goto usage;
    ret = kvno(&opt, argc - optidx, argv + optidx);
    return ret;
usage:
    arg_printusage (args, 6, "kvno", "");
    return 0;
}

static int
copy_cred_cache_wrap(int argc, char **argv)
{
    struct copy_cred_cache_options opt;
    int ret;
    int optidx = 0;
    struct getargs args[] = {
        { "krbtgt-only", 0, arg_flag, NULL, "only copy local krbtgt", NULL },
        { "service", 0, arg_string, NULL, "limit to this service", "service" },
        { "enctype", 0, arg_string, NULL, "limit to this enctype", "enctype" },
        { "flags", 0, arg_string, NULL, "limit to these flags", NULL },
        { "valid-for", 0, arg_string, NULL, "limit to creds valid for at least this long", "time" },
        { "fcache-version", 0, arg_integer, NULL, "file cache version to create", NULL },
        { "help", 'h', arg_flag, NULL, NULL, NULL }
    };
    int help_flag = 0;
    opt.krbtgt_only_flag = 0;
    opt.service_string = NULL;
    opt.enctype_string = NULL;
    opt.flags_string = NULL;
    opt.valid_for_string = NULL;
    opt.fcache_version_integer = 0;
    args[0].value = &opt.krbtgt_only_flag;
    args[1].value = &opt.service_string;
    args[2].value = &opt.enctype_string;
    args[3].value = &opt.flags_string;
    args[4].value = &opt.valid_for_string;
    args[5].value = &opt.fcache_version_integer;
    args[6].value = &help_flag;
    if(getarg(args, 7, argc, argv, &optidx))
        goto usage;
    if(argc - optidx > 2) {
        fprintf(stderr, "Arguments given (%u) are more than expected (2).\n\n", argc - optidx);
        goto usage;
    }
    if(argc - optidx < 1) {
        fprintf(stderr, "Arguments given (%u) are less than expected (1).\n\n", argc - optidx);
        goto usage;
    }
    if(help_flag)
        goto usage;
    ret = copy_cred_cache(&opt, argc - optidx, argv + optidx);
    return ret;
usage:
    arg_printusage (args, 7, "copy_cred_cache", "");
    return 0;
}

static int
help_wrap(int argc, char **argv)
{
    int ret;
    int optidx = 0;
    struct getargs args[] = {
        { "help", 'h', arg_flag, NULL, NULL, NULL }
    };
    int help_flag = 0;
    args[0].value = &help_flag;
    if(getarg(args, 1, argc, argv, &optidx))
        goto usage;
    if(argc - optidx > 1) {
        fprintf(stderr, "Arguments given (%u) are more than expected (1).\n\n", argc - optidx);
        goto usage;
    }
    if(argc - optidx < 0) {
        fprintf(stderr, "Arguments given (%u) are less than expected (0).\n\n", argc - optidx);
        goto usage;
    }
    if(help_flag)
        goto usage;
    ret = help(NULL, argc - optidx, argv + optidx);
    return ret;
usage:
    arg_printusage (args, 1, "help", "[command]");
    return 0;
}

SL_cmd commands[] = {
        { "klist", klist_wrap, "klist", "List kerberos tickets" },
        { "list" },

        { "kgetcred", kgetcred_wrap, "kgetcred", "Acquire a Kerberos ticket" },

        { "kswitch", kswitch_wrap, "kswitch", "Switch default kerberos cache" },
        { "switch" },

        { "kvno", kvno_wrap, "kvno", "Acquire a Kerberos ticket" },

        { "copy_cred_cache", copy_cred_cache_wrap, "copy_cred_cache", "Copies credential caches" },

        { "help", help_wrap, "help [command]", "Help! I need somebody." },
        { "?" },

    { NULL }
};
