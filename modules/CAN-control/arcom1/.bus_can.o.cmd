cmd_/home/rtai/ECAS/ECAS/V3.1_bus_can_asserv_asyn_asyn/arcom1/bus_can.o :=  gcc -m32 -Wp,-MD,/home/rtai/ECAS/ECAS/V3.1_bus_can_asserv_asyn_asyn/arcom1/.bus_can.o.d  -nostdinc -isystem /opt/x86_64/gcc/gcc-3.4.4/lib/gcc/x86_64-gnu-linux/3.4.4/include -D__KERNEL__ -Iinclude  -include include/linux/autoconf.h -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -ffreestanding -Os     -fomit-frame-pointer -pipe -msoft-float -mpreferred-stack-boundary=2 -fno-unit-at-a-time  -Iinclude/asm-i386/mach-default -Wdeclaration-after-statement  -I/usr/lib/arcom/realtime/include -Wall -ffast-math -mhard-float  -DMODULE -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(bus_can)"  -D"KBUILD_MODNAME=KBUILD_STR(bus_can)" -c -o /home/rtai/ECAS/ECAS/V3.1_bus_can_asserv_asyn_asyn/arcom1/bus_can.o /home/rtai/ECAS/ECAS/V3.1_bus_can_asserv_asyn_asyn/arcom1/bus_can.c

deps_/home/rtai/ECAS/ECAS/V3.1_bus_can_asserv_asyn_asyn/arcom1/bus_can.o := \
  /home/rtai/ECAS/ECAS/V3.1_bus_can_asserv_asyn_asyn/arcom1/bus_can.c \
  include/linux/init.h \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/hotplug.h) \
    $(wildcard include/config/hotplug/cpu.h) \
    $(wildcard include/config/memory/hotplug.h) \
  include/linux/config.h \
    $(wildcard include/config/h.h) \
  include/linux/compiler.h \
  include/linux/compiler-gcc3.h \
  include/linux/compiler-gcc.h \
  include/linux/module.h \
    $(wildcard include/config/modversions.h) \
    $(wildcard include/config/module/unload.h) \
    $(wildcard include/config/kallsyms.h) \
  include/linux/sched.h \
    $(wildcard include/config/ipipe.h) \
    $(wildcard include/config/detect/softlockup.h) \
    $(wildcard include/config/split/ptlock/cpus.h) \
    $(wildcard include/config/keys.h) \
    $(wildcard include/config/inotify.h) \
    $(wildcard include/config/schedstats.h) \
    $(wildcard include/config/smp.h) \
    $(wildcard include/config/debug/mutexes.h) \
    $(wildcard include/config/bsd/process/acct.h) \
    $(wildcard include/config/numa.h) \
    $(wildcard include/config/cpusets.h) \
    $(wildcard include/config/preempt.h) \
    $(wildcard include/config/pm.h) \
  include/asm/param.h \
    $(wildcard include/config/hz.h) \
  include/linux/ipipe.h \
    $(wildcard include/config/debug/spinlock.h) \
    $(wildcard include/config/proc/fs.h) \
    $(wildcard include/config/ipipe/trace.h) \
    $(wildcard include/config/debug/kernel.h) \
  include/linux/spinlock.h \
  include/linux/preempt.h \
    $(wildcard include/config/debug/preempt.h) \
  include/linux/thread_info.h \
  include/linux/bitops.h \
  include/asm/types.h \
    $(wildcard include/config/highmem64g.h) \
    $(wildcard include/config/lbd.h) \
  include/asm/bitops.h \
  include/asm/thread_info.h \
    $(wildcard include/config/4kstacks.h) \
    $(wildcard include/config/debug/stack/usage.h) \
  include/asm/page.h \
    $(wildcard include/config/x86/use/3dnow.h) \
    $(wildcard include/config/x86/pae.h) \
    $(wildcard include/config/hugetlb/page.h) \
    $(wildcard include/config/highmem4g.h) \
    $(wildcard include/config/page/offset.h) \
    $(wildcard include/config/physical/start.h) \
    $(wildcard include/config/flatmem.h) \
  include/asm/mmx.h \
  include/linux/types.h \
    $(wildcard include/config/uid16.h) \
  include/linux/posix_types.h \
  include/linux/stddef.h \
  include/asm/posix_types.h \
  include/asm-generic/page.h \
  include/asm/processor.h \
    $(wildcard include/config/x86/ht.h) \
    $(wildcard include/config/mk8.h) \
    $(wildcard include/config/mk7.h) \
    $(wildcard include/config/mtrr.h) \
    $(wildcard include/config/x86/mce.h) \
  include/asm/vm86.h \
    $(wildcard include/config/vm86.h) \
  include/asm/math_emu.h \
  include/asm/sigcontext.h \
  include/asm/segment.h \
  include/asm/cpufeature.h \
  include/asm/msr.h \
  include/asm/system.h \
    $(wildcard include/config/x86/cmpxchg64.h) \
    $(wildcard include/config/x86/cmpxchg.h) \
    $(wildcard include/config/x86/oostore.h) \
    $(wildcard include/config/ipipe/trace/irqsoff.h) \
  include/linux/kernel.h \
    $(wildcard include/config/preempt/voluntary.h) \
    $(wildcard include/config/debug/spinlock/sleep.h) \
    $(wildcard include/config/printk.h) \
  /opt/x86_64/gcc/gcc-3.4.4/lib/gcc/x86_64-gnu-linux/3.4.4/include/stdarg.h \
  include/linux/linkage.h \
  include/asm/linkage.h \
    $(wildcard include/config/x86/alignment/16.h) \
  include/asm/byteorder.h \
    $(wildcard include/config/x86/bswap.h) \
  include/linux/byteorder/little_endian.h \
  include/linux/byteorder/swab.h \
  include/linux/byteorder/generic.h \
  include/asm/bug.h \
    $(wildcard include/config/bug.h) \
    $(wildcard include/config/debug/bugverbose.h) \
  include/asm-generic/bug.h \
  include/linux/cache.h \
    $(wildcard include/config/x86.h) \
    $(wildcard include/config/sparc64.h) \
    $(wildcard include/config/ia64.h) \
    $(wildcard include/config/parisc.h) \
  include/asm/cache.h \
    $(wildcard include/config/x86/l1/cache/shift.h) \
  include/linux/threads.h \
    $(wildcard include/config/nr/cpus.h) \
    $(wildcard include/config/base/small.h) \
  include/asm/percpu.h \
  include/asm-generic/percpu.h \
  include/linux/stringify.h \
  include/linux/spinlock_types.h \
  include/linux/spinlock_types_up.h \
  include/linux/spinlock_up.h \
  include/linux/spinlock_api_up.h \
  include/asm/atomic.h \
    $(wildcard include/config/m386.h) \
  include/asm-generic/atomic.h \
  include/asm/ipipe.h \
    $(wildcard include/config/x86/local/apic.h) \
    $(wildcard include/config/pci/msi.h) \
  include/asm-i386/mach-default/irq_vectors.h \
  include/asm-i386/mach-default/irq_vectors_limits.h \
    $(wildcard include/config/x86/io/apic.h) \
  include/linux/cpumask.h \
  include/linux/bitmap.h \
  include/linux/string.h \
  include/asm/string.h \
  include/linux/list.h \
  include/linux/prefetch.h \
  include/asm/ptrace.h \
    $(wildcard include/config/frame/pointer.h) \
  include/linux/capability.h \
  include/asm/current.h \
  include/linux/timex.h \
    $(wildcard include/config/time/interpolation.h) \
  include/linux/time.h \
  include/linux/seqlock.h \
  include/asm/timex.h \
    $(wildcard include/config/x86/elan.h) \
    $(wildcard include/config/x86/tsc.h) \
    $(wildcard include/config/x86/generic.h) \
  include/linux/jiffies.h \
  include/linux/calc64.h \
  include/asm/div64.h \
  include/linux/rbtree.h \
  include/linux/errno.h \
  include/asm/errno.h \
  include/asm-generic/errno.h \
  include/asm-generic/errno-base.h \
  include/linux/nodemask.h \
  include/linux/numa.h \
  include/asm/semaphore.h \
  include/linux/wait.h \
  include/linux/rwsem.h \
    $(wildcard include/config/rwsem/generic/spinlock.h) \
  include/asm/rwsem.h \
  include/asm/mmu.h \
  include/asm/cputime.h \
  include/asm-generic/cputime.h \
  include/linux/smp.h \
  include/linux/sem.h \
    $(wildcard include/config/sysvipc.h) \
  include/linux/ipc.h \
  include/asm/ipcbuf.h \
  include/asm/sembuf.h \
  include/linux/signal.h \
  include/asm/signal.h \
  include/asm-generic/signal.h \
  include/asm/siginfo.h \
  include/asm-generic/siginfo.h \
  include/linux/securebits.h \
  include/linux/fs_struct.h \
  include/linux/completion.h \
  include/linux/pid.h \
  include/linux/percpu.h \
  include/linux/slab.h \
    $(wildcard include/config/.h) \
    $(wildcard include/config/slob.h) \
    $(wildcard include/config/debug/slab.h) \
  include/linux/gfp.h \
    $(wildcard include/config/dma/is/dma32.h) \
  include/linux/mmzone.h \
    $(wildcard include/config/force/max/zoneorder.h) \
    $(wildcard include/config/discontigmem.h) \
    $(wildcard include/config/flat/node/mem/map.h) \
    $(wildcard include/config/have/memory/present.h) \
    $(wildcard include/config/need/node/memmap/size.h) \
    $(wildcard include/config/need/multiple/nodes.h) \
    $(wildcard include/config/sparsemem.h) \
    $(wildcard include/config/have/arch/early/pfn/to/nid.h) \
    $(wildcard include/config/sparsemem/extreme.h) \
  include/linux/memory_hotplug.h \
  include/linux/notifier.h \
  include/linux/topology.h \
    $(wildcard include/config/sched/smt.h) \
  include/asm/topology.h \
  include/asm-generic/topology.h \
  include/linux/kmalloc_sizes.h \
    $(wildcard include/config/mmu.h) \
    $(wildcard include/config/large/allocs.h) \
  include/linux/seccomp.h \
    $(wildcard include/config/seccomp.h) \
  include/linux/rcupdate.h \
  include/linux/auxvec.h \
  include/asm/auxvec.h \
  include/linux/param.h \
  include/linux/resource.h \
  include/asm/resource.h \
  include/asm-generic/resource.h \
  include/linux/timer.h \
  include/linux/hrtimer.h \
    $(wildcard include/config/no/idle/hz.h) \
  include/linux/ktime.h \
    $(wildcard include/config/ktime/scalar.h) \
  include/linux/aio.h \
  include/linux/workqueue.h \
  include/linux/aio_abi.h \
  include/linux/stat.h \
  include/asm/stat.h \
  include/linux/kmod.h \
    $(wildcard include/config/kmod.h) \
  include/linux/elf.h \
  include/asm/elf.h \
  include/asm/user.h \
  include/linux/utsname.h \
  include/linux/kobject.h \
    $(wildcard include/config/net.h) \
  include/linux/sysfs.h \
    $(wildcard include/config/sysfs.h) \
  include/linux/kref.h \
  include/linux/moduleparam.h \
  include/asm/local.h \
  include/asm/module.h \
    $(wildcard include/config/m486.h) \
    $(wildcard include/config/m586.h) \
    $(wildcard include/config/m586tsc.h) \
    $(wildcard include/config/m586mmx.h) \
    $(wildcard include/config/m686.h) \
    $(wildcard include/config/mpentiumii.h) \
    $(wildcard include/config/mpentiumiii.h) \
    $(wildcard include/config/mpentiumm.h) \
    $(wildcard include/config/mpentium4.h) \
    $(wildcard include/config/mk6.h) \
    $(wildcard include/config/mcrusoe.h) \
    $(wildcard include/config/mefficeon.h) \
    $(wildcard include/config/mwinchipc6.h) \
    $(wildcard include/config/mwinchip2.h) \
    $(wildcard include/config/mwinchip3d.h) \
    $(wildcard include/config/mcyrixiii.h) \
    $(wildcard include/config/mviac3/2.h) \
    $(wildcard include/config/mgeodegx1.h) \
    $(wildcard include/config/mgeode/lx.h) \
    $(wildcard include/config/regparm.h) \
  include/asm/io.h \
    $(wildcard include/config/x86/ppro/fence.h) \
    $(wildcard include/config/x86/numaq.h) \
  include/asm-generic/iomap.h \
  include/linux/vmalloc.h \
  include/asm/irq.h \
    $(wildcard include/config/irqbalance.h) \
  /usr/lib/arcom/realtime/include/rtai.h \
  include/linux/version.h \
  /usr/lib/arcom/realtime/include/rtai_sanity.h \
  /usr/lib/arcom/realtime/include/asm/rtai.h \
  /usr/lib/arcom/realtime/include/rtai_config.h \
    $(wildcard include/config/kbuild.h) \
    $(wildcard include/config/rtai.h) \
    $(wildcard include/config/rtai/adeos.h) \
    $(wildcard include/config/rtai/allow/rr.h) \
    $(wildcard include/config/rtai/bits.h) \
    $(wildcard include/config/rtai/bits/builtin.h) \
    $(wildcard include/config/rtai/build/string.h) \
    $(wildcard include/config/rtai/busy/time/align.h) \
    $(wildcard include/config/rtai/cal/freqs/fact.h) \
    $(wildcard include/config/rtai/compiler.h) \
    $(wildcard include/config/rtai/cpus.h) \
    $(wildcard include/config/rtai/dont/dispatch/core/irqs.h) \
    $(wildcard include/config/rtai/drivers/16550a.h) \
    $(wildcard include/config/rtai/drivers/serial.h) \
    $(wildcard include/config/rtai/fifos.h) \
    $(wildcard include/config/rtai/fifos/builtin.h) \
    $(wildcard include/config/rtai/fifos/template.h) \
    $(wildcard include/config/rtai/fpu/support.h) \
    $(wildcard include/config/rtai/full/prinher.h) \
    $(wildcard include/config/rtai/hal/preempt.h) \
    $(wildcard include/config/rtai/host/string.h) \
    $(wildcard include/config/rtai/immediate/linux/syscall.h) \
    $(wildcard include/config/rtai/internal/leds/support.h) \
    $(wildcard include/config/rtai/internal/lxrt/inline.h) \
    $(wildcard include/config/rtai/internal/lxrt/support.h) \
    $(wildcard include/config/rtai/ipipe.h) \
    $(wildcard include/config/rtai/leds.h) \
    $(wildcard include/config/rtai/leds/builtin.h) \
    $(wildcard include/config/rtai/long/timed/list.h) \
    $(wildcard include/config/rtai/lxrt/inline.h) \
    $(wildcard include/config/rtai/lxrt/use/linux/syscall.h) \
    $(wildcard include/config/rtai/maintainer.h) \
    $(wildcard include/config/rtai/maintainer/pgm.h) \
    $(wildcard include/config/rtai/maintainer/pma.h) \
    $(wildcard include/config/rtai/malloc.h) \
    $(wildcard include/config/rtai/malloc/builtin.h) \
    $(wildcard include/config/rtai/malloc/heapsz.h) \
    $(wildcard include/config/rtai/malloc/vmalloc.h) \
    $(wildcard include/config/rtai/math.h) \
    $(wildcard include/config/rtai/math/builtin.h) \
    $(wildcard include/config/rtai/math/c99.h) \
    $(wildcard include/config/rtai/mbx.h) \
    $(wildcard include/config/rtai/mbx/builtin.h) \
    $(wildcard include/config/rtai/monitor/exectime.h) \
    $(wildcard include/config/rtai/mount/on/load.h) \
    $(wildcard include/config/rtai/mq.h) \
    $(wildcard include/config/rtai/mq/builtin.h) \
    $(wildcard include/config/rtai/msg.h) \
    $(wildcard include/config/rtai/msg/builtin.h) \
    $(wildcard include/config/rtai/netrpc.h) \
    $(wildcard include/config/rtai/netrpc/builtin.h) \
    $(wildcard include/config/rtai/netrpc/rtnet.h) \
    $(wildcard include/config/rtai/one/shot.h) \
    $(wildcard include/config/rtai/revision/level.h) \
    $(wildcard include/config/rtai/rtc/freq.h) \
    $(wildcard include/config/rtai/rtdm.h) \
    $(wildcard include/config/rtai/rtdm/fd/max.h) \
    $(wildcard include/config/rtai/sched/8254/latency.h) \
    $(wildcard include/config/rtai/sched/apic/latency.h) \
    $(wildcard include/config/rtai/sched/isr/lock.h) \
    $(wildcard include/config/rtai/sched/lxrt.h) \
    $(wildcard include/config/rtai/sched/lxrt/numslots.h) \
    $(wildcard include/config/rtai/sem.h) \
    $(wildcard include/config/rtai/sem/builtin.h) \
    $(wildcard include/config/rtai/shm.h) \
    $(wildcard include/config/rtai/shm/builtin.h) \
    $(wildcard include/config/rtai/tasklets.h) \
    $(wildcard include/config/rtai/tasklets/builtin.h) \
    $(wildcard include/config/rtai/tbx.h) \
    $(wildcard include/config/rtai/tbx/builtin.h) \
    $(wildcard include/config/rtai/trace.h) \
    $(wildcard include/config/rtai/use/newerr.h) \
    $(wildcard include/config/rtai/usi.h) \
    $(wildcard include/config/rtai/usi/builtin.h) \
    $(wildcard include/config/rtai/version/major.h) \
    $(wildcard include/config/rtai/version/minor.h) \
    $(wildcard include/config/rtai/wd.h) \
  /usr/lib/arcom/realtime/include/asm/rtai_hal.h \
  /usr/lib/arcom/realtime/include/asm/rtai_vectors.h \
  /usr/lib/arcom/realtime/include/rtai_types.h \
  /usr/lib/arcom/realtime/include/rtai_wrappers.h \
  /usr/lib/arcom/realtime/include/rtai_hal_names.h \
    $(wildcard include/config/adeos/nothreads.h) \
  include/linux/interrupt.h \
    $(wildcard include/config/generic/hardirqs.h) \
    $(wildcard include/config/generic/irq/probe.h) \
  include/linux/hardirq.h \
    $(wildcard include/config/preempt/bkl.h) \
    $(wildcard include/config/virt/cpu/accounting.h) \
  include/linux/smp_lock.h \
    $(wildcard include/config/lock/kernel.h) \
  include/asm/hardirq.h \
  include/linux/irq.h \
    $(wildcard include/config/s390.h) \
    $(wildcard include/config/irq/release/method.h) \
    $(wildcard include/config/generic/pending/irq.h) \
    $(wildcard include/config/auto/irq/affinity.h) \
  include/asm/hw_irq.h \
  include/linux/profile.h \
    $(wildcard include/config/profiling.h) \
  include/asm/sections.h \
  include/asm-generic/sections.h \
  include/linux/irq_cpustat.h \
  include/asm/desc.h \
  include/asm/ldt.h \
  /usr/lib/arcom/realtime/include/asm/rtai_atomic.h \
  /usr/lib/arcom/realtime/include/asm/rtai_fpu.h \
  /usr/lib/arcom/realtime/include/rtai_trace.h \
    $(wildcard include/config/ppc.h) \
    $(wildcard include/config/arm.h) \
  /usr/lib/arcom/realtime/include/asm/rtai_oldnames.h \
  /usr/lib/arcom/realtime/include/asm/rtai_emulate_tsc.h \
    $(wildcard include/config/vt.h) \
  /usr/lib/arcom/realtime/include/rtai_sched.h \
  /usr/lib/arcom/realtime/include/rtai_fifos.h \

/home/rtai/ECAS/ECAS/V3.1_bus_can_asserv_asyn_asyn/arcom1/bus_can.o: $(deps_/home/rtai/ECAS/ECAS/V3.1_bus_can_asserv_asyn_asyn/arcom1/bus_can.o)

$(deps_/home/rtai/ECAS/ECAS/V3.1_bus_can_asserv_asyn_asyn/arcom1/bus_can.o):
