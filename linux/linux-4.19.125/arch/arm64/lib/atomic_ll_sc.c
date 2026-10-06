#include <asm/atomic.h>
#define __ARM64_IN_ATOMIC_IMPL
#include <asm/atomic_ll_sc.h>

#ifdef CONFIG_ARM64_LSE_ATOMICS
/*
 * Compatibility aliases for legacy vendor modules built against Linux 4.19.125
 * where cmpxchg functions used byte sizes (1, 2, 4) instead of bit sizes (8, 16, 32).
 */
#define __CMPXCHG_CASE_ALIAS(name, oldsz, newsz) \
	typeof(__ll_sc___cmpxchg_case_##name##newsz) __ll_sc___cmpxchg_case_##name##oldsz \
		__attribute__((alias("__ll_sc___cmpxchg_case_" #name #newsz))); \
	EXPORT_SYMBOL(__ll_sc___cmpxchg_case_##name##oldsz)

__CMPXCHG_CASE_ALIAS(, 1, 8);
__CMPXCHG_CASE_ALIAS(, 2, 16);
__CMPXCHG_CASE_ALIAS(, 4, 32);

__CMPXCHG_CASE_ALIAS(acq_, 1, 8);
__CMPXCHG_CASE_ALIAS(acq_, 2, 16);
__CMPXCHG_CASE_ALIAS(acq_, 4, 32);

__CMPXCHG_CASE_ALIAS(rel_, 1, 8);
__CMPXCHG_CASE_ALIAS(rel_, 2, 16);
__CMPXCHG_CASE_ALIAS(rel_, 4, 32);

__CMPXCHG_CASE_ALIAS(mb_, 1, 8);
__CMPXCHG_CASE_ALIAS(mb_, 2, 16);
__CMPXCHG_CASE_ALIAS(mb_, 4, 32);
#endif
