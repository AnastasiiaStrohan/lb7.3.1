#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void SortRowsByDuplicateCount(int** a, const int rowCount, const int colCount);
int FindFirstNonNegativeColumn(int** a, const int rowCount, const int colCount);

int main()
{
    srand((unsigned)time(NULL));
    int Low = -17;
    int High = 15;
    int rowCount, colCount;

    cout << "rowCount = ";
    cin >> rowCount;
    cout << "colCount = ";
    cin >> colCount;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

   
    Create(a, rowCount, colCount, Low, High);

    
    Print(a, rowCount, colCount);

    
    SortRowsByDuplicateCount(a, rowCount, colCount);
    cout << "Matrix after sorting rows by the count of duplicate elements:" << endl;
    Print(a, rowCount, colCount);

    
    int nonNegativeCol = FindFirstNonNegativeColumn(a, rowCount, colCount);
    if (nonNegativeCol != -1)
        cout << "The first column with no negative elements is: " << nonNegativeCol << endl;
    else
        cout << "There are no columns without negative elements." << endl;

    
    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}


int CountDuplicatesInRow(int* row, const int colCount)
{
    int duplicateCount = 0;
    for (int i = 0; i < colCount; i++)
        for (int j = i + 1; j < colCount; j++)
            if (row[i] == row[j])
            {
                duplicateCount++;
                break;
            }
    return duplicateCount;
}


void SortRowsByDuplicateCount(int** a, const int rowCount, const int colCount)
{
    for (int i = 0; i < rowCount - 1; i++)
    {
        for (int j = 0; j < rowCount - i - 1; j++)
        {
            if (CountDuplicatesInRow(a[j], colCount) > CountDuplicatesInRow(a[j + 1], colCount))
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}


int FindFirstNonNegativeColumn(int** a, const int rowCount, const int colCount)
{
    for (int j = 0; j < colCount; j++)
    {
        bool hasNegative = false;
        for (int i = 0; i < rowCount; i++)
        {
            if (a[i][j] < 0)
            {
                hasNegative = true;
                break;
            }
        }
        if (!hasNegative)
            return j; 
    }
    return -1; 
}
