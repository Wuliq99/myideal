# [Linux系统如何查看版本信息](https://www.cnblogs.com/sunshineliulu/p/8984704.html)

**1、查看当前操作系统内核信息**

**uname -a**

```
$ uname -a

Linux vm-web 3.10.0-693.21.1.el7.x86_64 #1 SMP Wed Mar 7 19:03:37 UTC 2018 x86_64 x86_64 x86_64 GNU/Linux
```

 

**2、查看当前操作系统版本信息**

**cat /proc/version**

```
$ cat /proc/version

Linux version 3.10.0-693.21.1.el7.x86_64 ([builder@kbuilder.dev.centos.org](mailto:builder@kbuilder.dev.centos.org)) (gcc version 4.8.5 20150623 (Red Hat 4.8.5-16) (GCC) ) #1 SMP Wed Mar 7 19:03:37 UTC 2018
```

 

**3、查看当前操作系统发行版信息**

**cat /etc/issue 或 cat /etc/redhat-release**

```
$ cat /etc/issue

Debian GNU/Linux 10 \n \l

 
$ cat /etc/redhat-release

CentOS Linux release 7.4.1708 (Core)
```

 

**4、查看cpu相关信息，包括型号、主频、内核信息等**

**cat /proc/cpuinfo**

```
$ cat /proc/cpuinfo

processor  : 0
vendor_id  : GenuineIntel
cpu family  : 6
model    : 45
model name  : Intel(R) Xeon(R) CPU E5-2660 0 @ 2.20GHz
stepping  : 7
microcode  : 0xffffffff
cpu MHz    : 2199.998
cache size  : 20480 KB
physical id  : 0
siblings  : 2
core id    : 0
cpu cores  : 2
apicid    : 0
initial apicid  : 0
fpu    : yes
fpu_exception  : yes
cpuid level  : 13
wp    : yes
flags    : fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ss ht syscall nx pdpe1gb rdtscp lm constant_tsc rep_good nopl xtopology eagerfpu pni pclmulqdq ssse3 cx16 sse4_1 sse4_2 popcnt aes xsave avx hypervisor lahf_lm xsaveopt
bogomips  : 4399.99
clflush size  : 64
cache_alignment  : 64
address sizes  : 44 bits physical, 48 bits virtual
power management:
processor  : 1
vendor_id  : GenuineIntel
cpu family  : 6
model    : 45
model name  : Intel(R) Xeon(R) CPU E5-2660 0 @ 2.20GHz
stepping  : 7
microcode  : 0xffffffff
cpu MHz    : 2199.998
cache size  : 20480 KB
physical id  : 0
siblings  : 2
core id    : 1
cpu cores  : 2
apicid    : 1
initial apicid  : 1
fpu    : yes
fpu_exception  : yes
cpuid level  : 13
wp    : yes
flags    : fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ss ht syscall nx pdpe1gb rdtscp lm constant_tsc rep_good nopl xtopology eagerfpu pni pclmulqdq ssse3 cx16 sse4_1 sse4_2 popcnt aes xsave avx hypervisor lahf_lm xsaveopt
bogomips  : 4399.99
clflush size  : 64
cache_alignment  : 64
address sizes  : 44 bits physical, 48 bits virtual
power management:
```

 

**5、列出所有版本信息**

**lsb_release -a**

```
$ lsb_release -a

-bash: lsb_release: command not found
```

出现command not found说明没安装lsb_realease，可以执行命令yum install -y redhat-lsb安装lsb_realease，安装完成后，版本信息如下：

```
$ lsb_release -a

LSB Version:  :core-4.1-amd64:core-4.1-noarch:cxx-4.1-amd64:cxx-4.1-noarch:desktop-4.1-amd64:desktop-4.1-noarch:languages-4.1-amd64:languages-4.1-noarch:printing-4.1-amd64:printing-4.1-noarch
Distributor ID:  CentOS
Description:  CentOS Linux release 7.4.1708 (Core)
Release:  7.4.1708
Codename:  Core
```