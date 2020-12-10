/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 09:56:44 by kyuki             #+#    #+#             */
/*   Updated: 2020/12/08 16:19:46 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "limits.h"
#include "stdlib.h"
#include "stdio.h"

int main(void)
{
    int len[1000];
    int test1;
    int test2;
    int a;
    len[0] = ft_printf("dwadwa\n");
    len[1] = printf("dwadwa\n");
    len[10] = ft_printf("aa%d\n", 33333);
    len[11] = printf("aa%d\n", 33333);
    len[12] = ft_printf("aa%d\n", -33333);
    len[13] = printf("aa%d\n", -33333);
    len[14] = ft_printf("aa%20daa\n", 500);
    len[15] = printf("aa%20daa\n", 500);
    len[16] = ft_printf("aa%.10daa\n", 500);
    len[17] = printf("aa%.10daa\n", 500);
    len[18] = ft_printf("aa%16.8daa\n", 500);
    len[19] = printf("aa%16.8daa\n", 500);
    len[20] = ft_printf("aa%16.8daa\n", -500);
    len[21] = printf("aa%16.8daa\n", -500);
    len[22] = ft_printf("%i\n", 33);
    len[23] = printf("%i\n", 33);
    len[24] = ft_printf("%-16.8d\n", -33);
    len[25] = printf("%-16.8d\n", -33);
    len[26] = ft_printf("vv%-*.*d\n",-10, -5, -1000);
    len[27] = printf("vv%-*.*d\n",-10, -5, -1000);
    len[28] = ft_printf("vv%*.*d\n",5, 10, 1000);
    len[29] = printf("vv%*.*d\n",5, 10, 1000);
    len[30] = ft_printf("vv%010d\n",123);
    len[31] = printf("vv%010d\n",123);
    len[32] = ft_printf("vv%010.5d\n",123);
    len[33] = printf("vv%010.5d\n",123);
    
    len[40] = ft_printf("aa%c\n", 'a');
    len[41] = printf("aa%c\n", 'a');
    len[42] = ft_printf("aa%5c\n", 'a');
    len[43] = printf("aa%5c\n", 'a');
    len[44] = ft_printf("aa%-5c\n", 'a');
    len[45] = printf("aa%-5c\n", 'a');
    
    len[50] = ft_printf("aa%x\n", 33333);
    len[51] = printf("aa%x\n", 33333);
    len[52] = ft_printf("aa%X\n", -33333);
    len[53] = printf("aa%X\n", -33333);
    len[54] = ft_printf("aa%20X\n", -33333);
    len[55] = printf("aa%20X\n", -33333);
    len[56] = ft_printf("aa%20.10X\n", 33333);
    len[57] = printf("aa%20.10X\n", 33333);
    len[58] = ft_printf("aa%-20.10X\n", -33333);
    len[59] = printf("aa%-20.10X\n", -33333);
    len[60] = ft_printf("vv%-*.*x\n",-10, -5, -1000);
    len[61] = printf("vv%-*.*x\n",-10, -5, -1000);
    len[62] = ft_printf("vv%*.*X\n",5, 10, 1000);
    len[63] = printf("vv%*.*X\n",5, 10, 1000);
    len[64] = ft_printf("aa%#X\n", 33333);
    len[65] = printf("aa%#X\n", 33333);
    len[66] = ft_printf("vv%#20.10x\n", -10);
    len[67] = printf("vv%#20.10x\n", -10);
    
    len[70] = ft_printf("aa%u\n", -33333);
    len[71] = printf("aa%u\n", -33333);
    len[72] = ft_printf("aa%u\n", 33333);
    len[73] = printf("aa%u\n", 33333);
    len[74] = ft_printf("aa%10u\n", 33333);
    len[75] = printf("aa%10u\n", 33333);
    len[76] = ft_printf("aa%10.6u\n", 333);
    len[77] = printf("aa%10.6u\n", 333);
    len[78] = ft_printf("vv%-*.*u\n",-10, -5, -1000);
    len[79] = printf("vv%-*.*u\n",-10, -5, -1000);
    len[80] = ft_printf("vv%*.*u\n",5, 10, 1000);
    len[81] = printf("vv%*.*u\n",5, 10, 1000);
    len[82] = ft_printf("vv%20.10u\n", -10);
    len[83] = printf("vv%20.10u\n", -10);
    
	len[90] = ft_printf("vv%10s\n", "ssss");
	len[91] = printf("vv%10s\n", "ssss");
    len[92] = ft_printf("vv%-10.2s\n", "12345");
    len[93] = printf("vv%-10.2s\n", "12345");
    len[94] = ft_printf("[vv%2.3s]\n", "12345");
    len[95] = printf("[vv%2.3s]\n", "12345");
    len[96] = ft_printf("[%-10s]\n", "12345");
    len[97] = printf("[%-10s]\n", "12345");
    
    len[98] = ft_printf("[%5s]\n", "123456789");
    len[99] = printf("[%5s]\n", "123456789");
    len[100] = ft_printf("[%7.5s]\n", "123456789");
    len[101] = printf("[%7.5s]\n", "123456789");
    len[102] = ft_printf("[%7.5s]\n", "1234");
    len[103] = printf("[%7.5s]\n", "1234");
    len[104] = ft_printf("[%.5s]\n", "123456789");
    len[105] = printf("[%.5s]\n", "123456789");
    len[106] = ft_printf("[%-7.5s]\n", "1234");
    len[107] = printf("[%-7.5s]\n", "1234");
    len[108] = ft_printf("[%3.sa]","   ");
    len[109] = printf("[%3.sa]","   ");
    
    
     len[110] = ft_printf("aa%o\n", 33333);
     len[111] = printf("aa%o\n", 33333);
     len[112] = ft_printf("aa%20o\n", -33333);
     len[113] = printf("aa%20o\n", -33333);
     len[114] = ft_printf("aa%20.10o\n", 33333);
     len[115] = printf("aa%20.10o\n", 33333);
     len[116] = ft_printf("aa%-20.10o\n", -33333);
     len[117] = printf("aa%-20.10o\n", -33333);
     len[118] = ft_printf("vv%-*.*o\n",-10, -5, -1000);
     len[119] = printf("vv%-*.*o\n",-10, -5, -1000);
     len[120] = ft_printf("vv%*.*o\n",5, 10, 1000);
     len[121] = printf("vv%*.*o\n",5, 10, 1000);
     len[122] = ft_printf("aa%#o\n", 33333);
     len[123] = printf("aa%#o\n", 33333);
     len[124] = ft_printf("vv%#20.10o\n", -10);
     len[125] = printf("vv%#20.10o\n", -10);
    len[140] = ft_printf("%p\n", &a);
    len[141] = printf("%p\n", &a);
    len[142] = ft_printf("%30p\n", &a);
    len[143] = printf("%30p\n", &a);
    len[144] = ft_printf("%-30p\n", &a);
    len[145] = printf("%-30p\n", &a);
    len[146] = ft_printf("%-*p\n", 30,&a);
    len[147] = printf("%-*p\n", 30,&a);
    
    len[160] = ft_printf("%5%\n");
    len[161] = printf("%5%\n");
    len[162] = ft_printf("%-5%\n");
    len[163] = printf("%-5%\n");
    len[164] = ft_printf("%05%\n");
    len[165] = printf("%05%\n");
    
    len[180] = ft_printf("hello, %s.\n", NULL);
    len[181] = printf("hello, %s.\n", NULL);
    len[182] = ft_printf("hello, %10s.\n", NULL);
    len[183] = printf("hello, %10s.\n", NULL);
    len[184] = ft_printf("hello, %10.5s.\n", NULL);
    len[185] = printf("hello, %10.5s.\n", NULL);
    len[186] = ft_printf("hello, %-10s.\n", NULL);
    len[187] = printf("hello, %-10s.\n", NULL);
    len[188] = ft_printf("%3.sa\n", NULL);
    len[189] = printf("%3.sa\n", NULL);
    
    puts("***************   ノーマル   *****************");
    puts("----------------------------------");
    ft_printf("normal: dwadwa: %d\n", len[0]);
    printf("normal: dwadwa: %d\n", len[1]);
    
    puts("***************   %d %i  *****************");
    puts("----------------------------------");
	ft_printf("%%d: aa%d: %d\n", 33333, len[10]);
	printf("%%d: aa%d: %d\n", 33333, len[11]);
    puts("----------------------------------");
	ft_printf("%%d(-): %d: %d\n", -33333, len[12]);
	printf("%%d(-): %d: %d\n", -33333, len[13]);
    puts("----------------------------------");
    ft_printf("%%20d: aa%20daa: %d\n",500, len[14]);
    printf("%%20d: aa%20daa: %d\n", 500, len[15]);
    puts("----------------------------------");
    ft_printf("%%.10d: aa%.10daa: %d\n",500, len[16]);
    printf("%%.10d: aa%.10daa: %d\n", 500, len[17]);
    puts("----------------------------------");
    ft_printf("%%16.8d: aa%16.8daa: %d\n",500, len[18]);
    printf("%%16.8d: aa%16.8daa: %d\n", 500, len[19]);
    puts("----------------------------------");
    ft_printf("%%16.8d(-): aa%16.8daa: %d\n",-500, len[20]);
    printf("%%16.8d(-): aa%16.8daa: %d\n", -500, len[21]);
    puts("----------------------------------");
    ft_printf("%%16.8i(-): aa%16.8iaa: %d\n",33, len[22]);
    printf("%%16.8i(-): aa%16.8iaa: %d\n", 33, len[23]);
    puts("----------------------------------");
    ft_printf("%%16.8d(-): aa%-16.8daa: %d\n",-33, len[24]);
    printf("%%16.8d(-): aa%-16.8daa: %d\n", -33, len[25]);
    puts("----------------------------------");
    ft_printf("%%-10.-5d(-): vv%-*.*daa: %d\n", -10, -5, -1000, len[26]);
    printf("%%-10.-5d(-): vv%-*.*daa: %d\n", -10, -5, -1000, len[27]);
    puts("----------------------------------");
    ft_printf("%%5.10d: vv%*.*daa: %d\n", 5, 10, 1000, len[28]);
    printf("%%5.10d: vv%*.*daa: %d\n", 5, 10, 1000, len[29]);
    puts("----------------------------------");
    ft_printf("%%010d: vv%010daa: %d\n", 123, len[30]);
    printf("%%010d: vv%010daa: %d\n", 123, len[31]);
    ft_printf("%%010.5d: vv%010.5daa: %d\n", 123, len[32]);
    printf("%%010.5d: vv%010.5daa: %d\n", 123, len[33]);
    
    puts("***************   %c   *****************");
    puts("----------------------------------");
    ft_printf("%%c: aa%c: %d\n", 'a', len[40]);
    printf("%%c: aa%c: %d\n", 'a',len[41]);
    puts("----------------------------------");
    ft_printf("%%c: aa%5c: %d\n", 'a', len[42]);
    printf("%%c: aa%5c: %d\n", 'a',len[43]);
    puts("----------------------------------");
    ft_printf("%%c: aa%-5c: %d\n", 'a', len[44]);
    printf("%%c: aa%-5c: %d\n", 'a',len[45]);

    puts("***************   %x %X   *****************");
    puts("----------------------------------");
    ft_printf("%%x: aa%x: %d\n", 33333, len[50]);
    printf("%%x: aa%x: %d\n", 33333, len[51]);
    puts("----------------------------------");
    ft_printf("%%X(-): aa%X: %d\n", -33333, len[52]);
    printf("%%X(-): aa%X: %d\n", -33333, len[53]);
    puts("----------------------------------");
    ft_printf("%%20X(-): aa%20X: %d\n", -33333, len[54]);
    printf("%%20X(-): aa%20X: %d\n", -33333, len[55]);
    puts("----------------------------------");
    ft_printf("%%20.10X: aa%20.10X: %d\n", 33333, len[56]);
    printf("%%20.10X: aa%20.10X: %d\n", 33333, len[57]);
    puts("----------------------------------");
    ft_printf("%%-20.10X(-): aa%-20.10X: %d\n", -33333, len[58]);
    printf("%%-20.10X(-): aa%-20.10X: %d\n", -33333, len[59]);
    puts("----------------------------------");
    ft_printf("%%-10.-5x(-): vv%-*.*xaa: %d\n", -10, -5, -1000, len[60]);
    printf("%%-10.-5x(-): vv%-*.*xaa: %d\n", -10, -5, -1000, len[61]);
    puts("----------------------------------");
    ft_printf("%%5.10X: vv%*.*Xaa: %d\n", 5, 10, 1000, len[62]);
    printf("%%5.10X: vv%*.*Xaa: %d\n", 5, 10, 1000, len[63]);
    puts("----------------------------------");
    ft_printf("%%#X: aa%#X: %d\n", 33333, len[64]);
    printf("%%#X: aa%#X: %d\n", 33333, len[65]);
    puts("----------------------------------");
    ft_printf("%%#20.10x: vv%#20.10x: %d\n", -10, len[66]);
    printf("%%#20.10x: vv%#20.10x: %d\n", -10, len[67]);
    
    puts("***************   %u   *****************");
    puts("----------------------------------");
    ft_printf("%%u(-): aa%u: %d\n", -33333, len[70]);
    printf("%%u(-): aa%u: %d\n", -33333, len[71]);
    puts("----------------------------------");
    ft_printf("%%u: aa%u: %d\n", 33333, len[72]);
    printf("%%u: aa%u: %d\n", 33333, len[73]);
    puts("----------------------------------");
    ft_printf("%%10u: aa%10u: %d\n", 33333, len[74]);
    printf("%%10u: aa%10u: %d\n", 33333, len[75]);
    puts("----------------------------------");
    ft_printf("%%10.6u: aa%10.6u: %d\n", 333, len[76]);
    printf("%%10.6u: aa%10.6u: %d\n", 333, len[77]);
    puts("----------------------------------");
    ft_printf("%%-10.-5u(-): vv%-*.*uaa: %d\n", -10, -5, -1000, len[78]);
    printf("%%-10.-5u(-): vv%-*.*uaa: %d\n", -10, -5, -1000, len[79]);
    puts("----------------------------------");
    ft_printf("%%5.10u: vv%*.*uaa: %d\n", 5, 10, 1000, len[80]);
    printf("%%5.10u: vv%*.*uaa: %d\n", 5, 10, 1000, len[81]);
    puts("----------------------------------");
    ft_printf("%%#20.10u: vv%20.10u: %d\n", -10, len[82]);
    printf("%%#20.10u: vv%20.10u: %d\n", -10, len[83]);
    
    puts("***************   %s   *****************");
    puts("----------------------------------");
    ft_printf("%%10s: vv%10saa: %d\n","ssss", len[90]);
    printf("%%10s: vv%10saa: %d\n", "ssss", len[91]);
    puts("----------------------------------");
    ft_printf("%%-10.2s: [vv%-10.2s]: %d\n", "12345", len[92]);
    printf("%%-10.2s: [vv%-10.2s]: %d\n", "12345", len[93]);
    puts("----------------------------------");
    ft_printf("%%2.3s: [vv%2.3s]: %d\n", "12345", len[94]);
    printf("%%2.3s: [vv%2.3s]: %d\n", "12345", len[95]);
    puts("----------------------------------");
    ft_printf("%%-10s: [vv%-10s]: %d\n", "12345", len[96]);
    printf("%%-10s: [vv%-10s]: %d\n", "12345", len[97]);
    puts("----------------------------------");
    ft_printf("%%5s: [%5s]: %d\n", "123456789", len[98]);
    printf("%%5s: [%5s]: %d\n", "123456789", len[99]);
    puts("----------------------------------");
    ft_printf("%%7.5s: [%7.5s]: %d\n", "123456789", len[100]);
    printf("%%7.5s: [%7.5s]: %d\n", "123456789", len[101]);
    puts("----------------------------------");
    ft_printf("%%7.5s: [%7.5s]: %d\n", "1234", len[102]);
    printf("%%7.5s: [%7.5s]: %d\n", "1234", len[103]);
    puts("----------------------------------");
    ft_printf("%%.5s: [%.5s]: %d\n", "123456789", len[104]);
    printf("%%.5s: [%.5s]: %d\n", "123456789", len[105]);
    puts("----------------------------------");
    ft_printf("%%-7.5: [%-7.5sa]: %d\n", "yolo", len[106]);
    printf("%%-7.5: [%-7.5sa]: %d\n", "yolo", len[107]);
    puts("----------------------------------");
    ft_printf("%%3.s: [%3.sa]: %d\n", "    ", len[108]);
    printf("%%3.s: [%3.sa]: %d\n", "   ", len[109]);
    
    
    
    puts("***************   %o   *****************");
    puts("----------------------------------");
    ft_printf("%%o: aa%o: %d\n", 33333, len[110]);
    printf("%%o: aa%o: %d\n", 33333, len[111]);
    puts("----------------------------------");
    ft_printf("%%20o(-): aa%20o: %d\n", -33333, len[112]);
    printf("%%20o(-): aa%20o: %d\n", -33333, len[113]);
    puts("----------------------------------");
    ft_printf("%%20.10o: aa%20.10o: %d\n", 33333, len[114]);
    printf("%%20.10o: aa%20.10o: %d\n", 33333, len[115]);
    puts("----------------------------------");
    ft_printf("%%-20.10o(-): aa%-20.10o: %d\n", -33333, len[116]);
    printf("%%-20.10o(-): aa%-20.10o: %d\n", -33333, len[117]);
    puts("----------------------------------");
    ft_printf("%%-10.-5o(-): vv%-*.*oaa: %d\n", -10, -5, -1000, len[118]);
    printf("%%-10.-5o(-): vv%-*.*oaa: %d\n", -10, -5, -1000, len[119]);
    puts("----------------------------------");
    ft_printf("%%5.10o: vv%*.*oaa: %d\n", 5, 10, 1000, len[120]);
    printf("%%5.10o: vv%*.*oaa: %d\n", 5, 10, 1000, len[121]);
    puts("----------------------------------");
    ft_printf("%%#o: aa%#o: %d\n", 33333, len[122]);
    printf("%%#o: aa%#o: %d\n", 33333, len[123]);
    puts("----------------------------------");
    ft_printf("%%#o: aa%#o: %d\n", 33333, len[122]);
    printf("%%#o: aa%#o: %d\n", 33333, len[123]);
    puts("----------------------------------");
    ft_printf("%%#20.10o: vv%#20.10o: %d\n", -10, len[124]);
    printf("%%#20.10o: vv%#20.10o: %d\n", -10, len[125]);
    puts("***************   %p   *****************");
    puts("----------------------------------");
    ft_printf("%%p: aa%p: %d\n", &a, len[140]);
    printf("%%p: aa%p: %d\n", &a, len[141]);
    puts("----------------------------------");
    ft_printf("%%30p: aa%30pa: %d\n", &a, len[142]);
    printf("%%30p: aa%30pa: %d\n", &a, len[143]);
    puts("----------------------------------");
    ft_printf("%%-30p: aa%-30p: %d\n", &a, len[144]);
    printf("%%-30p: aa%-30p: %d\n", &a, len[145]);
    puts("----------------------------------");
    ft_printf("%%-30p: aa%-*p: %d\n",30, &a, len[146]);
    printf("%%-30p: aa%-*p: %d\n",30,  &a, len[147]);
    puts("***************   %   *****************");
    puts("----------------------------------");
    ft_printf("%5%: %d\n",len[160]);
    printf("%5%: %d\n",len[161]);
    puts("----------------------------------");
    ft_printf("%-5%: %d\n",len[162]);
    printf("%-5%: %d\n",len[163]);
    puts("----------------------------------");
    ft_printf("%05%: %d\n",len[164]);
    printf("%05%: %d\n",len[165]);
    puts("***************   %s-NULL   *****************");
    puts("----------------------------------");
    ft_printf("%%s(NULL): hello, %s.: %d\n", NULL, len[180]);
    printf("%%s(NULL): hello, %s.: %d\n", NULL, len[181]);
    puts("----------------------------------");
    ft_printf("%%10s(NULL): hello, %10s.: %d\n", NULL, len[182]);
    printf("%%10s(NULL): hello, %10s.: %d\n", NULL, len[183]);
    puts("----------------------------------");
    ft_printf("%%10s(NULL): hello, %10.5s.: %d\n", NULL, len[184]);
    printf("%%10s(NULL): hello, %10.5s.: %d\n", NULL, len[185]);
    puts("----------------------------------");
    ft_printf("%%10s(NULL): hello, %-10s.: %d\n", NULL, len[186]);
    printf("%%10s(NULL): hello, %-10s.: %d\n", NULL, len[187]);
    puts("----------------------------------");
    ft_printf("%%3.s: %3.sa: %d\n", NULL, len[188]);
    printf("%%3.s: %3.sa: %d\n", NULL, len[189]);

    puts("***************   \"\"   *****************");
    puts("----------------------------------");
    test1 = printf("%-1.sa\n","");
    test2 = ft_printf("%-1.sa\n", "");
    printf("len [ %d : %d ] \n", test1, test2);
    puts("----------------------------------");
    test1 = printf("a%-3.1sa\n", "");
    test2 = ft_printf("a%-3.1sa\n", "");
    printf("len [ %d : %d ] \n", test1, test2);
    puts("***************   d   *****************");
    puts("----------------------------------");
    test1 = printf(".*.*%*d.*.*a\n",5,500);
    test2 = ft_printf(".*.*%*d.*.*a\n",5,500);
    printf("len [ %d : %d ] \n", test1, test2);
    puts("----------------------------------");
    test1 = printf("a%.*d..a\n",5,500);
    test2 = ft_printf("a%.*d..a\n",5,500);
    printf("len [ %d : %d ] \n", test1, test2);
    puts("----------------------------------");
    test1 = printf("%%-d 42 == %-d\n", INT_MIN);
    test2 = ft_printf("%%-d 42 == %-d\n", INT_MIN);
    printf("len [ %d : %d ] \n", test1, test2);
    puts("----------------------------------");
    test1 = printf("%07da\n", -54);
    test2 = ft_printf("%07da\n", -54);
    printf("len [ %d : %d ] \n", test1, test2);
    puts("***************   s   *****************");
    puts("----------------------------------");
    test1 = printf("%.*s\n",-3,NULL);
    test2 = ft_printf("%.*s\n",-3,NULL);
    printf("len [ %d : %d ] \n", test1, test2);
    puts("----------------------------------");
    test1 = printf("%-*.*sa\n", -7, -3, "yolo");
    test2 = ft_printf("%-*.*sa\n", -7, -3, "yolo");
    printf("len [ %d : %d ] \n", test1, test2);
    puts("----------------------------------");
    test1 = printf("%.*sa\n", -3, "hello");
    test2 = ft_printf("%.*sa\n", -3, "hello");
    printf("len [ %d : %d ] \n", test1, test2);
    puts("----------------------------------");
    test1 = printf("%-*sa\n", -10, "hello");
    test2 = ft_printf("%-*sa\n", -10, "hello");
    printf("len [ %d : %d ] \n", test1, test2);
    puts("----------------------------------");
    test1 = printf("%*sa\n", -32, "abc");
    test2 = ft_printf("%*sa\n", -32, "abc");
    printf("len [ %d : %d ] \n", test1, test2);
    puts("----------------------------------");
    test1 = printf("%s", "");
    test2 = ft_printf("%s","");
    printf("len [ %d : %d ] \n", test1, test2);
    puts("***************   i   *****************");
    puts("----------------------------------");
    test1 = printf("%*ia \n", -7, -54);
    test2 = ft_printf("%*ia \n", -7, -54);
    printf("len [ %d : %d ] \n", test1, test2);
    puts("----------------------------------");
    test1 = printf("|%-4i|\n", 42);
    test2 = ft_printf("|%-4i|\n", 42);
    printf("len [ %d : %d ] \n", test1, test2);
    puts("----------------------------------");
    test1 = printf("%0*ia\n", 7, -54);
    test2 = ft_printf("%0*ia\n", 7, -54);
    printf("len [ %d : %d ] \n", test1, test2);
    puts("----------------------------------");
    test1 = printf("%-5.ia\n", 0);
    test2 = ft_printf("%-5.ia\n", 0);
    printf("len [ %d : %d ] \n", test1, test2);
    puts("----------------------------------");
    test1 = printf("%.0ia\n", 0);
    test2 = ft_printf("%.0ia\n", 0);
    printf("len [ %d : %d ] \n", test1, test2);
    puts("------------------------------");
    test1 = printf("%08.3ia\n", -8473);
    test2 = ft_printf("%08.3ia\n", -8473);
    printf("len [ %d : %d ] \n", test1, test2);
    puts("***************   X   *****************");
    test1 = printf("%-5.Xa\n", 0);
    test2 = ft_printf("%-5.Xa\n", 0);
    printf("len [ %d : %d ] \n", test1, test2);
    puts("------------------------------");
    test1 = printf("%5.Xa\n", 0);
    test2 = ft_printf("%5.Xa\n", 0);
    printf("len [ %d : %d ] \n", test1, test2);
    puts("------------------------------");
    test1 = printf("%.Xa\n", 0);
    test2 = ft_printf("%.Xa\n", 0);
    printf("len [ %d : %d ] \n", test1, test2);
    puts("------------------------------");
    test1 = printf("%08.5Xa\n", 0);
    test2 = ft_printf("%08.5Xa\n", 0);
    printf("len [ %d : %d ] \n", test1, test2);
    puts("------------------------------");
    test1 = printf("%03Xa\n", 0);
    test2 = ft_printf("%03Xa\n", 0);
    printf("len [ %d : %d ] \n", test1, test2);
    puts("------------------------------");
    puts("***************   p   *****************");
    test1 = printf("%2.pa\n", NULL);
    test2 = ft_printf("%2.pa\n", NULL);
    printf("len [ %d : %d ] \n", test1, test2);
    puts("------------------------------");
    test1 = printf("%5.pa\n", NULL);
    test2 = ft_printf("%5.pa\n", NULL);
    printf("len [ %d : %d ] \n", test1, test2);
    puts("------------------------------");
	puts("***************   未定義処理   *****************");
    puts("------------------------------");
	test1 = printf("%.0p\n", 0);
    test2 = ft_printf("%.0p\n", 0);
    printf("len [ %d : %d ] \n", test1, test2);
    puts("------------------------------");
    test1 = printf("%5pa\n", 0);
    test2 = ft_printf("%5pa\n", 0);
    printf("len [ %d : %d ] \n", test1, test2);
    puts("------------------------------");
    test1 = printf("hi low\n\0don't print me lol\0");
    test2 = ft_printf("hi low\n\0don't print me lol\0");
    printf("len [ %d : %d ] \n", test1, test2);
    puts("------------------------------");
    test1 = printf("%0-3.3Xa\n", 6983);
    test2 = ft_printf("%0-3.3Xa\n", 6983);
    printf("len [ %d : %d ] \n", test1, test2);
    puts("------------------------------");
    test1 = printf("%0-8.5Xa\n", 0);
    test2 = ft_printf("%0-8.5Xa\n", 0);
    printf("len [ %d : %d ] \n", test1, test2);
    puts("------------------------------");
    test1 = printf("%010.7s\n", "123");
    test2 = ft_printf("%010.7s\n", "123");
    printf("len [ %d : %d ] \n", test1, test2);
    puts("------------------------------");
    test1 = printf("%010c\n", 'a');
    test2 = ft_printf("%010c\n", 'a');
    printf("len [ %d : %d ] \n", test1, test2);
	puts("------------------------------");
	test1 = printf("");
	test2 = ft_printf("");
	printf("%d: %d\n", test1, test2);
	puts("------------------------------");
	test1 = printf("aa: %-05:");
	test2 = ft_printf("aa: %-05:");
	printf("%d: %d\n", test1, test2);
	puts("------------------------------");
	test1 = printf("%0*ia\n", -7, -54);
	test2 = ft_printf("%0*ia\n", -7, -54);
	printf("%d: %d\n", test1, test2);
	puts("----------------------------------");
	test1 = printf("a%3.6sa\n", "");
	test2 = ft_printf("a%3.6sa\n", "");
	printf("%d: %d\n", test1, test2);
    puts("***************   追加   *****************");
    puts("----------------    1    ----------------");
    test1 = printf("");
    test2 = ft_printf("");
    printf("%d: %d\n", test1, test2);
    puts("----------------    2    ----------------");
    test1 = printf("%0*ia\n", -7, -54);
    test2 = ft_printf("%0*ia\n", -7, -54);
    printf("%d: %d\n", test1, test2);
    puts("----------------    3    ----------------");
    test1 = printf("ultimate2 %*d %*s %*x %*X %*i %*u\n", 1, 3, 1, "hey", 10, 3, 1, 2, 10, -2, 1, -3);
    test2 = ft_printf("ultimate2 %*d %*s %*x %*X %*i %*u\n", 1, 3, 1, "hey", 10, 3, 1, 2, 10, -2, 1, -3);
    printf("%d: %d\n", test1, test2);
    puts("----------------    4    ----------------");
    test1 = printf("{%05.*da}\n", 6, 42);
    test2 = ft_printf("{%05.*da}\n", 6, 42);
    printf("%d: %d\n", test1, test2);
    puts("----------------    5    ----------------");
    test1 = printf(".*.*%*d.*.*a\n",5,500);
    test2 = ft_printf(".*.*%*d.*.*a\n",5,500);
    printf("len [ %d : %d ] \n", test1, test2);
    puts("----------------    6    ----------------");
    test1 = printf("{%05.*da}\n", -15, 42);
    test2 = ft_printf("{%05.*da}\n", -15, 42);
    printf("len [ %d : %d ] \n", test1, test2);
    puts("----------------    7    ----------------");
    test1 = printf("neg2 %*.*da\n", -9, 4, 1555);
    test2 = ft_printf("neg2 %*.*da\n", -9, 4, 1555);
    printf("len [ %d : %d ] \n", test1, test2);
    puts("----------------    8    ----------------");
    test1 = printf("neg3 %*s\n", -9, NULL);
    test2 = ft_printf("neg3 %*s\n", -9, NULL);
    printf("len [ %d : %d ] \n", test1, test2);
    puts("----------------    9    ----------------");
    test1 = printf("-->|%-4.pa|<-- \n", NULL);
    test2 = ft_printf("-->|%-4.pa|<--\n", NULL);
    printf("len [ %d : %d ] \n", test1, test2);
    puts("----------------    10    ----------------");
    test1 = printf("%-4p\n", NULL);
    test2 = ft_printf("%-4p\n", NULL);
    printf("len [ %d : %d ] \n", test1, test2);
    puts("----------------    11    ----------------");
    test1 = printf("a%3.6sa\n", "\0");
    test2 = ft_printf("a%3.6sa\n", "\0");
    printf("[ %d: %d ]\n", test1, test2);
    puts("----------------    12    ----------------");
    test1 = printf("a%6.6sa\n", "");
    test2 = ft_printf("a%6.6sa\n", "");
    printf("[ %d: %d ]\n", test1, test2);
    puts("----------------    13    ----------------");
    test1 = printf("a%-3.1sa\n", "");
    test2 = ft_printf("a%-3.1sa\n", "");
    printf("len [ %d : %d ] \n", test1, test2);

//     puts("-----------       bonus       -------------------");
//      puts("*********************     nfge   *****************");
//    puts("------------------------------");
//	test1 = printf("aa: %n:", &a);
//	test2 = ft_printf("aa: %n:", &a);
//	printf("%d: %d\n", test1, test2);
//	puts("------------------------------");
//	test1 = printf("%10.5f\n", 6.213);
//	test2 = ft_printf("%10.5f\n", 6.213);
//	printf("%d: %d\n", test1, test2);
//	puts("----------------------------------");
//	test1 = printf("a%-30.20g\n", 100.2345);
//	test2 = ft_printf("a%-30.20g\n", 100.2345);
//	printf("%d: %d\n", test1, test2);
//    puts("----------------------------------");
//	test1 = printf("a%10.5e\n", 100.111111111111111);
//	test2 = ft_printf("a%10.5e\n", 100.111111111111111);
//	printf("%d: %d\n", test1, test2);
//     puts("*********************     l ll h hh   *****************");
//    puts("------------------------------");
//	test1 = printf("aa: %-50.25ld:\n", LONG_MAX);
//	test2 = ft_printf("aa: %-50.25ld:\n", LONG_MAX);
//	printf("%d: %d\n", test1, test2);
//	puts("------------------------------");
//	test1 = printf("%-50.25lld\n", LONG_LONG_MAX);
//	test2 = ft_printf("%-50.25lld\n", LONG_LONG_MAX);
//	printf("%d: %d\n", test1, test2);
//	puts("----------------------------------");
//	test1 = printf("a%-50.25hd\n", (short)32767);
//	test2 = ft_printf("a%-50.25hd\n", (short)32767);
//	printf("%d: %d\n", test1, test2);
//    puts("----------------------------------");
//	test1 = printf("a%.25hd\n", (short)127);
//	test2 = ft_printf("a%.25hd\n", (short)127);
//	printf("%d: %d\n", test1, test2);
//    puts("*********************     ＃+スペース   *****************");
//    puts("------------------------------");
//	test1 = printf("aa: %#50.25lx:\n", LONG_MAX);
//	test2 = ft_printf("aa: %#50.25lx:\n", LONG_MAX);
//	printf("%d: %d\n", test1, test2);
//    puts("------------------------------");
//	test1 = printf("aa: %#50.25lX:\n", LONG_MAX);
//	test2 = ft_printf("aa: %#50.25lX:\n", LONG_MAX);
//	printf("%d: %d\n", test1, test2);
//	puts("------------------------------");
//	test1 = printf("%+50.25lld\n", LONG_LONG_MAX);
//	test2 = ft_printf("%+50.25lld\n", LONG_LONG_MAX);
//	printf("%d: %d\n", test1, test2);
//    puts("------------------------------");
//	test1 = printf("%+*.25lld\n", 50, LONG_LONG_MAX);
//	test2 = ft_printf("%+*.25lld\n", 50, LONG_LONG_MAX);
//	printf("%d: %d\n", test1, test2);
//	puts("----------------------------------");
//	test1 = printf("a% d\n", -32767);
//	test2 = ft_printf("a% d\n", -32767);
//	printf("%d: %d\n", test1, test2);
//    puts("----------------------------------");
//	test1 = printf("a%-.0d\n", -0);
//	test2 = ft_printf("a%-.0d\n", -0);
//	printf("%d: %d\n", test1, test2);
//    puts("----------------------------------");
//	test1 = printf("a%-10c\n", 'a');
//	test2 = ft_printf("a%-10c\n", 'a');
//	printf("%d: %d\n", test1, test2);
}