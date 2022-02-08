#!/bin/bash
arc=$(uname -a)
pCPU=$(nproc)
vCPU=$(cat /proc/cpuinfo | grep processor | wc -l)
mem=$(free | grep Mem | awk '{printf"%.f/%.fMB (%.2f%%)", $3/1000, $2/1000, ($4/$2)/($3/$2)) }')
disk=$(df -h | awk '$NF=="/"{printf"%d/%dGB (%s)", $3,$2,$5}')
CPUload=$(top -bn1 | grep '^%Cpu' | cut -c 9- | xargs | awk '{printf("%.1f%%"), $1 + $3}')
last=$(who -b | cut -c 23-)
LVM=$(lsblk | grep lvm | awk '{if ($1) {print "yes";exit;} else {print "no"} }')
TCP=$(netstat -ant | grep ESTABLISHED | wc -l)
usrlog=$(who | wc -l)
ip=$(ip route | grep src | cut -c 52-)
MAC=$(ip link | grep link/ether | cut -c 16-32)
sudo=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

wall "  #Architecture: $arc
		#CPU physical : $pCPU
		#vCPU : $vCPU
		#Memory Usage: $mem
		#Disk Usage: $disk
		#CPU load: $CPUload
		#Last boot: $last
		#LVM use: $LVM
		#Connexions TCP : $TCP ESTABLISHED
		#User log: $usrlog
		#Network: IP $ip ($MAC)
		#Sudo: $sudo cmd"

