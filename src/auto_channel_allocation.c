#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <termios.h>
#include <stdlib.h>


/*
01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789
ra0       get_site_survey:
Ch  SSID                             BSSID               Security               Siganl(%)W-Mode  ExtCH  NT
1   FAST                             00:5a:39:04:1b:88   WPA1PSKWPA2PSK/TKIPAES 44       11b/g/n ABOVE  In
1   FAST_997ACA                      bc:d1:77:99:7a:ca   WPA1PSKWPA2PSK/AES     76       11b/g/n ABOVE  In
1   MERCURY_Office                   14:cf:92:36:04:ce   WPA1PSKWPA2PSK/AES     34       11b/g/n ABOVE  In
6   SoftwareOffice                   b8:a3:86:b7:49:da   WPA1PSKWPA2PSK/TKIPAES 86       11b/g/n ABOVE  In
6   WRTnode2090                      00:0c:43:76:20:90   NONE                   100      11b/g/n ABOVE  In
6   FAST_997868                      bc:d1:77:99:78:68   WPA1PSKWPA2PSK/AES     81       11b/g/n NONE   In
11  wcy318                           28:2c:b2:aa:9d:3c   WPA1PSKWPA2PSK/AES     29       11b/g/n BELOW  In
11  Ruckus-Wireless-1                74:91:1a:3a:71:c8   NONE                   100      11b/g   NONE   In
11  0x333630E5858DE8B4B9576946692D   58:91:cf:3c:0a:74   WPA2PSK/AES            39       11b/g/n NONE   In

*/


/*
#include <stdio.h>
int main()
{
    double lat[1000];
    double lon[1000];
 
    FILE *fp;
    char str[128];
    int i=0,j;
    fp=fopen( "data.txt", "r");
    if ( fp == NULL )
    {
        printf("open file error\n");
        return -1;
    }
    fgets(str,sizeof(str),fp);//skip first line
    while ( fgets(str,sizeof(str),fp) )
    {
        sscanf( str, "%lf %lf", &lat[i], &lon[i] );
        i++;
    }
    fclose(fp);
    for( j=0;j<i;j++ )
    {
        printf( "%lf %lf\n", lat[j], lon[j] );
    }
    return 0;
}
*/
typedef struct
{
	char ch[2];
	char SSID[32];
	char BSSID[17];
	char Security[22];
	char Siganl[3];
	char W_Mode[7];
	char ExtCH[5];
	char NT[2];
}site_survey;








int main(void)
{
    FILE *fp;
	char i;
	char ch_quantity = 0;
	char ch_num;
	char ch_num_str[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	char str[128];
    fp=fopen( "/usr/aps.txt", "r");
    if ( fp == NULL )
    {
        printf("open aps.txt file error\n");
        return -1;
    }
	printf("open aps.txt file OK!\n");
	fgets(str,sizeof(str),fp);			//skip first line
	printf("aps.txt first line:\n%s",str);
	fgets(str,sizeof(str),fp);			//skip first line
	printf("aps.txt second line:\n%s",str);
	printf("ap scan data:\n");
	
	while( fgets(str,sizeof(str),fp) )
	{
		if('0' < str[0])
		{
			ch_quantity++;
			printf("%s",str);
		}
		
		if(('0' < str[0]) && (' ' == str[1]))
		{
			ch_num = str[0] - '0';
		}
		else if(('0' < str[0]) && ('/' < str[1]))
		{
			ch_num = (str[0] - '0') * 10 + (str[1] - '0');
		}

		switch(ch_num)
		{
			case 1:
				ch_num_str[ch_num - 1] ++;
				break;
			case 2:
				ch_num_str[ch_num - 1] ++;
				break;
			case 3:
				ch_num_str[ch_num - 1] ++;
				break;
			case 4:
				ch_num_str[ch_num - 1] ++;
				break;
			case 5:
				ch_num_str[ch_num - 1] ++;
				break;
			case 6:
				ch_num_str[ch_num - 1] ++;
				break;
			case 7:
				ch_num_str[ch_num - 1] ++;
				break;
			case 8:
				ch_num_str[ch_num - 1] ++;
				break;
			case 9:
				ch_num_str[ch_num - 1] ++;
				break;
			case 10:
				ch_num_str[ch_num - 1] ++;
				break;
			case 11:
				ch_num_str[ch_num - 1] ++;
				break;
			case 12:
				ch_num_str[ch_num - 1] ++;
				break;
			case 13:
				ch_num_str[ch_num - 1] ++;
				break;
			case 14:
				ch_num_str[ch_num - 1] ++;
				break;
			default:
				// printf("wrong channel number!\n");
				break;
		}
		ch_num = 0;
	}

	printf("The number of local ap is %d.\n",ch_quantity);
	
	for(i = 0;i < sizeof(ch_num_str);i++)
	{
		if( ch_num_str[i] > 0)
		{
			printf("The number of channel-%02d is %d.\n",i+1,ch_num_str[i]);
		}
	}
    fclose(fp);

	return 0;
}








