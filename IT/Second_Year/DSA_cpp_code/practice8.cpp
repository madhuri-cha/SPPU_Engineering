#include <iostream>
using namespace std;
#define MAX 20
class graph
{

    int g[MAX][MAX];
    int n;
    char v[MAX];

public:
    graph(int m)
    {

        n = m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                g[i][j] = 0;
            }
        }
    }
    void accept_v()
    {
        int i = 0;
        cout << " name of landmarks ";
        while (i < n)
        {
            cout << " Landmark 1 : [" << i + 1 << "] ";
            cin >> v[i];
            i++;
        }
        cout << "\n";
    }

    void accept_e()
    {
        int i, j, cst;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (i == j)
                {
                    g[i][j] = 0;
                    continue;
                }
                else
                {
                    cout << " accept Distance bet land mark [" << v[i] << "] [" << v[j] << "] :" << cst;
                }
                g[i][j] = g[j][i] = cst;
            }
            cout << "\n";
        }
    }
    void display()
    {
        int i = 0;
        while (i < n)
        {
            cout << "\t " << v[i];
            i++;
        }
        cout << "\n";
        for (int i = 0; i < n; i++)
        {
            cout << v[i];

            for (int j = 0; j < n; j++)
            {
                cout << "\t" << g[i][j];
            }
            cout << "\n";
        }
    }
};
int main()
{
    int n;
    graph dij(n);
    cout << " Enter landmarks you want  : \n";
    cin >> n;
    dij.accept_v();
    dij.accept_e();
    dij.display();
    return 0;
}