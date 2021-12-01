#include "boolean.h"
#include "matrix.h"
#include <stdio.h>

void CreateMatrix(int nRow, int nCol, Matrix *m){
    ROWS(*m)=nRow;
    COLS(*m)=nCol;
}

boolean isIdxValid(int i, int j){
    return i>=0 && i<ROW_CAP && j>=0 && j<COL_CAP;
}

Index getLastIdxRow(Matrix m){
    return ROWS(m)-1;
}

Index getLastIdxCol(Matrix m){
    return COLS(m)-1;
}

boolean isIdxEff(Matrix m, Index i, Index j){
    return i>=0 && i<ROWS(m) && j>=0 && j<COLS(m);
}

ElType getElmtDiagonal(Matrix m, Index i){
    return ELMT(m,i,i);
}

void copyMatrix(Matrix mIn, Matrix *mRes){
    CreateMatrix(ROWS(mIn), COLS(mIn), mRes);
    int i, j;
    for (i=0;i<ROWS(mIn);i++) {
        for (j=0;j<COLS(mIn);j++) {
            ELMT(*mRes,i,j)=ELMT(mIn,i,j);
        }
    }
}

void readMatrix(Matrix *m, int nRow, int nCol){
    CreateMatrix(nRow, nCol, m);
    int i, j;
    for(i=0;i<nRow;i++){
        for (j=0;j<nCol;j++) {
            scanf("%d", &ELMT(*m, i, j));
        }
    }
}

void displayMatrix(Matrix m){
    int i, j;
    for(i=0;i<ROWS(m);i++){
        for (j=0;j<COLS(m);j++) {
            printf("%d ", ELMT(m,i,j));
        }
        if(i!=ROWS(m)-1) printf("\n");
    }
}

Matrix addMatrix(Matrix m1, Matrix m2){
    Matrix m;int i, j;
    CreateMatrix(ROWS(m1), COLS(m1), &m);
    for(i=0;i<ROWS(m1);i++){
        for (j=0;j<COLS(m2);j++) {
            ELMT(m,i,j)=ELMT(m1,i,j)+ELMT(m2,i,j);
        }
    }
    return m;
}

Matrix subtractMatrix(Matrix m1, Matrix m2){
    Matrix m;int i, j;
    CreateMatrix(ROWS(m1), COLS(m1), &m);
    for(i=0;i<ROWS(m1);i++){
        for (j=0;j<COLS(m2);j++) {
            ELMT(m,i,j)=ELMT(m1,i,j)-ELMT(m2,i,j);
        }
    }
    return m;
}

Matrix multiplyMatrix(Matrix m1, Matrix m2){
    Matrix m;int i, j;
    CreateMatrix(ROWS(m1), COLS(m1), &m);
    for(i=0;i<ROWS(m1);i++){
        for (j=0;j<COLS(m2);j++) {
            ELMT(m,i,j)=ELMT(m1,i,j)*ELMT(m2,i,j);
        }
    }
    return m;
}

Matrix multiplyConst(Matrix m, ElType x){
    int i, j; Matrix mm;
    CreateMatrix(ROWS(m), COLS(m), &mm);
    for(i=0;i<ROWS(m);i++){
        for (j=0;j<COLS(m);j++) {
            ELMT(mm,i,j)=x*ELMT(m,i,j);
        }
    }
    return mm;
}

void pMultiplyConst(Matrix *m, ElType k){
    *m = multiplyConst(*m, k);
}

boolean isEqual(Matrix m1, Matrix m2){
    if(ROWS(m1)!=ROWS(m2)) return false;
    if(COLS(m1)!=COLS(m2)) return false;
    int i, j;
    for(i=0;i<ROWS(m1);i++){
        for(j=0;j<COLS(m1);j++){
            if(ELMT(m1, i, j)!=ELMT(m2, i, j)) return false;
        }
    }
    return true;
}

boolean isNotEqual(Matrix m1, Matrix m2){
    return !isEqual(m1, m2);
}

boolean isSizeEqual(Matrix m1, Matrix m2){
    return ROWS(m1)==ROWS(m2) && COLS(m1)==COLS(m2);
}

int count(Matrix m){
    return ROWS(m)*COLS(m);
}
boolean isSquare(Matrix m){
    return ROWS(m)==COLS(m);
}

boolean isSymmetric(Matrix m){
    if(!isSquare(m)) return false;
    int i, j;
    for(i=0;i<ROWS(m);i++){
        for(j=0;j<COLS(m);j++){
            if(ELMT(m, i, j)!=ELMT(m, j, i)) return false;
        }
    }
    return true;
}

boolean isIdentity(Matrix m){
    if(!isSquare(m)) return false;
    int i, j;
    for(i=0;i<ROWS(m);i++){
        for(j=0;j<COLS(m);j++){
            if(i==j && ELMT(m, i, j)!=1) return false;
            if(i!=j && ELMT(m, i, j)!=0) return false;
        }
    }
    return true;
}

boolean isSparse(Matrix m){
    int i,j,cnt=0;
    for(i=0;i<ROWS(m);i++){
        for(j=0;j<COLS(m);j++){
            if(ELMT(m, i, j)!=0)cnt++;
        }
    }
    return cnt*20<=count(m) ? true : false;
}

Matrix inverse1(Matrix m){
    Matrix mm;int i, j;
    CreateMatrix(ROWS(m), COLS(m), &mm);
    for(i=0;i<ROWS(mm);i++){
        for(j=0;j<COLS(mm);j++){
            ELMT(m, i, j)*=-1;
        }
    }
    return mm;
}

void pInverse1(Matrix *m){
    *m = inverse1(*m);
}

float determinant(Matrix m){
    int i, j, sn=1;
    float det=0;
    Matrix mk;
    CreateMatrix(ROWS(m)-1, COLS(m)-1, &mk);
    for(i=0;i<ROWS(mk);i++){
        for(j=0;j<COLS(mk);j++){
            ELMT(mk,i,j)=ELMT(m, i+1, j+1);
        }
    }
    for(i=0;i<COLS(m);i++){
        if(i!=0){
            int x;
            for(x=0;x<ROWS(mk);x++){
                ELMT(mk,x,i-1)=ELMT(m,x+1,i-1);
            }
        }
        det+=ELMT(m, 0, i)*sn*determinant(mk);
        sn*=-1;
    }
    return det;
}

void transpose(Matrix *m){
    Matrix mm;int i, j;
    CreateMatrix(COLS(*m), ROWS(*m), &mm);
    for(i=0;i<ROWS(mm);i++){
        for(j=0;j<COLS(mm);j++){
            ELMT(mm, i, j)=ELMT(*m, i, j);
        }
    }
    copyMatrix(mm, m);
}















float rowMean (Matrix m, Index i) {
    float sum,row=ROWS(m);
    int j;
    for (j=0;j<COLS(m);j++)sum+=ELMT(m,i,j);
    return sum/row;
}

float colMean (Matrix m, Index j){
	float sum,col=COLS(m);
	int i;
	for(i=0; i<ROWS(m);i++)sum+=ELMT(m,i,j);
	return sum/col;
}

void rowExtremes (Matrix m, Index i, ElType *max, ElType *min){
	*max=ELMT(m,i,0);
    *min=ELMT(m,i,0);
    int j;
    for (j=0;j<COLS(m);j++) {
        if(ELMT(m,i,j)>*max)*max=ELMT(m,i,j);
        if(ELMT(m,i,j)<*min)*min=ELMT(m,i,j);
    }
}

void colExtremes (Matrix m, Index j, ElType *max, ElType *min){
	*max=ELMT(m,0,j);
    *min=ELMT(m,0,j);
    int i;
    for (i=0;i<ROWS(m);i++) {
        if(ELMT(m,i,j)>*max)*max=ELMT(m,i,j);
        if(ELMT(m,i,j)<*min)*min=ELMT(m,i,j);
    }
}

int countValOnRow (Matrix m, Index i, ElType val) {
    int j, cnt=0;
    for (j=0;j<COLS(m);j++)if(ELMT(m,i,j)==val)cnt++;
    return cnt;
}

int countValOnCol (Matrix m, Index j, ElType val) {
    int i, cnt=0;
    for (i=0;i<ROWS(m);i++)if(ELMT(m,i,j)==val)cnt++;
    return cnt;
}
