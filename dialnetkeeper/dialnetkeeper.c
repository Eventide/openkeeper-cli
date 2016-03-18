#include "dialnetkeeper.h"

int main( int argc, char *argv[] )
{
	char user_src[ BUF_SIZE ];
	char user_real[ BUF_SIZE ];
	char radius[16];

	get_user_message( argc, argv, user_src, radius );
	get_real_user_name( user_src, radius, user_real );
	printf ("%s\n", user_real );

	return 0;
}

void get_user_message( int argc, char *argv[], char *user, char *radius )
{
	if ( 3 != argc ) {
		printf ( "Usage: dianetkeeper <user_name> <radius>\n"
				"Radius as falllow:\n"
				"ChongQing Netkeeper: cqxinliradius002\n"
				"ChongQing Netkeeper(0094): xianxinli1radius\n"
				"WuHan E xin: hubtxinli01\n"
				"Hangzhou(Tested on HDU): singlenet01\n"
				"NanChangV18: nanchang3.0\n"
				"NanChangV12~V17: radius\n"
				"NanChangV29: nanchang3.0\n"
				"NanChangV32: jiangxi4.0\n"
				"QingHai: qhtel@xiaoyuanyi\n" );
		exit(-1);
	}
	strcpy( user, argv[1] );
	strcpy( radius, argv[2] );
}

void get_real_user_name( const char *src, const char *radius, char *dst )
{
	char time_byte[4], *before_md5;
	unsigned char after_md5[16];
	char md5_01h[2], md5_01[3];
	char time_hash[4], pin_27[6];
	int i;
	char tmp[32];
	time_t _time;
	MD5_CTX md5;

	_time = time( NULL ) / 5;
	for ( i = 0; i < 4; i++ )
		time_byte[i] = (unsigned char)( _time >> (8*(3-i)) & 0xFF );
	before_md5 = malloc(strlen(time_byte) + strlen(src) + strlen(radius) + 1);
	memcpy( before_md5, time_byte, 4 );
	memcpy( before_md5 + 4, src, strcspn( src, "@" ) );
	strcat( before_md5, radius );
	MD5_Init( &md5 );
	MD5_Update( &md5, before_md5, strlen( before_md5 ) );
	MD5_Final( after_md5, &md5 );
	md5_01h[0] = after_md5[0] >> 4 & 0xF;
	md5_01h[1] = after_md5[0] & 0xF;
	sprintf( md5_01, "%x", md5_01h[0] );
	sprintf( md5_01 + 1, "%x", md5_01h[1] );

	for ( i = 0; i < 32; i++ ) {
		tmp[i] = time_byte[ (31-i)/8 ] & 1;
		time_byte[ (31-i)/8 ] = time_byte[ (31-i)/8 ] >> 1;
	}

	for ( i = 0; i < 4; i++ ) {
		 time_hash[i] = tmp[i] * 128 + tmp[4 + i] * 64 + tmp[8 + i] * 32
			+ tmp[12 + i] * 16 + tmp[16 + i] * 8 + tmp[20 + i] * 4 + tmp[24 + i] * 2 + tmp[28 + i];
	}

	tmp[1] = (time_hash[0] & 3) << 4;
	tmp[0] = (time_hash[0] >> 2) & 0x3F;
	tmp[2] = (time_hash[1] & 0xF) << 2;
	tmp[1] = (time_hash[1] >> 4 & 0xF) + tmp[1];
	tmp[3] = time_hash[2] & 0x3F;
	tmp[2] = ((time_hash[2] >> 6) & 0x3) + tmp[2];
	tmp[5] = (time_hash[3] & 3) << 4;
	tmp[4] = (time_hash[3] >> 2) & 0x3F;

	for ( i = 0; i < 6; i++ ) {
		pin_27[i] = tmp[i] + 0x020;
		if ( pin_27[i] >= 0x40 )
			pin_27[i]++;
	}

	dst[0] = '\r';
	if ( 0 == strcmp( radius, "jiangxi4.0" ) ) 
		dst[1] = '1';
	else 
		dst[1] = '\n';

	memcpy( dst + 2, pin_27, 6 );
	dst[8] = md5_01[0];
	dst[9] = md5_01[1];
	strcpy( dst + 10, src );

	free(before_md5);
}
