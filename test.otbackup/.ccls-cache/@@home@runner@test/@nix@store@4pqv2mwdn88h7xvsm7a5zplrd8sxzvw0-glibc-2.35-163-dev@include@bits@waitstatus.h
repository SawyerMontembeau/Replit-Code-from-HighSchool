[{"ops":[{"insert":"/* Definitions of status bits for `wait' et al.\n   Copyright (C) 1992-2022 Free Software Foundation, Inc.\n   This file is part of the GNU C Library.\n\n   The GNU C Library is free software; you can redistribute it and/or\n   modify it under the terms of the GNU Lesser General Public\n   License as published by the Free Software Foundation; either\n   version 2.1 of the License, or (at your option) any later version.\n\n   The GNU C Library is distributed in the hope that it will be useful,\n   but WITHOUT ANY WARRANTY; without even the implied warranty of\n   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU\n   Lesser General Public License for more details.\n\n   You should have received a copy of the GNU Lesser General Public\n   License along with the GNU C Library; if not, see\n   <https://www.gnu.org/licenses/>.  */\n\n#if !defined _SYS_WAIT_H && !defined _STDLIB_H\n# error \"Never include <bits/waitstatus.h> directly; use <sys/wait.h> instead.\"\n#endif\n\n\n/* Everything extant so far uses these same bits.  */\n\n\n/* If WIFEXITED(STATUS), the low-order 8 bits of the status.  */\n#define\t__WEXITSTATUS(status)\t(((status) & 0xff00) >> 8)\n\n/* If WIFSIGNALED(STATUS), the terminating signal.  */\n#define\t__WTERMSIG(status)\t((status) & 0x7f)\n\n/* If WIFSTOPPED(STATUS), the signal that stopped the child.  */\n#define\t__WSTOPSIG(status)\t__WEXITSTATUS(status)\n\n/* Nonzero if STATUS indicates normal termination.  */\n#define\t__WIFEXITED(status)\t(__WTERMSIG(status) == 0)\n\n/* Nonzero if STATUS indicates termination by a signal.  */\n#define __WIFSIGNALED(status) \\\n  (((signed char) (((status) & 0x7f) + 1) >> 1) > 0)\n\n/* Nonzero if STATUS indicates the child is stopped.  */\n#define\t__WIFSTOPPED(status)\t(((status) & 0xff) == 0x7f)\n\n/* Nonzero if STATUS indicates the child continued after a stop.  We only\n   define this if <bits/waitflags.h> provides the WCONTINUED flag bit.  */\n#ifdef WCONTINUED\n# define __WIFCONTINUED(status)\t((status) == __W_CONTINUED)\n#endif\n\n/* Nonzero if STATUS indicates the child dumped core.  */\n#define\t__WCOREDUMP(status)\t((status) & __WCOREFLAG)\n\n/* Macros for constructing status values.  */\n#define\t__W_EXITCODE(ret, sig)\t((ret) << 8 | (sig))\n#define\t__W_STOPCODE(sig)\t((sig) << 8 | 0x7f)\n#define __W_CONTINUED\t\t0xffff\n#define\t__WCOREFLAG\t\t0x80\n"}],"crc32":551043944,"timestamp":1704214355,"tsString":"2024-01-02 16:52:28.0 +00:00:00","version":1}]