/**************************************************************
** 作   者:  xcc
** 创建时间:  2020-05-07
** 描   述:  Boyer-Moore 算法源码
**************************************************************/

void preBmBc(char *x, int m, int bmBc[]);

void suffixes(char *x, int m, int *suff);

void preBmGs(char *x, int m, int bmGs[]);

void BM(char *x, int m, char *y, int n);
