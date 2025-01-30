[{"ops":[{"insert":"/* Definitions for POSIX 1003.1b-1993 (aka POSIX.4) scheduling interface.\n   Copyright (C) 1996-2022 Free Software Foundation, Inc.\n   This file is part of the GNU C Library.\n\n   The GNU C Library is free software; you can redistribute it and/or\n   modify it under the terms of the GNU Lesser General Public\n   License as published by the Free Software Foundation; either\n   version 2.1 of the License, or (at your option) any later version.\n\n   The GNU C Library is distributed in the hope that it will be useful,\n   but WITHOUT ANY WARRANTY; without even the implied warranty of\n   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU\n   Lesser General Public License for more details.\n\n   You should have received a copy of the GNU Lesser General Public\n   License along with the GNU C Library; if not, see\n   <https://www.gnu.org/licenses/>.  */\n\n#ifndef\t_SCHED_H\n#define\t_SCHED_H\t1\n\n#include <features.h>\n\n/* Get type definitions.  */\n#include <bits/types.h>\n\n#define __need_size_t\n#define __need_NULL\n#include <stddef.h>\n\n#include <bits/types/time_t.h>\n#include <bits/types/struct_timespec.h>\n#ifndef __USE_XOPEN2K\n# include <time.h>\n#endif\n\n#ifndef __pid_t_defined\ntypedef __pid_t pid_t;\n# define __pid_t_defined\n#endif\n\n/* Get system specific constant and data structure definitions.  */\n#include <bits/sched.h>\n#include <bits/cpu-set.h>\n\n/* Backward compatibility.  */\n#define sched_priority    sched_priority\n#define __sched_priority  sched_priority\n\n\n__BEGIN_DECLS\n\n/* Set scheduling parameters for a process.  */\nextern int sched_setparam (__pid_t __pid, const struct sched_param *__param)\n     __THROW;\n\n/* Retrieve scheduling parameters for a particular process.  */\nextern int sched_getparam (__pid_t __pid, struct sched_param *__param) __THROW;\n\n/* Set scheduling algorithm and/or parameters for a process.  */\nextern int sched_setscheduler (__pid_t __pid, int __policy,\n\t\t\t       const struct sched_param *__param) __THROW;\n\n/* Retrieve scheduling algorithm for a particular purpose.  */\nextern int sched_getscheduler (__pid_t __pid) __THROW;\n\n/* Yield the processor.  */\nextern int sched_yield (void) __THROW;\n\n/* Get maximum priority value for a scheduler.  */\nextern int sched_get_priority_max (int __algorithm) __THROW;\n\n/* Get minimum priority value for a scheduler.  */\nextern int sched_get_priority_min (int __algorithm) __THROW;\n\n/* Get the SCHED_RR interval for the named process.  */\n#ifndef __USE_TIME_BITS64\nextern int sched_rr_get_interval (__pid_t __pid, struct timespec *__t) __THROW;\n#else\n# ifdef __REDIRECT_NTH\nextern int __REDIRECT_NTH (sched_rr_get_interval,\n                           (__pid_t __pid, struct timespec *__t),\n                           __sched_rr_get_interval64);\n# else\n#  define sched_rr_get_interval __sched_rr_get_interval64\n# endif\n#endif\n\n#ifdef __USE_GNU\n/* Access macros for `cpu_set'.  */\n# define CPU_SETSIZE __CPU_SETSIZE\n# define CPU_SET(cpu, cpusetp)\t __CPU_SET_S (cpu, sizeof (cpu_set_t), cpusetp)\n# define CPU_CLR(cpu, cpusetp)\t __CPU_CLR_S (cpu, sizeof (cpu_set_t), cpusetp)\n# define CPU_ISSET(cpu, cpusetp) __CPU_ISSET_S (cpu, sizeof (cpu_set_t), \\\n\t\t\t\t\t\tcpusetp)\n# define CPU_ZERO(cpusetp)\t __CPU_ZERO_S (sizeof (cpu_set_t), cpusetp)\n# define CPU_COUNT(cpusetp)\t __CPU_COUNT_S (sizeof (cpu_set_t), cpusetp)\n\n# define CPU_SET_S(cpu, setsize, cpusetp)   __CPU_SET_S (cpu, setsize, cpusetp)\n# define CPU_CLR_S(cpu, setsize, cpusetp)   __CPU_CLR_S (cpu, setsize, cpusetp)\n# define CPU_ISSET_S(cpu, setsize, cpusetp) __CPU_ISSET_S (cpu, setsize, \\\n\t\t\t\t\t\t\t   cpusetp)\n# define CPU_ZERO_S(setsize, cpusetp)\t    __CPU_ZERO_S (setsize, cpusetp)\n# define CPU_COUNT_S(setsize, cpusetp)\t    __CPU_COUNT_S (setsize, cpusetp)\n\n# define CPU_EQUAL(cpusetp1, cpusetp2) \\\n  __CPU_EQUAL_S (sizeof (cpu_set_t), cpusetp1, cpusetp2)\n# define CPU_EQUAL_S(setsize, cpusetp1, cpusetp2) \\\n  __CPU_EQUAL_S (setsize, cpusetp1, cpusetp2)\n\n# define CPU_AND(destset, srcset1, srcset2) \\\n  __CPU_OP_S (sizeof (cpu_set_t), destset, srcset1, srcset2, &)\n# define CPU_OR(destset, srcset1, srcset2) \\\n  __CPU_OP_S (sizeof (cpu_set_t), destset, srcset1, srcset2, |)\n# define CPU_XOR(destset, srcset1, srcset2) \\\n  __CPU_OP_S (sizeof (cpu_set_t), destset, srcset1, srcset2, ^)\n# define CPU_AND_S(setsize, destset, srcset1, srcset2) \\\n  __CPU_OP_S (setsize, destset, srcset1, srcset2, &)\n# define CPU_OR_S(setsize, destset, srcset1, srcset2) \\\n  __CPU_OP_S (setsize, destset, srcset1, srcset2, |)\n# define CPU_XOR_S(setsize, destset, srcset1, srcset2) \\\n  __CPU_OP_S (setsize, destset, srcset1, srcset2, ^)\n\n# define CPU_ALLOC_SIZE(count) __CPU_ALLOC_SIZE (count)\n# define CPU_ALLOC(count) __CPU_ALLOC (count)\n# define CPU_FREE(cpuset) __CPU_FREE (cpuset)\n\n\n/* Set the CPU affinity for a task */\nextern int sched_setaffinity (__pid_t __pid, size_t __cpusetsize,\n\t\t\t      const cpu_set_t *__cpuset) __THROW;\n\n/* Get the CPU affinity for a task */\nextern int sched_getaffinity (__pid_t __pid, size_t __cpusetsize,\n\t\t\t      cpu_set_t *__cpuset) __THROW;\n#endif\n\n__END_DECLS\n\n#endif /* sched.h */\n"}],"crc32":1464576830,"timestamp":1704214356,"tsString":"2024-01-02 16:52:28.0 +00:00:00","version":1}]