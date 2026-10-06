#ifndef __DTS_AX620E_RESERVE_MEM_DEFINE_H
#define __DTS_AX620E_RESERVE_MEM_DEFINE_H

#define ATF_RESERVED_START_HI 0x00
#define ATF_RESERVED_START_LO 0x40040000
#define ATF_RESERVED_SIZE_HI  0x00
#define ATF_RESERVED_SIZE_LO  0x40000

#define SUPPORT_ATF

#define OPTEE_BOOT
#define OPTEE_RESERVED_START_HI 0x00
#define OPTEE_RESERVED_START_LO 0x44200000
#define OPTEE_RESERVED_SIZE_HI  0x00
#define OPTEE_RESERVED_SIZE_LO  0x2000000

#define BOOTARGS "mem=256M console=ttyS0,115200n8 earlycon=uart8250,mmio32,0x4880000 board_id=0x0,boot_reason=0x00,initcall_debug=0 loglevel=8 usbcore.autosuspend=-1 root=/dev/mmcblk0p17 rootfstype=ext4 rw rootwait blkdevparts=mmcblk0:768K(spl),512K(ddrinit),256K(atf),256K(atf_b),1536K(uboot),1536K(uboot_b),1M(env),6M(logo),6M(logo_b),1M(optee),1M(optee_b),1M(dtb),1M(dtb_b),64M(kernel),64M(kernel_b),128M(boot),-(rootfs)"

#endif /* __DTS_AX620E_RESERVE_MEM_DEFINE_H */
