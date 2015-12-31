#!/system/bin/sh

if [ "${1}" = "-v" ]; then
exec "/system/bin/ks_exec" -v -w /data/cp_log/ -p /dev/ttyUSB0 -r 21 -s 2:/firmware/image/amss.mbn -s 6:/firmware/image/apps.mbn -s 8:/firmware/image/dsp1.mbn -s 11:/firmware/image/osbl.mbn -s 12:/firmware/image/dsp2.mbn -s 21:/firmware/image/sbl1.mbn -s 22:/firmware/image/sbl2.mbn -s 23:/firmware/image/rpm.mbn -s 28:/firmware/image/dsp3.mbn -s 16:/tombstones/qcks/efs1.bin -s 17:/tombstones/qcks/efs2.bin -s 20:/tombstones/qcks/efs3.bin -s 29:/tombstones/qcks/acdb.bin | /system/bin/setprop ril.ks.status 0
elif [ "${1}" = "-m" ]; then
exec "/system/bin/ks_exec" -m -v -w /dev/block/modem/dump_path/ -p /dev/ttyUSB0 -t -1 -l
fi