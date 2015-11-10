#!/bin/sh

clear
echo "WRTnode AP scaner."
echo "Begin scaning APs, pls wait..."

# 设置现场测量参数标志为0
iwpriv ra0 set SiteSurvey=0

echo "Finished."
echo "APs available are..."
iwpriv ra0 get_site_survey >/usr/aps.txt

