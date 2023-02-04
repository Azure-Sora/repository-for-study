#include<stdio.h>
/*
3、将1, 2,…，9共9个数分成三组，分别组成三个三位数，且使这三个三位数构成1: 2: 3的比例，试求出所有满足条件的三个三位数。
例如：三个三位数 192, 384, 576满足以上条件
*/
int main()
{
	for (int a = 1; a <= 9; a++)//1
	{
		for (int b =1; b <= 9 ; b++)//2
		{
			if (b != a)
			{
				for (int c =1; c <= 9; c++)//3
				{
					if (c != b && c != a)
					{
						for (int d = 1; d <= 9; d++)//4
						{
							if (d != a && d != b && d != c)
							{
								for (int e = 1; e <= 9; e++)//5
								{
									if (e != a && e != b && e != c && e != d)
									{
										for (int f = 1; f <= 9; f++)//6
										{
											if (f != a && f != b && f != c && f != d && f != e)
											{
												for (int g = 1; g <= 9; g++)//7
												{
													if (g != a && g != b && g != c && g != d && g != e && g != f)
													{
														for (int h = 1; h <= 9; h++)//8
														{
															if (h != a && h != b && h != c && h != d && h != e && h != f && h != g)
															{
																for (int i = 1; i <= 9; i++)//9
																{
																	if (i != a && i != b && i != c && i != d && i != e && i != f && i != g && i != h)
																	{
																		if ((a * 100 + b * 10 + c) * 2 == (d * 100 + e * 10 + f) && (a * 100 + b * 10 + c) * 3 == (g * 100 + h * 10 + i))
																		{
																			printf("%d%d%d，%d%d%d，%d%d%d\n", a, b, c, d, e, f, g, h, i);
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	printf("\n黄天予 2022141461050");
	return 0;
}