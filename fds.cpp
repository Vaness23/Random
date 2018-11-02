#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s; // стек, хранящий вершины

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

    cout << "<-- ПОИСК В ГЛУБИНУ -->" << endl;
    cout << "          1     " << endl;
    cout << "        2   3   " << endl;
    cout << "      4       5 " << endl;
    cout << "Порядок обхода вершин:" << endl;

    int counter = 1; // счетчик для нумерации вершин

    s.push(0); // занесение первой вершины в стек
    while(!s.empty())
    {
        int num = s.top(); // извлечение вершины
        s.pop();

        if (values[num] == 1) // если вершина - тупик
            continue;

        values[num] = 1; // вершина пройдена

        for (int i = 4; i >= 0; i--) // проходим по смежным, непройденным вершинам
            if (matrix[num][i] == 1 && values[i] != 1)
                s.push(i); // вершина заносится в стек

        cout << "       #" << counter << " - " << num + 1 << endl;
        counter++;
    }

    return 0;
}