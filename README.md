# ImageBenchmarker
Benchmark the performance of image process for GraphicsMagick and OpenCV

### Test environment
```
wells@wells-VirtualBox:~$ cat /proc/version
Linux version 4.8.0-46-generic (buildd@lgw01-05) (gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.4) ) #49~16.04.1-Ubuntu SMP Fri Mar 31 14:50:48 UTC 2017

wells@wells-VirtualBox:~$ cat /proc/cpuinfo
processor       : 0
vendor_id       : GenuineIntel
cpu family      : 6
model           : 142
model name      : Intel(R) Core(TM) i5-7200U CPU @ 2.50GHz
stepping        : 9
cpu MHz         : 2712.002
cache size      : 3072 KB
physical id     : 0
siblings        : 1
core id         : 0
cpu cores       : 1
apicid          : 0
initial apicid  : 0
fdiv_bug        : no
f00f_bug        : no
coma_bug        : no
fpu             : yes
fpu_exception   : yes
cpuid level     : 22
wp              : yes
flags           : fpu vme de pse tsc msr pae mce cx8 apic mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 rdtscp constant_tsc xtopology nonstop_tsc eagerfpu pni monitor ssse3 sse4_1 sse4_2 x2apic hypervisor lahf_lm
bugs            :
bogomips        : 5424.00
clflush size    : 64
cache_alignment : 64
address sizes   : 39 bits physical, 48 bits virtual
power management:

wells@wells-VirtualBox:~$ cat /proc/meminfo
MemTotal:        2061052 kB
MemFree:          183348 kB
MemAvailable:      86152 kB
```

### Using GraphicsMagick, 1 thread, 2.8M image
```
wells@wells-VirtualBox:~/Workspace/ImageBenchmarker/src$ ../bin/imagebenchmarker -n 1 -t 0 -s ../image.jpg -c 960x640
Source file size: 2953018
Benchmark: totoal 8.00 images, 11.45 MByte files processed per second
Benchmark: totoal 9.50 images, 13.60 MByte files processed per second
Benchmark: totoal 8.60 images, 12.31 MByte files processed per second
Benchmark: totoal 4.30 images, 6.15 MByte files processed per second
Benchmark: totoal 7.90 images, 11.31 MByte files processed per second
Benchmark: totoal 7.60 images, 10.88 MByte files processed per second
Benchmark: totoal 7.09 images, 10.16 MByte files processed per second
Benchmark: totoal 8.20 images, 11.74 MByte files processed per second
Benchmark: totoal 5.90 images, 8.45 MByte files processed per second
Benchmark: totoal 8.70 images, 12.46 MByte files processed per second
Benchmark: totoal 8.60 images, 12.31 MByte files processed per second
```

### Using GraphicsMagick, 10 thread, 2.8M image
```
wells@wells-VirtualBox:~/Workspace/ImageBenchmarker/src$ ../bin/imagebenchmarker -n 10 -t 0 -s ../image.jpg -c 960x640
Source file size: 2953018
Benchmark: totoal 5.50 images, 7.87 MByte files processed per second
Benchmark: totoal 3.60 images, 5.15 MByte files processed per second
Benchmark: totoal 1.60 images, 2.29 MByte files processed per second
Benchmark: totoal 0.80 images, 1.15 MByte files processed per second
Benchmark: totoal 1.30 images, 1.86 MByte files processed per second
Benchmark: totoal 0.30 images, 0.43 MByte files processed per second
Benchmark: totoal 1.60 images, 2.29 MByte files processed per second
Benchmark: totoal 1.20 images, 1.72 MByte files processed per second
Benchmark: totoal 1.40 images, 2.00 MByte files processed per second
Benchmark: totoal 1.40 images, 2.00 MByte files processed per second
```

### Using OpenCv, 1 thread, 2.8M image
```
wells@wells-VirtualBox:~/Workspace/ImageBenchmarker/src$ ../bin/imagebenchmarker -n 1 -t 1 -s ../image.jpg -c 960x640
Source file size: 2953018
Benchmark: totoal 19.50 images, 27.92 MByte files processed per second
Benchmark: totoal 22.70 images, 32.50 MByte files processed per second
Benchmark: totoal 21.60 images, 30.92 MByte files processed per second
Benchmark: totoal 19.50 images, 27.92 MByte files processed per second
Benchmark: totoal 19.20 images, 27.49 MByte files processed per second
Benchmark: totoal 17.30 images, 24.77 MByte files processed per second
```

### Using OpenCv, 10 thread, 2.8M image
```
wells@wells-VirtualBox:~/Workspace/ImageBenchmarker/src$ ../bin/imagebenchmarker -n 10 -t 1 -s ../image.jpg -c 960x640
Source file size: 2953018
Benchmark: totoal 0.00 images, 0.00 MByte files processed per second
Benchmark: totoal 18.99 images, 27.20 MByte files processed per second
Benchmark: totoal 19.60 images, 28.06 MByte files processed per second
Benchmark: totoal 21.69 images, 31.06 MByte files processed per second
Benchmark: totoal 21.10 images, 30.21 MByte files processed per second
Benchmark: totoal 22.40 images, 32.07 MByte files processed per second
Benchmark: totoal 22.00 images, 31.50 MByte files processed per second
```
