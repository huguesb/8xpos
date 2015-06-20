Please note that this document is a rough draft...

# Introduction #

> XOS is a third party OS for the 83+ series of calculator. It is primarily targeted to the "SE family" (83+SE, 84+ and 84+SE) but **might** still work on a regular 83+ though with many features disabled.

> XOS is being developed by Luc BRUANT aka fullmetalcoder. It is based on previous similar attempts of writing OS for the 83+ series and especially on Sean Mc Laughlin's CSX project (now defunct) but it has significantly diverged from it.

> XOS is Open Source, the whole source code is available under open source license(s), BSD in most cases and other licenses in case bits of code are taken from other projects with different licenses (most flash writing code comes from PongOS for instance and is GPL'ed).

# Design #

  * XOS is **minimal** : the default interface is a simple command line, most of the actual features (from end-user point of view) are to be implemented in userspace (by flash apps or programs)
  * XOS is **fast** : all system routines are optimized for speed and a fast calling convention is used (direct call instead of bcall)
  * XOS is **robust** : backward/forward binary compat is ensured accross versions and the exception system can prevent many crashes
  * XOS gives **power** to coders : XOS programs have 32kb of private memory for code and data and can allocate up to 12kb from the shared heap and up to 1kb from the hardware stack. XOS provides a large number of system routines that are optimized for speed.
  * XOS takes **advantage** of the hardware : it uses the extra RAM pages available on SE calculators to offer larger storage space (up to 64kb of storage RAM) and program execution space.
  * XOS aims to offer **backward TIOS compatibility** : through an emulation layer XOS strives to run programs and flash apps that were designed for the TIOS.