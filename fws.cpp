#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q; // очередь, хранящая вершины

    /* 1
      2 3
     4   5
          */

    // матрица смежности
    int matrix[5][5] =
    {{0, 1, 1, 0, 0},
     {1, 0, 0, 1, 0},
     {1, 0, 0, 0, 1},
     {0, 1, 0, 0, 0},
     {0, 0, 1, 0, 0}};

    int values[5]; // массив, хранящий значения вершин

    for(int i = 0; i < 5; i++)
        values[i] = 0; // все вершины не пройдены

    cout << "<-- ПОИСК В ШИРИНУ -->" << endl;
    cout << "          1     " << endl;
    cout << "        2   3   " << endl;
    cout << "      4       5 " << endl;
    cout << "Порядок обхода вершин:" << endl;

    int counter = 1; // счетчик для нумерации вершин

    q.push(0); // занесение первой вершины в очередь
    while(!q.empty())
    {
        int num = q.front(); // извлечение вершины
        q.pop();

        values[num] = 1; // вершина пройдена

        for (int i = 0; i < 5; i++) // проходим по смежным, непройденным вершинам
            if(matrix[num][i] == 1 && values[i] == 0)
            {
                q.push(i); // вершина заносится в очередь
                values[i] = 1; // вершина посещена
            }
            
        cout << "       #" << counter << " - " << num + 1 << endl;
        counter++;
    }

    return 0;
}