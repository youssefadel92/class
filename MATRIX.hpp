#ifndef _MATRIX_hpp
#define _MATRIX_hpp

#include <iostream>
using namespace std;
// A class to store a matrix
class matrix
{
    protected:
    int** data;       // Pointer to 2-D array that will simulate matrix
    int row, col;
    public:
    matrix(){
        row=0;
        col=0;
    }
    matrix(int r,int c){
        col=c;
        row=r;
    }
    ~matrix() { delete[] data;}

    void setr(int r){
        row=r;
    }
    void setc(int c){
        col=c;
    }
    void create (int num[]){
        data = new int* [row];
        for (int i = 0; i < row; i++)
        data[i] = new int [col];
        for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        data[i][j] = num[i * col + j];
    }
    friend ostream& operator<< (ostream& out, matrix mat4);
    friend istream& operator>> (istream& in, matrix& mat4);
    friend matrix operator+ (matrix mat1, matrix mat2);
    friend matrix operator- (matrix mat1, matrix mat2);
    friend void operator++ (matrix& mat);
    friend void operator-- (matrix& mat);
    friend matrix operator+= (matrix& mat1, matrix mat2);
    friend matrix operator-= (matrix& mat1, matrix mat2);
    friend matrix operator+= (matrix& mat1, int num);
    friend matrix operator-= (matrix& mat1, int num);
    friend bool   operator!= (matrix mat1, matrix mat2);
    friend bool   operator== (matrix mat1, matrix mat2);
    friend bool issqaure(matrix mat1);
    friend bool issquareandidentity(matrix mat1);
    friend matrix transoposing (matrix mat1);
    friend bool symmetric (matrix mat1);
    void operator= (const matrix mat1)
    {
        delete[] data;
        matrix mat4;
        mat4.setr(mat1.row);
        mat4.setc(mat1.col);
        mat4.data = new int* [mat1.row];
        for (int i = 0; i < mat1.row; i++)
            mat4.data[i] = new int [mat1.col];

        for (int i = 0; i < mat1.row; i++)
            for (int j = 0; j < mat1.col; j++){
                mat4.data[i][j] = mat1.data[i][j];
                cout<<mat4.data[i][j];
            }
        for (int i = 0; i < mat1.row; i++)
            for (int j = 0; j < mat1.col; j++){
               data[i][j] = mat4.data[i][j];
            }


    }
};

// Takes an array of data and stores in matrix according
// to rows and columns
ostream& operator<< (ostream& out, matrix mat4) {
for (int i=0;i<mat4.row;i++){
        cout<<endl;
    for (int j=0;j<mat4.col;j++){
        cout<<mat4.data[i][j]<<"  ";
    }
}
    return out;
}

istream& operator>> (istream& in, matrix& mat4) {
    int r,c;
    cout<<"enter num of rows:";
    cin>>r;
    cout<<"enter num of cols:";
    cin>>c;
    cout<<"enter "<<r*c<<" numbers:";
    int data1 [r*c];
    for (int i=0;i<r*c;i++){
        cin>>data1[i];
    }
    mat4.setr(r);
    mat4.setc(c);
    mat4.create(data1);

    return in;
}

matrix operator+ (matrix mat1, matrix mat2) {
  if (mat1.row == mat2.row && mat1.col == mat2.col){
        matrix mat4;
        mat4.setr(mat1.row);
        mat4.setc(mat1.col);
        mat4.data = new int* [mat1.row];

        for (int i = 0; i < mat1.row; i++)
        mat4.data[i] = new int [mat1.col];

        for (int i = 0; i < mat1.row; i++)
        for (int j = 0; j < mat1.col; j++)
        mat4.data[i][j] = mat1.data[i][j]+mat2.data[i][j];
        return mat4;
  }
  else {
        cout<<"dimensions are different!";
  }
}

matrix operator- (matrix mat1, matrix mat2) {
  if (mat1.row == mat2.row && mat1.col == mat2.col){
        matrix mat4;
        mat4.setr(mat1.row);
        mat4.setc(mat1.col);
        mat4.data = new int* [mat1.row];

        for (int i = 0; i < mat1.row; i++)
        mat4.data[i] = new int [mat1.col];

        for (int i = 0; i < mat1.row; i++)
        for (int j = 0; j < mat1.col; j++)
        mat4.data[i][j] = mat1.data[i][j]-mat2.data[i][j];
        return mat4;
  }
  else {
        cout<<"dimensions are different!";
  }
}

void operator++ (matrix& mat){
    for (int i = 0; i < mat.row; i++)
        for (int j = 0; j < mat.col; j++)
            mat.data[i][j] = mat.data[i][j]+1;
};

void operator-- (matrix& mat){
    for (int i = 0; i < mat.row; i++)
        for (int j = 0; j < mat.col; j++)
            mat.data[i][j] = mat.data[i][j]-1;
}

matrix operator+= (matrix& mat1, matrix mat2){
    if (mat1.row == mat2.row && mat1.col == mat2.col){
        for (int i = 0; i < mat1.row; i++)
            for (int j = 0; j < mat1.col; j++)
                mat1.data[i][j] = mat1.data[i][j]+mat2.data[i][j];
    }
  else {
        cout<<"dimensions are different!";
  }
  return mat1;
}

matrix operator-= (matrix& mat1, matrix mat2){
    if (mat1.row == mat2.row && mat1.col == mat2.col){
        for (int i = 0; i < mat1.row; i++)
            for (int j = 0; j < mat1.col; j++)
                mat1.data[i][j] = mat1.data[i][j]-mat2.data[i][j];
    }
  else {
        cout<<"dimensions are different!";
  }
  return mat1;
}

matrix operator+= (matrix& mat1, int num){
    for (int i = 0; i < mat1.row; i++)
        for (int j = 0; j < mat1.col; j++)
            mat1.data[i][j] = mat1.data[i][j]+num;
  return mat1;
}

matrix operator-= (matrix& mat1, int num){
    for (int i = 0; i < mat1.row; i++)
        for (int j = 0; j < mat1.col; j++)
            mat1.data[i][j] = mat1.data[i][j]-num;
  return mat1;
}

bool   operator== (matrix mat1, matrix mat2){
	    if (mat1.row == mat2.row && mat1.col == mat2.col){
        bool state = true;
        for (int i=0;i<mat1.row;i++){
            for (int j=0;j<mat1.col;j++){
                if (mat1.data[i][j]!=mat2.data[i][j])
                    state= false;
            }
        }
        return state;
    }
    else
        return false;
}

bool   operator!= (matrix mat1, matrix mat2){
    if (mat1.row == mat2.row && mat1.col == mat2.col){
        bool state = false;
        for (int i=0;i<mat1.row;i++){
            for (int j=0;j<mat1.col;j++){
                if (mat1.data[i][j]!=mat2.data[i][j])
                    state= true;
            }
        }
        return state;
    }
    else
        return true;
}

bool issqaure(matrix mat1){
    if(mat1.row==mat1.col){
        return true ;
    }
    else{
        return false ;
    }
}

bool issquareandidentity(matrix mat1){
    if (issqaure(mat1)==1){
        for (int row = 0; row < mat1.row; row++)
        {
            for (int col = 0; col < mat1.row; col++)
            {
                if (row == col && mat1.data[row][col] != 1)
                    return false;
                else if (row != col && mat1.data[row][col] != 0)
                    return false;
            }
        }
        return true;
    }
    else return false;

}

matrix transoposing (matrix mat1){
    int data7[]={};
    matrix trans(mat1.row,mat1.col);
    trans.create(data7);
    for(int i=0 ; i<mat1.row; i++){
        for(int j =0; j<mat1.col ;j++){
            trans.data[i][j]=mat1.data[j][i];
        }
    }
    return trans;



}

bool symmetric (matrix mat1){
    int data7[]={};
    matrix trans(mat1.row,mat1.col);
    trans.create(data7);
    for(int i=0 ; i<mat1.row; i++){
        for(int j =0; j<mat1.col ;j++){
            trans.data[i][j]=mat1.data[j][i];
        }


    }
   for(int i=0 ; i<mat1.row ; i++){
        for(int j=0;j<mat1.col;j++){
            if(trans.data[i][j]!=mat1.data[i][j]){
                    return false ;

            }
        }
   }
   return true ;
}


#endif
