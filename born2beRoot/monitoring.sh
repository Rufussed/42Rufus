#!/bin/bash

# ARCH
architechture=$(uname -a)

# CPU PHYSICAL
cpu_physical=$(grep "physical id" /proc/cpuinfo | wc -l)

# CPU VIRTUAL
cpu_virtual=$(grep "processor" /proc/cpuinfo | wc -l)

# RAM
ram_total=$(free --mega | awk '$1 == "Mem:" {print $2}')
ram_used=$(free --mega | awk '$1 == "Mem:" {print $3}')
ram_percent=$(awk "BEGIN {printf \"%.2f\", $ram_used/$ram_total*100}")

# DISK
disk_total=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_t += $2} END {printf "%.1f", disk_t/1024}')
disk_used=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} END {print disk_u}')
disk_percent=$(awk "BEGIN {printf \"%.2f\", $disk_used/$disk_total*100/1024}")

# CPU LOAD
cpu_wait=$(vmstat 1 2 | tail -1 | awk '{printf $15}')
cpu_load=$(expr 100 - $cpu_wait)
cpu_load_formatted=$(printf "%.1f" $cpu_load)

# LAST BOOT
last_boot=$(who -b |awk '$1 == "system" {print $3 " " $4}')

# LVM USE
lvm_use=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)

# TCP CONNECTIONS
tcp_connections=$(ss -ta | grep ESTAB | wc -l)

# USER LOG
user_log=$(users | wc -w)

# NETWORK
ip=$(hostname -I)
mac=$(ip link | grep "link/ether" | awk '{print $2}')

# SUDO
cmnd=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

wall "	Architechture: $architechture
	CPU physical: $cpu_physical
	vCPU: $cpu_virtual
	Memory Usage: $ram_used/${ram_total}MB ($ram_percent%)
	Disk Usage: $disk_used/${disk_total}GB ($disk_percent%)
	CPU Load: $cpu_load_formatted%
	Last Boot: $last_boot
	LVM use: $lvm_use
	Connections TCP: $tcp_connections ESTABLISHED
	User log: $user_log
	Network: IP $ip ($mac)
	Sudo: $cmnd cmd"
