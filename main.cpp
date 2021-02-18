#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
/* 1 Комментарии*/

void show(int** matrix,int row, int column){
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

int** create_matrix(int row, int column){
    int** matrix = new int* [row];
    for (int i = 0; i < row; i++)
        matrix[i] = new int[column];
    return matrix;
}

void filling_null_matrix(int** matrix, int row, int column){
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            matrix[i][j] = 0;
}

void filling_matrix_random(int** matrix, int row,  int column ){
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            matrix[i][j] = rand() % 10;
}
void filling_matrix_by_user(int** matrix, int row,  int column){
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            cin >> matrix[i][j];
}

void filling_matrix_by_matrix(int** matrix, int** M, int row, int column){
    //TODO придумать названия для матриц
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            M[i][j] = matrix[i][j];
    }
}


void alignment_matrix_borders(int** matrix ,int x,int f, int l ) {
    for (int i = 0; i < l; i++)
    {
        x = 0;
        for (int j = 0; j < l; j++)
        {
            if (matrix[i][j] != 0)
            {
                x++;
                f = 100;
            }
        }
        if (x == 0 && i < f)
        {
            f = i;
        }
    }
}


void clear_memory(int** matrix, int row){
    for (int i=0; i < row; i++)
        delete[] matrix[i];
    delete[] matrix;
}

int main()
{
    srand(time(NULL));
    int row1, column1, row2, column2, choice, l = 2;
    system("chcp 1251");
    cout << "Вас приветствует программа" << endl <<
         "быстрого перемножения матриц методом Штрассена\n\n";

    //Ввод размеров матрицы пользователем//
    //TODO
    do
    {
        cout << "Введите размеры первой матрицы\n";
        cin >> row1 >> column1;
    } while (row1 <= 0 || column1 <= 0);

    do
    {
        cout << "Введите размеры второй матрицы\n";
        cin >> row2 >> column2;
    } while (row2 <= 0 || column2 <= 0);

    //     * Выделение памяти для матриц//
    int** matrix1 = create_matrix(row1,column1);
    int** matrix2 = create_matrix(row2,column2);






////////////////////Ввод размеров матрицы пользователем////////////////////////

    do
    {
        cout << "Выберите способ заполнения матриц\n" <<
             "1 - Вручную \n2 - Случайным образом\n";
        cin >> choice;
    } while (choice < 1 || choice > 2);


    switch (choice)
    {
        case 1:
            filling_matrix_by_user(matrix1,row1,column1);
            filling_matrix_by_user(matrix2,row2,column2);

            cout << "\nМатрица 1"<<"\n";
            show(matrix1, row1, column1);
            cout << "\nМатрица 2"<<"\n";
            show(matrix2, row2, column2);
            break;
        case 2:
            filling_matrix_random(matrix1,row1,column1);
            filling_matrix_random(matrix2,row2,column2);

            cout << "\nМатрица 1"<<"\n";
            show(matrix1, row1, column1);
            cout << "\nМатрица 2"<<"\n";
            show(matrix2, row2, column2);
            break;
    }

    /////////////////Приведение матриц к требуемому размеру////////////////////////

    while (l < row1 || l < row2 || l < column1 || l < column2)
        l *= 2;

    int** M3 = create_matrix(l,l);
    filling_null_matrix(M3,l,l);

    int** M4 = create_matrix(l,l);
    filling_null_matrix(M4,l,l);




    filling_matrix_by_matrix(matrix1,M3,row1,column1);
    filling_matrix_by_matrix(matrix2,M4,row2,column2);

    cout << "Приведенные матрицы\n";
    cout << "\nМатрица 1"<<"\n";
    show(M3,l,l);
    cout << "\nМатрица 2"<<"\n";
    show(M4,l,l);


    ///////////////Разбиение матриц на подматрицы и их заполнение//////////////////
    //TODO
    int** mat1 = new int* [l / 2];
    for (int i = 0; i < l / 2; i++)
    {
        mat1[i] = new int[l / 2];
        for (int j = 0; j < l / 2; j++)
            mat1[i][j] = M3[i][j];
    }

    int** mat2 = new int* [l / 2];
    for (int i = 0; i < l / 2; i++)
    {
        mat2[i] = new int[l / 2];
        for (int j = 0; j < l / 2; j++)
            mat2[i][j] = M3[i][j + l / 2];
    }

    int** mat3 = new int* [l / 2];
    for (int i = 0; i < l / 2; i++)
    {
        mat3[i] = new int[l / 2];
        for (int j = 0; j < l / 2; j++)
            mat3[i][j] = M3[i + l / 2][j];
    }

    int** mat4 = new int* [l / 2];
    for (int i = 0; i < l / 2; i++)
    {
        mat4[i] = new int[l / 2];
        for (int j = 0; j < l / 2; j++)
            mat4[i][j] = M3[i + l / 2][j + l / 2];
    }

    int** mat5 = new int* [l / 2];
    for (int i = 0; i < l / 2; i++)
    {
        mat5[i] = new int[l / 2];
        for (int j = 0; j < l / 2; j++)
            mat5[i][j] = M4[i][j];
    }

    int** mat6 = new int* [l / 2];
    for (int i = 0; i < l / 2; i++)
    {
        mat6[i] = new int[l / 2];
        for (int j = 0; j < l / 2; j++)
            mat6[i][j] = M4[i][j + l / 2];
    }

    int** mat7 = new int* [l / 2];
    for (int i = 0; i < l / 2; i++)
    {
        mat7[i] = new int[l / 2];
        for (int j = 0; j < l / 2; j++)
            mat7[i][j] = M4[i + l / 2][j];
    }

    int** mat8 = new int* [l / 2];
    for (int i = 0; i < l / 2; i++)
    {
        mat8[i] = new int[l / 2];
        for (int j = 0; j < l / 2; j++)
            mat8[i][j] = M4[i + l / 2][j + l / 2];
    }

    ////////////////////////Создание промежуточных матриц//////////////////////////
    //TODO
    int** p1 = new int* [l / 2];
    for (int i = 0; i < l / 2; i++)
    {
        p1[i] = new int[l / 2];
    }
    int** p2 = new int* [l / 2];
    for (int i = 0; i < l / 2; i++)
    {
        p2[i] = new int[l / 2];
    }
    int** p3 = new int* [l / 2];
    for (int i = 0; i < l / 2; i++)
    {
        p3[i] = new int[l / 2];
    }
    int** p4 = new int* [l / 2];
    for (int i = 0; i < l / 2; i++)
    {
        p4[i] = new int[l / 2];
    }
    int** p5 = new int* [l / 2];
    for (int i = 0; i < l / 2; i++)
    {
        p5[i] = new int[l / 2];
    }
    int** p6 = new int* [l / 2];
    for (int i = 0; i < l / 2; i++)
    {
        p6[i] = new int[l / 2];
    }
    int** p7 = new int* [l / 2];
    for (int i = 0; i < l / 2; i++)
    {
        p7[i] = new int[l / 2];
    }

    ////////////////////Вычисление значений промежуточных матриц///////////////////
    //TODO
    for (int i = 0; i < l / 2; i++)
    {
        for (int j = 0; j < l / 2; j++)
        {
            p1[i][j] = 0;
            for (int z = 0; z < l / 2; z++)
            {
                p1[i][j] += (mat1[i][z] + mat4[i][z]) * (mat5[z][j] + mat8[z][j]);
            }

            p2[i][j] = 0;
            for (int z = 0; z < l / 2; z++)
            {
                p2[i][j] += (mat3[i][z] + mat4[i][z]) * mat5[z][j];
            }

            p3[i][j] = 0;
            for (int z = 0; z < l / 2; z++)
            {
                p3[i][j] += mat1[i][z] * (mat6[z][j] - mat8[z][j]);
            }

            p4[i][j] = 0;
            for (int z = 0; z < l / 2; z++)
            {
                p4[i][j] += mat4[i][z] * (mat7[z][j] - mat5[z][j]);
            }

            p5[i][j] = 0;
            for (int z = 0; z < l / 2; z++)
            {
                p5[i][j] += (mat1[i][z] + mat2[i][z]) * mat8[z][j];
            }

            p6[i][j] = 0;
            for (int z = 0; z < l / 2; z++)
            {
                p6[i][j] += (mat3[i][z] - mat1[i][z]) * (mat5[z][j] + mat6[z][j]);
            }

            p7[i][j] = 0;
            for (int z = 0; z < l / 2; z++)
            {
                p7[i][j] += (mat2[i][z] - mat4[i][z]) * (mat7[z][j] + mat8[z][j]);
            }
        }
    }

    ///////////////////////Создание вспомогательных матриц/////////////////////////


    int** mat9 = create_matrix(l/2,l/2);


    int** mat10 = create_matrix(l/2,l/2);


    int** mat11 = create_matrix(l/2,l/2);


    int** mat12 = create_matrix(l/2,l/2);

    ////////////Подсчет значений вспомогательных матриц из промежуточных///////////

    for (int i = 0; i < l / 2; i++)
    {
        for (int j = 0; j < l / 2; j++)
        {
            mat9[i][j] = p1[i][j] + p4[i][j] - p5[i][j] + p7[i][j];
            mat10[i][j] = p3[i][j] + p5[i][j];
            mat11[i][j] = p2[i][j] + p4[i][j];
            mat12[i][j] = p1[i][j] - p2[i][j] + p3[i][j] + p6[i][j];
        }
    }

    ///////////////////Создание результирующей матрицы/////////////////////////////


    int** M5 = create_matrix(l,l);

    ///////Занесение информации из вспомогательных матриц в результирующую/////////

    for (int i = 0; i < l / 2; i++)
    {
        for (int j = 0; j < l / 2; j++)
        {
            M5[i][j] = mat9[i][j];
            M5[i][j + l / 2] = mat10[i][j];
            M5[i + l / 2][j] = mat11[i][j];
            M5[i + l / 2][j + l / 2] = mat12[i][j];
        }
    }

    ////////////////Выравнивание границ результирующей матрицы//////////////////////

    int x = 0, f = 100, s = 100;

    alignment_matrix_borders(M5,x,f,l);
    alignment_matrix_borders(M5,x,s,l);


    int** M6 = create_matrix(f,s);
    filling_matrix_by_matrix(M6,M5,f,s);


    ///////////////////Вывод результирующей матрицы////////////////////////////////

    cout << "\nРезультирующая матрица \n\n";
    show(M6,f,s);


    system("pause");

    //Очистка динамической памяти/////


    clear_memory(matrix1, row1);
    clear_memory(matrix2, row2);
    clear_memory(M3, l);
    clear_memory(M4, l);
    clear_memory(M5, l);
    clear_memory(M6, f);
    clear_memory(mat1, l / 2);
    clear_memory(mat2, l / 2);
    clear_memory(mat3, l / 2);
    clear_memory(mat4, l / 2);
    clear_memory(mat5, l / 2);
    clear_memory(mat6, l / 2);
    clear_memory(mat7, l / 2);
    clear_memory(mat8, l / 2);
    clear_memory(mat9, l / 2);
    clear_memory(mat10, l / 2);
    clear_memory(mat11, l / 2);
    clear_memory(mat12, l / 2);
    clear_memory(p1,l/2);
    clear_memory(p2,l/2);
    clear_memory(p3,l/2);
    clear_memory(p4,l/2);
    clear_memory(p5,l/2);
    clear_memory(p6,l/2);
    clear_memory(p7,l/2);


    return 0;

}
