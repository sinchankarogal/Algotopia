#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define MAX 42
#define INF INT_MAX/2
int visited[MAX];



int Edgematrix[42][42]= 
{

{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,1,1,0,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,0,0,1,1,1,0,1,0,0,0,0,0,0,0,0,1,0,0,0},
{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,1},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0}
};



/*
Distance matrix

Assumption - Assumes that there exists just one edge between any 2 vertices
if row and column indices are same entry is 0
if there exists path bw u and v ,then the distance bewteen the 2 is taken as entry
and there exists no path,then the entry of matrix is INF
and INF=INT_MAX/2

*/

int distMatrix[42][42] = {
    {0, INF, INF, INF, INF, INF, INF, INF, 5, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 9, 
    INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
    {INF, 0, INF, INF, INF, INF, INF, 3, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 
    INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
    {INF, INF, 0, 3, INF, 7, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 
    INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
    {INF, INF, 3, 0, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 
    INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
    {INF, INF, INF, INF, 0, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 5, INF, INF, INF, 
    INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
    {INF, INF, 7, INF, INF, 0, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 10, INF, INF, INF, INF, 
    INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
    {INF, INF, INF, INF, INF, INF, 0, 4, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 3, INF, 
    INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
    {INF, 3, INF, INF, INF, INF, 4, 0, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 
    INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
    {5, INF, INF, INF, INF, INF, INF, INF, 0, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 
    INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, INF, INF, INF, INF, INF, INF, INF, INF, 4, INF, INF, INF, 
    INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, 6, INF, INF, INF, INF, INF, INF, 3, INF, INF, INF, INF, 
    INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 6, 0, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 
    INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, INF, INF, INF, 6, INF, 11, INF, INF, INF, INF, 
    INF, INF, INF, INF, INF, INF, INF, INF, 10, INF, INF, INF, INF, INF, INF, INF, INF, INF, 3},
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, 5, INF, INF, INF, INF, INF, INF, INF, 
    INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 4},
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 5, 0, INF, INF, INF, INF, INF, INF, INF, 
    INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, INF, INF, INF, 5, INF, INF, 
    INF, INF, INF, INF, INF, INF, INF, 4, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 6, INF, INF, INF, 0, INF, INF, INF, INF, INF, 
    INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, INF, INF, 4, INF, 
    INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
    {INF, INF, INF, INF, 5, 10, INF, INF, INF, 4, 3, INF, 11, INF, INF, INF, INF, INF, 0, INF, INF, INF, INF, INF, 
    INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 13, INF, INF, INF},
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 5, INF, INF, INF, 0, INF, INF, 
    INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 7, INF, INF, INF},
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 4, INF, INF, 0, 5, 10, 
    INF, INF, 3, 9, 7, INF, 15, INF, INF, INF, INF, INF, INF, INF, INF, 6, INF, INF, INF},
    {INF, INF, INF, INF, INF, INF, 3, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 5, 0, INF, 
    INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
    {9, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 10, INF, 0, 
    INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 7, INF},
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 
    INF, 0, INF, 14, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 
    INF, INF, 0, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 5, INF, INF, INF, INF},
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 3, INF, 
    INF, 14, INF, 0, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 10, INF, 10, INF, INF},
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 9, INF, 
    INF, INF, INF, INF, 0, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 5, INF, INF},
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 7, INF, 
    INF, INF, INF, INF, INF, 0, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 
    INF, INF, INF, INF, INF, INF, 0, 6, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 4, INF, INF, INF, INF, 15, INF, 
    INF, INF, INF, INF, INF, INF, 6, 0, 5, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 
    INF, INF, INF, INF, INF, INF, INF, 5, 0, 7, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 10, INF, INF, INF, INF, INF, INF, INF, INF, INF, 
    INF, INF, INF, INF, INF, INF, INF, INF, 7, 0, 12, INF, INF, INF, 9, INF, INF, INF, INF, INF},
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 
    INF, INF, INF, INF, INF, INF, INF, INF, INF, 12, 0, 8, INF, 7, INF, INF, INF, INF, INF, 8},
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 
    INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 8, 0, 5, INF, 4, INF, INF, INF, INF, INF},
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 
    INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 5, 0, INF, INF, INF, INF, INF, INF, INF},
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 
    INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 7, INF, INF, 0, INF, INF, INF, INF, INF, INF},
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 
    INF, INF, INF, INF, INF, INF, INF, INF, INF, 9, INF, 4, INF, INF, 0, INF, INF, INF, INF, INF},
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 
    INF, INF, 5, 10, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, INF, 3, INF, INF},
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 13, 7, 6, INF, INF, 
    INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, INF, INF, INF},
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 
    INF, INF, INF, 10, 5, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 3, INF, 0, INF, INF},
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 
    7, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, INF},
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 3, 4, INF, INF, INF, INF, INF, INF, INF, INF, 
    INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 8, INF, INF, INF, INF, INF, INF, INF, INF, 0}};



// Define a node in the graph

typedef struct node
{
    char name[50];      
    // Name of the location

    int type;           
    // Type of the location (e.g. park, building, town),different numbers for different type

    int population;     
    // Population of the location

    int accessibility;  
    // Ease of access to the location 
    //0=not accessible, 1=easy access by foot, 2=easy access by cycle, 3=easy access by public transport, 4=easy access by car

    int sustainability; 
    // Eco-friendliness of the location
    //0=not eco-friendly, 1=partially eco-friendly, 2=mostly eco-friendly, 3=completely eco-friendly

} NODE;


// Define an edge in the graph

typedef struct edge
{
    int start;
    //the index of node from which edge starts

    int dest;
    //the index of node at which edge terminates

    int distance;            
    // Distance between the nodes in kms

    int transportation_type; 
    // Type of transportation available between the nodes 
    //(1=walking, 2=cycling, 3=public transport, 4=car)

} EDGE;



/***

Node numbers and the city mapped to it
1 : Ivy_Lane
2 : Quiet_Valley
3 : Louvre_Museum
4 : Hilltop_View
5 : Victoria_Coach_Station
6 : Rose_Garden
7 : City_Hall
8 : Golden_Hills
9 : Bright_Skyline
10 : Diamond_Cove
11 : Crystal_Creek
12 : Starry_Night
13 : Harvard_University
14 : Lakeside_Retreat
15 : Coastal_Bay
16 : St.Mary's_Hospital
17 : Oak_Hill
18 : Sunny_Plaza
19 : Main_Street
20 : Mayo_Clinic
21 : Central_Park
22 : NewYork_Police_Department
23 : University_of_Toronto
24 : Wild_Woods
25 : Royal_Museum
26 : Waterfront_View
27 : Green_Meadow
28 : London_King's_Cross_Station
29 : Grand_Avenue
30 : Bayfront_Park
31 : British_Museum
32 : Grand_Central_Station
33 : Stella_River
34 : Ocean_View
35 : Forest_Trail
36 : Blue_Harbor
37 : Hillside_Lane
38 : Pine_Forest
39 : Civic_Center
40 : Metropolitan_Police
41 : Maple_Grove
42 : Port_Authority_Bus_Terminal

**/

NODE nodes[MAX];     
//Global declaration



// intialize the edges
EDGE edges[48] =
    {
        //{start(node index) , to(node index) , dist(kms) , transportationType}
        {1, 9, 5, 3},
        {1, 23, 9, 3},
        {23, 41, 7, 2},
        {21, 23, 10, 3},
        {21, 22, 5, 4},
        {7, 22, 3, 4},
        {7, 8, 4, 3},
        {2, 8, 3, 2},
        {21, 26, 3, 2},
        {24, 26, 14, 4},
        {26, 38, 10, 2},
        {25, 38, 5, 2},
        {26, 40, 10, 3},
        {21, 27, 9, 3},
        {21, 28, 7, 2},
        {18, 21, 4, 2},
        {21, 39, 6, 4},
        {20, 39, 7, 4},
        {19, 39, 13, 3},
        {5, 19, 5, 3},
        {6, 19, 10, 4},
        {3, 6, 7, 4},
        {3, 4, 3, 2},
        {10, 19, 4, 2},
        {11, 19, 3, 1},
        {11, 12, 6, 4},
        {13, 19, 11, 3},
        {13, 17, 6, 2},
        {13, 42, 3, 1},
        {14, 42, 4, 2},
        {14, 15, 5, 2},
        {13, 32, 10, 3},
        {32, 33, 12, 3},
        {33, 34, 8, 4},
        {34, 35, 5, 1},
        {33, 36, 7, 2},
        {21, 30, 15, 4},
        {16, 30, 4, 3},
        {29, 30, 6, 4},
        {30, 31, 5, 3},
        {31, 32, 7, 3},
        {32, 37, 9, 3},
        {34, 37, 4, 2},
        {33, 42, 8, 4},
        {16, 20, 5, 3},
        {27, 40, 5, 4},
        {38, 40, 3, 4}
    
    };



/*
Function Name: load_weights(int a[42][42])

Input: a[][] - a 2D integer array representing the graph where a[i][j] represents the weight/distance of the edge between nodes i and j.

Output:
This function does not return any value. It modifies the 2D array a[][].

Task:
This function is used to initialize the 2D array a[][],which is the weight array
(in this case,the distance b/w 2 nodes is the weight).
It then updates the weights of the edges in the graph by iterating through the given set of edges and updating the corresponding entries in a[][].
*/


void load_weights(int a[][42])
{
    int k = 0;
    for (int i = 0; i < 42; i++)
    {
        for (int j = 0; j < 42; j++)
        {
            if (i == j)

            // assuming there are no self loops
            // initializing the diagonal entries to 0.
            {
                a[i][j] = 0;
            }

            
            // and initializing all others to infinity.Here infinity = INT_MAX/2
            else
            {
                a[i][j] = INT_MAX / 2;
            }
        }
    }

    while (k != 47)
    {
        a[(edges[k].start) - 1][(edges[k].dest) - 1] = edges[k].distance;
        a[(edges[k].dest) - 1][(edges[k].start) - 1] = edges[k].distance;
        k++;
    }
}




/** FUNCTIONALITIES **/



/**
Functionality 1:
Use DFS to traverse the graph.
Uses DFS to traverse all locations of the city
**/


/*
Function name: dfs_traversal()

Input: 
None explicitly defined within the function.
But, assumes the existence of a graph adjacency matrix loaded through the load_weights() function.

Output: Prints the DFS traversal order of the graph starting from node 1.

Task:
The function dfs_traversal() performs a depth-first search (DFS) traversal on a graph represented as an adjacency matrix.
It first loads the graph adjacency matrix using the load_weights() function and converts the weights to binary values of 0 or 1.
It initializes an array of visited nodes and sets all values to 0.
The DFS algorithm is then called by the function dfs(), starting from the source node 0 and printing the traversal order starting from node 1.
The function does not explicitly return anything, as the traversal order is printed as output.
*/


void dfs(int a[][42], int size, int source, int visited[])
{
    int i;
    visited[source] = 1;
    for (i = 0; i < size; i++)
    {
        if (a[source][i] == 1 && visited[i] == 0)
        {

            printf("%d\n", i + 1);
            dfs(a, size, i, visited);
        }
    }
}


void dfs_traversal()
{
    int a[42][42];
    int i;
    int j;
    int visited[41];
    int source = 0;
    int size = 42;
    load_weights(a);
    for (i = 0; i < 42; i++)
    {
        for (j = 0; j < 42; j++)
        {
            if (a[i][j] == INT_MAX / 2 || a[i][j] == 0)
            {
                a[i][j] = 0;
            }
            else
            {
                a[i][j] = 1;
            }
        }
    }

    for (i = 0; i < size; i++)
    {
        visited[i] = 0;
    }

    printf("the DFS traversal is:\n");
    printf("%d\n", 1);
    dfs(a, size, source, visited);
}




/***
Functionality 2: 
Find the shortest path from user given source to all other locations.
Uses Dijkstra's algorithm to find shortest path from single source to all other destinations.
**/


/*
Function i): next_source(int dist[],int v[],int size)

Input: 
dist[] - an integer array containing the distances from the source node to all other nodes.
v[] - an integer array containing the visited status of all nodes.
size - an integer indicating the size of the graph.

Output: The function returns an integer value which represents the index of the node which has the minimum distance among the unvisited nodes.

Task:
This function is used to find the node with the smallest distance from the source node, among the unvisited nodes in the graph.
It loops through all the nodes and checks if the node is unvisited and if its distance is less than the current minimum distance.
If it is, then the minimum distance and the corresponding node index is updated and returned.


Function ii): check_d(int m[],int size)

Input: 
m[] - an integer array containing the visited status of all nodes.
size - an integer indicating the size of the graph.

Output: The function returns an integer value.
0 - If all the nodes are visited.
1 - If there are unvisited nodes.

Task:
This function is used to check if all the nodes in the graph have been visited.
It loops through all the nodes and if any node is unvisited, it returns 1.
Otherwise, it returns 0.


Function iii): shortest_path

Input:
int source: the starting vertex for the path
int dest: the destination vertex for the path
int size: the total number of nodes in the graph
int path[size]: an array that stores the shortest path from the source vertex to each vertex in the graph

Output: Prints the shortest path from the source vertex to the destination vertex.

Task:
This function takes in the source and destination vertices, the total number of vertices in the graph,
and an array that stores the shortest path from the source vertex to each vertex in the graph.
It then uses this information to determine the shortest path from the source to the destination vertex and prints it out.
The function does this by traversing the path array from the destination vertex to the source vertex,
storing each vertex in a separate array, and then printing out the array in reverse order to display the shortest path.


Function iv): dijkstras()

Input: 
This function does not take any input. It uses the global array edges[] which contains the set of edges in the graph.

Output: This function does not return any value. It prints the shortest path from the source node to all other nodes in the graph along with their corresponding distances.

Task:
This function is the main function which implements Dijkstra's algorithm to find the shortest path from a given source node to all other nodes in the graph.
It first initializes the distance and visited status arrays, and then uses the next_source() function to find the node with the smallest distance.
It then updates the distances of all its neighboring nodes, if their distance can be reduced.
This process is repeated until all the nodes are visited.
Finally, it prints the shortest path from the source node to all other nodes in the graph along with their corresponding distances.
*/


int next_source(int dist[], int v[], int size)
{
    int min, j;
    min = INT_MAX / 2;
    for (int i = 0; i < size; i++)
    {
        if (v[i] != -1)
        {
            if (dist[i] < min)
            {
                min = dist[i];
                j = i;
            }
        }
    }

    return j;
}

int check_d(int m[], int size)
{
    int flag = 1;
    for (int i = 0; i < size; i++)
    {
        if (m[i] != -1)
        {
            flag = 0;
            break;
        }
    }

    if (flag == 1)
        return 0;
    
    else
        return 1;
}


void shortest_path(int source, int dest, int size, int path[])
{
    int b[size - 1];
    int k = 1;
    int i;
    b[0] = dest;
    i = dest;
    while (path[i] != source)
    {
        b[k] = path[i];
        i = path[i];
        k++;
    }

    b[k] = source;
    k++;

    printf("from %d to %d\n", source, dest);
    for (i = k - 1; i >= 0; i--)
    {
        printf("%d->", b[i]);
    }
}


void dijkstras()
{
    int u;
    int a[42][42] ;
    int k = 0;
    int v[42];
    int source;
    int size = 42;
    int dist[42];
    int path[42];

   
    // calling the function load_weights,this will initalize the 2-d matrix,ie the cost matrix
    load_weights(a);

    
    // taking user input,asking for source from where the shortest distance to all other locations is to be computed.

    printf("enter source :\n");
    scanf("%d", &source);

    int i;

    for (i = 0; i < size; i++)
    {
        path[i] = source;
        dist[i] = a[source][i];
        v[i] = i;
    }

    v[source] = -1;

    while (check_d(v, size))
    {
        u = next_source(dist, v, size);
        v[u] = -1;
        for (int i = 0; i < size; i++)
        {
            if (v[i] != -1)
            {
                if (dist[i] > (dist[u] + a[u][i]))
                {
                    dist[i] = dist[u] + a[u][i];
                    path[i] = u;
                }
            }
        }
    }

    
    printf("dist\tpath\n");
    for (i = 0; i < size; i++)
    {
        printf("%d\t%d\n", dist[i], path[i]);
    }
    for (i = 0; i < size; i++)
    {
        if (i != source)
        {
            shortest_path(source, i, size, path);
            printf("\ncost=%d\n\n", dist[i]);
        }
    }
}




/**
Functionality 3: 
Search whether the user given location is present in city or not
Returns 1 if the location is present and 0 otherwise
**/


/*
Function Name: Search

Inputs: 
char loc[]: a character array that represents the location to search for in the city

Output: Returns an integer 1 if the location is found in the city, and 0 otherwise.

Algorithm used : Linear Search

Task:
The Search function is designed to search for a given location in a city.
It does this by iterating through an array of nodes, each representing a location in the city. The function takes a character array as input, which represents the location to search for in the city.
It then loops through each node in the array, checking if the name of the node matches the location input using the strcmp() function.
If a match is found, the function prints a message to the console indicating that the location is present in the city and returns 1.
If no match is found, the function returns 0.
*/


int Search(char loc[])
{
    //Iterates through loop and finds whether the location entered by user is presnt in city or not

    for (int i = 0; i < MAX; i++)
    {
        if (strcmp(nodes[i].name, loc) == 0)
        {
            printf("%s is present in the city\n", loc);
            return 1;
        }
    }

    //returns 0 ,when city is not present
    return 0;
}





/**
Functionality 4 :
Create AVL tree and then apply inorder traversal.
Uses the concept of AVL tree to do the above task.
**/


/*
Function i): max

Input: 
Two character arrays (strings)

Output: An integer value indicating which of the two input strings is lexicographically greater,
with a return value of 1 indicating that the first string is greater,
2 indicating that the second string is greater, and 0 indicating that they are equal.

Task: The max function compares the two input strings character by character until it reaches the end of one of
the strings or finds a character that differs between the strings.
If the character in the first string is greater than the character in the second string, it returns 2, indicating
that the second string is lexicographically greater.
If the character in the second string is greater than the character in the first string, it returns 1, indicating
that the first string is lexicographically greater.
If it reaches the end of one of the strings without finding a differing character, it returns 0, indicating that the strings are equal.



Function ii): height_tree

Input: 
A pointer to a node in an AVL tree

Output: An integer value representing the height of the input node in the AVL tree

Task: The height_tree function takes a pointer to a node in an AVL tree as input and returns the height of that
node in the tree. If the input pointer is NULL, it returns 0.
Otherwise, it recursively calculates the height of the left and right subtrees of the input node and returns the
maximum of those two values plus 1, which represents the height of the input node.



Function iii):newnode

Input: 
A NODE structure containing the key of the new node to be created

Output: A pointer to a new struct tree node with the given key and NULL left and right pointers and height 1.

Task: The newnode function creates a new struct tree node with the given NODE key and initializes its left and
right child pointers to NULL and its height to 1.
It returns a pointer to the newly created node.



Function iv):maximum

Input: 
Two integer values a and b

Output: An integer value representing the maximum of the input values a and b

Task: The maximum function takes two integer values as input and returns the maximum of those values.
If a is greater than b, it returns a.
Otherwise, it returns b.



Function v):right_rotate

Input: 
A pointer to a node in an AVL tree that is the root of a left-heavy subtree

Output: A pointer to the new root of the subtree after a right rotation has been performed.

Task: The right_rotate function performs a right rotation on the input node, which is assumed to be the root of a
left-heavy subtree.
It first saves pointers to the left child of the input node (x) and the right child of that left child (y).
It then performs the right rotation by setting the input node's left child to y and the left child's right child
to the input node.
It then updates the heights of the input node and its left child and returns a pointer to the new root of the subtree, which is x.



Function vi):left_rotate

Input: 
A pointer to a node in an AVL tree that is the root of a right-heavy subtree

Output: A pointer to the new root of the subtree after a left rotation has been performed.

Task: This function performs a left rotation on the tree rooted at t and returns the new root of the subtree.
It updates the heights of the affected nodes.



Function vii): getbalance

Input: 
Pointer to a node T in the AVL tree.

Output: Integer representing the balance factor of the node T.

Task: Computes the balance factor of the node T,
by subtracting the height of the right subtree from the height of the left subtree.



Function viii): insert

Input: 
Pointer to the root node t of an AVL tree
and a NODE struct n to be inserted.

Output: Pointer to the new root of the AVL tree after the insertion operation.

Task: Inserts a new node with the data n into the AVL tree rooted at t and returns the new root of the AVL tree.
If the new node causes an imbalance in the tree, the necessary rotations are performed to restore the balance.



Function ix): inorder

Input: 
Pointer to the root node head of an AVL tree.

Output: None.

Task: Performs a inorder traversal of the AVL tree rooted at head.
and prints the name of each node in the tree.
The inorder traversal visits the left subtree, the root node and finally the right subtree.



Function x):avl

Input: None.

Output: None.

Task: Builds an AVL tree from an array of NODE structures called nodes.
It then performs a preorder traversal of the tree and prints the names of the nodes.
This function serves as the entry point for the AVL tree construction and traversal.
*/



// structure for node of AVL tree

struct tree
{
    struct node key;
    struct tree *left;
    struct tree *right;
    int height;
};


int max(char str1[], char str2[])
{
    int i;

    for (i = 0; i < strlen(str1) || strlen(str2); i++)
    {
        if (str1[i] > str2[i])
            return 2;

        else if (str1[i] < str2[i])
            return 1;
    }

    return 0;
}

int height_tree(struct tree *t)
{
    // function to compute the height of the tree

    if (t == NULL)
        return 0;

    return t->height;
}

struct tree *newnode(NODE t)
{
    // creates a newnode in AVL tree

    struct tree *temp = (struct tree *)malloc(sizeof(struct tree));

    temp->right = NULL;
    temp->left = NULL;
    temp->key = t;
    temp->height = 1;
    return temp;
}

int maximum(int a, int b)
{
    // to compute the max of 2 integers

    if (a > b)
        return a;

    return b;
}

struct tree *right_rotate(struct tree *t)
{
    // function to perform right rotation

    struct tree *x = t->left;
    struct tree *y = x->right;

    x->right = t;
    t->left = y;
    t->height = maximum(height_tree(t->left), height_tree(t->right)) + 1;
    x->height = maximum(height_tree(x->left), height_tree(x->right)) + 1;

    return x;
}

struct tree *left_rotate(struct tree *t)
{
    // function to perform left rotation

    struct tree *x = t->right;
    struct tree *y = x->left;

    x->left = t;
    t->right = y;
    t->height = maximum(height_tree(t->left), height_tree(y->right)) + 1;
    x->height = maximum(height_tree(x->left), height_tree(x->right)) + 1;

    return x;
}

int getbalance(struct tree *T)
{
    // function to compute the balance factor of each node

    // always the balance factor is either 0,1,2,-1,-2

    // if balance factor is not from above,then suitable rotations are performed and the tree is balanced.

    // Balance factor of AVL = height of left subtree - height of right subtree

    if (T == NULL)
        return 0;

    return height_tree(T->left) - height_tree(T->right);
}

struct tree *insert(struct tree *t, NODE n)
{
    // function to insert node in AVL tree

    // if tree is empty,the newnode itself becomes the root of the tree.
    if (t == NULL)
        return (newnode(n));

    if (max(n.name, t->key.name) == 1)
        t->left = insert(t->left, n);

    else if (max(n.name, t->key.name) == 2)
        t->right = insert(t->right, n);

    else
    {
        t->height = 1 + maximum(height_tree(t->left), height_tree(t->right));
        int balance = getbalance(t);

        if (balance > 1 && max(n.name, t->left->key.name) == 1)
            return right_rotate(t);

        if (balance < -1 && max(n.name, t->left->key.name) == 2)
            return left_rotate(t);
    }

    return t;
}

void inorder(struct tree *head)
{
    // function which computes inorder traversal of AVL tree

    // The inorder traversal of AVL tree will yield the locations of cities in alphabetical orderr.
    
    if (head != NULL)
    {
        inorder(head->left);
        printf("%s\n", head->key.name);
        inorder(head->right);
    }
}

void avl()
{
    // function which constructs the AVL tree

    struct tree *head = NULL;
    for (int i = 0; i < MAX; i++)
    {
        head = insert(head, nodes[i]);
    }

    printf("Printing the ciities which are sorted in alphabetical order : \n");
    inorder(head);

}




/**
Functionality 5: 
Find the shortest path b/w 2 locations.
Uses floyd's algorithm for the above purpose.
**/


/*
Function name: floyds

Input: None

Output: None

Task done: This function computes the shortest path between all pairs of locations in a weighted graph using the
Floyd algorithm.
It first loads the weights of the graph from a file into a 2D array.
Then, it iterates over all possible intermediate nodes in the graph and updates the distances between pairs of
nodes as necessary to find the shortest path between them.
Finally, it prompts the user to input the starting and ending locations and outputs the cost of the shortest path between them.
*/


void floyds()
{

    // using Floyd's algorithm to first compute the shortest path

    int a[42][42];
    int s, t;
    load_weights(a);
    for (int k = 0; k < 42; k++)
    {
        for (int i = 0; i < 42; i++)
        {
            for (int j = 0; j < 42; j++)
            {
                if (a[i][j] > (a[i][k] + a[k][j]))
                {
                    a[i][j] = (a[i][k] + a[k][j]);
                }
            }
        }
    }



    // taking user input to find the shortest distance b/w 2 locations
    printf("Locations and numbers mapped to it\n");
    printf("1 : Ivy_Lane\n");
    printf("2 : Quiet_Valley\n");
    printf("3 : Louvre_Museum\n");
    printf("4 : Hilltop_View\n");
    printf("5 : Victoria_Coach_Station\n");
    printf("6 : Rose_Garden\n");
    printf("7 : City_Hall\n");
    printf("8 : Golden_Hills\n");
    printf("9 : Bright_Skyline\n");
    printf("10 : Diamond_Cove\n");
    printf("11 : Crystal_Creek\n");
    printf("12 : Starry_Night\n");
    printf("13 : Harvard_University\n");
    printf("14 : Lakeside_Retreat\n");
    printf("15 : Coastal_Bay\n");
    printf("16 : St.Mary's_Hospital\n");
    printf("17 : Oak_Hill\n");
    printf("18 : Sunny_Plaza\n");
    printf("19 : Main_Street\n");
    printf("20 : Mayo_Clinic\n");
    printf("21 : Central_Park\n");
    printf("22 : NewYork_Police_Department\n");
    printf("23 : University_of_Toronto\n");
    printf("24 : Wild_Woods\n");
    printf("25 : Royal_Museum\n");
    printf("26 : Waterfront_View\n");
    printf("27 : Green_Meadow\n");
    printf("28 : London_King's_Cross_Station\n");
    printf("29 : Grand_Avenue\n");
    printf("30 : Bayfront_Park\n");
    printf("31 : British_Museum\n");
    printf("32 : Grand_Central_Station\n");
    printf("33 : Stella_River\n");
    printf("34 : Ocean_View\n");
    printf("35 : Forest_Trail\n");
    printf("36 : Blue_Harbor\n");
    printf("37 : Hillside_Lane\n");
    printf("38 : Pine_Forest\n");
    printf("39 : Civic_Center\n");
    printf("40 : Metropolitan_Police\n");
    printf("41 : Maple_Grove\n");
    printf("42 : Port_Authority_Bus_Terminal\n");


    printf("enter starting and ending location numbers:\n");
    scanf("%d%d", &s, &t);


    // printing the shortest distance b/w s and t
    printf("cost of shortest path from %d to %d is %d kilometres\n", s, t, a[s - 1][t - 1]);

}




/**
Functionality 6: 
Find the locations that are completely eco-friendly based on sustainability rating.
Location which are completely eco friendly have sustainability rating of 3.
**/


/*
Function name: displayEcofriendly

Input: There is no input parameter required for this function.

Output: This function displays a list of city names that have a sustainability score of 3, which means they are completely eco-friendly.

Task: This function is used to display a list of cities that are completely eco-friendly.
*/


void displayEcofriendly()
{

    printf("\nDisplaying the list of cities which are completely eco-friendlyy\n\n");
    for (int i = 0; i < MAX; i++)
    {
        if (nodes[i].sustainability == 3)
        {
            printf("%s\n", nodes[i].name);
        }
    }

}



/**
Functionality 7: Find the locations that are easily accesible by foot or cycle based on accesibilty rating.
If accessibilty rating is 1-easily accesible by walk and if 3 then they are easily accessible by cycle.
**/


/*
Function Name: displayFootCycle

Input: None

Output: None (displays output on the console)

Task: This function displays the locations that are easily accessible by foot or cycle.
It loops through the nodes array, which contains information about different locations, and checks the accessibility value of each location.
If the accessibility value is 1, it prints the location as easily accessible by walk.
If the accessibility value is 2, it prints the location as easily accessible by cycle.
This function does not return anything, but simply prints the output on the console.
*/


void displayFootCycle()
{
    
    printf("\n\nDisplaying the locations that are easily accesible by walk:\n\n");
    for (int i = 0; i < MAX; i++)
    {
        if (nodes[i].accessibility == 1)
        {
            printf("%s\n", nodes[i].name);
        }
    }


    printf("\nDisplaying locations that are easily accessible by a cycle\n\n");
    for (int i = 0; i < MAX; i++)
    {
        if (nodes[i].accessibility == 2)
        {
            printf("%s\n", nodes[i].name);
        }
    }
}




/**
Functionality 8:Find the most connected city.
Finds the city which has the maximum number of connections.
*/


/*
Function Name: most_connected

Input: None

Output: None
(prints the node index and the number of connections it has)

Task: The function loads the adjacency matrix representing the graph using the load_weights function, then it
loops through all the nodes in the graph and counts the number of connections each node has.
It keeps track of the node with the maximum number of connections and prints its index and the number of connections it has.
This function is useful to identify the most connected node in a graph, which can be important in various applications like network routing, social network analysis, etc.
*/


void most_connected()
{
    int a[42][42];
    // loads the adjacency matrix

    load_weights(a);
    int count = 0;
    int max = 0;
    int ind;
    for (int i = 0; i < 42; i++)
    {
        for (int j = 0; j < 42; j++)
        {
            // counting the number of connections ever node has

            if (a[i][j] != 0 && a[i][j] < INT_MAX / 2)
            {
                count++;
            }
        }

        // if the current node has connections greater than previous node,max is updated .
        if (count > max)
        {
            max = count;
            ind = i;
        }

        // setting count 0,for every node
        count = 0;
    }


    // printing the name of city and the numebr of connections it has
    printf("The most connected city is %s and has %d connections", nodes[ind], max);
}




/**
Functionality 9: 
Implementing efficient garbage collection and waste management.
This is done by using minimum spanning tree algorithms.
The 2 widely known MST algorithms are Prim's and Kruskal's algortihm.
In this case,Kruskal is used to implement the above thing.
**/


/*
Function i): selection_sort

Description: This function sorts an array of EDGE structures in ascending order based on their distance value using selection sort algorithm.

Input : None

Output: none
(Sorts the edges in ascending order)

Return: None.



Function ii): check

Description: This function checks if all elements in an integer array are equal.

Parameters:
b: the integer array to be checked.
n: the number of elements in the array.

Return:
1 if all elements are not equal.
0 if all elements are equal.



Function iii): find

Description: This function checks if two vertices are connected in a graph.

Parameters:
b: the integer array that represents the vertices of the graph.
n: the number of vertices in the graph.
u: the first vertex.
v: the second vertex.

Return:
0 if the two vertices are connected.
1 if the two vertices are not connected.



Function iv): union_k

Description:
This function connects two vertices in a graph by updating the values of the vertices in the integer array that represents the vertices of the graph.

Parameters:
b: the integer array that represents the vertices of the graph.
n: the number of vertices in the graph.
u: the first vertex to be connected.
v: the second vertex to be connected.

Return: None.
Function v): garbage_waste_management

Description: This function implements Kruskal's algorithm to find the minimum spanning tree of a graph.

Parameters: None.

Return: The total weight of the minimum spanning tree.
*/


void selection_sort()
{
    // using selection sort to sort the edges in increasing order

    int min;
    int i;
    int j;

    EDGE temp;

    for (i = 0; i < MAX - 1; i++)
    {
        min = i;
        for (j = i + 1; j < MAX; j++)
        {
            if (edges[j].distance < edges[min].distance)
            {
                min = j;
            }
        }

        temp = edges[i];
        edges[i] = edges[min];
        edges[min] = temp;
    }
}

int check(int b[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (b[i] != b[i + 1])
        {
            return 1;
        }
    }
    return 0;
}

int find(int b[], int n, int u, int v)
{
    if (b[u] == b[v])
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void union_k(int b[], int n, int u, int v)
{
    int temp;
    temp = b[u];
    for (int i = 0; i < n; i++)
    {
        if (b[i] == temp)
        {
            b[i] = b[v];
        }
    }
}

int garbage_waste_management()
{
    int i = 0;
    int k, j;
    int sum = 0;
    int b[42];

    for (i = 0; i < 42; i++)
    {
        b[i] = i;
    }

    i = 0;
    selection_sort();
    // sorts the edges

    while (check(b, 42))
    {
        k = find(b, 42, edges[i].start, edges[i].dest);
        if (k == 1)
        {
            printf("%d\t%d\n", edges[i].start, edges[i].dest);
            sum = sum + edges[i].distance;
            union_k(b, 42, edges[i].start, edges[i].dest);
        }
        i++;
    }

    return sum;
}




/**
Functionality 10: Find the most populous location in the city.
Finds the location which is most populated in the city.
**/


/*
Function Name: maxPopulationcity()

Input: None

Output: This function prints the name and population of the most populous city.

Task: The task of this function is to find the most populous city from an array of cities represented as nodes.
*/


void maxPopulationcity()
{

    //function which finds the location with max population

    NODE max;
    max.population = INT_MIN;
    for (int i = 0; i < MAX; i++)
    {
        if (nodes[i].population > max.population)
        {
            max = nodes[i];
        }
    }

    printf("The most populous city is %s and the population is %d\n", max.name, max.population);
}




/**
Functionality 11:
Find the minimum subset of roads that connect all buildings.
Uses MST algortithm for the above task.
Implemeted using Kruskal's algorithm.
**/


/*
Function i): int find1(int a[], int u, int v)

Description: This function takes an integer array a and two integer values u and v as input parameters.
It checks if the values of a at index u and v are the same or not.
If they are the same, it returns 1, otherwise, it returns 0.

Input: An integer array a, and two integer values u and v.

Output: Returns 1 if a[u] equals a[v], otherwise 0.



Function ii): void union1(int a[], int u, int v)

Description: This function takes an integer array a and two integer values u and v as input parameters.
It iterates over the array and replaces all the values that are equal to a[u] with a[v].

Input: An integer array a, and two integer values u and v.

Output: Returns void.



Function iii): void swap_edge(EDGE edge1, EDGE edge2)

Description: This function takes two EDGE structures edge1 and edge2 as input parameters.
It creates a temporary EDGE variable temp and swaps the values of edge1 and edge2.

Input: Two EDGE structures edge1 and edge2.

Output: Returns void.



Function iv): void bubble_sort()

Description: This function sorts an array of EDGE structures edges in ascending order of distance values using bubble sort algorithm.

Input: None.

Output: Returns void.



Function v): void connected_roads()

Description: This function sorts the array of EDGE structures edges using bubble sort algorithm by calling
bubble_sort() function.
It initializes an integer array a with values from 0 to MAX - 1.
Then it iterates over the edges array and checks if the values of a at the indices edges[k].start and edges[k].
dest are different or not by calling the find() function.
If they are different, it prints the values of edges[k].start and edges[k].dest, calls the union1() function with a
[edges[k].start] and a[edges[k].dest] as input parameters,
and updates the value of sum by adding edges[k].distance. Finally, it prints the value of sum.

Input: None.

Output: Returns void.
*/


int find1(int a[], int u, int v)
{
    if (a[u] == a[v])
        return 1;
    else
        return 0;
}

void union1(int a[], int u, int v)
{
    int i, temp = a[u];
    for (i = 0; i < MAX; i++)
    {
        if (a[i] == a[u])
        {
            a[i] = a[v];
        }
    }
}

void swap_edge(EDGE edge1, EDGE edge2)
{
    EDGE temp;
    temp = edge1;
    edge1 = edge2;
    edge2 = temp;
}

void bubble_sort()
{
    for (int i = 0; i < MAX - 1; i++)
    {
        for (int j = 0; j < MAX - i - 1; j++)
        {
            if (edges[i].distance > edges[j + 1].distance)
            {
                swap_edge(edges[i], edges[j + 1]);
            }
        }
    }
}

void connected_roads()
{
    bubble_sort();
    int sum = 0;
    int a[MAX];
    for (int i = 0; i < MAX; i++)
    {
        a[i] = i;
    }

    int k, r;

    for (k = 0; k < MAX; k++)
    {
        r = find1(a, edges[k].start, edges[k].dest);

        if (r == 0)
        {
            printf("%d\t%d\n", edges[k].start, edges[k].dest);
            union1(a, a[edges[k].start], a[edges[k].dest]);

            sum = sum + edges[k].distance;
        }
    }

    printf("%d\n", sum);
}




/**
Functionality 12:Find the connected locations of the city.
Uses DFS to find the locations which are connected.
**/


/*
Function name: connectedCity

Input: Two integers: n and i.
n represents the node to start the depth-first search from
and i represents the index of the current edge being examined.

Output: None (prints the names of the nodes visited which are connected)

Task: This function implements a depth-first search algorithm to traverse a graph represented by an array of nodes and an array of edges and finally prints the names of cities those are connected.

Alorithm used:Depth first search
*/


void connectedCity(int n, int i)
{
    if (i == 42)
    {
        return;
    }
    else if (edges[i].start == n)
    {
        printf("%s\n", nodes[edges[i].dest].name);
    }
    else if (edges[i].dest == n)
    {
        printf("%s\n", nodes[edges[i].start].name);
    }
    connectedCity(n, i + 1);
}




/**
Functinality 13: Location with least population and completely ecofriendly.
Finds the location in city which is completely ecofriendly and also has the least population.
**/

/*
Function Name: LeastPopMostEco

Input: None

Output: The function prints out the name of the city with the least population and is completely eco-friendly.

Task: This function searches through an array of NODE structures to find the city that has the least population and is completely eco-friendly.
*/


void LeastPopMostEco()
{
    //function which displays name of city with least population and which is completely eco friendly.

    NODE min;
    min.population = INT_MAX;
    for (int i = 0; i < MAX; i++)
    {
        if (nodes[i].population < min.population && nodes[i].sustainability == 3)
        {
            min = nodes[i];
        }
    }

    printf("The city having least population and is completely eco-friendly is %s\n", min.name);

}




/**
Functionality 14: Find all locations of particular type given by user.
**/


/*
Function Name: displayLoc

Inputs: locationType: an integer representing the type of location the user is searching for.

Outputs: None (the function simply displays the locations of the specified type)

Task:
The displayLoc function takes an integer input representing a type of location (e.g. residential area, park, hospital, etc.) and displays a message indicating the type of location being displayed.
It then loops through an array of location nodes and prints the names of all nodes whose type matches the specified locationType.

*/


void displayLoc(int locationType)
{

    //displays the locations of same type
    printf("Displaying  ");
    if (locationType == 0)
    {
        printf("Residential area");
    }
    else if (locationType == 1)
    {
        printf("Commercial area");
    }
    else if (locationType == 2)
    {
        printf("Park");
    }
    else if (locationType == 3)
    {
        printf("River/Lake");
    }
    else if (locationType == 4)
    {
        printf("Museum");
    }
    else if (locationType == 5)
    {
        printf("University/College");
    }
    else if (locationType == 6)
    {
        printf("Hospital");
    }
    else if (locationType == 7)
    {
        printf("Police station");
    }
    else if (locationType == 8)
    {
        printf("Fire station");
    }
    else if (locationType == 9)
    {
        printf("Train station");
    }
    else if (locationType == 10)
    {
        printf("Bus station");
    }
    printf("\n");


    for (int i = 0; i < MAX; i++)
    {
        if (nodes[i].type == locationType)
        {
            printf("%s\n", nodes[i].name);
        }
    }
}




/**
Functionality 15: Find all.locations that are accessible by car.
For plcaes accesible by car,the rating is 3.
**/


/*
Function Name: displayCar

Input: None

Output: None (displays output on the console)

Task: This function displays the locations that are easily accessible car
It loops through the nodes array, which contains information about different locations, and checks the accessibility value of each location.
If the accessibility value is 3, it prints the location as easily accessible by car
This function does not return anything, but simply prints the output on the console.
*/


void displayCar()
{
    //function to display locations which are accesible by car

    printf("\n\nDisplaying the locations that are easily accesible by car:\n\n");
    for (int i = 0; i < MAX; i++)
    {
        if (nodes[i].accessibility == 4)
        {
            printf("%s\n", nodes[i].name);
        }
    }

}




/**
Functionality 17: Help user to  see all the locations present in the city.
Prints the names of all locations that are present in Algotopia.
**/


/*
Function name: display

Input: none

Output : Prints locations and their respective populations.

*/


void display()
{

    //displays locations and their populations
    printf("Displaying locations and their polulations\n\n");
    for (int i = 0; i < MAX; i++)
    {
        printf("%s -  %d people\n", nodes[i].name, nodes[i].population);
    }
}




/**
Functionality 18: Print names of all police stations and fire station.
Prints all police and fire stations present in the city based on location type.
**/



/*
Function name: print_police_fire()

Input: None

Output: None (prints the names of all police stations and fire stations in the nodes array)

Task: This function iterates through the nodes array and prints the names of all police stations and fire stations that are present in the array.
For each node, the function checks whether its type property is equal to 7 (indicating a police station) or 8 (indicating a fire station).
If the type property matches either of these values, the function prints the name of the corresponding node. Finally, the function prints a separator and then prints the names of all fire stations present in the array using a similar loop.
The purpose of this function is to display a list of all the police and fire stations in the map data, which can be useful for planning emergency response routes.
*/


void print_police_fire()
{
    //prints the police and fire stations

    printf("Displaying police stations in the city : \n");
    for (int i = 0; i < MAX; i++)
    {
        if (nodes[i].type == 7)
        // if the location type is 7,then it is a police station.
        {
            printf("  %s\n", nodes[i].name);
        }
    }


    printf("\nDisplaying the fire stations in the city: \n");
    for (int i = 0; i < MAX; i++)
    {
        // if location type is 8,then it is fire station.
        if (nodes[i].type == 8)
        {
            printf("  %s\n", nodes[i].name);
        }
    }
}




/**
Functionality 19:Hash the names of city and display the hash value.
Hashes the name of the locations and then prints the hash value.
**/


/*
Function name: hashed()

Input: None

Output: Prints the hash value of each location name along with its name.

Task: The function hashes the names of cities and displays their corresponding hash value.
It takes no input but accesses the global array of nodes which contains the name of each city.
The function uses a simple hash function that calculates the sum of the ASCII values of the characters in each
city name and takes the modulo with 3 to obtain the hash value.
The calculated hash value is printed along with the city name in a formatted manner.
The function uses a loop to iterate through each node in the nodes array.
Inside the loop, another loop is used to calculate the hash value of the name of the city using the
above-mentioned hash function.
The hash value is then printed along with the name of the city.
After printing the hash value, the variables sum and j are reset to zero to calculate the hash value for the next city.

Overall, the function helps to demonstrate how hash values can be calculated for a given set of data,
and how these hash values can be used to efficiently store and retrieve the data.
*/


void hashed()
{
    int j = 0, sum = 0;
    printf("location name \t hash value\n");
    for (int i = 0; i < 42; i++)
    {
        while (nodes[i].name[j] != '\0')
        {
            sum = sum + nodes[i].name[j];
            j++;
        }
        printf("%s \t %d\n", nodes[i].name, sum % 3);
        j = 0;
        sum = 0;
    }
}




/***
Functionality 20: Find the university with lowest population.
Finds the univeristy whose location type is 5 which has the least population.
**/


/*
Function name: lowest_popu_university

Input: None

Output: None (prints the university with the lowest population)

Task: This function searches through an array of nodes (representing universities) and finds the university with the lowest population.
It does this by first initializing a minimum variable to a large number, and then iterating through the nodes array.
If the current node represents a university and has a lower population than the current minimum, then the minimum is updated to the node's population and the index of the node is saved.
Finally, the function prints the name and population of the university with the lowest population.
*/



void lowest_popu_unverisity()
{
    //prints the university with lowest population

    int min = INT_MAX;
    int j;

    for (int i = 0; i < MAX; i++)
    {
        if (nodes[i].type == 5 && nodes[i].population < min)
        {
            min = nodes[i].population;
            j = i;
        }
    }

    printf("University with lowest population is %s and has a population %d", nodes[j].name, min);

}




/**
Functionality 21: Sort the cities according to population.(in decreasing order).
Sorts the cities in decreasing order of their population.
**/


/*
Function i): void swap(NODE node1, NODE node2)

Input:
NODE node1: A node to be swapped with node2
NODE node2: A node to be swapped with node1

Output: None

Description: This function is used to swap two nodes of type NODE.



Function ii): int partition(int l, int r, NODE nodes[])

Input:
int l: The left index of the array
int r: The right index of the array
NODE nodes[]: An array of nodes to be sorted

Output: An integer representing the index of the pivot element after partitioning

Description: This function is used to partition an array of nodes around a pivot element.
It takes the left and right indices of the array, and the array itself as input, and returns the index of the
pivot element after partitioning the array. It uses the quicksort algorithm for partitioning.



Function iii): void quick_sort(int l, int r, NODE nodes[])

Input:
int l: The left index of the array
int r: The right index of the array
NODE nodes[]: An array of nodes to be sorted

Output: None

Description: This function is used to sort an array of nodes in ascending order according to their population.
It takes the left and right indices of the array, and the array itself as input, and sorts the array in place
using the quicksort algorithm.



Function iv): void display_sorted_population()

Input:None

Output: None

Description: This function is used to display the sorted population of nodes in the array.
It iterates over the nodes array and prints the population and name of each node in the array.




Function v): void sort_acc_population()

Input: None

Output: None

Description: This function is used to sort an array of nodes in ascending order according to their population.
It calls the quick_sort() function with the appropriate input parameters and sorts the nodes array in place.
*/


void swap(NODE node1, NODE node2)
{
    NODE temp;
    temp = node1;
    node1 = node2;
    node2 = node1;
}


int partition(int l, int r, NODE nodes[])
{
    int i = l;
    int j = r + 1;
    int p = nodes[l].population;

    do
    {
        do
        {
            i = i + 1;
        } while (nodes[i].population >= p);

        do
        {
            j = j - 1;
        } while (nodes[j].population <= p);

        swap(nodes[i], nodes[j]);

    } while (i >= j);

    swap(nodes[i], nodes[j]);
    swap(nodes[l], nodes[j]);

    return j;
}


void quick_sort(int l, int r, NODE nodes[])
{
    int s;
    if (l < r)
    {
        s = partition(l, r, nodes);
        quick_sort(l, s - 1, nodes);
        quick_sort(s + 1, r, nodes);
    }
}


void display_sorted_population()
{
    // function to display the population which is sorted in decreasing orderr

    for (int i = 0; i < MAX; i++)
    {
        printf("%d : %s\n", nodes[i].population, nodes[i].name);
    }
}


void sort_acc_population()
{
    // calling the quick_Sort function to first sort the locations in decreasing order of their population

    quick_sort(0, 41, nodes);

    // displaying population after sorting

    display_sorted_population();
}




/**
Functionality 22 : Create a bst using the names of locations and find inorder,preorder and postorder traversal.
Creates BST using location names and finds preorder,inorder and postorder traversal.
**/


/*
Function i): insert_into_city

Input parameters
A pointer to the root node of the city tree (CITY *root)
A character array representing the name of the city to be inserted into the tree (char data[])

Output:
A pointer to the root node of the updated city tree (CITY *)

Task:
The function inserts a new node with the given city name into the city tree.
It traverses the tree to find the appropriate position to insert the new node, comparing the value of the new node
with the value of the current node in the tree.
If the new node's value is less than or equal to the current node's value, the function goes left in the tree,
otherwise it goes right.
If the current node is NULL, the new node is inserted at that position.
Once the appropriate position is found, the function inserts the new node as a leaf node.
The function returns a pointer to the root node of the updated tree.



Function ii): inorder_CITY

Input parameters: A pointer to the root node of the city tree (CITY *root)

Output: None

Task: The function performs an inorder traversal of the city tree,
printing out the name of each city in ascending order.


Function iii): preorder_CITY

Input parameters: A pointer to the root node of the city tree (CITY *root)

Output: None

Task: The function performs an preorder traversal of the city tree,
printing out the name of each city in ascending order.


Function iv): postorder_CITY

Input parameters: A pointer to the root node of the city tree (CITY *root)

Output: None

Task: The function performs an postorder traversal of the city tree,
printing out the name of each city in ascending order.



Function v): CITY_bst_traversal

Input parameters: None

Output: None

Task: The function creates an empty city tree and inserts 42 cities into the tree using the insert_into_city function.
Then, it performs an inorder traversal of the tree using the inorder_CITY function,
printing out the names of the cities in ascending order.
*/


struct city
{
    char val[20];
    struct city *left;
    struct city *right;
};

typedef struct city CITY;


CITY *insert_into_city(CITY *root, char data[])
{
    CITY *newnode;
    CITY *currnode;
    CITY *parent;

    newnode = (CITY *)malloc(sizeof(CITY));

    // checking if newnode is created or not
    if (newnode == 0)
    {
        printf("Memory allocation failed\n");
        return root;
    }

    // intializing the newly created node

    strcpy(newnode->val, data);
    newnode->left = NULL;
    newnode->right = NULL;

    // if root is empty ,the newnode becomes the root of the tree

    if (root == NULL)
    {
        root = newnode;
        return root;
    }

    // otherwise,finding a right place and then inserting into BST

    currnode = root;
    parent = NULL;
    while (currnode != NULL)
    {
        parent = currnode;

        if (strcmp(newnode->val, currnode->val) <= 0)
            currnode = currnode->left;

        else
            currnode = currnode->right;
    }

    if (strcmp(newnode->val, parent->val) <= 0)
    {
        parent->left = newnode;
    }

    else
    {

        parent->right = newnode;
    }

    return root;
}


void inorder_CITY(CITY *root)
{

    // performs inorder traversal of the city

    // inorder traversal of BST leads names of locations in lexicographical order

    if (root != NULL)
    {
        inorder_CITY(root->left);
        printf("%s\n", root->val);
        inorder_CITY(root->right);
    }
}


void preorder_CITY(CITY *root)
{

    // performs preorder traversal of the city

    if (root != NULL)
    {
        printf("%s\n", root->val);
        preorder_CITY(root->left);
        preorder_CITY(root->right);
    }
}


void postorder_CITY(CITY *root)
{

    // performs postorder traversal of the city

    if (root != NULL)
    {
        postorder_CITY(root->left);
        postorder_CITY(root->right);
        printf("%s\n", root->val);
    }
}


void CITY_bst_traversal()
{
    CITY *roott = NULL;
    int i;
    for (i = 0; i < 42; i++)
    {
        roott = insert_into_city(roott, nodes[i].name);
    }

    // printing the preorder traversal
    printf("Printing the preorder traversal : \n");
    preorder_CITY(roott);

    // printing the postorder traversal
    printf("Printing the postorder traversal : \n");
    postorder_CITY(roott);

    // printing the inorder traversal
    printf("Printing the inorder traversal : \n");
    inorder_CITY(roott);
}





/**
Functionality 23:Detect whether any cycle is present in the city
Detects whether cycle is present in Algotopia.
Uses the DFS algorithm to detect,if cycle is present.
**/


/*
Function Name: check_cycle

Input: No input parameter

Output: Prints "cycle exists in the graph" if any cycle is present in the city graph.
Otherwise, it does not produce any output.

Description:
The check_cycle() function uses the Union-Find algorithm to detect if there is any cycle in the city graph.
It first initializes an array b[] with indices from 0 to 41.
Then, it sorts the edges in decreasing order of their weights using the selection_sort() function.
The function then iterates through the sorted edges and checks if the start and end vertices of the edge are already connected or not using the find() function.
If they are not connected, it merges the two vertices using the union_k() function.
If the vertices are already connected, then it means that adding the current edge will create a cycle in the
graph, and the function prints "cycle exists in the graph" and exits the loop.
If the loop completes without printing anything, it means that there is no cycle in the graph.
*/


void check_cycle()
{

    int i = 0;
    int k, j;
    int sum = 0;
    int b[42];

    for (i = 0; i < 42; i++)
    {
        b[i] = i;
    }

    i = 0;

    selection_sort();

    while (check(b, 42))
    {
        k = find(b, 42, edges[i].start, edges[i].dest);

        if (k == 1)
        {
            union_k(b, 42, edges[i].start, edges[i].dest);
        }

        else
        {
            printf("cycle exists in the graph\n");
            break;
        }

        i++;
    }
}




/***
Functinality 24: Sort the edges according to the distances.
Sorts the edges based on distance bewteen the 2 nodes.
**/


/*
Function name: display_sorted_edge

Input: None

Output: None (prints the sorted edges in the edges array)

Task: This function iterates through the edges array and prints the start and destination nodes of each edge along with its distance.
This function is primarily used to display the sorted edges in the edges array after they have been sorted using the insertion_sort() function.



Function name: insertion_sort()

Input: None

Output: None (sorts the edges array by their distance property)

Task: This function implements an insertion sort algorithm to sort the edges array by their distance property.
It iterates through each element of the edges array, and inserts it into the correct position in a sorted subarray of elements that have already been examined.
The j variable keeps track of the index of the last element in the sorted subarray, and the v variable stores the value of the current element being examined.
The while loop checks whether the current element should be inserted before the last element in the sorted subarray, and shifts the elements in the subarray accordingly.
Finally, the function calls the display_sorted_edge() function to print the sorted edges.

Algorithm used: Insertion Sort
*/

void insertion_sort()
{
    int j;
    int v;
    EDGE e;

    for (int i = 1; i < MAX; i++)
    {
        e = edges[i];
        v = edges[i].distance;
        j = i - 1;
        while (j >= 0 && edges[j].distance > v)
        {
            edges[j + 1] = edges[j];
            j = j - 1;
        }
        edges[j + 1] = e;
    }

}


void display_sorted_edge()
{
    //first sorts the edge using insertion sort
    //the  displays them


    insertion_sort();

    for (int i = 0; i < MAX; i++)
    {
        printf("%d -> %d : %d\n", edges[i].start, edges[i].dest, edges[i].distance);
    }

}




/**
Functionality 25 : Use BFS traversal for the city.
Prints the location numbers using BFS.
**/


/*
Function Name: bfs_traversal

Input:
a: 2D integer array representing an adjacency matrix of a graph
size: an integer representing the number of vertices in the graph
source: an integer representing the vertex from which the breadth-first search (BFS) should start

Output: This function does not return anything. 
It prints the BFS traversal of the graph starting from the source vertex.

Function Description: 
This function performs the breadth-first search (BFS) algorithm on a given graph represented by an adjacency 
matrix. 
The BFS algorithm starts from a given source vertex and visits all the vertices in the graph in breadth-first 
order. 
The function uses a queue data structure to keep track of the vertices to be visited next.

The function first initializes a queue data structure and enqueues the source vertex into it. 
It also initializes a visited array to keep track of the visited vertices. 
The source vertex is marked as visited in the visited array.

The function then enters a while loop that runs until the queue becomes empty. 
In each iteration of the loop, the function dequeues a vertex from the queue and prints it. 
It then checks all the adjacent vertices of the dequeued vertex and enqueues them into the queue if they have not been visited before.
The adjacent vertices are marked as visited in the visited array.

The function continues this process until all the vertices in the graph have been visited.
The final output of the function is the BFS traversal of the graph starting from the source vertex.
*/


void bfs_traversal(int a[42][42],int size,int source)
{
    int queue[42];
    int front=0;
    int rear=0;
    int u;

    queue[rear]=source;
    visited[source]=1;

    printf("BFS traversal is:\n");
    while(front<=rear)
    {
        u=queue[front];
        printf("%d\t",u+1);
        front++;

        for(int i=0;i<size;i++)
        {
            if(a[u][i]==1 && visited[i]==0)
            {
                visited[i]=1;
                rear++;
                queue[rear]=i;
            }
        }
    }
}





/**
Functionality 26:
Apply Warshall algorithm to find the transitive closure
Applies Warshall algorithm and then yields the result.
**/

/*
Function Name: Warshall Algorithm

Inputs:
A square matrix R of size n x n, representing a directed graph where R[i][j] is 1 if there is an edge from vertex 
i to vertex j, and 0 otherwise, and n is the number of nodes.

Outputs:
A modified matrix R where R[i][j] is 1 if there exists a path from vertex i to vertex j in the input graph, and 0 
otherwise.

Task:
The algorithm computes the transitive closure of a directed graph using dynamic programming. 
It iterates over all possible vertices k and computes whether there is a path from vertex i to vertex j through 
vertex k, and updates the matrix accordingly. 
The resulting matrix R is the transitive closure of the input graph, i.e.,
it contains all pairs of vertices (i, j) for which there exists a path from i to j in the input graph.
*/


void Warshall()
{
    int R[42][42] =
        {

            {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    int n = 42;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (R[i][k] == 1 && R[k][j] == 1)
                {
                    R[i][j] = 1;
                }
            }
        }
    }


    //print the resultant matrix
    for(int i=0;i<42;i++)
    {
        for(int j=0;j<42;j++)
        {
            printf("%d ",R[i][j]);
        }
        printf("\n");
    }
}



/**
Functionality 27:
Sort the locations in lexicographical order.
Algorithm used:Bubble Sort
Prints the locations names in alphabetical order.
**/



/*
Function name: Sort_locations

Input: None

Output: 
None (prints sorted list to console)

Task: This function sorts an array of NODE structures, which contain information about locations, alphabetically by the name of the 
location, using the bubble sort algorithm. 
The function loops through the array using nested loops, comparing adjacent elements and swapping them if they are in the wrong order. 
The outer loop iterates MAX-1 times, where MAX is a constant that represents the maximum number of elements in the array, and the inner 
loop iterates from 0 to MAX-i-1, 
where i is the current iteration of the outer loop. 
This ensures that the largest element "bubbles" to the end of the array in each iteration.
The function then prints the sorted list of locations to the console.

Algorithm:Bubble sort
*/


void Sort_locations() 
{
    NODE temp;
    for (int i = 0; i < MAX-1; i++) 
    {
        for (int j = 0; j < MAX-i-1; j++) 
        {
            if (strcmp(nodes[j].name, nodes[j+1].name) > 0) 
            {
               temp=nodes[j];
               nodes[j]=nodes[j+1];
               nodes[j+1]=temp;
            }
        }
    }

    // displaying in alphabetical order
    printf("Displaying the locations in alphabetical order\n");

    for(int i=0;i<MAX;i++)
    {
        printf("%s\n",nodes[i].name);
    }
}


int main()
{
    // FILE pointer
    FILE *fp;


    // opening the file nodes.txt in read mode
    fp = fopen("nodes.txt", "r");


    if (fp == NULL)
    // when there is no such file called nodes.txt
    {
        printf("Errror in opening file\n");
        // return with exit status of -1.
        exit(-1);
    }


    // Otherwise,reading data from file and then initializing the nodes

    for (int i = 0; i < MAX; i++)
    {
        fscanf(fp, "%s %d %d %d %d", nodes[i].name, &nodes[i].type, &nodes[i].population, &nodes[i].accessibility, &nodes[i].sustainability);

        // printf("%s %d %d %d %d\n", nodes[i].name, nodes[i].type, nodes[i].population, nodes[i].accessibility, nodes[i].sustainability);
    }

    fclose(fp);


    int choice;
    while (1)
    {
        // Giving options to user
        printf("\n\n **** Welcome to Algotopia - where technology shapes the future **** \n\n");


        printf("1. Traverse the city graph using DFS/BFS\n");

        printf("2. Find the shortest path using Dijkstra's algorithm\n");

        printf("3. Search for a location in the city\n");

        printf("4. Create AVL tree and print inorder traversal\n");

        printf("5. Find the shortest path between two locations\n");

        printf("6. Find eco-friendly locations based on sustainability rating\n");

        printf("7. Find locations accessible by cycle/foot based on accessibility rating\n");

        printf("8. Find the most connected location/central location\n");

        printf("9. Implement efficient garbage collection and waste management using MST algorithm\n");

        printf("10. Find the most populous city\n");

        printf("11. Find the minimum subset of roads that connect all buildings using Prims/Kruskal algorithm\n");

        printf("12. Find the connected locations of the city using DFS\n");

        printf("13. Find the least populous and completely eco-friendly city\n");

        printf("14. Find all the locations of a particular type\n");

        printf("15. Find all the locations accessible by car\n");

        printf("16. View the entire city map\n");

        printf("17. See the names of all locations in the city\n");

        printf("18. See the names of all police stations and fire stations in the city\n");

        printf("19. Hash the names of cities and display the hash value\n");
        
        printf("20. Display the university with the least population\n");
        
        printf("21. Sort the cities according to population (in decreasing order)\n");
        
        printf("22. Create a BST using the names of locations and find the inorder traversal\n");
        
        printf("23. Detect whether any cycle is present in the city\n");
        
        printf("24. Sort the edges according to distances\n");
        
        printf("25.BFS traversal of the city\n");
        
        printf("26.Apply Warshall's Algorithm to find the transitive closure\n");
        
        printf("27.Sort the location names in lexicographical order\n");
        
        printf("28.Exit\n");

        printf("Enter your choice (1-24):\n");
        scanf("%d", &choice);



        switch (choice)
        {
        case 1:
            printf("Performs DFS traversal on the graph \n");
            dfs_traversal();
            break;



        case 2:
            printf("Finds shortest path from single source to all other locations\n");
            dijkstras();
            break;



        case 3:
            printf("Searchs whether location entered by user is presnt in city or not\n");
            char loc[50];
            printf("Enter location to search whether it is present in city or not\n");
            scanf("%s", loc);

            int res = Search(loc);
            if (res == 0)
            {
                printf("%s is not present in Algotopia\n");
            }
            break;



        case 4:
            printf("Creates AVL tree and then prints the inorder traversal\n");
            avl();
            break;



        case 5:
            printf("Finds the shortest distance/path between 2 locations given by user\n");
            floyds();
            break;



        case 6:
            printf("Displays the names of locations that are completely eco friendly\n");
            displayEcofriendly();
            break;



        case 7:
            printf("Finds the locations that are accessible by walk or by cycle\n");
            displayFootCycle();
            break;



        case 8:
            printf("Finds the central/most connected location in the city\n");
            most_connected();
            break;



        case 9:
            printf("Implements efficient garbage collection and waste management\n");
            int num = garbage_waste_management();
            printf("Distance to be travelled everyday,to visit all locations and collect garbage is %d\n", num);
            break;



        case 10:
            printf("Finds the location with highest population\n");
            maxPopulationcity();
            break;



        case 11:
            printf("Finds the minimum distance required to travel all the locations in the city\n");
            connected_roads();
            break;



        case 12:
            printf("Finds the location which are connected in the city\n");
            connectedCity(0, 0);
            break;



        case 13:
            printf("Prints the name of city with least population and completely eco-friendly\n");
            LeastPopMostEco();
            break;



        case 14:
            printf("Prints all the locations of particular type given by the user\n");
            int locationType;

            printf("Enter what type of locations are to be displayed\n");
            printf("0: Residential area\n");
            printf("1: Commercial area\n");
            printf("2: Park\n");
            printf("3: River/Lake\n");
            printf("4: Museum\n");
            printf("5: University/College\n");
            printf("6: Hospital\n");
            printf("7: Police station\n");
            printf("8: Fire station\n");
            printf("9: Train station\n");
            printf("10: Bus station\n");
            scanf("%d", &locationType);

            if (locationType < 0 || locationType > 10)
            {
                printf("Invalid location type\n");
                exit(0);
            }

            displayLoc(locationType);
            break;



            case 15:
            printf("Prints the locations which are accessible by car\n");
            displayCar();
            break;



            case 16:
            printf("Prints the locations and edges present in the graph\n");

            //prints the names of locations
            printf("Prints the locations present in the city\n");
            for(int i=0;i<MAX;i++)
            {
                printf("%s\n",nodes[i].name);
            }


            //prints the edges present in the city
            printf("Prints the edges present in the city\n");
            for(int i=0;i<47;i++)
            {
                //prints the edges present in the city
                //printf("%d --> %d\n",edges[i].start,edges[i].dest);
                printf("%s --> %s\n",nodes[edges[i].start],nodes[edges[i].dest]);
            }
            break;



            case 17:
            printf("Displays all locations present in Algotopia\n");
            display();
            break;



            case 18:
            printf("Prints names of all police and fire stations\n");
            print_police_fire();
            break;



            case 19:
            printf("Hashes the location names and prints the has values of the location\n");
            hashed();
            break;



            case 20:
            printf("Displays the University name with least population\n");
            lowest_popu_unverisity();
            break;



            case 21:
            printf("Sorts the cities according to population in decreasing order\n");
            sort_acc_population();
            break;

            

            case 22:
            printf("Creates BST using location names and prints preorder,inorder and postorder traversals\n");
            CITY_bst_traversal();
            break;



            case 23:
            printf("Detect if cycle is present in the city or not\n");
            check_cycle();
            break;



            case 24:
            printf("Sorts the edges according to the distances present on them\n");
            display_sorted_edge();
            break;



            case 25:
            printf("BFS traversal of the graph\n");
            int source;
            printf("enter the source from where BFS traversal is to be done:\n");
            scanf("%d",&source);
            bfs_traversal(Edgematrix,MAX,source);
            break;



            case 26:
            printf("Finds the transitive closure\n");
            Warshall();
            break;

             

             case 27:
             printf("Sort the locations in lexicographical order\n");
             Sort_locations();
             break;



            case 28:
            printf("Program terminated\n");
            exit(0);
            break;
            


            default:
            printf("enter valid choice\n");
            break;

            
        }

    }

    return 0;


}
