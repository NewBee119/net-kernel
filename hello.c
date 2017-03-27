#ifndef __KERNEL__
#define __KERNEL__
#endif

#ifndef MODULE
#define MODULE
#endif

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/skbuff.h>
#include <linux/ip.h>                  /* For IP header */
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
#include <linux/inet.h>

/* This is the structure we shall use to register our function */
static struct nf_hook_ops nfho;

/* IP address we want to drop packets from, in NB order */
static unsigned char *drop_ip = "\x7f\x00\x00\x01";

/* This is the hook function itself */
unsigned int hook_func(unsigned int hooknum,
                       struct sk_buff *skb,
                       const struct net_device *in,
                       const struct net_device *out,
                       int (*okfn)(struct sk_buff *))
{   
    struct iphdr *iph;
    iph = ip_hdr(skb); 
    iph = ip_hdr(skb); 
    printk("iph->saddr is %d \n", iph->saddr);       
    printk("iph->daddr is %d \n", iph->daddr);       
	return NF_ACCEPT;
}

/* Initialisation routine */
int init_module()
{
    /* Fill in our hook structure */
    nfho.hook     = hook_func;
    /* Handler function */
    nfho.hooknum  = 0; /* First for IPv4 */
    nfho.pf       = PF_INET;
    nfho.priority = NF_IP_PRI_FIRST;   /* Make our func first */
          
    nf_register_hook(&nfho);

    return 0;
}
          
/* Cleanup routine */
void cleanup_module()
{
    nf_unregister_hook(&nfho);
}
