#include <time.h>
#include <strproc.h>


#define INTERVAL(now) ((int)(now_usec() - now))

#ifdef __cplusplus
extern "C" {
#endif

/*  准儒略历日期函数 */
/************************************************************************/
/*function:rymdjul 将年月日数组转换为准儒略历数,1899.12.31至指定日的天数*/
/************************************************************************/
INT4	rymdjul(short ymd[3]);

/************************************************************************/
/*function:rjulymd 将准儒略历数(距离1899.12.31的天数)转换为年月日数组	*/
/************************************************************************/
INT4	rjulymd(INT4  date,short ymd[3]);

/************************************************************************/
/*function:rjulstr 将准儒略历数按最后设置默认的格式转换为年月日字符串	*/
/*description:缺省默认格式为YYYY.MM.DD	准儒略历数(以天为单位)		*/
/************************************************************************/
char	*rjulstr(char *str,INT4 jul);

/************************************************************************/
/*function:rstrjul 将最后设置默认格式的年月日字符串转换为准儒略历数	*/
/*description:缺省默认格式为YYYY.MM.DD	准儒略历数(以天为单位)		*/
/************************************************************************/
INT4	rstrjul(char *str);

/************************************************************************/
/*function:SetDefaultDateFormat 设置默认日期格式		        */
/*description:如果没有设置，则默认格式为YYYY.MM.DD			*/
/*返回原来的格式 if format is (char *)0,recover DefaultDateFormat	*/
/************************************************************************/
char	*SetDefaultDateFormat(char *format);

/************************************************************************/
/*function:rjultostrfmt 将准儒略历数按指定格式转换为年月日字符串        */
/*description:fmt(YYYY-MM-DD等格式)	准儒略历数(以天为单位)		*/
/*可以任意颠倒次序，可以大写或小写，可以没有分隔符。分隔符可以是汉字	*/
/************************************************************************/
char	*rjultostrfmt(char *buffer,INT4  dat,const char *fmt);

/************************************************************************/
/*function:rstrfmttojul 将年月日字符串按指定格式转换为准儒略历数        */
/*description:fmt(YYYY-MM-DD等格式)	 准儒略历数(以天为单位)		*/
/*可以任意颠倒次序，可以大写或小写，可以没有分隔符。分隔符可以是汉字	*/
/************************************************************************/
INT4	rstrfmttojul(char *str,const char *fmt);

/* 准儒略历时间函数 */
/************************************************************************/
/*function:rminstr 将GREENWITH(以分钟为单位)按格式转换成本地的年月日时分*/
/*description:fmt(默认为YYYY.MM.DD HH24:MI格式)				*/
/*rminstr() convert GREENWITH minuts to  local time			*/
/************************************************************************/
char	*rminstr(char *year_to_min,INT4  minuts);

/************************************************************************/
/*function:rstrmin 将本地的年月日时分按格式转换成GREENWITH(以分钟为单位)*/
/*description:fmt(默认为YYYY.MM.DD HH24:MI格式)				*/
/*rstrmin() convert local time to GREENWITH minuts			*/
/************************************************************************/
INT4	rstrmin(char *year_to_min);

/************************************************************************/
/*function:rminstrfmt 将准儒略历数(以分钟为单位)按格式转换成年月日时分	*/
/*description:fmt(YYYY-MM-DD HH24:MI或YYYY-MM-DD HH:NN等格式)		*/
/*可以任意颠倒次序，可以大写或小写，可以没有分隔符。分隔符可以是汉字	*/
/************************************************************************/
char	*rminstrfmt(char *year_to_min,INT4  minuts,const char *fmt);

/************************************************************************/
/*function:rstrminfmt 将年月日时分按格式转换成准儒略历数(以分钟为单位)	*/
/*description:fmt(YYYY-MM-DD HH24:MI或YYYY-MM-DD HH:NN等格式)		*/
/*可以任意颠倒次序，可以大写或小写，可以没有分隔符。分隔符可以是汉字	*/
/************************************************************************/
INT4	rstrminfmt(char *year_to_min,const char *fmt);

/************************************************************************/
/* function:rtimetostrfmt将日期型转换成字符串的年月日时分秒             */
/*description:fmt(YYYY-MM-DD HH24:MI:SS或YYYY-MM-DD HH:NN:SS.FF6等格式)	*/
/*可以任意颠倒次序，可以大写或小写，可以没有分隔符。分隔符可以是汉字	*/
/************************************************************************/
char	*rtimetostrfmt(char *buffer,const char *fmt,short ymd[3],short hms[3],int usec);

/************************************************************************/
/* function:rstrfmttotime 将字符串的年月日时分秒转换成准儒略历数	*/
/*description:fmt(YYYY-MM-DD HH24:MI:SS或YYYY-MM-DD HH:NN:SS.FF6等格式)	*/
/*可以任意颠倒次序，可以大写或小写，可以没有分隔符。分隔符可以是汉字	*/
/*返回：准儒略历数(以天为单位),hms：时分秒，usec：微秒			*/
/************************************************************************/
INT4	rstrfmttotime(char *str,const char *fmt,short hms[3],int *usec);

/************************************************************************/
/* function:rsecstrfmt 将准儒略历数转换成字符串的年月日时分秒		*/
/*description:fmt(YYYY-MM-DD HH24:MI:SS或YYYY-MM-DD HH:NN:SS等格式)	*/
/*可以任意颠倒次序，可以大写或小写，可以没有分隔符。分隔符可以是汉字	*/
/*准儒略历数(以秒为单位)						*/
/************************************************************************/
char	*rsecstrfmt(char *buf,INT64 sec,const char *fmt);

/************************************************************************/
/* function:rstrsecfmt 将字符串的年月日时分秒转换成准儒略历数		*/
/*description:fmt(YYYY-MM-DD HH24:MI:SS或YYYY-MM-DD HH:NN:SS等格式)	*/
/*可以任意颠倒次序，可以大写或小写，可以没有分隔符。分隔符可以是汉字	*/
/*准儒略历数(以秒为单位)						*/
/************************************************************************/
INT64	rstrsecfmt(char *str,const char *fmt);
/************************************************************************/
/* function:rusecstrfmt 将准儒略历微秒数转换成字符串的年月日时分秒.微秒			*/
/*description:fmt(YYYY-MM-DD HH24:MI:SS.FF6或YYYY-MM-DD HH:NN:SS.FF6等格式)		*/
/*可以任意颠倒次序，可以大写或小写，可以没有分隔符。分隔符可以是汉字	*/
/*准儒略历数(以微秒为单位)												*/
/************************************************************************/
char *rusecstrfmt(char *buf,INT64 usec,const char *fmt);
/************************************************************************/
/* function:rstrusecfmt 将字符串的年月日时分秒转换成准儒略历微秒数	*/
/*description:fmt(YYYY-MM-DD HH24:MI:SS或YYYY-MM-DD HH:NN:SS等格式)	*/
/*可以任意颠倒次序，可以大写或小写，可以没有分隔符。分隔符可以是汉字	*/
/*返回：准儒略历数(以微秒为单位)						*/
/************************************************************************/
INT64 rstrusecfmt(char *str,const char *fmt);

/************************************************************************/
/*function:cvtdate 相对日期转换函数,返回准儒略历数(以天为单位)		*/
/*description:								*/
/*基本形式:str(YYYY.MM.DD), refday:参考日期				*/
/*如果哪一段缺省,以参考日期的相应数字代替				*/
/*DD = 31,将被参考日期月底日取代					*/
/*哪一段以+ -开头，相对参考日期的相应数字运算				*/
/*L代表月底(包括2月的28或29日,以及其它月的30日、31日)			*/
/*例：									*/
/*  .代表当日，..代表本月当日。						*/
/*  +1代表明天，-1代表昨天, .31或31或.L代表本月月底。			*/
/*  .-1.或-1. 代表上月同日，-1.31代表上月月底。				*/
/*  -1.1.1代表去年1月1日。 -1..代表去年本月当日。-1.2.31代表去年2月底	*/
/*  2009.1.1代表2009年1月1日。.1.1或1.1代表今年1月1日。.1或1代表本月1日 */
/************************************************************************/
INT4	cvtdate(char *str,INT4 refday);

/************************************************************************/
/*function:yday 年时间戳函数						*/
/*description:								*/
/*计算指定的准儒略历数对应的年月日距离该年1月1日(包含该天)的天数	*/
/*例：									*/
/* day = 367 对应的年月日为1901.1.2,则距离1901.1.1的天数为2		*/
/************************************************************************/
INT4	yday(INT4 day);

/************************************************************************/
/*function:jday 季度时间戳函数						*/
/*description:								*/
/*计算指定的准儒略历数对应的年月日距离每一季度(1、4、7、10月1日(包含	*/
/*该天))的天数								*/
/*例：									*/
/* day = 457 对应的年月日为1901.4.2,则距离1901.4.1的天数为2		*/
/************************************************************************/
INT4	jday(INT4 day);

/************************************************************************/
/*function:mon_end 月底时间戳函数					*/
/*description:								*/
/*计算指定的准儒略历数对应月的月底距离1899.12.31的天数			*/
/*例：									*/
/* day = 366 对应的年月日为1901.1.1,即月底为1901.1.31，则距离1899.12.31	*/
/*的天数为396								*/
/************************************************************************/
INT4	mon_end(INT4 day);

/************************************************************************/
/*function:mday	每月天数函数						*/
/*description:计算指定的准儒略历数对应月的总天数			*/
/*例：									*/
/* day = 397 对应的年月日为1901.2.1,即2月有28天				*/
/************************************************************************/
INT4	mday(INT4 day);

/************************************************************************/
/*function:dday	月时间戳函数						*/
/*description:计算指定的准儒略历数对应月距离该月1日(包含该天)的天数	*/
/*例：									*/
/* day = 397 对应的年月日为1901.2.1,则距离2.1的天数为1			*/
/************************************************************************/
INT4	dday(INT4 day);

/************************************************************************/
/*functions:系统时间的准儒略历格式函数			*/
/*这部分内容与操作系统有关，适于unix类系统。		*/
/*有效的时间范围是1970.1.1 00:00:00 -- 2038.1.19	*/
/*应根据不同的操作系统修改				*/
/************************************************************************/
/************************************************************************/
/*function:rtoday 取出当日的准儒略历(距离1899.12.31)的天数		*/
/************************************************************************/
INT4	rtoday(void); /* 返回本地时间的日期 */

/************************************************************************/
/*function:now_minuts 取出当日的准儒略历(距离1899.12.31 0:0)的分钟数	*/
/************************************************************************/
INT4	now_minuts(void);	/* 返回GREEMWITH时间 */

/************************************************************************/
/*function:now_sec 取出当日的准儒略历(距离1899.12.31 0:0:0)的秒数	*/
/************************************************************************/
INT64	now_sec(void);		/* 返回GREEMWITH时间 */
/*function:now_usec 取出当日的准儒略历(距离1899.12.31 0:0:0.000000)的微秒数 */
INT64 now_usec(void);	 	/* 返回GREEMWITH时间 */

/************************************************************************/
/*function:DateTimeConvert 日期时间数值与字符串指定格式转换	*/
/*description:fmt(YYYYMMDDHHmmSS格式)	*/
/*如果指定字符串'date'时，则将字符串转换成距离(1970.01.01 00:00:00 GMT	*/
/*换算成本地时间)的时间戳秒数；如果指定时间戳秒数,则date设置为空,即将距	*/
/*离(1970.01.01 00:00:00 GMT换算成本地时间)的时间戳秒数转换成字符串	*/
/*有效的时间范围是1970.1.1 00:00:00 -- 2038.1.19(GREEMWITH时间)	*/
/*例：									*/
/* 1、date = 19700101080001; (localtime)，即对应GMT为19700101000001 */
/*	  secs = 0; fmt = YYYYMMDDHHmmSS ; 则可计算出时间戳秒数 secs = 1 */
/* 2、*date = NULL(必须); secs = 1; fmt = YYYYMMDDHHmmSS ; 则可根据时间	*/
/*    戳秒数按YYYYMMDDHHmmSS格式转换成对应的字符串值			*/
/************************************************************************/
void	DateTimeConvert(char *date,time_t *secs,char *fmt);

/************************************************************************/
/*function:DateFormatCovert 日期时间格式转换				*/
/*description:fmt(YYYYMMDDHHmmSS或YYYY-MM-DD HH:mm:SS等格式)		*/
/*将'src'转换成fmt格式存放到'dest'中					*/
/*包括：YYYYMMDD <----> YYYY-MM-DD (相互间转换)				*/
/*      YYYYMMDDHHmm  <----> YYYY-MM-DD HH:mm				*/
/*		YYYYMMDDHHmmSS  <---->  YYYY-MM-DD HH:mm:SS		*/
/************************************************************************/
int		DateFormatCovert(char *dest,char *src,char *fmt);


#ifdef __cplusplus
}
#endif
